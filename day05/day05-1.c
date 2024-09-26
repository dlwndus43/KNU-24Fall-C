#include<stdio.h>
#include<stdlib.h>

int main() {

	int N;						// 사용자가 입력할 학생 수
	int* stud_num;			// 학번
	char** name;			// 이름 
	int* score;					// 점수

	// 점수가 0~100점이라는 가정하에 변수를 0과 100으로 초기화.
	int min_jum = 100;	// 최소값
	int max_jum = 0;		// 최대값

	// 0이 가장 중립적인 숫자.
	int sum = 0;				// 합계
	float avg = 0.0;			// 평균
	
	// 학생 수 입력(scanf_s() --> N)
	printf("학생 수를 입력하세요: ___\b\b");
	scanf_s("%d", &N);

	// 동적 메모리 할당(malloc())
	stud_num = (int*)malloc(N  * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));

	for (int i = 0; i < N; i++) 
	{
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	// 학번, 이름, 점수 입력 받기(scanf_s() --> stud_num / name / score)
	for (int i = 0; i < N; i++)
	{
		printf("학번 : ");
		scanf_s("%d", &stud_num[i]);

		printf("이름 : ");
		scanf_s("%s", name[i], 100);

		printf("점수 : ");
		scanf_s("%d", &score[i]);
	}

	// 띄우기
	printf("\n");

	// 학번, 이름, 점수 출력
	for (int i = 0; i < N; i++)
	{
		printf("학번: %d | 이름: %s | 점수 : %d\n\n", stud_num[i], name[i], score[i]);
	}

	// 점수계산(합계, 최대값, 최소값)
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

	//평균 계산
	avg = (float)sum / N;

	// 최소값, 최대값, 평균 출력
	printf("최대값 : %d\n", max_jum);
	printf("최소값 : %d\n", min_jum);
	printf("평균 : %.2f\n", avg);

	// 동적메모리 해제
	free(stud_num);
	free(score);
	free(name);

	return 0;
}