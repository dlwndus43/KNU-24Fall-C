#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	int D;		// �Ǻ��� D, a, b, c�� �����̹Ƿ� �Ǻ��ĵ� ����.

	printf("<<������������� �ظ� ���ϴ� ���α׷�>>\n");
	printf("ax^2 + bx + c = ?\n");
	printf("��� a, b, c �Է�(������, �����ڴ� ���� ���): ");
	scanf_s("%d %d %d", &a, &b, &c);
	
	D = b * b - (4 * a * c);
	printf("D = %d\n", D);

	if (D > 0)
	{
		int x, y;
		x = (-b + (sqrt(b * b - 4 * a * c))) / 2 * a;
		y = (-b - (sqrt(b * b - 4 * a * c))) / 2 * a;

		printf("�ΰ��� ��: %d��(��) %d\n", x, y);
	}
	else if (D == 0)
	{
		int x;

		x = (-b + (sqrt(b * b - 4 * a * c))) / 2 * a;
		printf("�ϳ��� ��(�߱�): %d\n", x);
	}
	else
	{
		printf("���� ����(���).\n");
		return 0;
	}

	return 0;
}