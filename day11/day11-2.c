#include <stdio.h>
#include <math.h>

// �Լ� f(x) ����
double f(double x) {
    return -log10(1.0 / x) + sin(x);
}

// ���б����� �Լ�
double trapezoidal_integral(double (*func)(double), int a, int b, int n) {
    double h = (double)(b - a) / n; // ������ ��
    double integral = 0.0;

    // ù ��°�� ������ ���� �ݿ�
    integral += func(a) / 2.0;
    integral += func(b) / 2.0;

    // �߰� ������ �� �ջ�
    for (int i = 1; i < n; i++) {
        integral += func((double)a + i * h);
    }

    return integral * h;
}

int main() {
    int a = 10;     // ���� ���� ��
    int b = 30;     // ���� �� ��
    int n = 2;       // �ʱ� ���� ��

    printf("������ ���� �� a: %d\n", a);
    printf("������ �� �� b: %d\n\n", b);
    printf("���б������� �̿��� ���� ���:\n");

    // ������ �� ��� �ø��� ���а� ���
    for (int i = 1; i <= 20; i++) { // �ִ� 20ȸ �ݺ�
        double result = trapezoidal_integral(f, a, b, n);
        printf("����: %d,\t ���� ���: %.8f\n", n, result);
        n *= 2;     // ���� ���� �� ��� ����
    }

    return 0;
}