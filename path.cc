#include "path.h"
#include "flit.h"

bool flit_trace = false;

std::map<long, std::vector<add_type> > flit_paths;
long flit_counter = 0;

void print_paths(std::ostream &out)
{
    std::map<long, std::vector<add_type> >::iterator iter;
    for (iter = flit_paths.begin(); iter != flit_paths.end(); iter++) {
        out << "flit " << iter->first << ":\t";
        std::vector<add_type> path = iter->second;
        for (int i = 0; i < path.size(); i++) {
            out << '(';
            int size = path[i].size();
            for (int j = 0; j < size; j++) {
                out << path[i][j];
                if (j != size - 1)
                    out << ',';
            }
            out << ')';
            if (i != path.size() - 1)
                out << "->";
        }
        out << endl;
    }
}

