//Student: Eng.Humberto Ramos Zuniga.
//e-mail: humbertoramoszuniga@gmail.com
//skypename: humbertoramoszuniga.
//Advisor PhD. John E. Hurtado.
//Supervisor: M.S. Austin Probe
//LASR LAB.
//Aerospace Department.
//Texas A&M University.
//Last update August 6, 2014
//Summer 2014.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// UAV HEX-COPTER. 3D-ROBOTICS.//

/*The following code allows connecting the UAV to a computer by serial port. The program is able to receive, send encode and decode messages coming in and going out from the serial port referenced in the program as USB. This version can be improved and expanded. The way to implement MAVLink messages is found in the MAVlink libraries included.
 
 
 This code works under the following conditions:
 1. The UAV has an Ardupilot which has no failsafes related with Radio Controller and GPS system.
 2. ESC (Electronic Speed Controllers) are properly calibrated. Set minumum and maximum throttle 1000 and 2000 as PWM signals, respectively.
 3. The ID's of the components are consistent across the systems (Ardupilot and computer).
 
 
 In a general way, when this program runs will perform the following actions:
 1. Open the /dev/tty.usbmodem411 serial port.
 2. Start to send a heartbeat per second from the computer to the UAV. And continuously read serial port to verify if there are bytes available. If so, the program decode and analyze the messages by using a switch structure.
 3. Wait for initialization of UAV.
 4. Configure the flying mode as STABILIZE.
 5. The program arms the motors.
 6. An increasing sequence of values for angular velocity of the motors is sent to the UAV (the RC values are overwritten by using override command).
 
 NOTES:
 
 Definitions of types, variables and functions can be found at mavlink.h and mavlink_types.h (See common folder for command reference).
 
 The pattern for using the MAVLink command is the same for all of them.
 
 Sending heartbeats is indispensable so the UAV can recognize the computer as a Ground Control Station. One second between beats is recommendable.
 
 To generate the C libraries was necessary to use a Python code (mavgenerate.py) and the definitions from common.xml version 1.0.
 
 
 All the necessary files for running this program appropriately, are included in the files provided along with this code.
 
 Detailed software and hardware versions.
 
 MAVLINK version 3.0
 Ardupilot Mega 2.6
 Hexcopter Y6 3D Robotics. Firmware Uploaded from APM Planner 2.0 software. Stable version 3.1.5V. Pre-arm Check DISABLED.
 Code C/C++
 
 For complete reference visit http://qgroundcontrol.org/mavlink/start
 
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Mavlink includes
#include <stdlib.h>
//#include "common/mavlink.h"
#include "mavlink.h"
#include "../mavlink_types.h"
// Standard includes
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <string.h>
#include <inttypes.h>
#include <fstream>
// Serial includes
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#ifdef __linux
#include <sys/ioctl.h>
#endif

#include "mavlinkClass.h"

// Latency Benchmarking
#include <sys/time.h>
#include <time.h>


using std::string;
using namespace std;

struct timeval tv;		  ///< System time

// Settings
int sysid = 255;             ///< The ID of Ground Control System (computer) Has to be consistent across the system
int compid = 1;             //ID of the component which sends the message (also computer).
int serial_compid = 0;      //To identify serial port.
bool silent = false;              ///< Wether console output should be enabled
bool verbose = false;             ///< Enable verbose output
bool debug = false;               ///< Enable debug functions and output
unsigned int messageLength;
uint32_t cont=1;
int USB;
uint16_t len;

void sendHeart()
{
    uint8_t bufsend[MAVLINK_MAX_PACKET_LEN];
    
    mavlink_message_t msg;
    mavlink_heartbeat_t beat;
    beat.custom_mode=MAV_MODE_FLAG_STABILIZE_ENABLED;       //Parameters required to send a heartbeat.
    beat.type=MAV_TYPE_HEXAROTOR;
    beat.autopilot=MAV_AUTOPILOT_ARDUPILOTMEGA;
    beat.base_mode=MAV_MODE_STABILIZE_ARMED;
    beat.system_status=MAV_STATE_ACTIVE;
    beat.mavlink_version=3;
    
    mavlink_msg_heartbeat_encode(sysid, compid, &msg, &beat);
    len=mavlink_msg_to_send_buffer(bufsend, &msg);
    write(USB,&bufsend,len);
    
     usleep(100); //Wait while port writes.
    

}




//Alternative for writing.
void serialwrite(uint8_t* buf,int USB)

{
    int n_written = 0;
    
    do
    {
        n_written += write( USB, &buf[n_written], 1 );
    }
    while (buf[n_written-1] != '\r' && n_written > 0);


}

//Function to open serial port.

int open_port()

{

	//USB = open( "/dev/tty.usbmodem411", O_RDWR| O_NONBLOCK | O_NDELAY );
	USB = open( "/dev/ttyACM0", O_RDWR| O_NONBLOCK | O_NDELAY );
	    
	    if (USB == -1)
		
		{
			/* Could not open the port. */
			return(-1);
		}
		else
		{
		fcntl(USB, F_SETFL, 0);
		fprintf(stderr, "LASR");
		//fcntl(fd, F_SETFL, FNONBLOCK);
		}


	struct termios tty;
	struct termios tty_old;
	memset (&tty, 0, sizeof tty);

	/* Error Handling */
	if ( tcgetattr ( USB, &tty ) != 0 )
	{
	    fprintf(stderr, "Port error");
	}

	/* Save old tty parameters */
	tty_old = tty;

	/* Set Baud Rate */
	cfsetospeed (&tty, (speed_t)B115200);
	cfsetispeed (&tty, (speed_t)B115200);

	/* Setting other Port Stuff */
	tty.c_cflag     &=  ~PARENB;        // Make 8n1
	tty.c_cflag     &=  ~CSTOPB;
	tty.c_cflag     &=  ~CSIZE;
	tty.c_cflag     |=  CS8;

	tty.c_cflag     &=  ~CRTSCTS;       // no flow control
	tty.c_cc[VMIN]      =   1;                  // read doesn't block
	tty.c_cc[VTIME]     =   10;                  // 0.5 seconds read timeout
	tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

	/* Make raw */
	// WAS cfmakeraw(&tty);

	/* Flush Port, then applies attributes */
	// WAS tcflush( USB, TCIFLUSH );
	if ( tcsetattr ( USB, TCSAFLUSH, &tty ) != 0)
	{
	    fprintf(stderr, "Port error");
	}

	return USB;
}

int main (void)
{
   
    int USB=open_port();
	
	/*
	mavlink object declaration
	*/
	mavlinkClass mavl;
    
    while (1)
    
    {
        
        uint8_t cp = '\0';   //Initialized for avoiding warning.
        
        //Declarations for receiveing messages.
        mavlink_message_t message;
        mavlink_status_t status;
        uint8_t msgReceived = false;
        mavlink_status_t lastStatus;
        lastStatus.packet_rx_drop_count = 0;
        msgReceived = mavlink_parse_char(MAVLINK_COMM_0, cp, &message, &status);
        
        //Declarations for decoding messages.
        mavlink_statustext_t statustext;
        mavlink_sys_status_t sys_status;
        
        int i=1;
        
	//count number of packet drops
	int packet_drops = 0;
    
        // Blocking wait for new data
        while (1)
        {
	
		// check the serial port and store any dropped packets
		//packet_drops += mavl.check_serial(&USB);
		//cont = mavl.get_hb_counts();
	
		
		    if (read(USB, &cp, 1) > 0)
		    {
		        
		        // Check if a message could be decoded (that means that we receive a valid MAVLink frame), return the message in case yes.
		        
		        msgReceived = mavlink_parse_char(MAVLINK_COMM_0, cp, &message, &status);
			/*
		        if (lastStatus.packet_rx_drop_count != status.packet_rx_drop_count)
		        {
		            if (verbose || debug) 
				printf("ERROR: DROPPED %d PACKETS\n", status.packet_rx_drop_count);
		            if (debug)
		            {
		                unsigned char v=cp;
		                fprintf(stderr,"%02x ", v);
		            }
		        }
		        lastStatus = status;*/
		    }
		    
		    // If a message could be decoded, handle it.
		    if(msgReceived)
		    {
		        
		        mavl.handle_mavlink_msg(&message);
			cont = mavl.get_hb_counts();
			/*
		       	uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
			messageLength = mavlink_msg_to_send_buffer(buffer, &message);
			if (messageLength > MAVLINK_MAX_PACKET_LEN)
			{
				fprintf(stderr, "\nFATAL ERROR: MESSAGE LENGTH IS LARGER THAN BUFFER SIZE\n");
			}                
		        
		        
		        // Switch to decode messages and print information in console.                
		        switch (message.msgid)
		        {
		            case MAVLINK_MSG_ID_HEARTBEAT:
		            {
		                mavlink_heartbeat_t h;
		               // fprintf(stderr, "Heartbeat received %d \n",cont++);
		                cont++;
				mavl.handle_heartbeat(&message);
		                //mavlink_msg_heartbeat_decode(&message, &h);
		                
		                //fprintf(stderr, "custom mode:%u type: %u autopilot: %d base mode:%u systems sttus: %u mavlink version: %u",h.custom_mode,h.type,h.autopilot,h.base_mode,h.system_status,h.mavlink_version);
		                
		                sendHeart();
		                
		                
		            }
		                break;
		                
		            case MAVLINK_MSG_ID_STATUSTEXT:
		            {
		                
		                mavlink_msg_statustext_decode(&message, &statustext);
		                
		                for(i=0;i<sizeof(statustext.text);i++)
		                {
		                    if (statustext.text[i]!=0)
		                    {
		                        fprintf(stderr,"%c",statustext.text[i]);
		                    }
		                    
		                    
		                }
		                fprintf(stderr,"\n");
		                
		            }
		                break;
		            case MAVLINK_MSG_ID_SYS_STATUS:
		            {
		                mavlink_msg_sys_status_decode(&message, &sys_status);
		                
		                //fprintf(stderr, "System status:\n Sensors enabled: %u\n Sensors health: %u\n ",sys_status.onboard_control_sensors_enabled,sys_status.onboard_control_sensors_health);
		                
		            }
		                break;
		                
		                
		            case MAVLINK_MSG_ID_COMMAND_ACK:
		            {
		                mavlink_command_ack_t response;
		                mavlink_msg_command_ack_decode(&message, &response);
		                fprintf(stderr, "ID:%u Command: %u \n",response.command,response.result);
		            
		            }
		                break;
		                
		                
		                
		        }*/
		    }
		    
		    
		    
		    if (cont==25)
		    {
			mavl.send_cmd_arm(&USB,1);
			/*
		        // Initialize the required buffers

		        uint8_t buf[MAVLINK_MAX_PACKET_LEN];
		        mavlink_message_t msg;
		        
		        //ENCODE ARM COMMAND
		        mavlink_command_long_t arm;
		        
		        //Parameters to send ARM command.
		        
		        arm.command=MAV_CMD_COMPONENT_ARM_DISARM;
		        arm.target_system=100;    //The ID of Ardupilot.
		        arm.target_component=250;   //ID of the control system of Ardupilot.
		        arm.confirmation=0;
		        arm.param1=1;                                   //1 to arm; 0 to disarm.
		        arm.param2=0;
		        arm.param3=0;
		        arm.param4=0;
		        arm.param5=0;
		        arm.param6=0;
		        arm.param7=0;
		                    
		        
		        mavlink_msg_command_long_encode(255, 1, &msg, &arm);
		        
		        // Copy the message to send buffer
		        len= mavlink_msg_to_send_buffer(buf, &msg);
		        
		        fprintf(stderr,"LASR:Trying to arm... ");
		        for (i=0; i<17; i++)                        //For to print message to send through serial port.
		        {
		            
		            fprintf(stderr,"%02x ", buf[i]);
		            
		        }
		        
		        fprintf(stderr,"\n");
		        
		        //serialwrite(buf,USB);
		        write(USB, &buf, len);
		        cont=26;
		        
		        usleep(100);
		          
		                
		        */
			cont++;
		        
		    }
		    
		    //Set Stabilize mode
		    
		    if (cont==15)
		    
		    {
		        mavl.send_set_mode(&USB,MAV_MODE_FLAG_STABILIZE_ENABLED,MAV_MODE_STABILIZE_ARMED);
/*
		        uint8_t buf[MAVLINK_MAX_PACKET_LEN];
		        mavlink_message_t msg;
		        mavlink_set_mode_t mode;
		        
		        mode.custom_mode=MAV_MODE_STABILIZE_ARMED;
		        mode.target_system=100;                         //ID of the control system of Ardupilot.
		        mode.base_mode=MAV_MODE_FLAG_STABILIZE_ENABLED;
		        
		        mavlink_msg_set_mode_encode(sysid, compid, &msg, &mode);
		        
		        
		        // Copy the message to send buffer
		        len= mavlink_msg_to_send_buffer(buf, &msg);
		        
		        fprintf(stderr,"LASR:SET MODE: ");     //Print message sent.
		        for (i=0; i<17; i++)
		        {
		            
		            fprintf(stderr,"%02x ", buf[i]);
		            
		        }
		        
		        fprintf(stderr,"\n");
		        
		        //serialwrite(buf,USB);
		        write(USB, &buf, len);
		        
		        cont=16;                
		        
		        usleep(100);
*/
			cont++;

		    }
		    
		    /////////Override command
		   
		    if (cont==35)
		        
		    {
		        
		        
		        uint8_t buf[MAVLINK_MAX_PACKET_LEN];
		        mavlink_message_t msg;
		        mavlink_rc_channels_override_t rc;
		        uint16_t vel=1000;
		        
		        while (1) {
		            
		        
		        
		        rc.chan1_raw=0;
		        rc.chan2_raw=0;
		        rc.chan3_raw=vel;       //Throttle value. Approximately from 1000 to 2000.
		        rc.chan4_raw=0;
		        rc.chan5_raw=0;
		        rc.chan6_raw=0;
		        rc.chan7_raw=0;
		        rc.chan8_raw=0;               
		        rc.target_component=250;    //ID of control system of Ardupilot.
		        rc.target_system=100;       //ID of Ardupilot.
		        
		        mavlink_msg_rc_channels_override_encode(sysid,compid, & msg, &rc);
		        
		        // Copy the message to send buffer
		        len= mavlink_msg_to_send_buffer(buf, &msg);
		        
		        fprintf(stderr,"LASR: RC3 %d",vel);    //Print message sent.
		        for (i=0; i<17; i++)
		        {
		            
		            fprintf(stderr,"%02x ", buf[i]);
		            
		        }
		        
		        fprintf(stderr,"\n");
		        
		        //serialwrite(buf,USB);
		        write(USB, &buf, len);
		        
		        
		        
		            vel=vel+10;
		        
		        sleep(1);
		        
		    }

            
            
            }
        }
        close(USB);
        return 0;
    
    }
    
    
    }
