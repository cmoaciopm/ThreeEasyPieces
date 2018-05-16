#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int signum) {
    //printf("Receive signal %d (pid:%d)\n", signum, getpid());
}

int main(int argc, char *argv[]) {
    int parentPid = getpid();
    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	//printf("Hello, I am child (pid:%d)\n", getpid());
        printf("Hello, ");
        kill(parentPid, SIGCONT);
    } else {
	//printf("Hello, I am parent of %d (pid:%d)\n", rc, getpid());
        signal(SIGCONT, sig_handler);
        pause();
        printf("world!\n");
    }
    return 0;
}
