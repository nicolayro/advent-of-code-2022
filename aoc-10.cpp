#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int part1 = 0;

void update_cycle(int &cycle, int X) {
        cycle++;
        part1 += cycle * X * (cycle % 40 == 20);
        // Part 2
        if (cycle % 40 == 1) std::cout << std::endl;
        if (cycle % 40 - X >= 0 && cycle % 40 - X <= 2) {
            std::cout << '#';
        } else {
            std::cout << '.';
        }
}

int main() {

    int cycle = 0, X = 1, V = 0; 

    std::string token;
    std::string line;
    std::ifstream data("data");
    while (std::getline(data, line)) {
        std::stringstream ss(line);
        ss >> token;
        update_cycle(cycle, X);

        if (token == "addx") {
            // Start
            ss >> token;
            V = std::stoi(token);
            
            update_cycle(cycle, X);

            // End
            X += V;
        }
    }
    std::cout << std::endl;
    std::cout << "Part 1: " << part1 << std::endl;
    return 0;
}
