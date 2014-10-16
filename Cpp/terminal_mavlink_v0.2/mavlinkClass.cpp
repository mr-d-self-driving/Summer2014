
#include "mavlinkClass.h"
#include "timerClass.h"

mavlinkClass::mavlinkClass(){
	counter = 0;
	_verbose = 0;
	for(int i = 0;i<6;i++)
		vicon_buffer[i] = 0;
	// identifying variables for this system via MAVlink
	system_id = 42;
	component_id = 0;
	// set flag to indicate we have not yet contacted a MAV
	has_contacted_mav = 0;
	// set target system variables to 0 initially
	target_system_id = 0;
	target_component_id = 0;
	return;
}

void mavlinkClass::handle_mavlink_msg(mavlink_message_t msg){
	// if this is the first time we talk to the MAV, get its sysid and compid
	if (!has_contacted_mav){
		target_system_id = msg.sysid;
		target_component_id = msg.compid;
		has_contacted_mav = 1;
		printf("Received heartbeat from MAV with sysid %i and compid %i\n",target_system_id,target_component_id);
	}
	// if we recognize the MAV, then parse the message
	if (msg.sysid == target_system_id)
	{
		switch(msg.msgid){
			case MAVLINK_MSG_ID_HEARTBEAT:
				handle_heartbeat(msg);
				break;
			case MAVLINK_MSG_ID_OPTICAL_FLOW:
				printf("Optic flow\n");
				break;
			case MAVLINK_MSG_ID_SYS_STATUS:
				handle_sys_status(msg);
				break;
			case MAVLINK_MSG_ID_STATUSTEXT:
				char buff[50];
				mavlink_msg_statustext_get_text(&msg,buff);
				printf("\nSTATUSTEXT: %s\n\n",buff);
				break;
			case MAVLINK_MSG_ID_COMMAND_ACK:
				printf("\n COMMAND_ACK MSG REC'D: msg id %i, result %i, ",
				mavlink_msg_command_ack_get_command(&msg),
				mavlink_msg_command_ack_get_result(&msg));
				switch(mavlink_msg_command_ack_get_result(&msg)){
					case MAV_RESULT_ACCEPTED:
						printf("Command accepted\n");
						break;
					case MAV_RESULT_TEMPORARILY_REJECTED:
						printf("Command temporarily rejected\n");
					case MAV_RESULT_DENIED:
						printf("Command denied\n");
						break;
					case MAV_RESULT_UNSUPPORTED:
						printf("Command unsupported\n");
						break;
					case MAV_RESULT_FAILED:
						printf("Command failed\n");
						break;
				}
				usleep(5e6);
				break;
			default:
				printf("Unrecognized MAVlink message type: %i\n",msg.msgid);
				break;
		}
	}
}

void mavlinkClass::handle_heartbeat(mavlink_message_t msg){
	//check the timing good/bad
	if (hb_rcv_timer.getDelta() <= (1.2*HB_TIME_IDEAL) ){
		heartbeat_status = 1;
		hb_rcv_timer.restart();
	}
	else {
		heartbeat_status = -1;
		hb_rcv_timer.restart();
	}
	//process the message
	uint8_t localvar;
	
	printf("Heartbeat: Mode ");
	localvar = mavlink_msg_heartbeat_get_base_mode(&msg);
	printf("%i",localvar);
	if (localvar & MAV_MODE_FLAG_SAFETY_ARMED)
		printf("%10s", "ARM");
	else
		printf("%10s","DISARMED");
	if (localvar & MAV_MODE_FLAG_STABILIZE_ENABLED)
		printf("%15s","STABILIZE");
	if (localvar & MAV_MODE_FLAG_GUIDED_ENABLED)
		printf("%15s","GUIDED");
	if (localvar & MAV_MODE_FLAG_MANUAL_INPUT_ENABLED)
		printf("%15s","MANUAL");
	if (localvar & MAV_MODE_FLAG_TEST_ENABLED)
		printf("%15s","TEST");
	if (localvar & MAV_MODE_FLAG_AUTO_ENABLED)
		printf("%15s","AUTO");
	// read the system state
	localvar = mavlink_msg_heartbeat_get_system_status(&msg);
	printf(", state: %i",localvar);
	if (localvar & MAV_STATE_UNINIT);
		printf("%10s","UNINIT");
	if(localvar & MAV_STATE_CALIBRATING);
		printf("%10s","CALIBRATING");
	if(localvar & MAV_STATE_STANDBY);
		printf("%10s","STANDBY");
	if(localvar & MAV_STATE_ACTIVE);
		printf("%10s","ACTIVE");
	
	printf("\n");
}

void mavlinkClass::handle_sys_status(mavlink_message_t msg){
	printf("Status message: sensors_present %i sensors_enabled %i sensors_health %i packet_drop_pct %f",
		mavlink_msg_sys_status_get_onboard_control_sensors_present(&msg),
		mavlink_msg_sys_status_get_onboard_control_sensors_enabled(&msg),
		mavlink_msg_sys_status_get_onboard_control_sensors_health(&msg),
		0.01*mavlink_msg_sys_status_get_drop_rate_comm(&msg));
	//tb continued
	
	printf("\n");
}

int mavlinkClass::get_heartbeat_status()
{
	return heartbeat_status;
}

void mavlinkClass::update_vicon_buffer(float*values){
	for(int i = 0;i<6;i++)
	{
		vicon_buffer[i] = values[i];
	}
}

void mavlinkClass::send_vicon(int &fd){
	//send garbage
	uint8_t tt = 254;
	write(fd,&tt,1);
	//send vicon
	vicon_buffer[0] = counter;
	mavlink_msg_vicon_position_estimate_pack(system_id,
		component_id,
		&msg,
		0.0f,
		vicon_buffer[0],vicon_buffer[1],vicon_buffer[2],vicon_buffer[3],vicon_buffer[4],vicon_buffer[5]);
	// Copy the message to the send buffer
	uint16_t len = mavlink_msg_to_send_buffer(buffy, &msg);
	// send the message
	if (write(fd,buffy,len)<0){
		printf("Vicon failed\n");
	}
	else{
		counter++;
		printf("Vicon wrote %li\n",counter);
	}
}

void mavlinkClass::send_heartbeat(int &fd){
	//send garbage
	uint8_t tt = 254;
	write(fd,&tt,1);
	mavlink_msg_heartbeat_pack(system_id,component_id,&msg,MAV_TYPE_ONBOARD_CONTROLLER,MAV_AUTOPILOT_INVALID,
	255,0,MAV_STATE_ACTIVE);
	// Copy the message to the send buffer
	uint16_t len = mavlink_msg_to_send_buffer(buffy, &msg);
	// send the message
	if (write(fd,buffy,len)<0){
		printf("Heartbeat failed to send\n");
	}
/*	else{
		printf("Wrote heartbeat\n");
	}*/
}

void mavlinkClass::send_periodic(int &fd){
	//check 50Hz loop
	if(fifty_hz_timer.getDelta() >= VICON_RATE_IDEAL){
		fifty_hz_timer.restart();
		//send vicon
		//send_vicon(fd);
	}
	// 1Hz loop
	if(one_hz_timer.getDelta() >= HB_TIME_IDEAL){
		one_hz_timer.restart();
		//send heartbeat
		send_heartbeat(fd);
	}
}

void mavlinkClass::send_cmd_arm(int &fd,bool state){
	//send garbage
	uint8_t tt = 254;
	write(fd,&tt,1);
	// state is 1 for arming, 0 for disarming
	mavlink_msg_command_long_pack(system_id,
	component_id,
	&msg,
	target_system_id,
	0,//MAV_COMP_ID_SYSTEM_CONTROL,//target_component_id,
	MAV_CMD_COMPONENT_ARM_DISARM,//400,//identifier for arm message
	0,//this is the first time we send the message
	float(state),
	0,0,0,0,0,0);
	// Copy the message to the send buffer
	uint16_t len = mavlink_msg_to_send_buffer(buffy, &msg);
	// send the message
	if (write(fd,buffy,len)<0){
		printf("Arm/disarm message failed.\n");
	}
	else{
		printf("Sent arm/disarm message: %f\n",float(state));
	}

	/*
	usleep(100);
	write(fd,&tt,1);
	mavlink_msg_command_long_pack(system_id,
	component_id,
	&msg,
	target_system_id,
	0,//MAV_COMP_ID_SYSTEM_CONTROL,//target_component_id,
	MAV_CMD_DO_SET_MODE,
	0,//this is the first time we send the message
	209,
	0,0,0,0,0,0);
	// Copy the message to the send buffer
	len = mavlink_msg_to_send_buffer(buffy, &msg);
	// send the message
	if (write(fd,buffy,len)<0){
		printf("Change mode message failed.\n");
	}
	else{
		printf("Sent change mode message: %f\n",float(state));
	}
	*/
}

void mavlinkClass::send_cmd_arm(int &fd,bool state,uint8_t target_system, uint8_t target_component){
	//send garbage
	uint8_t tt = 254;
	write(fd,&tt,1);
	// state is 1 for arming, 0 for disarming
	mavlink_msg_command_long_pack(system_id,
	component_id,
	&msg,
	target_system,
	target_component,//target_component_id,
	MAV_CMD_COMPONENT_ARM_DISARM,//identifier for arm message
	0,//this is the first time we send the message
	float(state),
	0,0,0,0,0,0);
	// Copy the message to the send buffer
	uint16_t len = mavlink_msg_to_send_buffer(buffy, &msg);
	if (write(fd,buffy,len)<0){
		printf("Failed to send arm message\n");
	}
	else{
		if (state)
			printf("Sent arm message to sys %i component %i: %f\n",target_system,target_component,float(state));
		else
			printf("Sent disarm message to sys %i component %i: %f\n",target_system,target_component,float(state));
	}
}

int mavlinkClass::check_serial(int &fd){
	int packet_drop_count = 0;
	//if(read(fd,&charval,1) > 0){
	//while(read(fd,&inputBuffy[counter],1) > 0 && counter < MAVLINK_MAX_PACKET_LEN){
	while(read(fd,&charval,1) > 0){
		//printf("%x\n",charval);
		if (mavlink_parse_char(MAVLINK_COMM_0, charval, &msg, &status)){
			handle_mavlink_msg(msg);
		}
		packet_drop_count += status.packet_rx_drop_count;
	}
	return packet_drop_count;
}
