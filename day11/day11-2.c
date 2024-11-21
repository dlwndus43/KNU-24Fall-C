#include <stdio.h>
#include <math.h>

// 함수 f(x) 정의
double f(double x) {
    return -log10(1.0 / x) + sin(x);
}

// 구분구적법 함수
double trapezoidal_integral(double (*func)(double), int a, int b, int n) {
    double h = (double)(b - a) / n; // 구간의 폭
    double integral = 0.0;

    // 첫 번째와 마지막 값을 반영
    integral += func(a) / 2.0;
    integral += func(b) / 2.0;

    // 중간 구간의 값 합산
    for (int i = 1; i < n; i++) {
        integral += func((double)a + i * h);
    }

    return integral * h;
}

int main() {
    int a = 10;     // 적분 시작 값
    int b = 30;     // 적분 끝 값
    int n = 2;       // 초기 구간 수

    printf("적분할 시작 값 a: %d\n", a);
    printf("적분할 끝 값 b: %d\n\n", b);
    printf("구분구적법을 이용한 적분 결과:\n");

    // 구간을 두 배로 늘리며 적분값 계산
    for (int i = 1; i <= 20; i++) { // 최대 20회 반복
        double result = trapezoidal_integral(f, a, b, n);
        printf("구간: %d,\t 적분 결과: %.8f\n", n, result);
        n *= 2;     // 구간 수를 두 배로 증가
    }

    return 0;
}