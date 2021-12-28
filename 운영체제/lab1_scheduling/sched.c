/*
*	DKU Operating System Lab
*		Lab1(Scheduler Algorithm Simulator)
*		Student id : 32194747
*		Student name : Choi Jiyun
*
*	lab1_sched.c :
*		- Lab1 source file.
*		- Must contains scueduler algorithm function'definition.
*
*/

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>

#include "lab1_sched_types.h"

/*
 * you need to implement FCFS, RR, SPN, SRT, HRRN, MLFQ scheduler.
 */

void process1() // ù��° ���μ��� ���̽�
{
    Task[0].name = 'A';
    Task[0].arrival = 0;
    Task[0].service = 3;
    Task[0].runtime[0] = 0;
    Task[0].runtime[1] = 0;
    Task[0].runtime[2] = 0;
    Task[0].r_run = 0;

    Task[1].name = 'B';
    Task[1].arrival = 2;
    Task[1].service = 6;
    Task[1].runtime[0] = 0;
    Task[1].runtime[1] = 0;
    Task[1].runtime[2] = 0;
    Task[1].r_run = 0;

    Task[2].name = 'C';
    Task[2].arrival = 4;
    Task[2].service = 4;
    Task[2].runtime[0] = 0;
    Task[2].runtime[1] = 0;
    Task[2].runtime[2] = 0;
    Task[2].r_run = 0;

    Task[3].name = 'D';
    Task[3].arrival = 6;
    Task[3].service = 5;
    Task[3].runtime[0] = 0;
    Task[3].runtime[1] = 0;
    Task[3].runtime[2] = 0;
    Task[3].r_run = 0;

    Task[4].name = 'E';
    Task[4].arrival = 8;
    Task[4].service = 2;
    Task[4].runtime[0] = 0;
    Task[4].runtime[1] = 0;
    Task[4].runtime[2] = 0;
    Task[4].r_run = 0;

    char Print[200] = { '\0' };
}
void process2() //�ι�° ���μ��� 
{
    Task[0].name = 'A';
    Task[0].arrival = 0;
    Task[0].service = 2;
    Task[0].runtime[0] = 0;
    Task[0].runtime[1] = 0;
    Task[0].runtime[2] = 0;
    Task[0].r_run = 0;

    Task[1].name = 'B';
    Task[1].arrival = 3;
    Task[1].service = 7;
    Task[1].runtime[0] = 0;
    Task[1].runtime[1] = 0;
    Task[1].runtime[2] = 0;
    Task[1].r_run = 0;

    Task[2].name = 'C';
    Task[2].arrival = 7;
    Task[2].service = 10;
    Task[2].runtime[0] = 0;
    Task[2].runtime[1] = 0;
    Task[2].runtime[2] = 0;
    Task[2].r_run = 0;

    Task[3].name = 'D';
    Task[3].arrival = 13;
    Task[3].service = 5;
    Task[3].runtime[0] = 0;
    Task[3].runtime[1] = 0;
    Task[3].runtime[2] = 0;
    Task[3].r_run = 0;

    Task[4].name = 'E';
    Task[4].arrival = 17;
    Task[4].service = 2;
    Task[4].runtime[0] = 0;
    Task[4].runtime[1] = 0;
    Task[4].runtime[2] = 0;
    Task[4].r_run = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int power(int x, int y)
{
    int result = 1;
    while (y)
    {
        if (y & 1)
        {
            result *= x;
        }
        y >>= 1;
        x *= x;
    }

    return result;

} //�������� ���� �ϱ� ���� �Լ� 

void InitQueue(Queue* queue)
{
    queue->front = queue->rear = NULL;  //front�� rear�� NULL�� ����
    queue->count = 0;                   //���� ������ 0���� ����
} //queue�� 

int IsEmpty(Queue* queue)
{
    return queue->count == 0;          //���� ������ 0�̸� �� ����
}

void Enqueue(Queue* queue, process* data)
{
    Node* now = (Node*)malloc(sizeof(Node));    //��� ����
    now->data = data;                           //������ ����
    now->link = NULL;

    if (IsEmpty(queue))                         //ť�� ������� ��
    {
        queue->front = now;                     //�� ���� now�� ����       
    }
    else                                        //������� ���� ��
    {
        queue->rear->link = now;                //�� ���� ������ now�� ����
    }
    queue->rear = now;                          //�� �ڸ� now�� ����   
    queue->count++;                             //���� ������ 1 ����
}

Node* Dequeue(Queue* queue)
{
    Node* re = 0;
    Node* now;
    if (IsEmpty(queue))         //ť�� ����� ��
    {
        return re;
    }
    now = queue->front;         // front ���� ��带 now�� ���
    re = now;                   //��ȯ�� ���� now�� data�� ����
    queue->front = now->link;   //�� ���� now�� ���� ���� ����
    free(now);                  //now �Ҹ�
    queue->count--;             //���� ������ 1 ����
    return re;
}

void Show() {
    char p_name[] = { 'A', 'B', 'C', 'D', 'E' };
    for (int j = 0; j < 5; j++) {
        int i = 0;
        printf("%c ", p_name[j]);
        while (Print[i] != '\0') {
            if (Print[i] == p_name[j]) {
                printf("�� ");
                i++;
            }
            else {
                if (Print[i] != p_name[j]) {
                    printf("�� ");
                    i++;
                }
                continue;
            }
        }
        printf("\n");
    }
   
} // ������ �����층�� ���� �׸��� �׷��ִ� �Լ� 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FIFO(process a, process b, process c, process d, process e) {
    int time = a.service + b.service + c.service + d.service + e.service;
    int print_count = 0;
    int time_count = 0;

    while (time != 0) {
        int pcs;
        for (int i = 0; i < 5; i++) { // ���񽺸� �������� ���� ���μ��� �ϳ� ����
            if (Task[i].r_run != Task[i].service) {
                pcs = i;
                break;
            }
        }

        for (int i = 0; i < 5; i++) { // ���õ� ���μ������� ���� ������ ���μ����� �ִ��� Ȯ�� �� ������ ���μ��� ����
            if ((Task[i].arrival < Task[pcs].arrival) && (Task[i].r_run != Task[i].service)) {
                pcs = i;
            }
        }

        for (int i = 0; i < Task[pcs].service; i++) {
            Print[print_count] = Task[pcs].name;
            print_count++;
            time_count++;
            time--;
            Task[pcs].r_run++;
        }

        int turnaround_time = Task[pcs].arrival + Task[pcs].service; // �����ð��� ���񽺽ð��� ���Ѵ�

        while (1) { // ���� ���μ����� ������ ���� ���μ����� �����Ҷ����� ������ ������� ���� �� ������ ������ ��ĭ
            int count = 0;
            for (int i = 0; i < 5; i++) {
                if (i == pcs) {
                    continue;
                }
                if (turnaround_time >= Task[i].arrival) { // �����ð��� ���񽺽ð��� ���� ������ �ٸ� task�� arrival�� ������ count++
                    count++;
                }
            }
            if (count > 0) { // �� ���� task�� turnaround���� �������� ������ ������ ������ �ʴ´�
                break;
            }
            turnaround_time++; // turnaround���� �������� �����Ƿ� ������ ����� �����ϴ� �ٸ� task�� �����ϱ� ���� turnaround++
            Print[print_count] = 'X';
            print_count++;
        }
    }
    Show();
}


void RR(process a, process b, process c, process d, process e, int q)
{
    int time_Slice = q; //Ÿ�� ����
    int time_count = 0; // ���� ī��Ʈ
    int time = a.service + b.service + c.service + d.service + e.service;
    Queue RR_Queue; // RR�� ť ����
    InitQueue(&RR_Queue);

    for (int i = 0; i < 5; i++)
    {
        if (Task[i].arrival == 0)
        {
            Enqueue(&RR_Queue, &Task[i]);
        }
    }//�����ð��� 0�� ���� Enqueue

    while (time != 0)
    {
        if (!IsEmpty(&RR_Queue))
        {
            Print[time_count] = RR_Queue.front->data->name;
            RR_Queue.front->data->service--;
            RR_Queue.front->data->runtime[0]++;
            time_count++;
            time--;
        }  // ť�� ���μ����� �ִ� ��� print�迭�� �̸� ����, service time ����, runtime ����
        else if (IsEmpty(&RR_Queue))
        {
            Print[time_count] = 'X';
            time_count++;
        }  // ť�� ����� ��� print�迭�� X���� �� time_count ����

        for (int i = 0; i < 5; i++)
        {
            if (time_count == Task[i].arrival)
            {
                Enqueue(&RR_Queue, &Task[i]);
            }
        } // �����߿� ������ ���μ����� �ִ��� �˻� 

        if (RR_Queue.front->data->runtime[0] == 0) // ������ ����� Ư���� ��쿡 Print�迭�� �̸�����, service time ����, runtime ����
        {
            Print[time_count] = RR_Queue.front->data->name;
            RR_Queue.front->data->service--;
            RR_Queue.front->data->runtime[0]++;
            time_count++;

            for (int i = 0; i < 5; i++)
            {
                if (time_count == Task[i].arrival)
                {
                    Enqueue(&RR_Queue, &Task[i]);
                }
            }
            time--; // time ����
        }
        if (RR_Queue.front->data->service != 0 && (RR_Queue.front->data->runtime[0]) % (time_Slice) == 0)
        {
            Enqueue(&RR_Queue, RR_Queue.front->data);
            Dequeue(&RR_Queue);
        }// ���� �ð��� �������� Ÿ�������� �ʰ��� ��� �ٽ� �ڷ� ����
        else if ((RR_Queue.front->data->service == 0))
        {
            Dequeue(&RR_Queue);
        } //���� Ÿ���� �ʰ��� ��� ť���� ��
    }

    Show();
}


void SJF(process a, process b, process c, process d, process e) 
{
    int time = a.service + b.service + c.service + d.service + e.service;
    int print_count = 0;
    int time_count = 0;

    while (time != 0) {
        int pcs;
        for (int i = 0; i < 5; i++) { // ���񽺸� �������� ���� ���μ��� �ϳ� ����
            if (Task[i].r_run != Task[i].service) {
                pcs = i;
                break;
            }
        }

        for (int i = 0; i < 5; i++) { // ���õ� ���μ������� ª�� ���μ����� �ִ��� Ȯ�� �� ������ ���μ��� ����
            if ((Task[i].arrival <= time_count) && (Task[i].service < Task[pcs].service) && (Task[i].r_run != Task[i].service)) {
                pcs = i;
            }
        }

        for (int i = 0; i < Task[pcs].service; i++) {
            Print[print_count] = Task[pcs].name;
            print_count++;
            time_count++;
            time--;
            Task[pcs].r_run++;
        }

        int turnaround_time = Task[pcs].arrival + Task[pcs].service; // �����ð��� ���񽺽ð��� ���Ѵ�

        while (1) { // ���� ���μ����� ������ ���� ���μ����� �����Ҷ����� ������ ������� ���� �� ������ ������ ��ĭ
            int count = 0;
            for (int i = 0; i < 5; i++) {
                if (i == pcs) {
                    continue;
                }
                if (turnaround_time >= Task[i].arrival) { // �����ð��� ���񽺽ð��� ���� ������ �ٸ� task�� arrival�� ������ count++
                    count++;
                }
            }
            if (count > 0) { // �� ���� task�� turnaround���� �������� ������ ������ ������ �ʴ´�
                break;
            }
            turnaround_time++; // turnaround���� �������� �����Ƿ� ������ ����� �����ϴ� �ٸ� task�� �����ϱ� ���� turnaround++
            Print[print_count] = 'X';
            print_count++;
        }
    }

    Show();
}


void MLFQ(process a, process b, process c, process d, process e, int q) {
    int time_Slice = q;
    int time_count = 0;
    int time = a.service + b.service + c.service + d.service + e.service;

    Queue Priorirty_1;   // �켱������ ���� ť 3�� ����
    Queue Priorirty_2;
    Queue Priorirty_3;

    InitQueue(&Priorirty_1);
    InitQueue(&Priorirty_2);
    InitQueue(&Priorirty_3);

    for (int i = 0; i < 5; i++) {
        if (0 == Task[i].arrival)
            Enqueue(&Priorirty_1, &Task[i]);
    }//�����ð��� 0�� ���� 1�� ť�� ����

    while (time != 0) {
        ////////////////////////////////////////////1��° �켱������ ������ 
        if (!IsEmpty(&Priorirty_1)) {
            for (int i = 0; i < power(time_Slice, 0); i++) {        //Ÿ�� �����̽� ��ŭ ����
                Print[time_count] = Priorirty_1.front->data->name;  // Print�迭�� �̸�����
                Priorirty_1.front->data->service--;                 // service Ÿ�� ����
                Priorirty_1.front->data->runtime[0]++;              // ���� ����ð� ����
            }
            time_count++;
            time--;
        }
        else if (IsEmpty(&Priorirty_1)) {   // ť�� �����
            Print[time_count] = 'X';        // Print�迭�� �̸����� X
            time_count++;
        }
        for (int i = 0; i < 5; i++) {
            if (time_count == Task[i].arrival)
                Enqueue(&Priorirty_1, &Task[i]);
        } // ���� �� ������ ���μ��� �˻� �� Enqueue 
        if (Priorirty_1.front->data->runtime[0] == 0) {  // ������ ��� print�迭�� �̸� ����, service ����, runtime ����
            for (int i = 0; i < power(time_Slice, 0); i++) {
                Print[time_count] = Priorirty_1.front->data->name;
                Priorirty_1.front->data->service--;
                Priorirty_1.front->data->runtime[0]++;
            }

            time_count++;
            for (int i = 0; i < 5; i++) {
                if (time_count == Task[i].arrival) {
                    Enqueue(&Priorirty_1, &Task[i]);    // ���� �� ������ ���μ��� �˻� ��  Enqueue
                }
            }
            time--;
        }
        if (!IsEmpty(&Priorirty_1) && Priorirty_1.front->data->service != 0 && (Priorirty_1.front->data->runtime[0]) % (int)power(time_Slice, 0) == 0) { // ����ð��� ������ �ʾ����� Ÿ�ӽ����̽��� ���� 
            if (Priorirty_1.front->link == NULL && IsEmpty(&Priorirty_2) && IsEmpty(&Priorirty_3)) {
                Enqueue(&Priorirty_1, Priorirty_1.front->data);
                Dequeue(&Priorirty_1);
            }  // ť�� ȥ�� �ִ� ��� �켱����1 ť��, ������ Enqueue, �Ŀ� �켱����1 ť Dequeue
            else {
                Enqueue(&Priorirty_2, Priorirty_1.front->data);
                Dequeue(&Priorirty_1);
            } // �ƴ� ��� �켱����2ť�� �켱����1�� ������ Enqueue, �Ŀ� �켱����1 ť Dequeue
        }
        else if ((Priorirty_1.front->data->service == 0))
            Dequeue(&Priorirty_1);
        ////////////////////////////////////////////////////2��° 
        while (IsEmpty(&Priorirty_1)) {
            if (!IsEmpty(&Priorirty_2)) {
                for (int i = 0; i < power(time_Slice, 1); i++) {
                    Print[time_count] = Priorirty_2.front->data->name;
                    Priorirty_2.front->data->service--;
                    Priorirty_2.front->data->runtime[1]++;

                    time_count++;
                    time--;
                    for (int i = 0; i < 5; i++) {
                        if (time_count == Task[i].arrival)
                            Enqueue(&Priorirty_1, &Task[i]);
                    }
                    if (IsEmpty(&Priorirty_1))
                        break;
                    if (Priorirty_2.front->data->service == 0)
                        break;
                }
            }
            if (!IsEmpty(&Priorirty_2) && Priorirty_2.front->data->service != 0 && ((Priorirty_2.front->data->runtime[1]) % (int)power(time_Slice, 1)) == 0) {
                Enqueue(&Priorirty_3, Priorirty_2.front->data);
                Dequeue(&Priorirty_2);
            }
            else if (!IsEmpty(&Priorirty_2) && (Priorirty_2.front->data->service == 0))
                Dequeue(&Priorirty_2);
            else if (IsEmpty(&Priorirty_2))
                break;
        }
        /////////////////////////////////////////////////// 3��° 
        while (IsEmpty(&Priorirty_1) && IsEmpty(&Priorirty_2)) {
            if (!IsEmpty(&Priorirty_3)) {
                for (int i = 0; i < power(time_Slice, 2); i++) {
                    Print[time_count] = Priorirty_3.front->data->name;
                    Priorirty_3.front->data->service--;
                    Priorirty_3.front->data->runtime[2]++;

                    time_count++;
                    time--;
                    for (int i = 0; i < 5; i++) {
                        if (time_count == Task[i].arrival)
                            Enqueue(&Priorirty_1, &Task[i]);
                    }
                    if (IsEmpty(&Priorirty_1))
                        break;
                    if (Priorirty_3.front->data->service == 0)
                        break;
                }
            }
            if (!IsEmpty(&Priorirty_3) && Priorirty_3.front->data->service != 0 && (Priorirty_3.front->data->runtime[2]) % (int)(power(time_Slice, 2)) == 0) {
                Enqueue(&Priorirty_3, Priorirty_3.front->data);
                Dequeue(&Priorirty_3);
            }
            else if (!IsEmpty(&Priorirty_3) && (Priorirty_3.front->data->service == 0))
                Dequeue(&Priorirty_3);
            if (IsEmpty(&Priorirty_3))
                break;
        }
    }

    Show();

}

void LOTTERY(int min, int max, int A_ticket, int B_ticket)
{
    int random_num[20];
    srand(time(NULL)); // ���� �ʱ�ȭ
    printf("  ");
    for (int i = 0; i < 20; i++) {
        random_num[i] = rand() % (max + 1) + min; // min ~ max ������ ���� ����
        printf("%2d ", random_num[i]);
    }
    printf("\n");
    for (int i = 0; i < 2; i++) {
        printf("%c ", 65 + i);
        for (int j = 0; j < 20; j++) {
            if (i == 0 && random_num[j] < A_ticket) printf("��  "); // A ticket ����
            else if (i == 1 && random_num[j] >= A_ticket) printf("��  "); // B ticket ����
            else printf("��  ");
        }
        printf("\n");
    }
}