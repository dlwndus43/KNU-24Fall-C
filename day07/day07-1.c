#include <stdio.h>

int main() {

    int height = 5;

    // �Ƕ�̵� ���
    for (int i = 1; i <= height; i++) {
        // �Ƕ�̵� �¿� ������ ���߱� ���� ���� ���
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        // �Ƕ�̵� ���·� * ����ϱ�
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }

        // �� �� ������ �� �ٲٱ�
        printf("\n");
    }

    return 0;
}
