/*
*       DKU Operating System Lab
*           Lab1 (Scheduler Algorithm Simulator)
*           Student id : 32194747
*           Student name : Choi Jiyun
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm test code.
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
 * you need to implement scheduler simlator test code.
 *
 */

int main(int argc, char* argv[]) {
    // 1번째 케이스에 대한 테스트
    process1();
    printf("-------------------------  FIFO  -------------------------\n");
    FIFO(Task[0], Task[1], Task[2], Task[3], Task[4]);

    process1();
    printf("----------------------  RR ( q = 1 ) ----------------------\n");
    RR(Task[0], Task[1], Task[2], Task[3], Task[4], 1);

    process1();
    printf("----------------------  RR ( q = 4 ) ----------------------\n");
    RR(Task[0], Task[1], Task[2], Task[3], Task[4], 4);

    process1();
    printf("--------------------------  SJF  --------------------------\n");
    SJF(Task[0], Task[1], Task[2], Task[3], Task[4]);

    process1();
    printf("---------------------  MLFQ ( q = 1 ) ---------------------\n");
    MLFQ(Task[0], Task[1], Task[2], Task[3], Task[4], 1);

    process1();
    printf("--------------------  MLFQ ( q = 2^i ) --------------------\n");
    MLFQ(Task[0], Task[1], Task[2], Task[3], Task[4], 2);

    // 2번째 케이스에 대한 테스트
    process2();
    printf("-------------------------  FIFO  -------------------------\n");
    FIFO(Task[0], Task[1], Task[2], Task[3], Task[4]);

    process2();
    printf("----------------------  RR ( q = 1 ) ----------------------\n");
    RR(Task[0], Task[1], Task[2], Task[3], Task[4], 1);

    process2();
    printf("----------------------  RR ( q = 4 ) ----------------------\n");
    RR(Task[0], Task[1], Task[2], Task[3], Task[4], 4);

    process2();
    printf("--------------------------  SJF  --------------------------\n");
    SJF(Task[0], Task[1], Task[2], Task[3], Task[4]);

    process2();
    printf("---------------------  MLFQ ( q = 1 ) ---------------------\n");
    MLFQ(Task[0], Task[1], Task[2], Task[3], Task[4], 1);

    process2();
    printf("--------------------  MLFQ ( q = 2^i ) --------------------\n");
    MLFQ(Task[0], Task[1], Task[2], Task[3], Task[4], 2);

    // [보너스] LOTTERY 1번째 케이스
    printf("\n------------------------  LOTTERY  ------------------------\n");
    LOTTERY(0, 99, 75, 25);

    // [보너스] LOTTERY 2번째 케이스
    printf("\n------------------------  LOTTERY  ------------------------\n");
    LOTTERY(0, 99, 80, 20);
}
