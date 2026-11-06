
#include <stdio.h>
#include "reto.h"

int main(void) {

    int n, m, q;

    if (scanf("%d %d %d", &n, &m, &q) != 3) {
        printf("ERROR\n");
        return 0;
    }

    if (n < 1 || n > MAX_REGISTROS) {
        printf("ERROR\n");
        return 0;
    }

    if (m < 1 || m > MAX_MUESTRAS) {
        printf("ERROR\n");
        return 0;
    }

    if (q < 1 || q > 9999) {
        printf("ERROR\n");
        return 0;
    }


    return 0;
}

