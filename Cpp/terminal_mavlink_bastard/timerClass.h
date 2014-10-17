#ifndef __TIMER_CLASS_H__
#define __TIMER_CLASS_H__

/*
timerClass.h

timerClass() object for measuring the time between events in a process
intended for use in real-time applications on Linux
on Windows you should use <ctime>

TDW
twoodbury@tamu.edu
*/

#include <stdio.h>   /* Standard input/output definitions */
#include <sys/time.h>

class timerClass{
	public:
		timerClass();
		void restart();
		double getDelta();
		long getMicros();
	private:
		timeval lastTime;
		timeval thisTime;
};

#endif
