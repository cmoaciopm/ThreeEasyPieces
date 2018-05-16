#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid:%d)\n", getpid());
    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	printf("Hello, I am child (pid:%d)\n", getpid());
	close(STDOUT_FILENO);
	printf("Can we see this output?\n");
    } else {
	int wc = wait(NULL);
	printf("Hello, I am parent of %d (pid:%d)\n", rc, getpid());
    }
    return 0;
}
