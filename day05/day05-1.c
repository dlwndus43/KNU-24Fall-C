#include<stdio.h>
#include<stdlib.h>

int main() {

	int N;						// ����ڰ� �Է��� �л� ��
	int* stud_num;			// �й�
	char** name;			// �̸� 
	int* score;					// ����

	// ������ 0~100���̶�� �����Ͽ� ������ 0�� 100���� �ʱ�ȭ.
	int min_jum = 100;	// �ּҰ�
	int max_jum = 0;		// �ִ밪

	// 0�� ���� �߸����� ����.
	int sum = 0;				// �հ�
	float avg = 0.0;			// ���
	
	// �л� �� �Է�(scanf_s() --> N)
	printf("�л� ���� �Է��ϼ���: ___\b\b");
	scanf_s("%d", &N);

	// ���� �޸� �Ҵ�(malloc())
	stud_num = (int*)malloc(N  * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));

	for (int i = 0; i < N; i++) 
	{
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	// �й�, �̸�, ���� �Է� �ޱ�(scanf_s() --> stud_num / name / score)
	for (int i = 0; i < N; i++)
	{
		printf("�й� : ");
		scanf_s("%d", &stud_num[i]);

		printf("�̸� : ");
		scanf_s("%s", name[i], 100);

		printf("���� : ");
		scanf_s("%d", &score[i]);
	}

	// ����
	printf("\n");

	// �й�, �̸�, ���� ���
	for (int i = 0; i < N; i++)
	{
		printf("�й�: %d | �̸�: %s | ���� : %d\n\n", stud_num[i], name[i], score[i]);
	}

	// �������(�հ�, �ִ밪, �ּҰ�)
	for (int i = 0; i < N; i++) 
	{
		sum += score[i];
		if (score[i] > max_jum)
		{
			max_jum = score[i];
		}
		if (score[i] < min_jum)
		{
			min_jum = score[i];
		}
	}

	//��� ���
	avg = (float)sum / N;

	// �ּҰ�, �ִ밪, ��� ���
	printf("�ִ밪 : %d\n", max_jum);
	printf("�ּҰ� : %d\n", min_jum);
	printf("��� : %.2f\n", avg);

	// �����޸� ����
	free(stud_num);
	free(score);
	free(name);

	return 0;
}