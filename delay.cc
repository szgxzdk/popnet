#include "delay.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <vector>

using namespace std;

bool delay_trace = false;

long start_cycle = 0, end_cycle = LONG_MAX;

FILE * delay_file = NULL;

class delay {
public:
  int delay_time;
  long packet_id;

  delay(int delay_time, long packet_id):
    delay_time(delay_time), packet_id(packet_id) {}
};

vector<delay> delays;

void init_delay(const char * path) {
  delay_trace = true;

  delay_file = fopen(path, "w");
  if (delay_file == NULL) {
    fprintf(stderr, "ERROR: failed to open delay file %s\n", path);
    exit(1);
  }
}

void release_delay() {
  if (delay_file != NULL)
    fclose(delay_file);
}

void add_delay(int delay_time, long packet_id) {
  if (delay_trace)
    delays.push_back(delay(delay_time, packet_id));
}

void save_delay() {
  if (delay_trace) {
    vector<delay>::iterator it;
    for (it = delays.begin(); it != delays.end(); it++)
      fprintf(delay_file, "%ld %d\n", it->packet_id, it->delay_time);
  }
}
