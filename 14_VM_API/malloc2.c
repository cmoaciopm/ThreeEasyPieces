#include <stdio.h>
extern int malloc();

int main() {
    int ret = malloc();
    printf("Return value of my own malloc() is = %d\n", ret);
}
