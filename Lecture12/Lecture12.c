/*
 * 7-segment 숫자 표현 예제
 * - drawLine 함수로 선분을 그려 7-segment 스타일로 숫자 표시
 * - GLFW로 윈도우 및 OpenGL 컨텍스트 관리
 */

#pragma comment(lib, "opengl32.lib")   // OpenGL 1.1 라이브러리 링크

#include <GLFW/glfw3.h>

 // 숫자별 세그먼트 비트마스크 (a b c d e f g 순서, 1=ON, 0=OFF)
 // 세그먼트 구성 예시: 
 //   — a
 //  |   |
 //  f   b
 //   — g
 //  |   |
 //  e   c
 //   — d
 //
 // 0 → a,b,c,d,e,f (g 꺼짐)     0b1111110
 // 1 →    b,c                  0b0110000
 // 2 → a,b,  d,e,  g           0b1101101
 // 3 → a,b,c,d,   g            0b1111001
 // 4 →   b,c,   f,g            0b0110011
 // 5 → a,  c,d,  f,g           0b1011011
 // 6 → a,  c,d,e,f,g           0b1011111
 // 7 → a,b,c                   0b1110000
 // 8 → a,b,c,d,e,f,g           0b1111111
 // 9 → a,b,c,d,  f,g           0b1111011

 // 화면에 직선을 그리는 유틸 함수
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);    // 시작점
    glVertex2f(x2, y2);    // 끝점
    glEnd();
}

int main(void) {
    // 1. GLFW 초기화: 실패 시 프로그램 종료
    if (!glfwInit()) {
        return -1;
    }

    // 2. 윈도우 생성: 크기800×600, 제목 "Cross in Center"
    GLFWwindow* window = glfwCreateWindow(
        800, 600,
        "Cross in Center",
        NULL, NULL
    );
    if (!window) {
        // 윈도우 생성 실패 시 GLFW 정리 후 종료
        glfwTerminate();
        return -1;
    }

    // 3. OpenGL 컨텍스트 바인딩
    glfwMakeContextCurrent(window);

    // 4. 2D 직교 투영 설정: 좌표계를 −1…1 범위로 매핑
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // 5. 메인 루프: 창 닫힐 때까지 반복
    while (!glfwWindowShouldClose(window)) {
        // 5-1. 화면 초기화 (색상 버퍼만)
        glClear(GL_COLOR_BUFFER_BIT);

        // 5-2. 중앙 십자(+) 모양 그리기
        //   ┌───┐
        //   │   │    윗부분
        //   └───┘
        //   │   │    중간 가로
        //   └───┘    아래부분

        // 좌상 수직선: 윗칸 왼쪽 세그먼트
        drawLine(-0.25f, 0.5f, -0.25f, 0.0f);
        // 상단 가로선: 윗칸 가운데 세그먼트
        drawLine(-0.25f, 0.5f, 0.25f, 0.5f);
        // 우상 수직선: 윗칸 오른쪽 세그먼트
        drawLine(0.25f, 0.5f, 0.25f, 0.0f);

        // 중간 가로선: 중앙 세그먼트
        drawLine(-0.25f, 0.0f, 0.25f, 0.0f);

        // 좌하 수직선: 아랫칸 왼쪽 세그먼트
        drawLine(-0.25f, 0.0f, -0.25f, -0.5f);
        // 하단 가로선: 아랫칸 가운데 세그먼트
        drawLine(-0.25f, -0.5f, 0.25f, -0.5f);
        // 우하 수직선: 아랫칸 오른쪽 세그먼트
        drawLine(0.25f, 0.0f, 0.25f, -0.5f);

        // 5-3. 더블 버퍼 교체: 부드러운 화면 전환
        glfwSwapBuffers(window);
        // 5-4. 이벤트 처리: 키 입력, 창 이벤트 등
        glfwPollEvents();
    }

    // 6. GLFW 종료: 생성된 자원 모두 해제
    glfwTerminate();
    return 0;
}