#include <stdio.h>
#include<string.h>

#define MAX_PRODUCTS 5

// ��ǰ ������ ���� ����ü ����
typedef struct 
{
    int id;        // ��ǰ ID
    char name[100]; // ��ǰ��
    int price;     // ����
} Product;

// ��ǰ ������ ����ϴ� �Լ� ����
void printProduct(Product p) 
{
    printf("��ǰ ID: %d\n", p.id);
    printf("��ǰ��: %s\n", p.name);
    printf("����: %d��\n", p.price);
}

int main() {
    Product products[MAX_PRODUCTS]; // ��ǰ ������ ������ �迭
    int count = 0;  // ���� �Էµ� ��ǰ ����

    while (count < MAX_PRODUCTS) 
    {
        int id;
        printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
        printf("ID: ");
        scanf_s("%d", &id, sizeof(id));

        // ���� ���� (���� ���� ����)
        while (getchar() != '\n');

        // ID�� 0�̸� �Է� �ߴ�
        if (id == 0) 
        {
            break;
        }

        // ��ǰ ���� �Է� �ޱ�
        products[count].id = id;
        printf("��ǰ��: ");
        fgets(products[count].name, sizeof(products[count].name), stdin);
        // fgets�� �Է¹��� �� ���� ���� ����
        products[count].name[strcspn(products[count].name, "\n")] = 0;

        printf("����: ");
        scanf_s("%d", &products[count].price, sizeof(products));

        printf("\n");

        // ���� ���� (���� ���� ����)
        while (getchar() != '\n');

        count++;
    }

    // �Էµ� ��ǰ ��� ���
    printf("\n<<�Էµ� ��ǰ ���>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}