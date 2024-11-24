#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	int D;		// 판별식 D, a, b, c가 정수이므로 판별식도 정수.

	printf("<<이차방식정식의 해를 구하는 프로그램>>\n");
	printf("ax^2 + bx + c = ?\n");
	printf("계수 a, b, c 입력(정수만, 구분자는 띄어쓰기 사용): ");
	scanf_s("%d %d %d", &a, &b, &c);
	
	D = b * b - (4 * a * c);
	printf("D = %d\n", D);

	if (D > 0)			// 두 개의 실근
	{
		double x, y;
		x = (-b + sqrt(D)) / (2.0 * a);
		y = (-b - sqrt(D)) / (2.0 * a);

		printf("두개의 근: %d과(와) %.2f\n", x, y);
	}
	else if (D == 0)			// 중근
	{
		double x;
		x = -b / (2.0 * a);
		printf("하나의 근(중근): %.2f\n", x);
	}
	else			// 허근
	{
		printf("근이 없음(허근).\n");
		return 0;
	}

	return 0;
}