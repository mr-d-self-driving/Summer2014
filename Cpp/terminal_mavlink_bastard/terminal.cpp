#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <string>
#include <mavlink.h>

#include "mavlinkClass.h"

using namespace std;

int main(int argc, char* argv[]){
	/*
	check if a serial port is specified
	open it if it is, else open the default
	*/
	struct termios tio;
	int fd;
	fd_set rdset;

	/*
	Parse input arguments. Add a second argument for
	baud rate in the future. 
	*/
	string portStr;
	if(argc > 1){
		portStr = argv[1];
	}
	else{
		portStr = "/dev/ttyACM0";
	}

	printf("Trying to open port %s\n",portStr.c_str());
	memset(&tio,0,sizeof(tio));
  
        fd=open(portStr.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
	//fd=open(portStr.c_str(), O_RDWR | O_NDELAY | O_NONBLOCK);
	if (fd == -1){
		perror("Error opening port");
		return -1;
	}
	else{
		printf("Opened port\n");
	}
	// set read() calls to be nonblocking
	fcntl(fd, F_SETFL, FNDELAY);
	//fcntl(fd, F_SETFL, 0);

	//hardwire the baud rate for now
	if (cfsetispeed(&tio,B115200) < 0 || cfsetospeed(&tio,B115200) < 0 )
	{
		perror("Error setting baud rate");
	}

	//set port attirubtes
       /*tio.c_iflag=0;
        tio.c_oflag=0;
        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
        tio.c_lflag=0;
        tio.c_cc[VMIN]=0;
        tio.c_cc[VTIME]=5;*/
	tio.c_cflag     &=  ~PARENB;        // Make 8n1
	tio.c_cflag     &=  ~CSTOPB;
	tio.c_cflag     &=  ~CSIZE;
	tio.c_cflag     |=  CS8;

	tio.c_cflag     &=  ~CRTSCTS;       // no flow control
	tio.c_cc[VMIN]      =   1;                  // read doesn't block
	tio.c_cc[VTIME]     =   10;                  // 0.5 seconds read timeout
	tio.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

	//if( tcsetattr(fd,TCSANOW,&tio) < 0 ){
	if( tcsetattr(fd,TCSAFLUSH,&tio) < 0 ){
		perror("Error setting serial port attributes");
	}
	printf("Set baud rate to 115200 baud\n");

	tcflush(fd,TCIOFLUSH);
	printf("Flushed i/o buffers\n");

	/*
	mavlink object declaration
	*/
	mavlinkClass mavl;
	//count number of packet drops
	int packet_drops = 0;

	/*
	Buffer for input keystrokes
	*/
	char keyBuffer[256];
	uint keyCounter = 0;
	fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);

	/*
	Status flags
	*/
	bool FLAG_STABILIZE_SENT = false;

	float vicon_data[6] = {0,0,0,0,0,0};
	while(true){
		// check the serial port and store any dropped packets
		packet_drops += mavl.check_serial(&fd);

		// check the number of heartbeats and prevent user interaction before mode set
		if (mavl.get_hb_counts() > 15)
		{
			mavl.send_periodic(fd);
			// read keyboard inputs to the buffer
			if(read(STDIN_FILENO,&keyBuffer[keyCounter],1)>0){
				keyCounter++;
				//check for carriage return or newline characters
				if (keyBuffer[keyCounter-1] == 13||keyBuffer[keyCounter-1]==10){
					// append null character
					keyBuffer[keyCounter-1] = 0;
					printf("Keyboard input:");
					for(int i = 0;i<keyCounter-1;i++)
						printf("%c",keyBuffer[i]);
					printf("\n");
					//process keyboard input
					if (strcmp(keyBuffer,"arm")==0){
						printf("Arm command\n");
						mavl.send_cmd_arm(fd,1);
					}
					if(strcmp(keyBuffer,"disarm")==0){
						printf("Disarm command\n");
						mavl.send_cmd_arm(fd,0);
					}
					if(strcmp(keyBuffer,"exit")==0){
						printf("Terminating session\n");
						break;
					}
					if(strcmp(keyBuffer,"heartbeat")==0){
						//query the heatbeat receive status
						printf("RX heartbeat status: %i, RX packet drops: %i\n",mavl.get_heartbeat_status(),packet_drops);
					}
					//reset for next loop
					keyCounter = 0;
				}
			}
			//mavl.update_vicon_buffer(vicon_data);
		}
		else if (mavl.get_hb_counts() == 15 && !FLAG_STABILIZE_SENT){
			FLAG_STABILIZE_SENT = true;
			printf("\nAttempting to set MAV stabilize mode...\n");
			mavl.send_set_mode(fd,MAV_MODE_FLAG_STABILIZE_ENABLED,MAV_MODE_STABILIZE_ARMED);
		}

		//check terminal status
		if (tcdrain(fd) != 0){
			printf("tcdrain() error\n");
			return -1;
		}

	}
	return 0;
}

