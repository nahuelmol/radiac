#include <vector>


std::pair<std::vector<float>, std::vector<float>> insert_specy(int n){
    std::vector<float> times;
    std::vector<float> percent;

    int ntimes;
    std::cout << "tell me the times " << std::endl;
    std::cin >> ntimes;
    for (int j = 0; j < ntimes; j++) {
        std::cout << "time " << j <<" : " << std::endl;
        float time;
        std::cin >> time;
        times.push_back(time);
        for(int i = 0;i < n; i++) {
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
    std::vector<float> percents = data.second;
    std::vector<float> time = data.first;
    int nacum = n;
    int j = 0;
    std::vector<std::string> formulas;
    for(int i = 0; i < (percents.size()); i++) {
        //tomo los porcentajes en cada tiempo
        std::string num = std::to_string(1.0/percents[i]);
        char name = name_spec(i);
        formula = formula + num + " N"+name+"(" + std::to_string(time[j])+")" + " = ";
        if(i == (nacum - 1)) {
            nacum = nacum + n;
            std::cout << "time : " << time[j] << std::endl;
            formulas.push_back(formula);
            formula = "";
            j++;
        }
    }
    for(j=0; j < time.size(); j++) {
        std::cout << "In "+std::to_string(time[j]) << std::endl;
        std::cout << "     -> " << formulas[j] << std::endl;
    }
}

void input(std::string nspecis){
    int n = stoi(nspecis);
    if(n > 1) {
        std::cout << "insert each specy" << std::endl;
        auto output = insert_specy(n);
        data_analyzer(output, n);
    } else if (n == 1) {
        std::cout << "you should introduce more than only one specy";
    }
}

