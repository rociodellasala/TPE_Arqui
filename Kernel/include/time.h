#ifndef _TIME_H_
#define _TIME_H_

/* Increments ticks */
void timer_handler();

/* Returns ticks elapsed since last time */
int ticks_elapsed();

/* Returns seconds elapsed since last time */
int seconds_elapsed();

/* Sleeps console for a while */
void sleep(unsigned long t);

#endif
