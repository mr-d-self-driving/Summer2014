#ifndef __TERMINAL_MAVLINK_H__
#define __TERMINAL_MAVLINK_H__

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <mavlink.h>

void handle_mavlink_msg(mavlink_message_t msg);
void main_process(int argc, char* argv[]);
void handle_heartbeat(mavlink_message_t msg);

#endif
