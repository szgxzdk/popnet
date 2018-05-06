#ifndef _DELAY_H_
#define _DELAY_H_

extern long start_cycle, end_cycle;

void init_delay(const char * path);

void release_delay();

void add_delay(int delay_time, long packet_id);

void save_delay();

#endif
