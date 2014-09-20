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
	int fd;
	string portStr;
	if(argc > 1){
		portStr = argv[1];
	}
	else{
		portStr = "/dev/ttyACM0";
	}
	printf("Trying to open port: %s\n",portStr.c_str());
	fd = open(portStr.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1){
		perror("Error opening port");
		return -1;
	}
	else{
		printf("Opened port\n");
	}
	// set read() calls to be nonblocking
	fcntl(fd, F_SETFL, FNDELAY);

	struct termios config;
	tcgetattr(fd,&config);
	//hardwire the baud rate for now
	if (cfsetispeed(&config,B115200) < 0 || cfsetospeed(&config,B115200) < 0 )
	{
		perror("Error setting baud rate");
	}
	if( tcsetattr(fd, TCSAFLUSH, &config) < 0 ){
		perror("Error setting serial port attributes");
	}
	printf("Set baud rate to 115200 baud\n");

	tcflush(fd,TCIOFLUSH);
	printf("Flushed i/o buffers\n");
	
	mavlinkClass mavl;
	
	float vicon_data[6] = {0,0,0,0,0,0};
	while(true){
		mavl.check_serial(fd);
		//usleep(100);
		mavl.send_periodic(fd);
		//mavl.update_vicon_buffer(vicon_data);
	}
	return 0;
}

