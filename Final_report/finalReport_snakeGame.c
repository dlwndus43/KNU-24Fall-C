#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <Windows.h>

int i, j, height = 20, width = 30;      // ���̿� ���� ����
int gameover, score;
int gameOverReason = 0; // 1: �� �浹, 2: ���� �浹
int x, y, fruitx, fruity, flag;
int tailX[100], tailY[100];
int nTail = 0;
int gamesPlayed = 0, highScore = 0;
int speed = 200;
char fruitSymbol = '*'; // ���� ���
char tailSymbol = 'o';  // �⺻ ���� ���

// �ȳ����� ��� �Լ�
void printInstructions() {
    system("cls"); // ȭ�� �ʱ�ȭ
    printf("====================================\n");
    printf("            Snake Game            \n");
    printf("====================================\n");
    printf("�� W, A, S, D Ű�� ���� �����ϼ���.\n");
    printf("�� ���Ÿ� ������ ������ �ö󰩴ϴ�.\n  �� *: 10�� #: 20��\n  �� #�� 5�� ��� ������ ��Ÿ���ϴ�!\n");
    printf("�� ���� ���̳� �ڽ��� ������ �浹�ϸ� ���� �����̴� �����ϼ���!\n");
    printf("�� ���� �ӵ��� ���Ÿ� �������� �������ϴ�!\n");
    printf("�� X Ű�� ������ ������ ����˴ϴ�.\n");
    printf("====================================\n");
    printf("������ �����Ϸ��� Enter Ű�� ��������...\n");
    getchar(); // Enter Ű �Է� ���
    system("cls"); // ���� ���� �� ȭ�� �ʱ�ȭ
}

// �ʱ� ����
void setup() {
    gameover = 0;
    gameOverReason = 0;

    x = height / 2;
    y = width / 2;

    fruitx = rand() % (height - 2) + 1;
    fruity = rand() % (width - 2) + 1;

    fruitSymbol = '*'; // �ʱ� ���� ���
    score = 0;
    nTail = 0;
    speed = 200;

    flag = 0; // ���� �ʱ�ȭ -> ���� ������ �ÿ� ���� �������� �ʰ� ó�� �ڸ��� ����.
}

// ������ �׸���
void draw() {
    COORD cursorPosition;       // COORD ����ü: �ܼ� Ŀ���� X,Y ��ǥ�� �����ϴ� ����ü
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);    // ȭ�� ��ü�� ������ �ʰ� �ʿ��� ��ġ�� ����.
    // ȭ�� �������� �ּ�ȭ�ϱ� ���� �ڵ�.
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1) {
                printf("\u2500");       // ������ ����ϴ� �����ڵ�
            }
            else if (j == 0 || j == width - 1) {
                printf("\u2502");       // �������� ����ϴ� �����ڵ�
            }
            else if (i == x && j == y) {
                printf("O"); // ���� �Ӹ�
            }
            else if (i == fruitx && j == fruity) {
                printf("%c", fruitSymbol); // ����
            }
            else {
                int isTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == i && tailY[k] == j) {
                        printf("%c", tailSymbol); // ���� ���
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
    printf("���� �ߴ��� ���Ͻø� X�� ��������\n");
}

// ����� �Է��� �޾� ���� �̵� ��� ����
void input() {
    if (_kbhit()) {
        switch (getch()) {
        case 'a':       // �������� �̵�
            if (flag != 3) flag = 1;
            break;
        case 's':       // �Ʒ��� �̵�
            if (flag != 4) flag = 2;
            break;
        case 'd':       // ���������� �̵�
            if (flag != 1) flag = 3;
            break;
        case 'w':       // ���� �̵�
            if (flag != 2) flag = 4;
            break;
        case 'x':       // ���� ����
            gameover = 1;
            break;
        }
    }
}

// ���� ����
void logic() {
    Sleep(speed);

    // ���� ��ġ ������Ʈ
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
        break; // flag�� 0�̸� �������� ����
    }

    // ���� ���� ����
    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1) {
        gameover = 1;       // ���ӿ���
        gameOverReason = 1; // ���� �浹�ؼ� ���� �����Ǵ� ���
    }

    // �� �ڽŰ� �浹
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameover = 1;       //���ӿ���
            gameOverReason = 2; // �Ӹ��� ������ �浹�ؼ� ���� �����Ǵ� ���
        }
    }

    // ���� �Ա�
    if (x == fruitx && y == fruity) {
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;

        // ���� ������ ���� ��� ����
        if (fruitSymbol == '#') { // # ������ ��
            score += 20;
            tailSymbol = '@'; // ���� #�� ȹ���ϸ� ���� ��� @�� ����
        }
        else { // * ������ ��
            score += 10;
            tailSymbol = 'o'; // ���� *�� ȹ���Ҷ��� ���� ��� o�� ����(���󺹱�)
        }

        nTail++;

        // �ӵ� ����
        if (nTail % 5 == 0 && speed > 50) {
            speed -= 10;
        }

        // ���� ��� ����: 5�� ����� �� #
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
        printInstructions(); // �ȳ����� ���
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
        if (gameOverReason == 1) {          // ���� ���� �浹�� ���� ������ ���
            printf("�̷�! ���� ���� ��ҽ��ϴ�...!\n");
        }
        else if (gameOverReason == 2) {     // ���� �Ӹ��� ������ ��� ���� ������ ���
            printf("�̷�! ���� �Ӹ��� ����(����)�� �浹�߽��ϴ�...!\n");
        }

        printf("\n������ �ٽ� �����Ͻðڽ��ϱ�? (1: Yes, 0: No): ");
        scanf_s("%d", &playAgain);          // ���� ������ �ǻ� Ȯ��

    } while (playAgain);

    printf("\n�� �÷��� Ƚ��: %d\n", gamesPlayed);          // �� �÷��� Ƚ�� ���
    printf("\n�ְ� ����: %d\n����ؿ�~~bb\n", highScore);           // �ְ����� ���

    return 0;
}
