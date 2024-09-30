#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;
void Character(char character, int width, int speed) {
    int p = 0;
    int d = 1;
    while (true) {
        system("cls");
        for (int i = 0; i < p; i++) {
            cout << ' ';
        }
        cout<<character<<endl;
        p += d;
        if (p >= width - 1) {
            d = -1;
        } else if (p <= 0) {
            d = 1;
        }
        Sleep(speed);
    }
}

int main() {
    char character = 'A';
    int width = 40;
    int speed = 100;
    Character(character, width, speed);
    return 0;
}
