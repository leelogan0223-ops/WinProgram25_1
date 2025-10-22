// Lecture08_Struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>       // time() 사용 (랜덤 시드)
#include <string.h>     // strstr() 사용 (로그 파일 읽기용)

struct Fish
{
	char* name;     // 이름
	char* talk;		// 물고기가 퀴즈를 냄(문제 + 보기(객관식))
	int answer;		// 답
	char* talk_O;	// 맞았을때 대사
	char* talk_X;	// 틀렸을때 대사		
};

// [과제 3] 콘솔 텍스트 색상을 변경하기 위한 핸들
HANDLE hConsole;

// [과제 3] 텍스트 색상 설정 함수
void set_text_color(int color)
{
	SetConsoleTextAttribute(hConsole, color);
}

// [과제 6] 게임 시작 시 log.txt를 읽어 기존 기록을 불러오는 함수
void load_game_stats(int* total_games, int* correct_games)
{
    FILE* fp = fopen("log.txt", "r"); // 읽기 모드로 파일 열기
    if (fp == NULL)
    {
        // 파일이 없으면 0으로 시작 (과제 5: 새로 생겨야 한다)
        *total_games = 0;
        *correct_games = 0;
        return;
    }

    char buffer[100]; // 로그 한 줄을 읽을 버퍼
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        (*total_games)++; // 한 줄 = 게임 1회

        // [과제 5] "O"가 포함되어 있는지 확인
        if (strstr(buffer, " / O") != NULL)
        {
            (*correct_games)++; // 정답 횟수 증가
        }
    }
    fclose(fp);

    if (*total_games > 0)
    {
        printf("--- 이전 기록을 불러왔습니다. (총 %d회, 정답 %d회) ---\n\n", *total_games, *correct_games);
    }
}

//물고기 5개 만들기 Fish 배열로.
int main()
{
    // [과제 3] 콘솔 핸들 가져오기
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 랜덤 함수 시드 초기화
    srand((unsigned int)time(NULL));

    // 물고기 5마리 정보 미리 만들기
    struct Fish fishes[5] = {
        { "맘스터치", "싱가포르에서는 '껌'을 씹는 것이 불법이다. (1. O  2. X)", 1, "정답! 의료용 껌을 제외하고 껌을 팔거나 씹는 건 불법이야. 길거리가 더러워진다고!", "땡! 진짜 불법이야! 도시를 깨끗하게 유지하려고 껌 판매와 반입을 금지했어." },
        { "버거킹", "호주 빅토리아 주에서는 자격증이 없는 일반인이 '전구'를 가는 것이 불법이다. (1. O  2. X)", 1, "정답! 안전 문제 때문에 자격증을 가진 전기 기술자만 교체할 수 있도록 법으로 정해 놨어.", "땡! 진짜 불법이야. 안전을 엄청 중요하게 생각하거든." },
        { "롯데리아", "미국 캘리포니아 주에서는 '수영장' 안에서 '자전거'를 타는 것이 불법이다. (1. O  2. X)", 2, "땡! 이건 유명한 '가짜 법'이야. 누가 수영장에서 자전거를 탄다고...", "정답! 이런 법은 없어. 그냥 '세상에 이런 멍청한 법이 ?'라고 놀리려고 만든 가짜 이야기야." },
        { "맥도날드", "태국에서는 '돈(지폐)'을 밟는 것이 불법이다.", 1, "정답! 돈에 존경받는 국왕의 얼굴이 그려져 있어서, 밟는 건 엄청난 무례이자 불법이야!", "땡! 불법 맞아! 지폐에 국왕 얼굴이 있어서, 밟으면 국왕 모독죄가 될 수 있어!" },
        { "파이브가이즈", "프로그래밍 언어 'Python'의 이름은 '비단뱀'에서 따왔다. (1. O  2. X)", 2, "아니야! 개발자가 좋아하던 코미디 쇼 '몬티 파이튼(Monty Python)'에서 따온 거야!", "맞아! 뱀 이름이 아니야. 개발자가 좋아하던 영국 코미디 쇼 이름이었어!" }
    };

    // [과제 6] 누적된 게임 횟수와 정답 횟수
    int total_games = 0;
    int correct_games = 0;

    // [과제 6] 프로그램 시작 시 기존 로그 읽어오기
    load_game_stats(&total_games, &correct_games);


    // 게임 루프 (계속 낚시를 시도)
    while (1)
    {
        // [과제 1] "찌를 던진다 (Y/N) >" 출력
        printf("찌를 던진다 (Y/N) > ");

        // [과제 2] 키 입력 받기 (y, n, f)
        char yn = _getch(); // 키를 누르자마자 입력받음
        printf("%c\n", yn); // 사용자 입력 확인

        // 'n' 또는 'N' 또는 'f' 또는 'F'를 누르면 게임 종료
        if (yn == 'n' || yn == 'N' || yn == 'f' || yn == 'F')
        {
            break;
        }

        // 'y' 또는 'Y'를 눌렀을 때 (게임 시작)
        if (yn == 'y' || yn == 'Y')
        {
            // [과제 6] 게임 횟수 1 증가
            total_games++;

            printf("미끼를 던졌습니다. 기다리는 중");
            fflush(stdout); // 출력 버퍼를 비워 '.'이 바로 보이게 함

            // [과제 3] 500ms마다 . 을 찍어서 총 5개의 점이 찍힌 후
            for (int i = 0; i < 5; i++)
            {
                Sleep(500);
                printf(".");
                fflush(stdout);
            }
            printf("\n");
            Sleep(500);

            // [과제 3] "입질이 왔다!!!!" 녹색으로 출력
            set_text_color(10); // 10: 밝은 녹색
            printf("입질이 왔다!!!!\n");
            set_text_color(7);  // 7: 원래 흰색(회색)으로 복구
            printf("\n");

            // [과제 4] 랜덤한 5개의 물고기중 하나가 튀어나와서 talk
            int index = rand() % 5;
            struct Fish caught_fish = fishes[index]; // 랜덤으로 잡힌 물고기

            printf("▶ [%s] (이)가 낚였다!\n\n", caught_fish.name);

            // 퀴즈 출제
            printf("--- %s의 퀴즈! ---\n", caught_fish.name);
            printf("Q. %s\n", caught_fish.talk);
            printf("당신의 대답은? (1 또는 2) : ");

            // 답 입력받기
            char answer_input = _getch();
            int user_answer = answer_input - '0'; // 문자 '1'을 숫자 1로 변경
            printf("%c\n\n", answer_input); // 사용자 입력 확인

            // [과제 5] 로그 파일을 append(추가) 모드로 연다.
            // 파일이 없으면 자동 생성됨.
            FILE* log_fp = fopen("log.txt", "a");
            if (log_fp == NULL)
            {
                printf("오류: log.txt 파일을 열 수 없습니다.\n");
            }

            // [과제 5] 퀴즈를 풀어서
            if (user_answer == caught_fish.answer)
            {
                // 맞추면 talkO에 해당하는 대사 출력
                printf("▶ %s\n", caught_fish.talk_O);
                if (log_fp != NULL)
                {
                    // 로그에 [물고기 이름 / O] 저장
                    fprintf(log_fp, "%s / O\n", caught_fish.name);
                }
                correct_games++; // 정답 횟수 증가
            }
            else
            {
                // 틀리면 talkX 대사 출력
                printf("▶ %s\n", caught_fish.talk_X);
                if (log_fp != NULL)
                {
                    // 로그에 [물고기 이름 / X] 저장
                    fprintf(log_fp, "%s / X\n", caught_fish.name);
                }
            }

            if (log_fp != NULL)
            {
                fclose(log_fp); // 로그 파일 닫기
            }

            // [과제 6] 게임을 끝낼때마다 "n번째 게임입니다!"
            printf("\n%d번째 게임입니다!!\n", total_games);
            // 플레이 횟수 및 정답률 출력
            printf("정답률 %d/%d\n", correct_games, total_games);

            printf("\n====================================\n\n");
        }
        else
        {
            // [과제 2] (y,n,f)키 말고 예외처리
            set_text_color(12); // 12: 밝은 빨간색
            printf("잘못된 키입니다. (Y / N / F 키만 입력하세요.)\n\n");
            set_text_color(7);
        }
    }

    printf("\n낚시를 종료합니다. 이용해주셔서 감사합니다.\n");
    return 0;

}


//(1반) 과제물
//
// 1. "찌를 던진다 (Y/N) >"  출력
// 키 입력을 받는다. (y,n키) 말고 예외도 처리하도록

// 2. 500ms마다 .을 찍어서 총 5개의 점이 찍힌 후에 "입질이 왔다!!!!" 녹색으로 출력

// 3. 랜덤하게 5개의 물고기중 하나가 튀어나와서 말을건다. talk에 있는 말을. 여기엔 퀴즈를 집어넣고 answer에 답을 넣어둔다.

// 4. 퀴즈를 풀어서 맞추면 talkO에 해당하는 대사를 출력시키고, 틀리면 talkX대사를 출력시킨후 

// 5. 로그 파일을 log.txt라고 만들고 물고기 이름과, 퀴즈 맞췄는지여부를 저장하고 프로그램 종료시킨다.
//    "세자르\n"
//    "X\n"
//    **특징 : 계속 누적돼야한다.
//             log.txt는 지워도, 프로그램을 실행시키면 새로 생겨야한다.
//

// 6. 게임을 켤때마다 "n번째 게임입니다!" 하고 플레이 횟수 및 정답률을 출력한다.
//ex>     7번째 게임입니다!!
//        정답률 4/7