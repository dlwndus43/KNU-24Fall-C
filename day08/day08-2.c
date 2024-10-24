#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// �迭�� ���� ������ �ʱ�ȭ (1~20 ����)
void fillRandom(int array[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1;
        }
    }
}

// �迭�� ���
void printArray(int array[SIZE][SIZE]) {
    printf("�迭 ���:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

// �����͸� �̿��Ͽ� �迭 �̵�
void movePointer(void* array) {
    int(*arr)[SIZE] = (int*)array;  // 2���� �迭�� ����Ű�� ������
    int x = 0, y = 0;          // ���� ��ġ (0, 0)
    int moves = arr[x][y];      // ó�� ��

    printf("���� ��ġ: (%d, %d), �迭�� ��: %d\n", x, y, moves);

    while (1) {
        // �̵��� ���ο� ��ġ ���
        int new_x = x + (moves / SIZE);  // x�� �̵�
        int new_y = y + (moves % SIZE);  // y�� �̵�

        // ��踦 ����� �� ó��
        if (new_y >= SIZE) {  // ���� ����� ���
            new_x += new_y / SIZE;  // ���� ������ �̵�
            new_y = new_y % SIZE;   // ���� �ٽ� 0���� ����
        }

        // �迭 ������ ����� ����
        if (new_x >= SIZE) {
            printf("�� �̻� �̵��� �� �����ϴ�.\n");
            printf("���� ��ġ: (%d, %d), �迭�� ��: %d\n", x, y, arr[x][y]);
            break;
        }

        // ���� ��ġ ����
        x = new_x;
        y = new_y;
        moves = arr[x][y];  // ���ο� ��ġ�� ����ŭ �̵�

        printf("���� ��ġ: (%d, %d), �迭�� ��: %d\n", x, y, moves);
    }
}

int main() {
    int array[SIZE][SIZE];

    fillRandom(array);   // �迭 ���� �ʱ�ȭ
    printArray(array);   // �迭 ���
    movePointer(array);  // �����͸� �̿��� �̵�

    return 0;
}