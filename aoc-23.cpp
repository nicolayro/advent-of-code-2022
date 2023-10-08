#include <iostream>
#include <fstream>
#include <vector>

enum Direction {
    N,
    S,
    W,
    E,
    None
};

struct Position {
    int x, y;
};

bool check_dir(Direction d, std::vector<std::vector<bool>> &board, Position p) {
    for (int i = -1; i < 2; i++) {
        if (d == Direction::N) {
            if (board[p.y - 1][p.x + i]) {
                return false;
            }
        }
        else if (d == Direction::S) {
            if (board[p.y + 1][p.x + i]) {
                return false;
            }
        }
        else if (d == Direction::W) {
            if (board[p.y + i][p.x - 1]) {
                return false;
            }
        }
        else if (d == Direction::E) {
            if (board[p.y + i][p.x + 1]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    int empty = 0;
    std::vector<std::vector<bool>> board;
    Direction dirs[] = { N, S, W, E };

    std::string line;
    std::ifstream data("test");
    while(std::getline(data, line)) {
        std::vector<std::vector<bool>> row;
        row.emplace_back(false);
        for (auto &c : line) {
            row.emplace_back(c == '#');
        }
        row.emplace_back(false);
        board.emplace_back(row);
    }

    for (auto &row : board) {
        for (auto col : row) {
        }
    }

    std::cout << "Part 1: " << empty << std::endl;
    return 0;
}
