#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long int iterations = 1000000000;  // 10억 번 반복
    long int inside_circle = 0;
    double x, y, pi;
    int progress = 0;

    // 난수 생성기 초기화
    srand(time(NULL));

    printf("<Monte Carlo Algorithm>\n\n");

    for (long long int i = 1; i <= iterations; i++) {
        // (x, y) 점을 [0, 1) 구간에서 임의로 선택
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        // 점이 원 안에 있는지 확인
        if (x * x + y * y <= 1) {
            inside_circle++;
        }

        // 1%마다 진행 상황 및 원주율 출력
        if (i % (iterations / 100) == 0) {
            progress++;
            pi = (4.0 * inside_circle) / i;

            // 진행 상황 출력
            printf("%d%% 진행 >>> 원주율: %.6lf\n", progress, pi);

            // 진행 상황 출력
            
            for (int j = 0; j < progress; j++) {
                printf("■");  // 진행된 부분
            }
            for (int j = progress; j < 100; j++) {
                printf("□");  // 진행 남은 부분
            }
            printf("\n");
        }
    }

    // 최종 원주율 출력
    pi = (4.0 * inside_circle) / iterations;
    printf("원주율: %.6lf\n", pi);

    return 0;
}