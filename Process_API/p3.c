#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid:%d)\n", getpid());
    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	printf("Hello, I am child (pid:%d)\n", getpid());
	char *myargs[3];
	myargs[0] = strdup("wc");
	myargs[1] = strdup("p3.c");
	myargs[2] = NULL;
	execvp(myargs[0], myargs);
	printf("This shouldn't print out");
    } else {
	int wc = wait(NULL);
	printf("Hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, getpid());
    }
    return 0;
}
