
#include "timerClass.h"
#include <stdio.h>   /* Standard input/output definitions */
#include <sys/time.h>

// timerClass(): initialize the object at the current time
timerClass::timerClass(){
	//initialize the 'last time' value
	gettimeofday(&lastTime,NULL);
}

//restart(): reinitialize the 'initial' time to the current time
void timerClass::restart(){
	//reinitilize the last time value
	gettimeofday(&lastTime,NULL);
	// initialize the current time value
	gettimeofday(&thisTime,NULL);
}

//getDelta: update the "current time" structure and return the time difference since last time in seconds (double)
double timerClass::getDelta(){
	// get the current delta-time from the last time "restart" was called to the current time
	// in seconds
	gettimeofday(&thisTime,NULL);
	return double(thisTime.tv_sec-lastTime.tv_sec+1e-6*(thisTime.tv_usec - lastTime.tv_usec));
}

//getDelta: update the "current time" structure and return the time difference since last time in microseconds (long). Only use if you need super precise timing, which isn't really a C++ thing anyway so you're probably doing it wrongly already.
long timerClass::getMicros(){
	// get the current delta-time from the last time "restart" was called to the current time
	// in microseconds as a long int
	gettimeofday(&thisTime,NULL);
	return long(1e6*(thisTime.tv_sec-lastTime.tv_sec)+thisTime.tv_usec - lastTime.tv_usec);
}
