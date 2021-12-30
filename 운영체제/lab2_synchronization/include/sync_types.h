/*
*   DKU Operating System Lab
*           Lab2 (Vehicle Production Problem)
*           Student id : 
*           Student name : 
*
*   lab1_sync_types.h :
*       - lab2 header file.
*       - must contains Vehicle Production Problem's declations.
*
*/

#ifndef _LAB2_HEADER_H
#define _LAB2_HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>

#define MAX_SIZE 100

/*
 * You need to Declare functions in  here
 */

typedef struct Node {
	int car_num;
	struct Node* next;
}Node;

typedef struct car_queue {
	int balance;
	Node* front, * rear;
}CQ;

typedef struct scheduling_queue {
	int count;
	Node* front, * rear;
}SQ;

typedef struct car_process {
	int num;
	int arrival;
	int quantity;
	int runtime;
}CP;


CP Car[5];

	void init_car_queue(CQ* q);             // 생산 Queue 초기화
	void init_scheduling_queue(SQ* q);      // 스케줄링 Queue 초기화
	void enqueue(SQ* q, int c_n);           // RR 스케줄링을 위한 enqueue
	Node* dequeue(SQ* q);                   // RR 스케줄링을 위한 dequeue
	void RR();                              // RR 스케줄링
	void put_car(CQ* q, int c_n);           // 생산 Queue에 put (enqueue)
	int get_car(CQ* q);                    // 생산 Queue에서 get (dequeue)
	void* producer_n(void* qq);             // No Lock으로 구현한 producer
	void* producer_c(void* qq);             // Coarse-grained Lock으로 구현한 producer
	void* producer_f(void* qq);             // Fine-grained Lock으로 구현한 producer
	void* consumer_n(void* qq);             // No Lock으로 구현한 consumer
	void* consumer_c(void* qq);             // Coarse-grained Lock으로 구현한 consumer
	void* consumer_f(void* qq);             // Fine-grained Lock으로 구현한 consumer
	void show(int balance, double result);  // 결과 출력

#endif /* LAB2_HEADER_H*/


