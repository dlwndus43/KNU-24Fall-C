#include<stdio.h>

int is_prime_number(int num)
{
	for (int a = 2; a < num; a++)
	{
		if (num % a == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main() {

	int input;
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &input);

	int result = is_prime_number(input);
	printf("%d\n", result);
}