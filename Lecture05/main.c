#include <Windows.h>
#include <stdio.h>

void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, Cur);
}


int main()
{
    gotoxy(10, 10);
    puts("À¸¾Æ¾Æ");
	return 0;
}