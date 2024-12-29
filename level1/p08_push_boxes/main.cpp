#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const char PLAYER = 'P';
const char BOX = 'B';
const char TARGET = 'T';
const char WALL = 'W';
const char EMPTY = '.';
const char BOX_ON_TARGET = 'X';

struct Level {
    vector<vector<char>> map;
    vector<pair<int, int>> boxes;
    vector<pair<int, int>> targets;
    int width, height;
};

bool readLevel(const string& filename, Level& level) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open the map file." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        level.map.push_back(vector<char>(line.begin(), line.end()));
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == BOX) {
                level.boxes.push_back({i, level.map.size() - 1});
            }
            if (line[i] == TARGET) {
                level.targets.push_back({i, level.map.size() - 1});
            }
        }
    }
    level.width = level.map[0].size();
    level.height = level.map.size();
    return true;
}

void saveScore(const string& filename, int score, int level) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Unable to open the score file." << endl;
        return;
    }
    file << "Level " << level << ": " << score << endl;
}

bool isGameOver(const Level& level) {
    for (const auto& box : level.boxes) {
        for (const auto& target : level.targets) {
            if (box.first == target.first && box.second == target.second) {
                continue;
            }
            return false;
        }
    }
    return true;
}

bool move(Level& level, int& playerX, int& playerY, int dx, int dy) {
    // 计算新位置
    int newX = playerX + dx;
    int newY = playerY + dy;

    // 检查新位置是否越界
    if (newX < 0 || newX >= level.width || newY < 0 || newY >= level.height) {
        return false;
    }

    // 检查新位置是否是墙壁
    if (level.map[newY][newX] == WALL) {
        return false;
    }

    // 尝试推动箱子
    int boxX = newX + dx;
    int boxY = newY + dy;

    // 检查箱子位置是否越界
    if (boxX < 0 || boxX >= level.width || boxY < 0 || boxY >= level.height) {
        return false;
    }

    // 检查新箱子位置是否是墙壁
    if (level.map[boxY][boxX] == WALL) {
        return false;
    }

    // 检查目标位置是否有箱子
    if (level.map[boxY][boxX] == BOX) {
        // 检查箱子是否可以被推动到的目标位置
        int targetX = boxX + dx;
        int targetY = boxY + dy;

        // 检查目标位置是否越界
        if (targetX < 0 || targetX >= level.width || targetY < 0 || targetY >= level.height) {
            return false;
        }

        // 检查目标位置是否是墙壁
        if (level.map[targetY][targetX] == WALL) {
            return false;
        }

        // 检查目标位置是否是空的
        if (level.map[targetY][targetX] == EMPTY) {
            // 移动箱子
            level.map[boxY][boxX] = EMPTY;
            level.map[targetY][targetX] = BOX;

            // 更新箱子位置
            for (auto& box : level.boxes) {
                if (box.first == boxX && box.second == boxY) {
                    box.first = targetX;
                    box.second = targetY;
                }
            }

            // 移动玩家
            level.map[playerY][playerX] = EMPTY;
            playerX = newX;
            playerY = newY;
            level.map[newY][newX] = PLAYER;

            return true;
        }
    }

    // 玩家移动到空位置
    level.map[playerY][playerX] = EMPTY;
    playerX = newX;
    playerY = newY;
    level.map[newY][newX] = PLAYER;

    return true;
}

void displayMap(const Level& level, int playerX, int playerY) {
    for (int y = 0; y < level.height; ++y) {
        for (int x = 0; x < level.width; ++x) {
            if (x == playerX && y == playerY) {
                cout << PLAYER;
            } else if (find(level.boxes.begin(), level.boxes.end(), make_pair(x, y)) != level.boxes.end()) {
                cout << BOX;
            } else if (find(level.targets.begin(), level.targets.end(), make_pair(x, y)) != level.targets.end() &&
                       find(level.boxes.begin(), level.boxes.end(), make_pair(x, y)) != level.boxes.end()) {
                cout << BOX_ON_TARGET;
            } else if (find(level.targets.begin(), level.targets.end(), make_pair(x, y)) != level.targets.end()) {
                cout << TARGET;
            } else if (level.map[y][x] == WALL) {
                cout << WALL;
            } else {
                cout << EMPTY;
            }
        }
        cout << endl;
    }
}

int main() {
    Level level;
    int playerX = -1, playerY = -1;
    int score = 0;

    if (!readLevel("D://Users//leojiang//CLionProjects//c2024-a//level1//p08_push_boxes//level01.txt", level)) {
        return 1;
    }

    for (int y = 0; y < level.height; ++y) {
        for (int x = 0; x < level.width; ++x) {
            if (level.map[y][x] == PLAYER) {
                playerX = x;
                playerY = y;
            }
        }
    }

    while (true) {
        displayMap(level, playerX, playerY);
        char command;
        cout << "Move (WASD): ";
        cin >> command;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (command) {
            case 'W': move(level, playerX, playerY, 0, -1); break;
            case 'S': move(level, playerX, playerY, 0, 1); break;
            case 'A': move(level, playerX, playerY, -1, 0); break;
            case 'D': move(level, playerX, playerY, 1, 0); break;
            default: cout << "Invalid command." << endl; continue;
        }

        score++; // Increment score with each move

        if (isGameOver(level)) {
            cout << "Congratulations, you've won!" << endl;
            saveScore("scores.txt", score, 1); // Save score for level 1
            break;
        }
    }

    return 0;
}