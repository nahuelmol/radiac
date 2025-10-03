#include "inputs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "dmaths.h"

std::pair<std::vector<float>, std::vector<float>> insert_specy(int nspecy, int ntimes){
    std::vector<float> times;
    std::vector<float> percent;

    for (int j = 0; j < ntimes; j++) {
        float time;
        std::cout << "time " << j <<" : ";
        std::cin >> time;
        times.push_back(time);
        for(int i = 0; i < nspecy; i++) {
            char ascii = static_cast<char>(i + 65);
            float perc = 0.0;
            std::cout << "specy: " << ascii << " -> percent ";
            std::cin >> perc;
            percent.push_back(perc);
        }
    }
    return {times, percent};
}

char name_spec(int i) {
    char ascii = static_cast<char>(i + 65);
    return ascii;
}

void data_analyzer(std::pair<std::vector<float>, std::vector<float>> data, int n){
    std::string formula;
    std::vector<float> time     = data.first;
    std::vector<float> percents = data.second;
    int nacum = n;
    int j = 0;
    int k = 0;
    std::vector<std::string> formulas;
    for(int i = 0; i < (percents.size()); i++) {
        //std::string num = std::to_string(1.0/percents[i]);
        char name = name_spec(k);
        formula = formula + " N"+name+"(" + std::to_string(time[j])+")" + " = ";
        if(i == (nacum - 1)) {
            nacum = nacum + n;
            std::cout << "time : " << time[j] << std::endl;
            formulas.push_back(formula);
            formula = "";
            j++;
            k = -1;
        }
        k++;
    }
    for(j=0; j < time.size(); j++) {
        std::cout << "In "+std::to_string(time[j]) << std::endl;
        std::cout << "     -> " << formulas[j] << std::endl;
    }

    std::vector<int> options = { 1 };
    do {
        int opc;
        std::cout << "tell what to do" << std::end;
        std::cout << "1.Percent in time.." << std::end;
        std::cout << "2.Exit" << std::end;

        switch(opc) {
            case 1:
                std::cout << "making percent in time.." << std::end;
                percent_it(percents, time);
                break;
            default:
                std::out << "default" << std::end;
                break;
        }
    } while(std::find(options.begin(), options.end(), opc));
    
}

void input(int ns, int nt){
    if(ns > 1) {
        std::cout << "insert each specy: " << std::endl;
        auto output = insert_specy(ns, nt);
        data_analyzer(output, ns);
    } else if (ns == 1) {
        std::cout << "you should introduce more than only one specy";
    }
}
