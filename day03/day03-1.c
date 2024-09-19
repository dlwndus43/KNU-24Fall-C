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
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &input);

	int result = is_prime_number(input);
	printf("%d\n", result);
}