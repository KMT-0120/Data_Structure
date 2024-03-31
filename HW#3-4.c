//2022005650 김민현 p.143 12번
#define _CRT_SECURE_NO_WARNINGS // scanf 함수 사용을 위한 경고 무시
#include <stdio.h>
#include <string.h>


#define MAX_SIZE 100

typedef struct {
    char item;
    int count;
} Pair;

typedef struct {
    Pair items[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화 함수
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택이 가득 찼는지 확인하는 함수
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 스택에 요소를 추가하는 함수
void push(Stack* stack, char item, int count) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top].item = item;
    stack->items[stack->top].count = count;
}

// 스택에서 요소를 제거하고 반환하는 함수
Pair pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        Pair pair = {'\0', 0};
        return pair;
    }
    return stack->items[stack->top--];
}

// 알파벳을 소문자로 변환하여 압축하여 스택에 추가하는 함수
void compressString(Stack* stack, char* str) {
    int length = strlen(str);
    int count = 1;

    for (int i = 0; i < length; i++) {
        // 대소문자를 구분하지 않기 위해 모두 소문자로 변환
        char ch = tolower(str[i]);

        if (i + 1 < length && tolower(str[i]) == tolower(str[i + 1])) {
            count++;
        }
        else {
            push(stack, ch, count);
            count = 1;
        }
    }
}

int main() {
    char str[MAX_SIZE];
    printf("알파벳을 입력하세요: ");
    scanf("%s", str);

    Stack stack;
    initializeStack(&stack);

    compressString(&stack, str);

    // 압축된 문자열을 거꾸로 출력하기 위해 임시로 저장할 스택
    Stack tempStack;
    initializeStack(&tempStack);

    // 압축된 문자열을 임시 스택에 복사
    while (!isEmpty(&stack)) {
        Pair pair = pop(&stack);
        push(&tempStack, pair.item, pair.count);
    }

    printf("압축된 문자열: ");
    // 임시 스택에서 데이터를 꺼내어 거꾸로 출력
    while (!isEmpty(&tempStack)) {
        Pair pair = pop(&tempStack);
        printf("%d%c", pair.count, pair.item);
    }
    printf("\n");

    return 0;
}