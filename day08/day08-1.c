#include <stdio.h>
#include <string.h>

int main() {

    char str[100];
    char* p_start;
    char* p_end;

    // 문자열 입력 받기 (띄어쓰기도 포함)
    printf("문자열 입력: ");
    scanf_s("%s", &str, sizeof(str));

    // 문자열의 길이 계산
    int len = strlen(str);

    // 포인터 초기화
    p_start = str;         // 문자열의 첫 문자
    p_end = str + len - 1; // 문자열의 마지막 문자

    // 두 개의 포인터를 사용해서 문자열을 뒤집기
    while (p_start < p_end) {
        // 앞과 뒤 문자를 교환
        char temp = *p_start;
        *p_start = *p_end;
        *p_end = temp;

        // 포인터 이동
        p_start++;
        p_end--;
    }

    // 뒤집은 문자열 출력
    printf("뒤집은 문자열: %s\n", str);

    return 0;
}