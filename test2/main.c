#include <stdio.h>
#include <string.h>

// 커서 이동 함수
void moveCursor(int y, int x) {
    printf("\033[%d;%dH", y, x);
}

// 윈도우창 그리기 함수
void drawConsoleWindow(int startX, int startY, int width, int height, const char* title) {
    int endX = startX + width - 1;
    int endY = startY + height - 1;

    printf("\033[43m");
    // 1. 테두리 그리기
    for (int x = startX; x <= endX; x++) {
        moveCursor(startY, x);   printf("-");  // 상단
        moveCursor(endY, x);     printf("-");  // 하단
    }

    for (int y = startY; y <= endY; y++) {
        moveCursor(y, startX);   printf("|");  // 좌측
        moveCursor(y, endX);     printf("|");  // 우측
    }

    // 2. 제목 표시줄 배경 (노란색)
    printf("\033[43m");  // 배경색: 노랑
    for (int x = startX + 1; x < endX; x++) {
        moveCursor(startY + 1, x);
        printf(" ");
    }

    // 3. 제목 텍스트
    moveCursor(startY + 1, startX + 2);
    printf("\033[1;30m%s\033[0m\033[43m", title); // 굵은 검정 글씨

    // 4. 닫기 버튼 "X" (오른쪽에서 3번째)
    moveCursor(startY + 1, endX - 3);
    printf("\033[41;97mX\033[43m"); // 빨간 배경 + 흰 글자, 뒤에 노랑으로 복원

    // 5. 내부 바탕 채우기 (노란색)
    for (int y = startY + 2; y < endY; y++) {
        for (int x = startX + 1; x < endX; x++) {
            moveCursor(y, x);
            printf(" ");
        }
    }

    // 스타일 초기화
    printf("\033[0m");
    moveCursor(endY + 1, 1);  // 커서 아래로 이동
}

int main() {
    drawConsoleWindow(10, 3, 50, 15, "나의 멋진 윈도우");
    return 0;
}