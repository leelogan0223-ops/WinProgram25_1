#include <conio.h>  // kbhit(), getch() 사용
#include <stdio.h>

int main() 
{
    while (1) 
    {
        // 키가 눌렸으면
        if (kbhit()) 
        {
            char ch = getch();  // 눌린 키를 받아옴
            if (ch == 'w') 
            {
                printf("위로 이동\n");
            }
            else if (ch == 's') 
            {
                printf("아래로 이동\n");
            }
            else if (ch == 'a') 
            {
                printf("왼쪽으로 이동\n");
            }
            else if (ch == 'd') 
            {
                printf("오른쪽으로 이동\n");
            }
            else if (ch == 'q') 
            {
                printf("게임 종료\n");
                break;  // 'q' 키를 누르면 게임 종료
            }
        }
        // 여기에 다른 게임 로직이 들어갈 수 있음
    }
    return 0;
}