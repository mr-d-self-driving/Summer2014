#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <mavlink.h>

#include "terminal_mavlink.h"

int main(int argc, char* argv[]){
	main_process(argc, argv);
	return 0;
}

