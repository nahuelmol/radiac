#ifndef INPUTS_H
#define INPUTS_H

#include <utility>
#include <vector>
#include <string>

std::pair<std::vector<float>, std::vector<std::vector<float>>> insert_specy(int nspecy, int ntimes);
char name_spec(int i);
void data_analyzer(std::pair<std::vector<float>, std::vector<std::vector<float>>> data, int n);
void input(int nspecis, int ntimes);

#endif // INPUTS_H

