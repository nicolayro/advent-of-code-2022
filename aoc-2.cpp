#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> scores = {
    {"A X", 1 + 3},
    {"A Y", 2 + 6},
    {"A Z", 3 + 0},
    {"B X", 1 + 0},
    {"B Y", 2 + 3},
    {"B Z", 3 + 6},
    {"C X", 1 + 6},
    {"C Y", 2 + 0},
    {"C Z", 3 + 3},
};

std::unordered_map<std::string, int> scores2 = {
    {"A Y", 1 + 3},
    {"A Z", 2 + 6},
    {"A X", 3 + 0},
    {"B X", 1 + 0},
    {"B Y", 2 + 3},
    {"B Z", 3 + 6},
    {"C Z", 1 + 6},
    {"C X", 2 + 0},
    {"C Y", 3 + 3},
};

int main() {
    int total = 0;
    int total2 = 0;

    std::string line;
    std::ifstream data("data");
    while (std::getline(data, line)) {
        total += scores[line];
        total2 += scores2[line];
    }

    std::cout << "Part 1: " << total << std::endl;
    std::cout << "Part 1: " << total2 << std::endl;

    return 0;
} 
