#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::vector<std::vector<char>> map;

    std::string line;
    std::ifstream data("test");
    while (std::getline(data, line)) {
        std::vector<char> v;
        for (auto &c : line) {
            v.emplace_back(c);
        }
        map.emplace_back(v);
    }
    for (auto a : map) {
        for (auto b : a) {
            std::cout << b;
        }
        std::cout << std::endl;
    }

    return 0;
}
