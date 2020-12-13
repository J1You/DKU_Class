#include <stdio.h>
#include <sys/time.h>

// 노드의 위치를 서로 바꿔주는 swap 함수
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 이진트리를 히프 성질을 만족하도록 조정하는 adjust 함수
void adjust(int* arr, int size, int i) {
    int c = 2 * i + 1;
    if (c < size - 1 && arr[c] < arr[c + 1])
        c++;
    if (c < size && arr[i] < arr[c])
        swap(arr, i, c);
    if (c < size / 2)
        adjust(arr, size, c);
}

// 히프 정렬 함수
void heapSort(int* arr, int size) {
    int i;
    for (i = size / 2; i >= 0; i--) {
        adjust(arr, size, i);
    }
    for (i = size - 1; i >= 0; i--) {
        swap(arr, i, 0);
        adjust(arr, i, 0);
    }
}

int main() {
    int arr[] = { 41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36, 91, 4, 2, 53, 92, 82, 21, 16, 18, 95, 47, 26, 71, 38, 69, 12, 67, 99, 35, 94, 3, 11, 22, 33, 73, 64, 41, 11, 53, 68, 47, 44, 62, 57, 37, 59, 23, 41, 29, 78, 16, 35, 90, 42, 88, 6, 40, 42, 64, 48, 46, 5, 90, 29, 70, 50, 6, 1, 93, 48, 29, 23, 84, 54, 56, 40, 66, 76, 31, 8, 44, 39, 26, 23, 37, 38, 18, 82, 29, 41 }; // 기본 배열 (정렬 전)
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    struct timeval stime, etime, gap;
    gettimeofday(&stime, NULL); // 함수 호출 전 시간 측정
    heapSort(arr, size);  // 함수 호출
    gettimeofday(&etime, NULL); // 함수 호출 후 시간 측정
    printf("result>> ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // 정렬 결과
    }
    gap.tv_sec = etime.tv_sec - stime.tv_sec; // 실행 시간 (sec)
    gap.tv_usec = etime.tv_usec - stime.tv_usec; // 실행 시간 (usec)
    printf("\nElapsed time %ldsec : %ldusec\n", gap.tv_sec, gap.tv_usec); 
    return 0;
}