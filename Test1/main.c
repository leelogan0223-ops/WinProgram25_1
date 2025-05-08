#include <stdio.h>


// 커서 이동
void moveCursor(int y, int x) {
    printf("\033[%d;%dH", y, x);
}

// 윈도우창 출력 함수
void drawWindow(int startX, int startY, int width, int height) {
    int endX = startX + width - 1;
    int endY = startY + height - 1;

    // 배경 색 설정 (파란 배경)
    printf("\033[44m");

    // 윈도우 배경 내부 채우기
    for (int y = startY + 1; y < endY; y++) {
        for (int x = startX + 1; x < endX; x++) {
            moveCursor(y, x);
            printf(" ");
        }
    }

    // 테두리 그리기
    for (int x = startX; x <= endX; x++) {
        moveCursor(startY, x); printf("-");
        moveCursor(endY, x);   printf("-");
    }

    for (int y = startY; y <= endY; y++) {
        moveCursor(y, startX); printf("|");
        moveCursor(y, endX);   printf("|");
    }

    // 꼭짓점
    moveCursor(startY, startX);     printf("+");
    moveCursor(startY, endX);       printf("+");
    moveCursor(endY, startX);       printf("+");
    moveCursor(endY, endX);         printf("+");

    // 닫기 버튼 (우측 상단)
    moveCursor(startY, endX - 2);
    printf("\033[41;97mX\033[44m"); // 빨간 배경 + 흰 글자

    // 초기화 및 커서 아래로 이동
    printf("\033[0m");
    moveCursor(endY + 1, 1);
}

int main() {
    int width = 80;   // 콘솔 가로
    int height = 25;  // 콘솔 세로

    int top_margin = 1;
    int bottom_margin = 1;
    int left_margin = 2;
    int right_margin = 2;

    // 파란 배경으로 내부 영역 채우기
    printf("\033[44m");  // 파란색 배경
    for (int row = top_margin + 1; row <= height - bottom_margin; row++) {
        for (int col = left_margin + 1; col <= width - right_margin; col++) {
            printf("\033[%d;%dH ", row, col);  // 커서 이동 + 공백 출력
        }
    }

    // 맨 아래줄은 회색 배경으로 변경
    printf("\033[100m");  // 회색 배경
    int row = height;     // 마지막 줄
    for (int col = 3; col < width-1; col++) {
        printf("\033[%d;%dH ", row, col);
    }

    // 스타일 초기화 + 커서 아래로 내리기
    printf("\033[0m\033[%d;1H", height + 1);

    return 0;
}