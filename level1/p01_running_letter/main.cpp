#include <stdio.h>
#include <stdlib.h> // 用于system函数
#include <windows.h> // 用于Sleep函数

void movingCharacter(char character, int width, int speed) {
    int position = 0;
    int direction = 1; // 1表示向右，-1表示向左

    while (1) {
        system("cls"); // 清屏

        // 输出字符
        for (int i = 0; i < position; i++) {
            printf(" "); // 输出空格
        }
        printf("%c\n", character);

        // 更新位置
        position += direction;

        // 检查是否碰到边界
        if (position >= width - 1) { // 右边界
            direction = -1;
        } else if (position <= 0) { // 左边界
            direction = 1;
        }

        // 控制运动速度
        Sleep(speed); // Sleep接受的参数是毫秒
    }
}

int main() {
    char character = 'A'; // 可以替换为任何字符
    int width = 40; // 控制台宽度
    int speed = 100; // 控制速度（毫秒）

    movingCharacter(character, width, speed);

    return 0;
}
