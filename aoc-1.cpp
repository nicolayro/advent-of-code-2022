#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int calories;
    std::vector<int> scores;

    std::string line;
    std::ifstream data("data");

    while(std::getline(data, line)) {
        if (line == "") {
            scores.emplace_back(calories);
            calories = 0;
        } else {
            calories += std::stoi(line);
        }
    }
    // Don't forget the last datapoint!
    scores.emplace_back(calories);

    std::sort(scores.begin(), scores.end(), [](int a, int b) {
            return a > b;
        });

    std::cout << "Part 1: " << scores[0] << std::endl;
    std::cout << "Part 2: " << scores[0] + scores[1] + scores[2] << std::endl;

    return 0;
} 
