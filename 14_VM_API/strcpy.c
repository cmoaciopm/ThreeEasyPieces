#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *src = "hello";
    char *dst = (char *)malloc(strlen(src) + 1);
    strcpy(dst, src);
    printf("Dest string: %s\n", dst);
}
