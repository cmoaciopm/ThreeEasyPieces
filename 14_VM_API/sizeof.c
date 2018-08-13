#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int *x = malloc(10 * sizeof(int));
    printf("%zu\n", sizeof(x));
    free(x);

    int y[10];
    printf("%zu\n", sizeof(y));

    char *s = "abc";
    printf("strlen(s): %zu\n", strlen(s));
    printf("Characters are: %c, %c, %c, %d\n", *s, *(s+1), *(s+2), *(s+3));

    char t[] = "abc";
    printf("strlen(t): %zu, sizeof(t): %zu\n", strlen(t), sizeof(t));
    printf("Characters are: %c, %c, %c, %d\n", t[0], t[1], t[2], t[3]);

    t[1] = '\0';
    printf("strlen(t): %zu, sizeof(t): %zu\n", strlen(t), sizeof(t));
    printf("Characters are: %c, %d, %c, %d\n", t[0], t[1], t[2], t[3]);
}
