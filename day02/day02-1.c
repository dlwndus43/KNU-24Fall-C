#include<stdio.h>

int main() {

	double num1, num2, result;
	int type;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1. ���ϱ� 2. ���� 3. ���ϱ� 4. ������\n");
	printf("��� : ");
	scanf_s("%d", &type);

	printf("ù��° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);

	scanf_s("%lf", &num2);

	if (type == 1) {
		result = num1 + num2;
		printf("%f + %f = %f", num1, num2, result );
	}
	else if (type == 2) {
		result = num1 - num2;
		printf("%f - %f = %f", num1, num2, result);
	}
	else if (type == 3) {
		result = num1 * num2;
		printf("%f * %f = %f", num1, num2, result);
	}
	else if (type == 4) {
		result = num1 / num2;
		printf("%f / %f = %f", num1, num2, result);
	}
	else {
		printf("�߸��Է��ϼ̽��ϴ�.");
	}

	return 0;
}