// �������ڰ��к� 2022005650 �����

#include <stdio.h>
#define STACK_SIZE 100000
int Ackermann(int m, int n) {  // Ackermann �Լ�
	if (m == 0) {
		return n + 1; // m�� 0�� ���, n+1 ��ȯ
	}
	else if (m > 0 && n == 0) {
		return Ackermann(m - 1, 1); // n�� 0�� ���, Ackermann(m-1, 1) ��ȯ
	}
	else if (m > 0 && n > 0) { 
		return Ackermann(m - 1, Ackermann(m, n - 1)); // m, n�� ��� 0���� ū ���, Ackermann(m-1, Ackermann(m, n-1)) ��ȯ
	}
}
// ���� ���� ����
int stack[STACK_SIZE];
int top = -1;

// ���� ���� �Լ�
void push(int item) {
    if (top == STACK_SIZE - 1) { // ������ ���� �� ���
        printf("Stack Overflow\n");
        exit(1); // ���α׷� ����
    }
    stack[++top] = item; // ���ÿ� ��� �߰�
}

int pop() {
    if (top == -1) { // ������ ��� �ִ� ���
        printf("Stack Underflow\n");
        exit(1); // ���α׷� ����
    }
    return stack[top--]; // ���ÿ��� ��� ���� �� ��ȯ
}

// Ackermann �Լ�
int Ackermann2(int m, int n) {
    while (1) {
        if (m == 0) {
            if (top == -1) // ������ ������� ��
                return n + 1;
            m = pop();
            n++;
        }
        else if (n == 0) {
            m--;
            n = 1;
        }
        else {
            push(m - 1);
            n--;
        }
    }
}
int main() {
	printf("Ackermann_recursive(3,4) : %d\n", Ackermann(2, 3));
	printf("Ackermann_iteration(3,4) : %d\n",Ackermann2(2, 3));
	printf("Ackermann_recursive(4,5) : %d\n", Ackermann(3, 4));
	printf("Ackermann_iterationk(4,5) : %d\n",Ackermann2(3, 4));
	return 0;
}