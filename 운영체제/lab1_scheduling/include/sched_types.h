/*
*       DKU Operating System Lab
*           Lab1 (Scheduler Algorithm Simulator)
*           Student id : 32194747
*           Student name : Choi Jiyun
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H

/*
 * You need to Declare functions in  here
 */

typedef struct process
{
    char name;
    int arrival;
    int service; //실행해야하는 시간
    int runtime[3]; //실제 실행시간
    int r_run;
}process;

char Print[200];
process Task[5];

typedef struct Node //노드 정의
{
    process* data;
    struct Node* link;
}Node;

typedef struct Queue //Queue 구조체 정의
{
    Node* front; //맨 앞(꺼낼 위치)
    Node* rear; //맨 뒤(보관할 위치)
    int count;//보관 개수
}Queue;


void process1();
void process2();
void InitQueue(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, process* data);
Node* Dequeue(Queue* queue);
int getLCM(int* numArr);
int getGDC(int small, int big);
int power(int x, int y);
void Show();
void FIFO(process a, process b, process c, process d, process e);
void RR(process a, process b, process c, process d, process e, int q);
void SJF(process a, process b, process c, process d, process e);
void MLFQ(process a, process b, process c, process d, process e, int q);
void LOTTERY(int min, int max, int A_ticket, int B_ticket);

#endif /* LAB1_HEADER_H*/
