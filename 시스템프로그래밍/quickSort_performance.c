#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

// 노드의 위치를 서로 바꿔주는 swap 함수
int swap(int* arr, int l, int r) {
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

// 분할된 영역에서 중추키 (pivot)를 기준으로 위치를 조정하는 partition 함수
int partition(int arr[], int l, int r) {
	int pivot = arr[l]; 

	while (l <= r) {
		while (arr[l] < pivot) l++;
		while (arr[r] > pivot) r--;

		if (l <= r) {
			swap(arr, l, r);
			l++; r--;
		}
	}
	
	return l;
}

// 퀵 정렬 함수
void quick_sort(int* arr, int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);

		quick_sort(arr, l, p - 1);
		quick_sort(arr, p, r);
	}
}

// pivot을 랜덤하게 선정한 퀵 정렬 함수
void quick_sort_random(int *arr, int l, int r) {
	
	int pivot = rand() % (r + 1 - l) + l;
	swap(arr, l, pivot);
	
	if (l < r) {
		int p = partition(arr, l, r);

		quick_sort_random(arr, l, p - 1);
		quick_sort_random(arr, p, r);
	}
}

// 왼쪽, 오른쪽, 가운데 값 중 중간크기의 값을 고르는 choose 함수
int choose(int a, int b, int c) {
	if (a >= b) {
		if (b >= c) return b;
		else if (a <= c) return a;
		else return c;
	}
	else if (a >= c) return a;
	else if (b >= c) return c;
	else return b;
}

// 중간 값을 pivot으로 설정한 퀵 정렬 함수
void quick_sort_median(int* arr, int l, int r) {

	int mid= choose(arr[l], arr[(l+r)/2], arr[r]);
	if (mid == arr[(l + r) / 2]) swap(arr, (l + r) / 2, l);
	else if (mid == arr[r]) swap(arr, r, l);
	if (l < r) {
		int p = partition(arr, l, r);
		quick_sort_median(arr, l, p - 1);
		quick_sort_median(arr, p, r);
	}
}

// 삽입 정렬 
void insertion_sort(int* arr, int size) {
	int i;
	for (i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		for (; key < arr[j] && j >= 0; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int main() {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	struct timeval stime, etime, gap;
	gettimeofday(&stime, null);
	quick_sort_median(arr, 0, size - 1);
	gettimeofday(&etime, null);
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	gap.tv_sec = etime.tv_sec - stime.tv_sec;
	gap.tv_usec = etime.tv_usec - stime.tv_usec;
	printf("\nelapsed time %ldsec : %ldusec\n", gap.tv_sec, gap.tv_usec);
	return 0;
}