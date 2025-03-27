#include <stdio.h>
#include <conio.h>
#include "Display.h"

int main() {
    showMenu();

    char input;
    input = _getch();

    if (input == '1')
    {
        puts("GPT 미워잉!");
    }
    else if (input == '2')
    {
        puts("다음 발표를 기대해주세요!");
    }
    else
    {
        puts("ㅂㅅ 잘못눌렀어.");
    }

    return 0;
}