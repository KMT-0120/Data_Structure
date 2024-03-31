// 2022005650 김민현 p.99 12번
#define _CRT_SECURE_NO_WARNINGS // strcpy 함수 사용을 위한 경고 무시
#include <stdio.h>
#include <stdlib.h> // malloc 함수를 사용하기 위해 추가
#include <string.h>


// 구조체 정의
struct IntChar {
    int i;
    char c[20];
};

int main() {
    // 구조체 포인터 선언 및 메모리 할당
    struct IntChar *ptr;
    ptr = (struct IntChar *)malloc(sizeof(struct IntChar));

    // 포인터가 가리키는 구조체 멤버 설정
    ptr->i = 100;
    strcpy(ptr->c, "just testing");

    // 구조체 멤버 출력
    printf("%d %s\n", ptr->i, ptr->c);

    // 동적으로 할당한 메모리 해제
    free(ptr);

    return 0;
}
