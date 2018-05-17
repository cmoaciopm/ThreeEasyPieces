#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void setCpuAffinity(int cpu) {
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);
    int rc = sched_setaffinity(0, sizeof(mask), &mask);
    if (rc == 0) {
        printf("Set affinity successfully.\n");
    } else {
        printf("Set affinity failed.\n");
        exit(1);
    }
}

void contextSwitch() {
    int pipeFd[2];
    int pipeFd2[2];
    int rc = pipe(pipeFd);
    int rc2 = pipe(pipeFd2);
    if(rc == -1 || rc2 == -1) {
        printf("Creating pipe failed!\n");
        exit(1);
    }

    setCpuAffinity(1);
    int forkRc = fork();
    if(forkRc == -1) {
        printf("Creating child process failed!\n");
        exit(1);
    } else if(forkRc == 0) { // child process
        setCpuAffinity(1);
        close(pipeFd[1]);
        close(pipeFd2[0]);

        char buf[512];
        read(pipeFd[0], buf, 512);

        char *msg = "Hello, I'm child process";
        write(pipeFd2[1], msg, strlen(msg));

        printf("Child process, receive msg from pipe: %s.\n", buf);
    } else {
        close(pipeFd[0]);
        close(pipeFd2[1]);

        char *msg = "Hello, I'm main process";
        write(pipeFd[1], msg, strlen(msg));

        char buf[512];
        read(pipeFd2[0], buf, 512);

        printf("Parent process, receive msg from pipe: %s.\n", buf);
    }
}

int main(int argc, char *argv[]) {
    contextSwitch();
}

