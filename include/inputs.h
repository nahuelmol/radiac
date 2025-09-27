#ifndef INPUTS_H
#define INPUTS_H

#include <utility>
#include <vector>
#include <string>

std::pair<std::vector<float>, std::vector<float>> insert_specy(int n);
char name_spec(int i);
void data_analyzer(std::pair<std::vector<float>, std::vector<float>> data, int n);
void input(std::string nspecis);

#endif // INPUTS_H

