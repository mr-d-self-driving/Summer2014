#ifndef __MAVLINK_CLASS_H__
#define __MAVLINK_CLASS_H__

/*
mavlinkClass.h

mavlinkClass object for sending MAVLINK messages

TDW
twoodbury@tamu.edu
*/

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "mavlink.h"
#include "../mavlink_helpers.h"
#include <sys/time.h>

#include "timerClass.h"

// define ideal heartbeat rate - 1 Hz
# define HB_TIME_IDEAL 1.0f
// ideal VICON rate: 50 Hz
# define VICON_RATE_IDEAL 0.1f

class mavlinkClass{
	public:
		mavlinkClass();
		void handle_mavlink_msg(mavlink_message_t *msg);
		void handle_sys_status(mavlink_message_t *msg);
		void handle_heartbeat(mavlink_message_t *msg);
		void send_vicon(int *fd);
		void send_heartbeat(int *fd);
		int get_heartbeat_status();
		int check_serial(int *fd);
		void send_periodic(int *fd);
		void update_vicon_buffer(float*values);
		void send_cmd_arm(int *fd,bool state);
		void send_set_mode(int *fd,uint8_t base_mode, uint32_t custom_mode);//send mode change commands
		uint32_t get_hb_counts(void);//get the current number of heartbeat counts
	private:
		timerClass hb_rcv_timer;//tracks the time between receiving heartbeat messages
		timerClass one_hz_timer;//tracks time between last sending 1 Hz messages
		timerClass fifty_hz_timer;//tracks time between last sending 50 Hz messages
		int heartbeat_status;
		uint8_t buffy[MAVLINK_MAX_PACKET_LEN];
		uint8_t inputBuffy[MAVLINK_MAX_PACKET_LEN];
		uint8_t charval;//we read a  single serial character into here when we need to
		float vicon_buffer[6];//stores the most current vicon x,y,z,roll,pitch,yaw values
		uint32_t hb_counter;//counts received heartbeats
		// mavlink variables
		mavlink_message_t msg;
		mavlink_status_t status;
		//debugging variables
		long counter;
		//mavlink system parameters
		bool has_contacted_mav;
		uint8_t system_id;
		uint8_t component_id;
		uint8_t target_system_id;
		uint8_t target_component_id;
		// governs debugging output or not
		bool _verbose;
};

#endif
