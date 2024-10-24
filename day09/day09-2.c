#include <stdio.h>
#include<string.h>

#define MAX_PRODUCTS 5

// 상품 정보를 담을 구조체 정의
typedef struct 
{
    int id;        // 상품 ID
    char name[100]; // 상품명
    int price;     // 가격
} Product;

// 상품 정보를 출력하는 함수 정의
void printProduct(Product p) 
{
    printf("상품 ID: %d\n", p.id);
    printf("상품명: %s\n", p.name);
    printf("가격: %d원\n", p.price);
}

int main() {
    Product products[MAX_PRODUCTS]; // 상품 정보를 저장할 배열
    int count = 0;  // 현재 입력된 상품 개수

    while (count < MAX_PRODUCTS) 
    {
        int id;
        printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
        printf("ID: ");
        scanf_s("%d", &id, sizeof(id));

        // 버퍼 비우기 (개행 문자 제거)
        while (getchar() != '\n');

        // ID가 0이면 입력 중단
        if (id == 0) 
        {
            break;
        }

        // 상품 정보 입력 받기
        products[count].id = id;
        printf("상품명: ");
        fgets(products[count].name, sizeof(products[count].name), stdin);
        // fgets로 입력받은 후 개행 문자 제거
        products[count].name[strcspn(products[count].name, "\n")] = 0;

        printf("가격: ");
        scanf_s("%d", &products[count].price, sizeof(products));

        printf("\n");

        // 버퍼 비우기 (개행 문자 제거)
        while (getchar() != '\n');

        count++;
    }

    // 입력된 상품 목록 출력
    printf("\n<<입력된 상품 목록>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}