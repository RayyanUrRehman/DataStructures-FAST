#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

struct Config {
    string sortingAlgo;
   string searchingAlgo;
    int threshold;
};

Config readConfig(const string& filename) {
    Config config;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos) {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);

                if (key == "sorting_algorithm") {
                    config.sortingAlgo = value;
                } else if (key == "searching_algorithm") {
                    config.searchingAlgo = value;
                } else if (key == "threshold") {
                    config.threshold = std::stoi(value);
                }
            }
        }
        file.close();
    } else {
        // cerr << "Unable to open config file!" <<endl;
    }

    return config;
}

#endif 
