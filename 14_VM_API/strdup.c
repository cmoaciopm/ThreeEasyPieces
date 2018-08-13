#include <stdio.h>
#include <string.h>

int main() {
    char *src = "hello";
    char *dst = strdup(src);
    printf("Dest string: %s\n", dst);
    free(dst);
}
