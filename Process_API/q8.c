#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid:%d)\n", getpid());

    int fd[2];
    int pipeRet = pipe(fd);
    if(pipeRet < 0) {
        printf("Creating pipe failed!\n");
        exit(1);
    }

    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	printf("Hello, I am child (pid:%d) planning to read.\n", getpid());
        close(fd[1]); // close write end of the pipe
        dup2(fd[0], STDIN_FILENO);
        char buf[512];
        int len = read(STDIN_FILENO, buf, 512);
        printf("Got message(length = %d) via pipe: [%s]\n", len, buf);
    } else {
        int fork2Rc = fork();
        if(fork2Rc < 0) {
            printf("2nd fork failed\n");
            exit(1);
        } else if(fork2Rc == 0) {
	    printf("Hello, I am child (pid:%d) planning to write.\n", getpid());
            close(fd[0]); // close read end of the pipe
            dup2(fd[1], STDOUT_FILENO);
            printf("This message should be delivered via pipe.");
        } else {
	    printf("Hello, I am parent of %d and %d (pid:%d)\n", rc, fork2Rc, getpid());
	    int wc = waitpid(rc, NULL, 0);
            printf("Child process %d finished.\n", rc);
	    wc = waitpid(fork2Rc, NULL, 0);
            printf("Child process %d finished.\n", fork2Rc);
        }
    }
    return 0;
}
