#include <stdio.h>
#include "std_lol.h"

int main() {
    srand(time(NULL));
    printf("Hello, world!\n");

    fprintf(stdout, "output for fprintf stdout\n");
    fprintf(stderr, "output for fprintf stderr\n");

    FILE *f = fopen("test.txt", "w");
    if (f) {
        fprintf(f, "write the text file for fprintf\n");
        fclose(f);
    }

    return 0;
}