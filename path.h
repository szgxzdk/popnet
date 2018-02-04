#ifndef _PATH_H_
#define _PATH_H_

#include <map>
#include <vector>
#include <fstream>

#include "flit.h"

extern bool flit_trace;

extern std::map<long, std::vector<add_type> > flit_paths;
extern long flit_counter;

void print_paths(std::ostream &out);

#endif
