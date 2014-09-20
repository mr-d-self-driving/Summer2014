#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdlib.h>
#include <string>
#include "timerClass.h"
#include "terminal_mavlink.h"

/*
terminal_mavlink.cpp: source code for serial communication to PX4FMU board over USB

main_process should be called by main() and accepts a serial port as a command line argument
main_process looks for MAVlink heartbeats: if it gets them every 1.2 seconds or less, it sends dummy VICON MAVlink messages back at ~50 Hz.
*/

using namespace std;

// define ideal heartbeat rate - 1 Hz
# define HB_TIME_IDEAL 1.0f
// ideal VICON rate: 50 Hz
# define VICON_RATE_IDEAL 0.02f

static int heartbeat_status = -1;//heartbeat_status: -1 (heartbeat rate is slow) 1 (we are getting heartbeats at around 1 Hz or faster)
static int vicon_status = -1;
static timerClass vcn_send_timer;
static timerClass hb_rcv_timer;
int vcn_count = 0;


void handle_mavlink_msg(mavlink_message_t msg){
	switch(msg.msgid){
		case MAVLINK_MSG_ID_HEARTBEAT:
			handle_heartbeat(msg);
			break;
		case MAVLINK_MSG_ID_OPTICAL_FLOW:
			printf("Optic flow\n");
			break;
		default:
			//printf("Unrecognized MAVlink message type\n");
			break;
	}
}

void handle_heartbeat(mavlink_message_t msg){
	double hb_diff;
	if (hb_rcv_timer.getDelta() <= (1.2*HB_TIME_IDEAL) ){
		heartbeat_status = 1;
		hb_rcv_timer.restart();
		return;
	}
	else {
		printf("Warning: heartbeat rate appears slow\n");
		heartbeat_status = -1;
		hb_rcv_timer.restart();	
	}
}

/*
void main_process(int argc, char* argv[])

inputs:
argv[1]: serial port name, of the form "/dev/ttyxxxa". Default is "/dev/ttyACM0"

*/
void main_process(int argc, char* argv[]){
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
		return;
	}
	// set read() calls to be nonblocking
	fcntl(fd, F_SETFL, FNDELAY);

	mavlink_message_t msg;
	mavlink_status_t status;

	uint8_t buffy[MAVLINK_MAX_PACKET_LEN];
	uint8_t charval = 1;
	int serStatus=-1;
	while(true){
		//CHECK FOR NEW MESSAGES
		serStatus = read(fd,&charval,1);
		if(serStatus > 0){
			if (mavlink_parse_char(MAVLINK_COMM_0, charval, &msg, &status)){
				handle_mavlink_msg(msg);
			}
		}
		if (heartbeat_status >= 0){
			//send VICON messages at 50 Hz
			if (vcn_send_timer.getDelta() >= VICON_RATE_IDEAL){
				printf("%i,%f\t",vcn_count,vcn_send_timer.getDelta());
				vcn_send_timer.restart();
				
				//send garbage
				uint8_t tt = 254;
				write(fd,&tt,1);
				//send vicon
				mavlink_msg_vicon_position_estimate_pack(42,
					0,
					&msg,
					0.0f,
					vcn_count,vcn_count*vcn_count,0,0,0,0);
				// Copy the message to the send buffer
				uint16_t len = mavlink_msg_to_send_buffer(buffy, &msg);
				if (write(fd,buffy,len)<0)
					printf("Vicon failed\n");
				else{
					printf("Vicon wrote\n");
					vcn_count++;
				}
			}
		}
	}
	close(fd);
}
