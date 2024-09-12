#include<stdio.h>

int main() {

	double num1, num2, result;
	int type;

	printf("원하는 기능을 입력하시오.\n");
	printf("1. 더하기 2. 빼기 3. 곱하기 4. 나누기\n");
	printf("기능 : ");
	scanf_s("%d", &type);

	printf("첫번째 숫자를 입력하세요 : ");
	scanf_s("%lf", &num1);

	printf("두번째 숫자를 입력하세요 : ");
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
		printf("잘못입력하셨습니다.");
	}

	return 0;
}