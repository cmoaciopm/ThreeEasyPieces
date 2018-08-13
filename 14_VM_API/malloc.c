#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(int*) = %zu\n", sizeof(int*));
    printf("sizeof(long*) = %zu\n", sizeof(long*));

    int* p = (int*)malloc(sizeof(int));
    long* p2 = (long*)malloc(sizeof(long));
    int* p3 = (int*)malloc(sizeof(int));
    void* p4 = malloc(32);
    int* p5 = (int*)malloc(sizeof(int));

    printf("Address of p: %p, heap address of p1 pointed int: %p\n", &p, p);
    printf("Address of p2: %p, heap address of p2 pointed long: %p\n", &p2, p2);
    printf("Address of p3: %p, heap address of p3 pointed int: %p\n", &p3, p3);
    printf("Address of p4: %p, heap address of p4 pointed int: %p\n", &p4, p4);
    printf("Address of p5: %p, heap address of p5 pointed int: %p\n", &p5, p5);

    *p = 100;
    *p2 = 200L;

    printf("int value of p is %d\n", *p);
    printf("long value of p2 is %ld\n", *p2);
    printf("int value of p3 is %d\n", *p3);

    free(p);
    free(p2);
    free(p3);
    free(p4);
    free(p5);
    return 0;
}
