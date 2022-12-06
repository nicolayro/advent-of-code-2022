#include <iostream>
#include <fstream>

bool is_last_n_unique(const std::string& line, int pos, int n) {
    for (int i = pos; i > pos - n + 1; --i) {
        for (int j = i - 1; j > pos - n; --j) {
            if (line[i] == line[j]) return false;
        }
    }
    return true;
}

int main() {
    int package_pos = 0;
    int message_pos = 0;

    std::string datastream;
    std::ifstream data("data");
    std::getline(data, datastream);
    // Part 1
    for (size_t pos = 3; pos < datastream.size(); pos++) {
        if (is_last_n_unique(datastream, pos, 4)) {
            package_pos = pos + 1;
            break;
        }
    }
    // Part 2
    for (size_t pos = 3; pos < datastream.size(); pos++) {
        if (is_last_n_unique(datastream, pos, 14)) {
            message_pos = pos + 1;
            break;
        }
    }
    std::cout << "Part 1: " << package_pos << std::endl;
    std::cout << "Part 1: " << message_pos << std::endl;
    return 0;
}
