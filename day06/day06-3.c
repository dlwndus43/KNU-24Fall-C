#include<stdio.h>

int main()
{
	FILE* fp = NULL;
	fopen_s(&fp, "data.txt", "rt");

	int n1, n2, n3;
	while (fscanf_s(fp, "%d %d %d", &n1, &n2, &n3) != EOF)		//EOF: 파일의 끝을 나타냄.
	{
		printf("n1 = %d, n2 = %d, n3 = %d\n", n1, n2, n3);
	}

	fclose(fp);

	return 0;
}