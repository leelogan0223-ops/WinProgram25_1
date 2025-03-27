#include <stdio.h>
#include <conio.h>

int displayMenu() 
{
    puts("****************************");
    puts("*   !!!  0움직이기  !!!    *");
    puts("****************************");
    puts("");
    puts("1. 게임시작");
    puts("2. 종료");

    return 0;
}

void moveCharacter() {

    char land[30];
    int character = 0;

    for (int i = 0; i < 30; i++) {
        land[i] = '_';
    }
  
    while (1) {
        system("cls");

        for (int i = 0; i < 30; i++) {
            if (i == character) {
                printf("0");
            }
            else {
                printf("%c", land[i]);
            }
        }

        printf("\n");

        char move = _getch();
        if (move == 'd' && character < 29) {
            ++character;
        }
        else if (move == 'a' && character > 0) {
            --character;
        }

        if (move == '2') {
            puts("");
            puts("게임이 종료되었습니다.");
            break;
        }

    }
}

int main() {
    displayMenu();

    char choice;
    choice = _getch();

    if (choice == '1')
    {
        moveCharacter();
    }
    else if (choice == '2')
    {
        puts("");
        puts("종료되었습니다.");
    }
    else
    {
        puts("");
        puts("다시 시도해주세요.");
    }

    return 0;

}