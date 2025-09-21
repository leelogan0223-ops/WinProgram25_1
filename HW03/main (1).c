#include <stdio.h>
#include <math.h>
#include <Windows.h> // Sleep()함수 사용

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    COORD pos = { x - 1, y - 1 }; // COORD 구조체로 좌표 설정 (콘솔은 0,0부터 시작)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 커서 위치 설정
    printf("\x1b[%d;%dH",y,x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{   // isExploded 변수가 1이면 폭발, 0이면 폭탄 그림을 출력
    //폭탄은 항상 7칸
    if(isExploded)
    {   // 폭탄 폭발 시의 ASCII 아트 출력
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!"); 
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )"); // 폭탄이 터지지 않았을 때의 ASCII 아트 출력
}

int main()
{     
    // 여기부터 코드를 작성하세요----------------------   
      
      system("cls"); // 화면 지우기

	  // 폭탄 위치
      moveCursor(1, 3);
      printf("(  b  )");

    // 불꽃 (*) 위치
    moveCursor(14, 9);
    printf("*");

    // 불꽃으로부터 심지 그리기
    for (int y = 10; y <= 11; y++) {
        moveCursor(14, y);
        printf("#");
           }

    for (int x = 15; x <= 16; x++) {
        moveCursor(x, 11);
        printf("#");
          }
    
    for (int y = 10; y >= 7; y--) {
        moveCursor(16, y);
        printf("#");
           }

    for (int x = 16; x >= 12; x--) {
        moveCursor(x, 7);
        printf("#");
           }

    for (int y = 7; y <= 13; y++) {
        moveCursor(12, y);
        printf("#");
            }

    for (int x = 12; x <= 18; x++) {
        moveCursor(x, 13);
        printf("#");
           }

    for (int y = 13; y >= 5; y--) {
        moveCursor(18, y);
        printf("#");
           }

    for (int x = 18; x >= 10; x--) {
        moveCursor(x, 5);
        printf("#");
            }

    for (int y = 5; y <= 15; y++) {
        moveCursor(10, y);
        printf("#");
          }

    for (int x = 10; x <= 20; x++) {
        moveCursor(x, 15);
        printf("#");
            }

    for (int y = 15; y >= 3; y--) {
        moveCursor(20, y);
        printf("#");
           }

    for (int x = 20; x >= 8; x--) {
        moveCursor(x, 3);
        printf("#");
         }

    // 심지 태우기 
    for (int y = 10; y <= 11; y++) {
        moveCursor(14, y - 1);
        printf(" ");
		moveCursor(14, y);
		printf("*");
        Sleep(200);
    }
    
    for (int x = 15; x <= 16; x++) {
        moveCursor(x - 1,  11);
        printf(" ");
        moveCursor(x, 11);
        printf("*");
        Sleep(200);
    }

    for (int y = 11; y >= 7; y--) {
        moveCursor(16, y + 1);
        printf(" ");
        moveCursor(16, y);
        printf("*");
        Sleep(200);
    }

    for (int x = 16; x >= 12; x--) {
        moveCursor(x + 1, 7);
        printf(" ");
        moveCursor(x, 7);
        printf("*");
        Sleep(200);
    }

    for (int y = 7; y <= 13; y++) {
        moveCursor(12, y - 1);
        printf(" ");
        moveCursor(12, y);
        printf("*");
        Sleep(200);
    }

    for (int x = 12; x <= 18; x++) {
        moveCursor(x - 1, 13);
        printf(" ");
        moveCursor(x, 13);
        printf("*");
        Sleep(200);
    }

    for (int y = 13; y >= 5; y--) {
        moveCursor(18, y + 1);
        printf(" ");
        moveCursor(18, y);
        printf("*");
        Sleep(200);
    }

    for (int x = 18; x >= 10; x--) {
        moveCursor(x + 1, 5);
        printf(" ");
        moveCursor(x, 5);
        printf("*");
        Sleep(200);
    }

    for (int y = 5; y <= 15; y++) {
        moveCursor(10, y - 1);
        printf(" ");
        moveCursor(10, y);
        printf("*");
        Sleep(200);
    }

    for (int x = 10; x <= 20; x++) {
        moveCursor(x - 1, 15);
        printf(" ");
        moveCursor(x, 15);
        printf("*");
        Sleep(200);
    }


    for (int y = 15; y >= 3; y--) {
        moveCursor(20, y + 1);
        printf(" ");
        moveCursor(20, y);
        printf("*");
        Sleep(200);
    }

    for (int x = 20; x >= 1; x--) {
        moveCursor(x + 1, 3);
        printf(" ");
        moveCursor(x, 3);
        printf("*");

        Sleep(200);
    }

	// 불꽃이 폭탄에 다다른 후 사라지게 함
    moveCursor(1, 3);
    printf(" ");

    
    printBomb(1); // 마지막에 폭탄 터뜨리기 
    Sleep(5000); // 5초간 폭발 상태 유지

    // 여기까지 코드를 작성하세요----------------------  
    moveCursor(10, 20); // 커서를 아래로 옮겨서 텍스트가 겹치지 않게 합니다.
    return 0;
}