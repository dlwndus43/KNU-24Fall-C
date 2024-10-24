#include <stdio.h>

// 3���� ���� ����ü ����
typedef struct {
	float x;
	float y;
	float z;
} Vector;

// ������ ���� ����ϴ� �Լ�
Vector plus(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

// ������ ���� ����ϴ� �Լ�
Vector minus(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

// ������ ������ ����ϴ� �Լ�
float in(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// ������ ������ ����ϴ� �Լ�
Vector out(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

int main() {

	// �� ���� ����
	Vector v1;
	Vector v2;

	int num;

	printf("ù��° ����(x y z): ");
	scanf_s("%f %f %f", &v1.x, &v1.y, &v1.z);
	printf("�ι�° ����(x y z): ");
	scanf_s("%f %f %f", &v2.x, &v2.y, &v2.z);

	printf("\n***************************************************\n\n");

	printf("1. ������ ��\n");
	printf("2. ������ ��\n");
	printf("3. ������ ����\n");
	printf("4. ������ ����\n");
	printf("5. ����\n");

	printf("\n***************************************************\n\n");

	printf("���� ����: ");
	scanf_s("%d", &num);

	printf("\n");

	Vector result_plus = plus(v1, v2);
	Vector result_minus = minus(v1, v2);
	float result_in = in(v1, v2);
	Vector result_out = out(v1, v2);

	switch (num)
	{
	case 1:
		printf("������ ��: %.2f, %.2f, %.2f\n", result_plus.x, result_plus.y, result_plus.z);
		break;

	case 2:
		printf("������ ��: %.2f %.2f, %.2f\n", result_minus.x, result_minus.y, result_minus.z);
		break;

	case 3:
		printf("������ ����: %.2f\n", result_in);
		break;

	case 4:
		printf(" ������ ����: %.2f, %.2f, %.2f\n", result_out.x, result_out.y, result_out.z);
		break;

	default:
		printf("\'����\'����\n");
		break;

	}

	return 0;
}