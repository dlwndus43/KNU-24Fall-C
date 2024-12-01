#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int solution(int* topping, int toppingSize) {
    int leftCount[MAX] = { 0 };  // 왼쪽 조각에서 각 토핑의 개수
    int rightCount[MAX] = { 0 }; // 오른쪽 조각에서 각 토핑의 개수
    int leftUnique = 0, rightUnique = 0;
    int result = 0;

    // 오른쪽 조각의 토핑 수 초기화
    for (int i = 0; i < toppingSize; i++) {
        if (rightCount[topping[i]] == 0) {
            rightUnique++;
        }
        rightCount[topping[i]]++;
    }

    // 케이크를 자를 위치를 이동하며 검사
    for (int i = 0; i < toppingSize - 1; i++) {
        // 현재 토핑을 왼쪽으로 이동
        if (leftCount[topping[i]] == 0) {
            leftUnique++;
        }
        leftCount[topping[i]]++;

        // 현재 토핑을 오른쪽에서 제거
        rightCount[topping[i]]--;
        if (rightCount[topping[i]] == 0) {
            rightUnique--;
        }

        // 왼쪽과 오른쪽 조각의 고유 토핑 수가 같으면 결과 증가
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