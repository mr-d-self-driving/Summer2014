
#include "mavlinkClass.h"

#include "timerClass.h"

mavlinkClass::mavlinkClass(){
	counter = 0;
	for(int i = 0;i<6;i++)
		vicon_buffer[i] = 0;
	return;
}

void mavlinkClass::handle_mavlink_msg(mavlink_message_t msg){
	switch(msg.msgid){
		case MAVLINK_MSG_ID_HEARTBEAT:
			handle_heartbeat(msg);
			break;
		case MAVLINK_MSG_ID_OPTICAL_FLOW:
			printf("Optic flow\n");
			break;
		default:
			printf("Unrecognized MAVlink message type: %i\n",msg.msgid);
			break;
	}
}

void mavlinkClass::handle_heartbeat(mavlink_message_t msg){
	if (hb_rcv_timer.getDelta() <= (1.2*HB_TIME_IDEAL) ){
		heartbeat_status = 1;
		hb_rcv_timer.restart();
		printf("Getting good heartbeats\n");
		return;
	}
	else {
		heartbeat_status = -1;
		hb_rcv_timer.restart();	
		printf("Getting bad heartbeats\n");
	}
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
	mavlink_msg_vicon_position_estimate_pack(42,
		0,
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
	mavlink_msg_heartbeat_pack(42,0,&msg,0,0,0,0,0);
	// Copy the message to the send buffer
	uint16_t len = mavlink_msg_to_send_buffer(buffy, &msg);
	// send the message
	if (write(fd,buffy,len)<0){
		printf("Heartbeat failed\n");
	}
	else{
		printf("Wrote heartbeat\n");
	}
}

void mavlinkClass::send_periodic(int &fd){
	//check 50Hz loop
	if(fifty_hz_timer.getDelta() >= VICON_RATE_IDEAL){
		fifty_hz_timer.restart();
		//send vicon
		send_vicon(fd);
	}
	// 1Hz loop
	if(one_hz_timer.getDelta() >= HB_TIME_IDEAL){
		one_hz_timer.restart();
		//send heartbeat
		send_heartbeat(fd);
	}
}

void mavlinkClass::check_serial(int &fd){
	//if(read(fd,&charval,1) > 0){
	//while(read(fd,&inputBuffy[counter],1) > 0 && counter < MAVLINK_MAX_PACKET_LEN){		
	while(read(fd,&charval,1) > 0){
		//printf("%x\n",charval);
		if (mavlink_parse_char(MAVLINK_COMM_0, charval, &msg, &status)){
			handle_mavlink_msg(msg);
		}
	}
}
