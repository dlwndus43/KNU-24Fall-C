#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 배열을 랜덤 값으로 초기화 (1~20 범위)
void fillRandom(int array[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1;
        }
    }
}

// 배열을 출력
void printArray(int array[SIZE][SIZE]) {
    printf("배열 출력:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

// 포인터를 이용하여 배열 이동
void movePointer(void* array) {
    int(*arr)[SIZE] = (int*)array;  // 2차원 배열을 가리키는 포인터
    int x = 0, y = 0;          // 시작 위치 (0, 0)
    int moves = arr[x][y];      // 처음 값

    printf("현재 위치: (%d, %d), 배열의 값: %d\n", x, y, moves);

    while (1) {
        // 이동할 새로운 위치 계산
        int new_x = x + (moves / SIZE);  // x축 이동
        int new_y = y + (moves % SIZE);  // y축 이동

        // 경계를 벗어났을 때 처리
        if (new_y >= SIZE) {  // 열을 벗어났을 경우
            new_x += new_y / SIZE;  // 다음 행으로 이동
            new_y = new_y % SIZE;   // 열을 다시 0부터 시작
        }

        // 배열 범위를 벗어나면 종료
        if (new_x >= SIZE) {
            printf("더 이상 이동할 수 없습니다.\n");
            printf("종료 위치: (%d, %d), 배열의 값: %d\n", x, y, arr[x][y]);
            break;
        }

        // 현재 위치 갱신
        x = new_x;
        y = new_y;
        moves = arr[x][y];  // 새로운 위치의 값만큼 이동

        printf("현재 위치: (%d, %d), 배열의 값: %d\n", x, y, moves);
    }
}

int main() {
    int array[SIZE][SIZE];

    fillRandom(array);   // 배열 랜덤 초기화
    printArray(array);   // 배열 출력
    movePointer(array);  // 포인터를 이용한 이동

    return 0;
}