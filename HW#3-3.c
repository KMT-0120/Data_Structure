// 2022005650 김민현 p.143 11번
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// 스택 구조체 정의
typedef struct {
    int top;            // 스택의 탑을 나타내는 인덱스
    char items[MAX_STACK_SIZE]; // 스택에 저장되는 요소들을 담는 배열
} Stack;

// 스택에 요소를 추가하는 함수
void push(Stack* stack, char item) {
    if (stack->top == MAX_STACK_SIZE - 1) { // 스택이 꽉 찬 경우
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item; // 스택에 요소 추가하고 탑을 업데이트
}

// 스택에서 요소를 제거하고 반환하는 함수
char pop(Stack* stack) {
    if (stack->top == -1) { // 스택이 비어있는 경우
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--]; // 스택에서 요소 제거하고 탑을 업데이트
}

// 괄호 쌍을 검사하고 출력하는 함수
void checkParentheses(char* str) {
    int c = 1; // 괄호 쌍을 구분하기 위한 번호
    Stack stack;
    stack.top = -1; // 스택 초기화

    // 문자열을 순회하며 괄호를 검사
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') { // 여는 괄호인 경우
            printf("%d ", c); // 괄호 쌍 번호 출력
            push(&stack, c++); // 스택에 번호를 추가하고 증가
        } else if (str[i] == ')') { // 닫는 괄호인 경우
            printf("%d ", pop(&stack)); // 스택에서 번호를 꺼내어 출력
        }
    }
}

int main() {
    char str1[20] = "((())(()))"; // 검사할 문자열
    checkParentheses(str1); // 괄호 쌍 검사 함수 호출
    printf("\n");

    return 0;
}
