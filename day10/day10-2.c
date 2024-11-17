#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX (50)

enum Rank 
{
    VVIP = 1,    // ���� ���� �켱����
    VIP,
    GOLD,
    SILVER     // ���� ���� �켱����
};

struct Customer 
{
    char* customerName;     // �� �̸�
    int rank;                        // ���
    int order_amount;          // �ֹ���
    int point;                       // ����Ʈ
    struct Customer* prev;  // ���� ���
    struct Customer* next;  // ���� ���
};

struct Customer* head;

// ���ο� �� ����
struct Customer* create_node(char* name, int rank, int order_amount, int point) 
{
    struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
    if (!new_node) 
    {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    new_node->customerName = (char*)malloc(strlen(name) + 1);  // �̸� �޸� ���� �Ҵ�
    if (!new_node->customerName) 
    {
        printf("�޸� �Ҵ� ����\n");
        free(new_node);
        exit(1);
    }
    strcpy_s(new_node->customerName, strlen(name) + 1, name); // �̸� ����
    new_node->rank = rank;
    new_node->order_amount = order_amount;
    new_node->point = point;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// �켱������ ���ϴ� �Լ�
int compare_priority(struct Customer* a, struct Customer* b)
{
    if (a->rank != b->rank)
        return a->rank - b->rank; // ����� 1�� �������� �켱 ���� ����
    if (a->order_amount != b->order_amount)
        return b->order_amount - a->order_amount; // �ֹ����� �������� �켱���� ����
    return b->point - a->point; // ����Ʈ�� �������� �켱���� ����}
}

// �켱������ ���� ����
    void insert_node_priority(struct Customer* new_node)
{
    struct Customer* cur = head->next;

    if (!cur)      // ����Ʈ�� ��� ������ �ٷ� ����
    {
        head->next = new_node;
        new_node->prev = head;
        return;
    }

    while (cur)       // ������ ��ġ�� ã�� ����
    {
        if (compare_priority(new_node, cur) < 0)
        { // new_node�� cur���� �켱������ ������ ����
            new_node->next = cur;
            new_node->prev = cur->prev;
            if (cur->prev) cur->prev->next = new_node;
            cur->prev = new_node;
            if (cur == head->next) head->next = new_node; // ù ��° ��� ������Ʈ
            return;
        }
        cur = cur->next;
    }

    // ��� ��庸�� �켱������ ������ �������� ����
    struct Customer* last = head;
    while (last->next) last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

int delete_node(char* name)         // �� ����
{
    struct Customer* cur = head->next;
    while (cur) 
    {
        if (strcmp(cur->customerName, name) == 0) 
        {
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            free(cur->customerName);  // �̸� �޸� ����
            free(cur);                // ��� �޸� ����
            return 1;                 // ���� ����
        }
        cur = cur->next;
    }
    printf("�ش� ���� ã�� �� �����ϴ�.\n");
    return 0;      // ���� ����
}

int change_node(char* name)     // �� ���� ����
{
    struct Customer* cur = head->next;
    while (cur) 
    {
        if (strcmp(cur->customerName, name) == 0) 
        {
            printf("���� ���ο� ����� �Է��ϼ��� (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            scanf_s("%d", &cur->rank);
            printf("���� ���ο� �ֹ����� �Է��ϼ���: ");
            scanf_s("%d", &cur->order_amount);
            printf("���� ���ο� ����Ʈ�� �Է��ϼ���: ");
            scanf_s("%d", &cur->point);
            return 1;    // ���������� ����
        }
        cur = cur->next;
    }
    printf("�ش� �̸��� ���� ã�� �� �����ϴ�.\n");
    return 0;   // ���� ����
}

void print_nodes()      // �� ����Ʈ ���
{
    struct Customer* cur = head->next;
    printf("-----------------------------------------------------------\n");
    while (cur) 
    {
        printf("�̸�: %s | ���: %d | �ֹ���: %d | ����Ʈ: %d\n",
            cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("-----------------------------------------------------------\n");
}

int main()      // ���� �Լ�
{
    head = (struct Customer*)malloc(sizeof(struct Customer));
    if (!head) 
    {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    head->next = NULL;
    head->prev = NULL;

    int choice;
    int iteration = 1;

    char name[NAME_MAX];
    int rank;
    int order_amount;
    int point;

    while (iteration) 
    {
        printf("<<�� ���� ���α׷�(�켱 ���� ����)>>\n");
        printf("1. �� �߰��ϱ�\n");
        printf("2. �� �����ϱ�\n");
        printf("3. �� �����ϱ�\n");
        printf("4. �� ��ü����Ʈ ����ϱ�\n");
        printf("5. ���α׷� ����\n");

        printf("\n������ �ɼ��� �����ϼ���>> ");
        scanf_s("%d", &choice);
        printf("\n");

        int should_Print = 0;

        switch (choice) 
        {
        case 1:
            printf("���� �̸��� �Է��ϼ���: ");
            scanf_s("%s", name, NAME_MAX);
            printf("���� ����� �Է��ϼ��� (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            scanf_s("%d", &rank);
            printf("���� ��ü �ֹ����� �Է��ϼ���: ");
            scanf_s("%d", &order_amount);
            printf("���� ����Ʈ�� �Է��ϼ���: ");
            scanf_s("%d", &point);

            insert_node_priority(create_node(name, rank, order_amount, point));
            should_Print = 1;
            break;

        case 2:
            printf("������ ���� �̸��� �Է��ϼ���: ");
            scanf_s("%s", name, NAME_MAX);
            delete_node(name);
            should_Print = 1;
            break;

        case 3:
            printf("������ ���� �̸��� �Է��ϼ���: ");
            scanf_s("%s", name, NAME_MAX);
            change_node(name);
            should_Print = 1;
            break;

        case 4:
            print_nodes();
            break;

        case 5:
        default:
            iteration = 0;
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        if (should_Print) 
        {
            print_nodes();
        }
    }

    struct Customer* cur = head->next;          // �޸� ����
    while (cur) 
    {
        struct Customer* temp = cur;
        cur = cur->next;
        free(temp->customerName);
        free(temp);
    }
    free(head);

    return 0;
}
