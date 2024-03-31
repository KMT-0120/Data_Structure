//2022005650 ����� p.143 12��
#define _CRT_SECURE_NO_WARNINGS // scanf �Լ� ����� ���� ��� ����
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

// ���� �ʱ�ȭ �Լ�
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ������ ���� á���� Ȯ���ϴ� �Լ�
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(Stack* stack, char item, int count) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top].item = item;
    stack->items[stack->top].count = count;
}

// ���ÿ��� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
Pair pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        Pair pair = {'\0', 0};
        return pair;
    }
    return stack->items[stack->top--];
}

// ���ĺ��� �ҹ��ڷ� ��ȯ�Ͽ� �����Ͽ� ���ÿ� �߰��ϴ� �Լ�
void compressString(Stack* stack, char* str) {
    int length = strlen(str);
    int count = 1;

    for (int i = 0; i < length; i++) {
        // ��ҹ��ڸ� �������� �ʱ� ���� ��� �ҹ��ڷ� ��ȯ
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
    printf("���ĺ��� �Է��ϼ���: ");
    scanf("%s", str);

    Stack stack;
    initializeStack(&stack);

    compressString(&stack, str);

    // ����� ���ڿ��� �Ųٷ� ����ϱ� ���� �ӽ÷� ������ ����
    Stack tempStack;
    initializeStack(&tempStack);

    // ����� ���ڿ��� �ӽ� ���ÿ� ����
    while (!isEmpty(&stack)) {
        Pair pair = pop(&stack);
        push(&tempStack, pair.item, pair.count);
    }

    printf("����� ���ڿ�: ");
    // �ӽ� ���ÿ��� �����͸� ������ �Ųٷ� ���
    while (!isEmpty(&tempStack)) {
        Pair pair = pop(&tempStack);
        printf("%d%c", pair.count, pair.item);
    }
    printf("\n");

    return 0;
}