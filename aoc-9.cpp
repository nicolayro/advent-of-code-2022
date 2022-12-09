#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

int ROPE_LENGTH = 10;

struct Point {
    int x, y;
};

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

std::map<char, Point> direction_to_movement = {
   {'U', {0, 1}},
   {'L', {-1, 0}},
   {'D', {0, -1}},
   {'R', {1, 0}}
};

void print(const Point& head, const Point& tail) {
    for (int j = 6; j >= 0; --j) {
        for (int k = 0; k < 6; k++) {
            if (head.x == j && head.y == k) {
                std::cout << "H";
            }
            else if (tail.x == j && tail.y == k) {
                std::cout << "T";
            }
            else if (j == 0 && k == 0) {
                std::cout << "s";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Point rope[10];
    for (int i = 0; i < ROPE_LENGTH; i++) {
        rope[i] = {0, 0};
    }

    char direction;
    int steps;
    std::set<Point> visited_points_1;
    std::set<Point> visited_points_2;

    std::string line;
    std::ifstream data("data");
    while(std::getline(data, line)) {
        direction = line[0];
        steps = std::stoi(line.substr(line.find(" ")));

        Point movement_vector = direction_to_movement[direction];
        for (int i = 0; i < steps; i++) {
            rope[0].x += movement_vector.x;
            rope[0].y += movement_vector.y;

            for (int j = 0; j < ROPE_LENGTH - 1; j++) {
                Point head = rope[j];
                Point tail = rope[j + 1];
                if (head.x - tail.x > 1) {
                    tail.x = head.x - 1;
                    if (abs(tail.y - head.y) >= 1) {
                        tail.y = head.y;
                    }
                } else if (head.x - tail.x < -1) {
                    tail.x = head.x + 1;
                    if (abs(tail.y - head.y) >= 1) {
                        tail.y = head.y;
                    }
                } 

                if (head.y - tail.y > 1) {
                    tail.y = head.y - 1;
                    if (abs(tail.x - head.x) >= 1) {
                        tail.x = head.x;
                    }
                } else if (head.y - tail.y < -1) {
                    tail.y = head.y + 1;
                    if (abs(tail.x - head.x) >= 1) {
                        tail.x = head.x;
                    }
                }
                rope[j] = head;
                rope[j + 1] = tail;
            }
            visited_points_1.insert({rope[1].x, rope[1].y});
            visited_points_2.insert({rope[9].x, rope[9].y});
        }
    }

    std::cout << "Part 1: " << visited_points_1.size() << std::endl;
    std::cout << "Part 2: " << visited_points_2.size() << std::endl;
    return 0;
}
