#include <stdio.h>

// 3차원 벡터 구조체 정의
typedef struct {
	float x;
	float y;
	float z;
} Vector;

// 벡터의 합을 계산하는 함수
Vector plus(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

// 벡터의 차를 계산하는 함수
Vector minus(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

// 벡터의 내적을 계산하는 함수
float in(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 벡터의 외적을 계산하는 함수
Vector out(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

int main() {

	// 두 벡터 정의
	Vector v1;
	Vector v2;

	int num;

	printf("첫번째 벡터(x y z): ");
	scanf_s("%f %f %f", &v1.x, &v1.y, &v1.z);
	printf("두번째 벡터(x y z): ");
	scanf_s("%f %f %f", &v2.x, &v2.y, &v2.z);

	printf("\n***************************************************\n\n");

	printf("1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 외적\n");
	printf("4. 벡터의 내적\n");
	printf("5. 종료\n");

	printf("\n***************************************************\n\n");

	printf("연산 선택: ");
	scanf_s("%d", &num);

	printf("\n");

	Vector result_plus = plus(v1, v2);
	Vector result_minus = minus(v1, v2);
	float result_in = in(v1, v2);
	Vector result_out = out(v1, v2);

	switch (num)
	{
	case 1:
		printf("벡터의 합: %.2f, %.2f, %.2f\n", result_plus.x, result_plus.y, result_plus.z);
		break;

	case 2:
		printf("벡터의 차: %.2f %.2f, %.2f\n", result_minus.x, result_minus.y, result_minus.z);
		break;

	case 3:
		printf("벡터의 내적: %.2f\n", result_in);
		break;

	case 4:
		printf(" 벡터의 외적: %.2f, %.2f, %.2f\n", result_out.x, result_out.y, result_out.z);
		break;

	default:
		printf("\'종료\'선택\n");
		break;

	}

	return 0;
}