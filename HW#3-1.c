//2022005650 김민현 HW#3-1

#include <stdio.h>

#define SIZE 10 // 배열의 크기를 상수로 정의

// 배열에서 요소를 왼쪽으로 이동시키는 함수
void shiftArray(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        arr[i] = arr[i + 1];
    }
}

// 배열에서 특정 위치의 요소를 삭제하는 함수
void deleteElement(int arr[], int loc, int* size) {
    shiftArray(arr, loc, *size - 1); // 삭제할 요소의 뒷부분을 앞으로 당김
    (*size)--; // 배열의 크기를 1 감소시킴
}

int main() {
    int arr[SIZE];
    int size = SIZE; // 배열의 크기를 저장하는 변수
    int loc = 5; // 삭제할 요소의 인덱스

    // 배열 초기화
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    deleteElement(arr, loc, &size); // loc 위치의 요소를 삭제

    // 삭제 후 배열 출력
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}