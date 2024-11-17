#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX (50)

struct NODE
{
	char name[NAME_MAX];
	int score;
	struct NODE* link;
};

struct NODE* head;

struct NODE* create_node(char* name, int score)
{
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, NAME_MAX, name);
	new_node->score = score;
	new_node->link = NULL;

	return new_node;
}

struct NODE* last_node()
{
	struct NODE* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

void insert_node_last(struct NODE* new_node)
{
	struct NODE* last = last_node();			// 마지막 노드 찾기
	last->link = new_node;				// 마지막 노드의 link를 새 노드로 연결
}

void print_nodes()
{
	struct NODE* cur = head->link;
	printf("----------------------------\n");
	while (cur != NULL) {
		printf("%s: %d\n", cur->name, cur->score);
		cur = cur->link;
	}
	printf("----------------------------\n");
}

int delete_node(char* name)
{
	struct NODE* prev = head;			// 이전 노드
	struct NODE* cur = head->link;		// 현재 노드
	while (cur != NULL) {
		if (strcmp(name, cur->name) == 0) {			// 삭제할 노드 찾기
			prev->link = cur->link;			// 이전 노드가 다음 노드를 가리키도록 적성
			free(cur);					// 노드 메모리 해제
			return 1;
		}

		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main()
{
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;

	int choice;
	int iteration = 1;

	char name[NAME_MAX];
	int score;

	while (iteration) {
		printf("<<학생 성적 관리 프로그램>>\n");
		printf("1. 학생 성적 입력하기\n");
		printf("2. 학생 삭제하기\n");
		printf("3. 프로그램 종료하기\n\n");

		printf("실행할 옵션을 선택하세요>> ");
		scanf_s("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			printf("학생의 이름을 입력하세요: ");
			scanf_s("%s", name, NAME_MAX);
			printf("점수: ");
			scanf_s("%d", &score);

			if (strlen(name) == 0 || score < 0)
			{
				printf("유효하지 않은 입력입니다.\n");
			}

			insert_node_last(create_node(name, score));
			break;

		case 2:
			printf("삭제할 학생의 이름을 입력하세요: ");
			scanf_s("%s", name, NAME_MAX);
			if (!delete_node(name))
			{
				printf("\n!!해당 학생을 찾을 수 없습니다!!\n\n");
			}
			else
			{
				delete_node(name);
			}
			break;

		case 3:

		default:
			printf("\n!!올바른 범위의 옵션을 선택하세요!!\n\n");
			iteration = 0;
			break;
		}
		print_nodes();
	}
	return 0;
}