#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid:%d)\n", getpid());
    int x = 100;
    printf("Before calling fork(), x = %d\n", x);
    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	printf("Hello, I am child (pid:%d), x = %d\n", getpid(), x);
        x = 200;
	printf("Hello, I am child (pid:%d), x = %d\n", getpid(), x);
    } else {
	printf("Hello, I am parent of %d (pid:%d), x = %d\n", rc, getpid(), x);
	x = 300;
	printf("Hello, I am parent of %d (pid:%d), x = %d\n", rc, getpid(), x);
    }
    return 0;
}
