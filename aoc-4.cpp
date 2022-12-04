#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Pair {
    int a, b;
};

Pair parse_pair(std::string pair) {
    Pair p = {0, 0};
    int delim_pos = pair.find('-');
    p.a = std::stoi(pair.substr(0, delim_pos));
    p.b = std::stoi(pair.substr(delim_pos + 1));
    return p;
}

int main() {
    int count = 0;
    int count2 = 0;

    std::string line;
    std::ifstream data("data");
    while (std::getline(data, line)) {
        int end = line.find(',');
        Pair p1 = parse_pair(line.substr(0, end));
        Pair p2 = parse_pair(line.substr(end + 1));

        // Check if either pair contains the other 
        if ((p1.a <= p2.a && p1.b >= p2.b) || (p2.a <= p1.a && p2.b >= p1.b)) {
            count += 1;
        }

        // Check for any overlap between pairs
        if (p1.b >= p2.a && p1.a <= p2.b) {
            count2 += 1;
        }
    }

    std::cout << "part 1: " << count << std::endl;
    std::cout << "part 2: " << count2 << std::endl;
    return 0;
}
