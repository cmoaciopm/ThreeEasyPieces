#include <string.h>
#include <stdio.h>

int main() {
    char *src = "hello";
    char *dst; // unallocated!
    strcpy(dst, src); // segfault and die
    printf("Dest string: %s\n", dst);
}
