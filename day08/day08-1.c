#include <stdio.h>
#include <string.h>

int main() {

    char str[100];
    char* p_start;
    char* p_end;

    // ���ڿ� �Է� �ޱ� (���⵵ ����)
    printf("���ڿ� �Է�: ");
    scanf_s("%s", &str, sizeof(str));

    // ���ڿ��� ���� ���
    int len = strlen(str);

    // ������ �ʱ�ȭ
    p_start = str;         // ���ڿ��� ù ����
    p_end = str + len - 1; // ���ڿ��� ������ ����

    // �� ���� �����͸� ����ؼ� ���ڿ��� ������
    while (p_start < p_end) {
        // �հ� �� ���ڸ� ��ȯ
        char temp = *p_start;
        *p_start = *p_end;
        *p_end = temp;

        // ������ �̵�
        p_start++;
        p_end--;
    }

    // ������ ���ڿ� ���
    printf("������ ���ڿ�: %s\n", str);

    return 0;
}