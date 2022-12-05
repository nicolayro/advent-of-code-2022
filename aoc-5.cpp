#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>

int main() {
    std::deque<char> stacks[9];
    std::deque<char> stacks2[9];

    std::string line;
    std::ifstream data("data");
    while (std::getline(data, line)) {
        if (line[1] == '1') break;
        for (size_t i = 1; i < line.size(); i += 4) {
            if (line[i] != ' ') {
                stacks[(i - 1) / 4].push_front(line[i]);
                stacks2[(i - 1) / 4].push_front(line[i]);
            }
        }
    }

    std::string temp;
    int count, from, to;
    while (std::getline(data, line)) {
        std::deque<char> crane;
        std::stringstream ss(line);
        ss >> temp >> count >> temp >> from >> temp >> to;
        for (int i = 0; i < count; i++) {
            char crate = stacks[from - 1].back();
            stacks[to - 1].push_back(crate);
            stacks[from - 1].pop_back();

            // Part 2
            crane.emplace_front(stacks2[from - 1].back());
            stacks2[from - 1].pop_back();
        }
        for (auto &crate : crane) {
            stacks2[to - 1].emplace_back(crate);
        }
    }

    std::cout << "Part 1: ";
    for (auto stack : stacks) {
        if (!stack.empty()) std::cout << stack.back();
    }
    std::cout << "\nPart 2: ";
    for (auto stack : stacks2) {
        if (!stack.empty()) std::cout << stack.back();
    }
    std::cout << std::endl;
    return 0;
}
