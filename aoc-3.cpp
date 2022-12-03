#include <__tuple>
#include <iostream>
#include <fstream>
#include <string> 

// Used on char to convert to priority value
const unsigned UPPERCASE_OFFSET = 'A' - 27;
const unsigned LOWERCASE_OFFSET = 'a' - 1;

void part_one() {
    unsigned total = 0;

    std::string line;
    std::ifstream data("data");
    while (std::getline(data, line)) {
        size_t half = line.length() / 2;
        std::string first = line.substr(0, half);
        std::string second = line.substr(half, half);

        for (auto &c : first) {
            if (second.find(c) != std::string::npos) {
                total += c - (c < 'a' ? UPPERCASE_OFFSET : LOWERCASE_OFFSET);
                break;
            }
        }
    }

    std::cout << "Part 1: " << total << std::endl;
}

void part_two() {
    unsigned total = 0;

    std::string first;
    std::string second;
    std::string third;

    std::ifstream data("data");
    while (std::getline(data, first)) {
        std::getline(data, second);
        std::getline(data, third);
        
        for (auto &c : first) {
            if (second.find(c) != std::string::npos && third.find(c) != std::string::npos) {
                total += c - (c < 'a' ? UPPERCASE_OFFSET : LOWERCASE_OFFSET);
                break;
            }

        }
    }

    std::cout << "Part 2: " << total << std::endl;
}


int main() {
    part_one();
    part_two();
    return 0;
}
