#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <Windows.h>

int i, j, height = 20, width = 30;      // 높이와 넒이 설정
int gameover, score;
int gameOverReason = 0; // 1: 벽 충돌, 2: 꼬리 충돌
int x, y, fruitx, fruity, flag;
int tailX[100], tailY[100];
int nTail = 0;
int gamesPlayed = 0, highScore = 0;
int speed = 200;
char fruitSymbol = '*'; // 열매 모양
char tailSymbol = 'o';  // 기본 꼬리 모양

// 안내사항 출력 함수
void printInstructions() {
    system("cls"); // 화면 초기화
    printf("====================================\n");
    printf("            Snake Game            \n");
    printf("====================================\n");
    printf("☞ W, A, S, D 키로 뱀을 조작하세요.\n");
    printf("☞ 열매를 먹으면 점수가 올라갑니다.\n  → *: 10점 #: 20점\n  → #은 5의 배수 단위로 나타납니다!\n");
    printf("☞ 뱀이 벽이나 자신의 꼬리와 충돌하면 게임 오버이니 주의하세요!\n");
    printf("☞ 게임 속도는 열매를 먹을수록 빨라집니다!\n");
    printf("☞ X 키를 누르면 게임이 종료됩니다.\n");
    printf("====================================\n");
    printf("게임을 시작하려면 Enter 키를 누르세요...\n");
    getchar(); // Enter 키 입력 대기
    system("cls"); // 게임 시작 전 화면 초기화
}

// 초기 설정
void setup() {
    gameover = 0;
    gameOverReason = 0;

    x = height / 2;
    y = width / 2;

    fruitx = rand() % (height - 2) + 1;
    fruity = rand() % (width - 2) + 1;

    fruitSymbol = '*'; // 초기 열매 모양
    score = 0;
    nTail = 0;
    speed = 200;

    flag = 0; // 방향 초기화 -> 게임 재진행 시에 뱀이 움직이지 않고 처음 자리에 고정.
}

// 게임판 그리기
void draw() {
    COORD cursorPosition;       // COORD 구조체: 콘솔 커서의 X,Y 좌표를 정의하는 구조체
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);    // 화면 전체를 지우지 않고 필요한 위치만 갱신.
                                                                                  // 화면 깜빡임을 최소화하기 위한 코드.
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1) {
                printf("\u2500");       // 수평선을 출력하는 유니코드
            }
            else if (j == 0 || j == width - 1) {
                printf("\u2502");       // 수직선을 출력하는 유니코드
            }
            else if (i == x && j == y) {
                printf("O"); // 뱀의 머리
            }
            else if (i == fruitx && j == fruity) {
                printf("%c", fruitSymbol); // 열매
            }
            else {
                int isTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == i && tailY[k] == j) {
                        printf("%c", tailSymbol); // 꼬리 모양
                        isTail = 1;
                        break;
                    }
                }
                if (!isTail)
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
    printf("게임 중단을 원하시면 X를 누르세요\n");
}

// 사용자 입력을 받아 뱀의 이동 경로 결정
void input() {
    if (_kbhit()) {
        switch (getch()) {
        case 'a':       // 왼쪽으로 이동
            if (flag != 3) flag = 1;
            break;
        case 's':       // 아래로 이동
            if (flag != 4) flag = 2;
            break;
        case 'd':       // 오른쪽으로 이동
            if (flag != 1) flag = 3;
            break;
        case 'w':       // 위로 이동
            if (flag != 2) flag = 4;
            break;
        case 'x':       // 게임 종료
            gameover = 1;
            break;
        }
    }
}

// 게임 로직
void logic() {
    Sleep(speed);

    // 꼬리 위치 업데이트
    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break; // flag가 0이면 움직이지 않음
    }

    // 게임 종료 조건
    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1) {
        gameover = 1;       // 게임오버
        gameOverReason = 1; // 벽과 충돌해서 게임 오버되는 경우
    }

    // 뱀 자신과 충돌
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameover = 1;       //게임오버
            gameOverReason = 2; // 머리와 꼬리가 충돌해서 게임 오버되는 경우
        }
    }

    // 열매 먹기
    if (x == fruitx && y == fruity) {
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;

        // 열매 점수와 꼬리 모양 설정
        if (fruitSymbol == '#') { // # 열매일 때
            score += 20;
            tailSymbol = '@'; // 열매 #을 획득하면 꼬리 모양 @로 변경
        }
        else { // * 열매일 때
            score += 10;
            tailSymbol = 'o'; // 열매 *을 획득할때는 꼬리 모양 o로 설정(원상복귀)
        }

        nTail++;

        // 속도 증가
        if (nTail % 5 == 0 && speed > 50) {
            speed -= 10;
        }

        // 열매 모양 변경: 5의 배수일 때 #
        if (nTail % 5 == 0) {
            fruitSymbol = '#';
        }
        else {
            fruitSymbol = '*';
        }
    }
}

int main() {
    int playAgain;

    do {
        printInstructions(); // 안내사항 출력
        setup();
        gamesPlayed++;

        while (!gameover) {
            draw();
            input();
            logic();
        }

        if (score > highScore) {
            highScore = score;
        }

        printf("\n<<Game Over!>>\n");
        if (gameOverReason == 1) {          // 뱀이 벽에 충돌해 게임 오버된 경우
            printf("이런! 뱀이 벽에 닿았습니다...!\n");
        }
        else if (gameOverReason == 2) {     // 뱀의 머리와 꼬리가 닿아 게임 오버된 경우
            printf("이런! 뱀의 머리가 몸통(꼬리)과 충돌했습니다...!\n");
        }

        printf("\n게임을 다시 시작하시겠습니까? (1: Yes, 0: No): ");
        scanf_s("%d", &playAgain);          // 게임 재진행 의사 확인

    } while (playAgain);

    printf("\n총 플레이 횟수: %d\n", gamesPlayed);          // 총 플레이 횟수 출력
    printf("\n최고 점수: %d\n대단해요~~bb\n", highScore);           // 최고점수 출력

    return 0;
}
