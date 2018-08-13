#include <stdlib.h>

int main() {
    void *p = malloc(8);
    free(p);
    free(p); // double free might cause crash
}
