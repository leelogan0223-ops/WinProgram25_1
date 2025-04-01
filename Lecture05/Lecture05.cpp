#include <windows.h>
#include <stdio.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    // 예시: 10, 5 위치로 커서 이동
    gotoxy(10, 5);
    printf("커서가 (10, 5)로 이동했습니다!");
    return 0;
}