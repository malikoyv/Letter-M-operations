#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
using namespace std;
#define KEY_PLUS 43
#define KEY_MINUS 45
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_GREATER 62
#define KEY_LESS 60
#define _USE_MATH_DEFINES

void set_cursor(int x, int y);
void printM(int size);
void move(int x, int y, int size);
void increase(int &size);
void decrease(int &size);
void rotate(int x, int y, int rotation, int size);

int main() {
    int userSize;
    int x, y, rotation = 0;
    char c;
    cout << "Type a height of letter \"M\": ";
    cin >> userSize;
    if (userSize <= 5 || userSize % 2 == 0) return 0; // Borders of a letter
    printM(userSize); // printing a letter

    while (true) {
        set_cursor(x, y);
        switch (c = getch()) {
            case KEY_UP:
                y -= 1;
                break;
            case KEY_DOWN:
                y += 1;
                break;
            case KEY_LEFT:
                x -= 1;
                break;
            case KEY_RIGHT:
                x += 1;
                break;
            case KEY_PLUS:
                increase(userSize);
                break;
            case KEY_MINUS:
                decrease(userSize);
                break;
            /*case KEY_GREATER:
                rotation = (rotation + 90) % 360;
                rotate(x, y, rotation, userSize);
                break;
            case KEY_LESS:
                rotation = (rotation - 90 + 360) % 360;
                rotate(x, y, rotation, userSize);
                break;*/
            case 'q':
                break;
        }
        system("CLS");
        move(x, y, userSize);
    }
}

void set_cursor(int x, int y) // cursor configuration
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition ( handle , coordinates );
}

void printM(int size){ // function for printing a letter
    int mid = size / 2;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (j == 0 || j == size - 1 || (i <= mid && i == j) || (i < mid && size - 1 - i == j))
            {
                cout << "M";
            } else cout << " ";
        }
        cout << endl;
    }
}

void increase(int &size){ // increase of letter
    if (size < 40) {  // Limit the maximum size
        size += 2;    // Increase the size by 2
    }
    printM(size); // print a letter
}

void decrease(int &size){
    if (size > 5) {  // Limit the maximum size
        size-= 2;    // Increase the size by 2
    }
    printM(size); // print a letter
}

void move(int x, int y, int size) {
    int mid = size / 2;
    for (int i = 0; i < size; i++) {
        set_cursor(x, y + i); // moving cursor causing it to print a letter where is a cursor
        for (int j = 0; j < size; j++) {
            if (j == 0 || j == size - 1 || (i <= mid && i == j) || (i < mid && size - 1 - i == j)) {
                cout << "M";
            } else cout << " ";
        }
    }
}

/*
void rotate(int x, int y, int rotation, int size) {
    int rotatedX = 0, rotatedY = 0;
    int mid = size / 2;
    for (int i = 0; i < size; i++) {
        set_cursor(x, y + i);
        for (int j = 0; j < size; j++) {
            rotatedX = (j - mid) * static_cast<int>(cos(rotation * M_PI / 180)) - (i - mid) * static_cast<int>(sin(rotation * M_PI / 180)) + mid;
            rotatedY = (j - mid) * static_cast<int>(sin(rotation * M_PI / 180)) + (i - mid) * static_cast<int>(cos(rotation * M_PI / 180)) + mid;
            if (rotatedX == 0 || rotatedX == size - 1 || rotatedY == mid) {
                cout << "M";
            } else cout << " ";
        }
    }
}*/
