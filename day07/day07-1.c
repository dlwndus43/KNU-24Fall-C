#include <stdio.h>

int main() {

    int height = 5;

    // 피라미드 출력
    for (int i = 1; i <= height; i++) {
        // 피라미드 좌우 정렬을 맞추기 위한 공백 출력
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        // 피라미드 형태로 * 출력하기
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }

        // 한 줄 끝나면 줄 바꾸기
        printf("\n");
    }

    return 0;
}
