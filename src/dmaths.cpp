#include <iostream>
#include <vector>
#include <math.h>
#include "inputs.h"

void percent_it( std::vector<float> times, std::vector<std::vector<float>> percents) {
    std::cout << "calulating percent in time.." << std::endl;
}

void from_totals(std::vector<float> times, std::vector<std::vector<float>> percents) {
    std::vector<float> enes;
    std::vector<std::vector<float>> parts;
    std::vector<float> temps;
    int i=0;
    int nit;
    for(float time:times) {
        std::cout << "Insert N total at "<< i << " ("<< time <<")"<< std::endl;
        std::cin >> nit;
        enes.push_back(nit);
        i++;
    }

    i = 0;
    for(std::vector<float> percs: percents) {
        for(float p:percs){
            float part = p * enes[i];
            temps.push_back(part);
        }
        i++;
        parts.push_back(temps);
        temps.clear();
    }
    i = 0;
    std::cout << "\nShowing real quantities" << std::endl;
    std::vector<std::string> matrix;
    std::string line;
    for(std::vector<float> part:parts) {
        for(float p:part) {
            line = line + "|" +std::to_string(p)+ "|";
        }
        line = std::to_string(i) + line;
        matrix.push_back(line);
        line.clear();
        i++;
    }
    for(std::string data:matrix){
        std::cout << data << std::endl;
    }
    std::cout << "\nFinding for first and second times" << std::endl;
    i=0;
    int j=0;
    std::vector<float> lambdas;
    std::vector<float> aux;
    for(std::vector<float> part:parts) {
        if(j==0){
            aux = part;
        } else if(j==1){
            for(float p:part) {
                float t = times[j] - times[j-1];
                float lambda = log(p/ aux[i])/(-t);
                lambdas.push_back(lambda);
                i++;
            }
        }
        j++;
    }
    std::cout << "\nLambdas are:" << std::endl;
    i = 0;
    for(float each:lambdas) {
        std::cout << "lambda_" << name_spec(i) << ": " << each << std::endl;
        i++;
    }
}
