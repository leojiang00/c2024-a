
#include <iostream>
#include <vector>
#include <stack>
#include <conio.h> // 用于_getch()函数，以非阻塞方式读取键盘输入

using namespace std;

// 迷宫中的元素类型
enum Cell {
    WALL, // 墙
    PATH, // 路径
    START, // 起点
    EXIT, // 出口
    PLAYER // 玩家
};

// 迷宫结构
struct Maze {
    vector<vector<Cell>> grid;
    int width, height;

    Maze(int w, int h) : width(w), height(h) {
        grid.resize(h, vector<Cell>(w));
    }

    // 初始化迷宫
    void initialize() {
        // 简单迷宫示例
        grid = {
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, PATH, PATH, WALL, PATH, PATH, WALL, PATH, PATH, WALL},
            {WALL, PATH, WALL, WALL, PATH, WALL, WALL, PATH, WALL, WALL},
            {WALL, WALL, WALL, PATH, PATH, PATH, PATH, WALL, WALL, WALL},
            {WALL, PATH, WALL, WALL, WALL, WALL, PATH, PATH, WALL, WALL},
            {WALL, PATH, PATH, PATH, PATH, WALL, WALL, PATH, PATH, WALL},
            {WALL, WALL, WALL, WALL, PATH, WALL, WALL, WALL, PATH, WALL},
            {WALL, PATH, PATH, WALL, PATH, PATH, PATH, PATH, WALL, WALL},
            {WALL, PATH, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
        };
        // 设置起点和终点
        // 假设起点在左上角，出口在右下角
        grid[1][1] = START;
        grid[8][8] = EXIT;
    }

    // 打印迷宫
    void print() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                switch (grid[i][j]) {
                    case WALL: cout << "#"; break;
                    case PATH: cout << " "; break;
                    case START: cout << "S"; break;
                    case EXIT: cout << "E"; break;
                    case PLAYER: cout << "P"; break;
                }
            }
            cout << endl;
        }
    }

    // 移动玩家
    bool movePlayer(char direction) {
        static pair<int, int> playerPos = {1, 1}; // 假设玩家初始在左上角
        pair<int, int> newPos = playerPos;
        switch (direction) {
            case 'w': newPos.second = max(0, playerPos.second - 1); break;
            case 's': newPos.second = min(height - 1, playerPos.second + 1); break;
            case 'a': newPos.first = max(0, playerPos.first - 1); break;
            case 'd': newPos.first = min(width - 1, playerPos.first + 1); break;
        }
        // 检查新位置
        Cell newCell = grid[newPos.second][newPos.first];
        if (newCell == WALL) {
            return false; // 撞墙了
        }
        if (newCell == EXIT) {
            cout << "You win!" << endl;
            return true; // 到达出口
        }
        if (newCell == PATH) {
            grid[playerPos.second][playerPos.first] = PATH;
            grid[newPos.second][newPos.first] = PLAYER;
            playerPos = newPos;
        }
        return false;
    }
};

int main() {
    Maze maze(10, 10);
    maze.initialize();

    cout << "Use 'w', 'a', 's', 'd' to move. Try to reach the exit (E)." << endl;
    while (true) {
        maze.print();
        char input;
        if (_kbhit()) {
            input = _getch(); // 获取键盘输入
            if (maze.movePlayer(input)) {
                break; // 如果玩家赢了，退出游戏
            }
        }
    }

    return 0;
}