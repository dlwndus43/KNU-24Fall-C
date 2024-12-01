#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int solution(int* topping, int toppingSize) {
    int leftCount[MAX] = { 0 };  // ���� �������� �� ������ ����
    int rightCount[MAX] = { 0 }; // ������ �������� �� ������ ����
    int leftUnique = 0, rightUnique = 0;
    int result = 0;

    // ������ ������ ���� �� �ʱ�ȭ
    for (int i = 0; i < toppingSize; i++) {
        if (rightCount[topping[i]] == 0) {
            rightUnique++;
        }
        rightCount[topping[i]]++;
    }

    // ����ũ�� �ڸ� ��ġ�� �̵��ϸ� �˻�
    for (int i = 0; i < toppingSize - 1; i++) {
        // ���� ������ �������� �̵�
        if (leftCount[topping[i]] == 0) {
            leftUnique++;
        }
        leftCount[topping[i]]++;

        // ���� ������ �����ʿ��� ����
        rightCount[topping[i]]--;
        if (rightCount[topping[i]] == 0) {
            rightUnique--;
        }

        // ���ʰ� ������ ������ ���� ���� ���� ������ ��� ����
        if (leftUnique == rightUnique) {
            result++;
        }
    }

    return result;
}

int main() {
    int topping[] = { 4, 2, 1, 3, 4, 2, 1, 3, 4 };
    int toppingSize = sizeof(topping) / sizeof(topping[0]);

    int result = solution(topping, toppingSize);
    printf("Result: %d\n", result);

    return 0;
}