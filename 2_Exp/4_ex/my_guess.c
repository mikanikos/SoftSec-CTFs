/* my-guess.c */
#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    printf("%d", rand());
    return 0;
}