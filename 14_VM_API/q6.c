#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *data = malloc(100 * sizeof(int));
    free(data);
    printf("The 1st element of array is %d\n", data[0]);
}
