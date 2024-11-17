#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX (50)

enum Rank 
{
    VVIP = 1,    // 가장 높은 우선순위
    VIP,
    GOLD,
    SILVER     // 가장 낮은 우선순위
};

struct Customer 
{
    char* customerName;     // 고객 이름
    int rank;                        // 등급
    int order_amount;          // 주문량
    int point;                       // 포인트
    struct Customer* prev;  // 이전 노드
    struct Customer* next;  // 다음 노드
};

struct Customer* head;

// 새로운 고객 생성
struct Customer* create_node(char* name, int rank, int order_amount, int point) 
{
    struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
    if (!new_node) 
    {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    new_node->customerName = (char*)malloc(strlen(name) + 1);  // 이름 메모리 동적 할당
    if (!new_node->customerName) 
    {
        printf("메모리 할당 실패\n");
        free(new_node);
        exit(1);
    }
    strcpy_s(new_node->customerName, strlen(name) + 1, name); // 이름 복사
    new_node->rank = rank;
    new_node->order_amount = order_amount;
    new_node->point = point;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// 우선순위를 비교하는 함수
int compare_priority(struct Customer* a, struct Customer* b)
{
    if (a->rank != b->rank)
        return a->rank - b->rank; // 등급이 1에 가까울수록 우선 순위 높음
    if (a->order_amount != b->order_amount)
        return b->order_amount - a->order_amount; // 주문량이 많을수록 우선순위 높음
    return b->point - a->point; // 포인트가 많을수록 우선순위 높음}
}

// 우선순위에 따라 삽입
    void insert_node_priority(struct Customer* new_node)
{
    struct Customer* cur = head->next;

    if (!cur)      // 리스트가 비어 있으면 바로 삽입
    {
        head->next = new_node;
        new_node->prev = head;
        return;
    }

    while (cur)       // 적절한 위치를 찾아 삽입
    {
        if (compare_priority(new_node, cur) < 0)
        { // new_node가 cur보다 우선순위가 높으면 삽입
            new_node->next = cur;
            new_node->prev = cur->prev;
            if (cur->prev) cur->prev->next = new_node;
            cur->prev = new_node;
            if (cur == head->next) head->next = new_node; // 첫 번째 노드 업데이트
            return;
        }
        cur = cur->next;
    }

    // 모든 노드보다 우선순위가 낮으면 마지막에 삽입
    struct Customer* last = head;
    while (last->next) last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

int delete_node(char* name)         // 고객 삭제
{
    struct Customer* cur = head->next;
    while (cur) 
    {
        if (strcmp(cur->customerName, name) == 0) 
        {
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            free(cur->customerName);  // 이름 메모리 해제
            free(cur);                // 노드 메모리 해제
            return 1;                 // 삭제 성공
        }
        cur = cur->next;
    }
    printf("해당 고객을 찾을 수 없습니다.\n");
    return 0;      // 삭제 실패
}

int change_node(char* name)     // 고객 정보 수정
{
    struct Customer* cur = head->next;
    while (cur) 
    {
        if (strcmp(cur->customerName, name) == 0) 
        {
            printf("고객의 새로운 등급을 입력하세요 (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            scanf_s("%d", &cur->rank);
            printf("고객의 새로운 주문량을 입력하세요: ");
            scanf_s("%d", &cur->order_amount);
            printf("고객의 새로운 포인트를 입력하세요: ");
            scanf_s("%d", &cur->point);
            return 1;    // 성공적으로 변경
        }
        cur = cur->next;
    }
    printf("해당 이름의 고객을 찾을 수 없습니다.\n");
    return 0;   // 변경 실패
}

void print_nodes()      // 고객 리스트 출력
{
    struct Customer* cur = head->next;
    printf("-----------------------------------------------------------\n");
    while (cur) 
    {
        printf("이름: %s | 등급: %d | 주문량: %d | 포인트: %d\n",
            cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("-----------------------------------------------------------\n");
}

int main()      // 메인 함수
{
    head = (struct Customer*)malloc(sizeof(struct Customer));
    if (!head) 
    {
        printf("메모리 할당 실패\n");
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
        printf("<<고객 관리 프로그램(우선 순위 존재)>>\n");
        printf("1. 고객 추가하기\n");
        printf("2. 고객 삭제하기\n");
        printf("3. 고객 수정하기\n");
        printf("4. 고객 전체리스트 출력하기\n");
        printf("5. 프로그램 종료\n");

        printf("\n실행할 옵션을 선택하세요>> ");
        scanf_s("%d", &choice);
        printf("\n");

        int should_Print = 0;

        switch (choice) 
        {
        case 1:
            printf("고객의 이름을 입력하세요: ");
            scanf_s("%s", name, NAME_MAX);
            printf("고객의 등급을 입력하세요 (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            scanf_s("%d", &rank);
            printf("고객의 전체 주문량을 입력하세요: ");
            scanf_s("%d", &order_amount);
            printf("고객의 포인트를 입력하세요: ");
            scanf_s("%d", &point);

            insert_node_priority(create_node(name, rank, order_amount, point));
            should_Print = 1;
            break;

        case 2:
            printf("삭제할 고객의 이름을 입력하세요: ");
            scanf_s("%s", name, NAME_MAX);
            delete_node(name);
            should_Print = 1;
            break;

        case 3:
            printf("수정할 고객의 이름을 입력하세요: ");
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
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (should_Print) 
        {
            print_nodes();
        }
    }

    struct Customer* cur = head->next;          // 메모리 해제
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
