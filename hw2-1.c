// 융합전자공학부 2022005650 김민현

#include <stdio.h>
#define STACK_SIZE 100000
int Ackermann(int m, int n) {  // Ackermann 함수
	if (m == 0) {
		return n + 1; // m이 0인 경우, n+1 반환
	}
	else if (m > 0 && n == 0) {
		return Ackermann(m - 1, 1); // n이 0인 경우, Ackermann(m-1, 1) 반환
	}
	else if (m > 0 && n > 0) { 
		return Ackermann(m - 1, Ackermann(m, n - 1)); // m, n이 모두 0보다 큰 경우, Ackermann(m-1, Ackermann(m, n-1)) 반환
	}
}
// 스택 구조 정의
int stack[STACK_SIZE];
int top = -1;

// 스택 연산 함수
void push(int item) {
    if (top == STACK_SIZE - 1) { // 스택이 가득 찬 경우
        printf("Stack Overflow\n");
        exit(1); // 프로그램 종료
    }
    stack[++top] = item; // 스택에 요소 추가
}

int pop() {
    if (top == -1) { // 스택이 비어 있는 경우
        printf("Stack Underflow\n");
        exit(1); // 프로그램 종료
    }
    return stack[top--]; // 스택에서 요소 제거 후 반환
}

// Ackermann 함수
int Ackermann2(int m, int n) {
    while (1) {
        if (m == 0) {
            if (top == -1) // 스택이 비어있을 때
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