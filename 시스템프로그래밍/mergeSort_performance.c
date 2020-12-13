#include <stdio.h> 
#include <sys/time.h>
int sorted[8]; //정렬된 배열 

// 정렬된 리스트를 합병하는 merge 함수
void merge(int *data, int l, int mid, int r)
{ 
	int i = l, k = l, j = mid+1, t;
	while(i <= mid && j <= r) {
		if(data[i] <= data[j]){
			sorted[k] = data[i];
			i++; 
		}
		else{
			sorted[k] = data[j]; 
			j++;
		} 
		k++; 
	} 
	if(i > mid){
		for(t = j; t<=r; t++){ 
			sorted[k] = data[t];
			k++; 
		} 
	}
	else{
		for(t = i; t<=mid; t++){
			sorted[k] = data[t];
			k++; 
		} 
	} 

	for (t = l; t <= r; t++) data[t] = sorted[t]; 
} 

// 합병 정렬 함수
void mergeSort(int *data, int l, int r)
{ 
	if(l < r){
		int mid = (l + r) / 2; 
		mergeSort(data, l, mid); 
		mergeSort(data, mid+1, r); 
		merge(data, l, mid, r);
	} 
} 

int main(void)
{
	int arr[] = { 41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36, 91, 4, 2, 53, 92, 82, 21, 16, 18, 95, 47, 26, 71, 38, 69, 12, 67, 99, 35, 94, 3, 11, 22, 33, 73, 64, 41, 11, 53, 68, 47, 44, 62, 57, 37, 59, 23, 41, 29, 78, 16, 35, 90, 42, 88, 6, 40, 42, 64, 48, 46, 5, 90, 29, 70, 50, 6, 1, 93, 48, 29, 23, 84, 54, 56, 40, 66, 76, 31, 8, 44, 39, 26, 23, 37, 38, 18, 82, 29, 41 }; // 기본 배열 (정렬 전)
	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	struct timeval stime, etime, gap;
	gettimeofday(&stime, NULL); // 함수 호출 전 시간 측정
	mergeSort(arr, 0, size-1); // 함수 호출
	gettimeofday(&etime, NULL); // 함수 호출 후 시간 측정
	for (i = 0; i < 8; i++) {
		printf("%d ", arr[i]); // 정렬 결과
	}
	gap.tv_sec = etime.tv_sec - stime.tv_sec; // 실행 시간 (sec)
	gap.tv_usec = etime.tv_usec - stime.tv_usec; // 실행 시간 (usec)
	printf("\nelapsed time %ldsec : %ldusec\n", gap.tv_sec, gap.tv_usec);
	return 0;
}

