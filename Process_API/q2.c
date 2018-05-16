#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid:%d)\n", getpid());

    int fd = open("./q2.c", O_RDONLY);
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd2 = open("./q2.output", O_RDWR | O_CREAT | O_TRUNC, mode);

    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	printf("Hello, I am child (pid:%d)\n", getpid());
        char buf[16];
        ssize_t size = read(fd, buf, 15);
	printf("From child (pid:%d), read from file [%s]\n", getpid(), buf);
        char *content = "abc\n";
        printf("length is %d\n", strlen(content));
        write(fd2, content, strlen(content));
	printf("From child (pid:%d), write [%s] to file\n", getpid(), content);
    } else {
	printf("Hello, I am parent of %d (pid:%d)\n", rc, getpid());
        char buf[16];
        ssize_t size = read(fd, buf, 15);
	printf("From parent (pid:%d), read from file [%s]\n", getpid(), buf);
        char *content = "xyz\n";
        write(fd2, content, strlen(content));
	printf("From parent (pid:%d), write [%s] to file\n", getpid(), content);
    }
    return 0;
}
