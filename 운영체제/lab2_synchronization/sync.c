/*
*   DKU Operating System Lab
*           Lab2 (Vehicle production Problem)
*           Student id : 32194747
*           Student name : √÷¡ˆ¿±
*
*   lab2_sync.c :
*       - lab2 main file.
*       - must contains Vehicle production Problem function's declations.
*
*/

#include <aio.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>

#include "lab2_sync_types.h"

/*
 * you need to implement Vehicle production Problem.
 */

int total_car = 0, time_quantum = 0;
int Print[10000000] = { 0 };
pthread_mutex_t frontLock, rearLock, p_mutex;
pthread_cond_t empty, fill;



void workload() {
	Car[0].num = 1;
	Car[0].arrival = 0;
	Car[0].quantity = total_car / 5;
	Car[0].runtime = 0;

	Car[1].num = 2;
	Car[1].arrival = 2;
	Car[1].quantity = total_car / 5;
	Car[1].runtime = 0;

	Car[2].num = 3;
	Car[2].arrival = 4;
	Car[2].quantity = total_car / 5;
	Car[2].runtime = 0;

	Car[3].num = 4;
	Car[3].arrival = 6;
	Car[3].quantity = total_car / 5;
	Car[3].runtime = 0;

	Car[4].num = 5;
	Car[4].arrival = 8;
	Car[4].quantity = total_car / 5;
	Car[4].runtime = 0;
}

void lab2_sync_usage(char* cmd) {
	printf("\n Usage for %s : \n", cmd);
	printf("    -c: Total number of vehicles produced, must be bigger than 0 ( e.g. 100 )\n");
	printf("    -q: RoundRobin Time Quantum, must be bigger than 0 ( e.g. 1, 4 ) \n");
}

void lab2_sync_example(char* cmd) {
	printf("\n Example : \n");
	printf("    #sudo %s -c=100 -q=1 \n", cmd);
	printf("    #sudo %s -c=10000 -q=4 \n", cmd);
}

void init_car_queue(CQ* q) {
	q->front = q->rear = NULL;
	q->balance = 0;
}

void init_scheduling_queue(SQ* q) {
	q->front = q->rear = NULL;
	q->count = 0;
}

int isEmpty(SQ* q)
{
	return q->count == 0;
}

void enqueue(SQ* q, int c_n) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->car_num = c_n;
	tmp->next = NULL;

	if (isEmpty(q))
		q->front = tmp;
	else
		q->rear->next = tmp;
	q->rear = tmp;
	q->count++;
}

Node* dequeue(SQ* q) {
	Node* re = 0;
	Node* tmp;
	if (isEmpty(q))
		return re;
	tmp = q->front;
	re = tmp;
	q->front = tmp->next;
	free(tmp);
	q->count--;
	return re;
}

void RR() {
	int time_count = 0;
	int time = total_car;
	SQ RR_Queue;
	init_scheduling_queue(&RR_Queue);

	for (int i = 0; i < 5; i++) {
		if (Car[i].arrival == 0) {
			enqueue(&RR_Queue, Car[i].num);
		}
	}

	while (time != 0) {
		if (!isEmpty(&RR_Queue)) {
			Print[time_count] = RR_Queue.front->car_num;
			Car[RR_Queue.front->car_num - 1].quantity--;
			Car[RR_Queue.front->car_num - 1].runtime++;
			time_count++;
			time--;
		}
		else if (isEmpty(&RR_Queue)) {
			Print[time_count] = -1;
			time_count++;
		}

		for (int i = 0; i < 5; i++) {
			if (time_count == Car[i].arrival) {
				enqueue(&RR_Queue, Car[i].num);
			}
		}

		if (Car[RR_Queue.front->car_num - 1].runtime == 0) {
			Print[time_count] = RR_Queue.front->car_num;
			Car[RR_Queue.front->car_num - 1].quantity--;
			Car[RR_Queue.front->car_num - 1].runtime++;
			time_count++;

			for (int i = 0; i < 5; i++) {
				if (time_count == Car[i].arrival) {
					enqueue(&RR_Queue, Car[i].num);
				}
			}
			time--;
		}
		if (Car[RR_Queue.front->car_num - 1].quantity != 0 && (Car[RR_Queue.front->car_num - 1].runtime) % (time_quantum) == 0) {
			enqueue(&RR_Queue, RR_Queue.front->car_num);
			dequeue(&RR_Queue);
		}
		else if ((Car[RR_Queue.front->car_num - 1].quantity == 0)) {
			dequeue(&RR_Queue);
		}
	}
}

void put_car(CQ* q, int c_n) {
	Node* new_car = (Node*)malloc(sizeof(Node));
	new_car->car_num = c_n;
	new_car->next = NULL;
	//pthread_mutex_lock(&rearLock);
	if (q->balance == 0) {
		q->front = new_car;
	}
	else {
		q->rear->next = new_car;
	}
	q->rear = new_car;
	q->balance = q->balance + 1;
	//pthread_mutex_unlock(&rearLock);
}

int get_car(CQ* q) {
	Node* tmp = q->front;
	//pthread_mutex_lock(&frontLock);
	if (q->balance == 0) return 0;
	q->front = tmp->next;
	

	q->balance = q->balance - 1;
	//pthread_mutex_unlock(&frontLock);
	free(tmp);
	return 1;
}

void* producer_n(void* qq) {
	CQ* q = (CQ*)qq;
	RR();
	for (int i = 0; i < total_car; i++) {
		if (Print[i] != -1) {
			put_car(q, Print[i]);
		}
	}
}

void* producer_c(void* qq) {
	CQ* q = (CQ*)qq;
	RR();
	for (int i = 0; i < total_car; i++) {
		if (Print[i] != -1) {
			pthread_mutex_lock(&p_mutex);
			put_car(q, Print[i]);
			pthread_cond_signal(&fill);
			pthread_mutex_unlock(&p_mutex);
		}
	}
}

void* producer_f(void* qq) {
	CQ* q = (CQ*)qq;
	RR();
	for (int i = 0; i < total_car; i++) {
		if (Print[i] != -1) {
			pthread_mutex_lock(&rearLock);
			put_car(q, Print[i]);
			pthread_cond_signal(&fill);
			pthread_mutex_unlock(&rearLock);
		}
	}

}

void* consumer_n(void* qq) {
	CQ* q = (CQ*)qq;
	int result;
	for (int i = 0; i < total_car * 0.2; i++) {

		result = get_car(q);
		if (result == 0) i--;
	}
}

void* consumer_c(void* qq) {
	CQ* q = (CQ*)qq;
	for (int i = 0; i < total_car * 0.2; i++) {
		pthread_mutex_lock(&p_mutex);
		while (q->balance == 0) {
			pthread_cond_wait(&fill, &p_mutex);
		}
		get_car(q);
		pthread_mutex_unlock(&p_mutex);
	}
}

void* consumer_f(void* qq) {
	CQ* q = (CQ*)qq;
	for (int i = 0; i < total_car * 0.2; i++) {
		pthread_mutex_lock(&frontLock);
		while (q->balance == 0) {
			pthread_cond_wait(&fill, &frontLock);
		}
		get_car(q);
		pthread_mutex_unlock(&frontLock);
	}
}

void show(int balance, double result) {
	printf("Experiment Info\n");
	printf("\tTotal Produce Number = %d\n", total_car);
	printf("\tFinal Balance Value = %d\n", balance);
	printf("\tExecution time = %lf\n", result);
}

int main(int argc, char* argv[]) {
	char op;
	int n; char junk;
	CQ n_queue, c_queue, f_queue;
	struct timeval start, end;
	double result_T;

	pthread_mutex_init(&p_mutex, NULL);
	pthread_mutex_init(&frontLock, NULL);
	pthread_mutex_init(&rearLock, NULL);

	if (argc <= 1) {
		lab2_sync_usage(argv[0]);
		lab2_sync_example(argv[0]);
		exit(0);
	}

	for (int i = 1; i < argc; i++) {
		if (sscanf(argv[i], "-c=%d%c", &n, &junk) == 1) {
			total_car = n;
		}
		else if (sscanf(argv[i], "-q=%d%c", &n, &junk) == 1) {
			time_quantum = n;
		}
		else {
			lab2_sync_usage(argv[0]);
			lab2_sync_example(argv[0]);
			exit(0);
		}
	}


	/*
	   * You need to implement Vehicle production Problem
	   * If you want to use other header file, it's ok!
	   * If you have any question for this task, please contact me (ghwls03s@gmail.com)
	   * You may be need to use pthread_create function
	*/

	pthread_t n_pid, n_cid[5];

	gettimeofday(&start, NULL);

	init_car_queue(&n_queue);
	workload();

	
	for (int i = 0; i < 5; i++) {
		pthread_create(&n_cid[i], NULL, consumer_n, (void*)&n_queue);
	}
	pthread_create(&n_pid, NULL, producer_n, (void*)&n_queue);
	
	
	for (int i = 0; i < 5; i++) {
		pthread_join(n_cid[i], NULL);
	}
	pthread_join(n_pid, NULL);

	gettimeofday(&end, NULL);

	result_T = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) * 0.000001);

	printf("==== Vehicle Production Problem ====\n");
	printf("(1) No Lock Experiment\n");
	show(n_queue.balance, result_T);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	pthread_t c_pid, c_cid[5];
	result_T = 0;
	gettimeofday(&start, NULL);
	init_car_queue(&c_queue);
	workload();

	pthread_create(&c_pid, NULL, producer_c, (void*)&c_queue);
	for (int i = 0; i < 5; i++) {
		pthread_create(&c_cid[i], NULL, consumer_c, (void*)&c_queue);
	}

	pthread_join(c_pid, NULL);
	for (int i = 0; i < 5; i++)
		pthread_join(c_cid[i], NULL);

	gettimeofday(&end, NULL);
	pthread_mutex_destroy(&p_mutex);

	result_T = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) * 0.000001);

	printf("==== Vehicle Production Problem ====\n");
	printf("(2) Coarse-grained Lock Experiment\n");
	show(c_queue.balance, result_T);

	///// ////////////////////////////////////////////////////////////////////////////////////////////////////
	pthread_t f_pid, f_cid[5];
	result_T = 0;
	gettimeofday(&start, NULL);
	init_car_queue(&f_queue);
	workload();

	pthread_create(&f_pid, NULL, producer_f, (void*)&f_queue);
	for (int i = 0; i < 5; i++) {
		pthread_create(&f_cid[i], NULL, consumer_f, (void*)&f_queue);
	}

	pthread_join(f_pid, NULL);
	for (int i = 0; i < 5; i++)
		pthread_join(f_cid[i], NULL);

	gettimeofday(&end, NULL);

	result_T = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) * 0.000001);

	printf("==== Vehicle Production Problem ====\n");
	printf("(3) Fine-grained Lock Experiment\n");
	show(f_queue.balance, result_T);

	return 0;
}