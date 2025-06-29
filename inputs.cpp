#include <vector>


void insert_specy(int n){
    std::vector<int> times;
    std::vector<float> percent;

    int ntimes;
    std::cout << "tell me the times " << std::endl;
    std::cin >> ntimes;
    for (int j = 0; j < ntimes; j++) {
        std::cout << "time " << j <<" : " << std::endl;
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
}

void input(std::string nspecis){
    int n = stoi(nspecis);
    if(n > 1) {
        std::cout << "insert each specy" << std::endl;
        insert_specy(n);
    } else if (n == 1) {
        std::cout << "you should introduce more than only one specy";
    }
}

