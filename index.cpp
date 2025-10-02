#include <iostream>
#include "inputs.h"

int main(int argc, char* argv[]) {
    std::string nspecis;
    std::string ntimes;

    std::cout << "insert n specis: ";  
    std::cin >> nspecis;
    std::cout << "tell me the times: ";
    std::cin >> ntimes;

    int ns = stoi(nspecis);
    int nt = stoi(ntimes);
    input(ns, nt);
    return 0;
}
