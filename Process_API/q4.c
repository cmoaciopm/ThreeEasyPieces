#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid:%d)\n", getpid());
    int rc = fork();
    if(rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
	exit(1);
    } else if(rc == 0) { // child (new process)
	printf("Hello, I am child (pid:%d)\n", getpid());

        // TODO Refer https://stackoverflow.com/a/20823413/1093344

        char * const envp[] = { "PATH=/abc", NULL };
        // TODO ? 2nd parameter?
        //execl("/bin/ls", "cat", "-l");
        //execlp("ls", "ls", "-l");
        //execle("/bin/ls", "lsa", "-l", NULL, envp);

        char *const myargv[] = { "ls", "-l", NULL };
        //execv("/bin/ls", myargv);
        //execvp("ls", myargv);
        // TODO MacOSX does not have this function
        //execvpe("ls", myargv, envp);

	printf("This shouldn't print out");
    } else {
	int wc = wait(NULL);
	printf("Hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, getpid());
    }
    return 0;
}
