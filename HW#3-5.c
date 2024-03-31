//2022005650 김민현 p.143 16번
#define _CRT_SECURE_NO_WARNINGS // scanf 함수 사용을 위한 경고 무시
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// 스택 초기화 함수
void initialize(Stack *s) {
    s->top = -1;
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 스택이 가득 차있는지 확인하는 함수
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 스택에 요소를 추가하는 함수
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    } else {
        printf("Stack Overflow!\n");
    }
}

// 스택에서 요소를 제거하고 반환하는 함수
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow!\n");
        return '\0';
    }
}

// 주어진 문자열이 회문인지 판단하는 함수
bool isPalindrome(char *str) {
    Stack stack;
    int len = strlen(str);
    initialize(&stack);

    // 문자열을 스택에 푸시
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    // 문자열의 절반까지 스택에서 문자를 팝하면서 비교
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != pop(&stack)) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("회문입니다.\n");
    } else {
        printf("회문이아닙니다.\n");
    }


    return 0;
}
