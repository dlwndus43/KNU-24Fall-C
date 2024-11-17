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
	struct NODE* last = last_node();			// ������ ��� ã��
	last->link = new_node;				// ������ ����� link�� �� ���� ����
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
	struct NODE* prev = head;			// ���� ���
	struct NODE* cur = head->link;		// ���� ���
	while (cur != NULL) {
		if (strcmp(name, cur->name) == 0) {			// ������ ��� ã��
			prev->link = cur->link;			// ���� ��尡 ���� ��带 ����Ű���� ����
			free(cur);					// ��� �޸� ����
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
		printf("<<�л� ���� ���� ���α׷�>>\n");
		printf("1. �л� ���� �Է��ϱ�\n");
		printf("2. �л� �����ϱ�\n");
		printf("3. ���α׷� �����ϱ�\n\n");

		printf("������ �ɼ��� �����ϼ���>> ");
		scanf_s("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			printf("�л��� �̸��� �Է��ϼ���: ");
			scanf_s("%s", name, NAME_MAX);
			printf("����: ");
			scanf_s("%d", &score);

			if (strlen(name) == 0 || score < 0)
			{
				printf("��ȿ���� ���� �Է��Դϴ�.\n");
			}

			insert_node_last(create_node(name, score));
			break;

		case 2:
			printf("������ �л��� �̸��� �Է��ϼ���: ");
			scanf_s("%s", name, NAME_MAX);
			if (!delete_node(name))
			{
				printf("\n!!�ش� �л��� ã�� �� �����ϴ�!!\n\n");
			}
			else
			{
				delete_node(name);
			}
			break;

		case 3:

		default:
			printf("\n!!�ùٸ� ������ �ɼ��� �����ϼ���!!\n\n");
			iteration = 0;
			break;
		}
		print_nodes();
	}
	return 0;
}