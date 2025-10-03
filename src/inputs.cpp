#include "inputs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "dmaths.h"

std::pair<std::vector<float>, std::vector<std::vector<float>>> insert_specy(int nspecy, int ntimes){
    std::vector<float> times;
    std::vector<std::vector<float>> percents;
    std::vector<float> temps;

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
            temps.push_back(perc);
        }
        percents.push_back(temps);
        temps.clear();
    }
    return {times, percents};
}

char name_spec(int i) {
    char ascii = static_cast<char>(i + 65);
    return ascii;
}

void data_analyzer(std::pair<std::vector<float>, std::vector<std::vector<float>>> data, int n){
    std::string formula;
    std::vector<float> times                = data.first;
    std::vector<std::vector<float>> percents= data.second;
    int nacum = n;
    int i = 0;
    int k = 0;
    std::vector<std::string> formulas;
    for(std::vector<float> per_time: percents) {
        for(float perc: per_time){
            std::string stri = std::to_string(i+1);
            std::string strp = std::to_string(perc);
            formula = formula + "N"+ name_spec(k)+ (stri) +"("+(strp)+".N) +";
            k++;
        }
        formulas.push_back(formula);
        formula = "";
        k=0;
        i++;
    }
    for(i=0; i < times.size(); i++) {
        std::cout << "In "+std::to_string(times[i]) << std::endl;
        std::cout << "     -> " << formulas[i] << std::endl;
    }

    std::vector<int> options = { 1, 2 };
    int opc = 0;
    bool out = false;
    do {
        switch(opc) {
            case 0:
                std::cout << "starting asistant.." << std::endl;
                break;
            case 1:
                percent_it(times, percents);
                break;
            case 2:
                from_totals(times, percents);
                break;
            default:
                std::cout << "doing nothing, exiting!" << std::endl;
                break;
        }

        std::cout << "tell what to do" << std::endl;
        std::cout << "1.Percent in time.." << std::endl;
        std::cout << "2.From totals.." << std::endl;
        std::cout << "3.Exit" << std::endl;
        std::cin >> opc;
        auto it_found = std::find(options.begin(), options.end(), opc);
        if (it_found == options.end()) {
            std::cout << "false option" << std::endl;
            out = false;
        } else {
            out = true;
        }
    } while(out);
    std::cout << "Program ending" << std::endl;
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
