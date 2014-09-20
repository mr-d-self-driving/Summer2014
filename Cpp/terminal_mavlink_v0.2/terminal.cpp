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

	string portStr;
	if(argc > 1){
		portStr = argv[1];
	}
	else{
		portStr = "/dev/ttyACM0";
	}

	printf("Trying to open port %s\n",portStr.c_str()cu);
	memset(&tio,0,sizeof(tio));
        tio.c_iflag=0;
        tio.c_oflag=0;
        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
        tio.c_lflag=0;
        tio.c_cc[VMIN]=0;
        tio.c_cc[VTIME]=5;
 
        fd=open(portStr.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fd == -1){
		perror("Error opening port");
		return -1;
	}
	else{
		printf("Opened port\n");
	}
	// set read() calls to be nonblocking
	//fcntl(fd, F_SETFL, FNDELAY);

	//hardwire the baud rate for now
	if (cfsetispeed(&tio,B57600) < 0 || cfsetospeed(&tio,B57600) < 0 )
	{
		perror("Error setting baud rate");
	}
	if( tcsetattr(fd,TCSANOW,&tio) < 0 ){
		perror("Error setting serial port attributes");
	}
	printf("Set baud rate to 57600 baud\n");

	//tcflush(fd,TCIOFLUSH);
	//printf("Flushed i/o buffers\n");
	
	mavlinkClass mavl;
	
	float vicon_data[6] = {0,0,0,0,0,0};
	while(true){
		mavl.check_serial(fd);
		mavl.send_periodic(fd);
		if (tcdrain(fd) != 0){
			printf("tcdrain() error\n");
			return -1;
		}
		//mavl.update_vicon_buffer(vicon_data);
	}
	return 0;
}

