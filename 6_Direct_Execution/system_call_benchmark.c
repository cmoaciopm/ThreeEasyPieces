#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ITER_COUNT (1000 * 1000)
#define BILLION (1000 * 1000 * 1000L)

void systemCall() {
    struct timespec start;
    struct timespec end;
    long sum = 0;

    char buf[0];
    for(int i = 0; i < ITER_COUNT; i++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        read(STDIN_FILENO, buf, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);
        sum += BILLION * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
    }

    double avg = sum / (float)ITER_COUNT;
    printf("System call total = %ld nano-seconds, average time = %f nano-seconds\n", sum, avg);
}

int main(int argc, char *argv[]) {
    systemCall();
}

