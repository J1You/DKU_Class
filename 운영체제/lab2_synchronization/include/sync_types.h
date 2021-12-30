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

	void init_car_queue(CQ* q);             // ���� Queue �ʱ�ȭ
	void init_scheduling_queue(SQ* q);      // �����ٸ� Queue �ʱ�ȭ
	void enqueue(SQ* q, int c_n);           // RR �����ٸ��� ���� enqueue
	Node* dequeue(SQ* q);                   // RR �����ٸ��� ���� dequeue
	void RR();                              // RR �����ٸ�
	void put_car(CQ* q, int c_n);           // ���� Queue�� put (enqueue)
	int get_car(CQ* q);                    // ���� Queue���� get (dequeue)
	void* producer_n(void* qq);             // No Lock���� ������ producer
	void* producer_c(void* qq);             // Coarse-grained Lock���� ������ producer
	void* producer_f(void* qq);             // Fine-grained Lock���� ������ producer
	void* consumer_n(void* qq);             // No Lock���� ������ consumer
	void* consumer_c(void* qq);             // Coarse-grained Lock���� ������ consumer
	void* consumer_f(void* qq);             // Fine-grained Lock���� ������ consumer
	void show(int balance, double result);  // ��� ���

#endif /* LAB2_HEADER_H*/


