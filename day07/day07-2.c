#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long int iterations = 1000000000;  // 10�� �� �ݺ�
    long int inside_circle = 0;
    double x, y, pi;
    int progress = 0;

    // ���� ������ �ʱ�ȭ
    srand(time(NULL));

    printf("<Monte Carlo Algorithm>\n\n");

    for (long long int i = 1; i <= iterations; i++) {
        // (x, y) ���� [0, 1) �������� ���Ƿ� ����
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        // ���� �� �ȿ� �ִ��� Ȯ��
        if (x * x + y * y <= 1) {
            inside_circle++;
        }

        // 1%���� ���� ��Ȳ �� ������ ���
        if (i % (iterations / 100) == 0) {
            progress++;
            pi = (4.0 * inside_circle) / i;

            // ���� ��Ȳ ���
            printf("%d%% ���� >>> ������: %.6lf\n", progress, pi);

            // ���� ��Ȳ ���
            
            for (int j = 0; j < progress; j++) {
                printf("��");  // ����� �κ�
            }
            for (int j = progress; j < 100; j++) {
                printf("��");  // ���� ���� �κ�
            }
            printf("\n");
        }
    }

    // ���� ������ ���
    pi = (4.0 * inside_circle) / iterations;
    printf("������: %.6lf\n", pi);

    return 0;
}