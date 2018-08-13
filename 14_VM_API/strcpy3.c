#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *src = "hello";
    char *dst = (char *)malloc(strlen(src)); // too small! buffer overflow
    strcpy(dst, src);
    printf("Dest string: %s\n", dst);
}
