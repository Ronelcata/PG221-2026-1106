
#include <stdio.h>
#include "reto.h"

int main(void) {

    int n, m, q;
    int i, j;

    Registro registros[MAX_REGISTROS];
    int muestras[MAX_REGISTROS][MAX_MUESTRAS];

    /* Leer la cabecera */
    if (scanf("%d %d %d", &n, &m, &q) != 3) {
        printf("ERROR\n");
        return 0;
    }

    /* Validar la cabecera */
    if (n < 1 || n > MAX_REGISTROS ||
        m < 1 || m > MAX_MUESTRAS ||
        q < 1 || q > 9999) {

        printf("ERROR\n");
        return 0;
    }

    /* Leer los registros */
    for (i = 0; i < n; i++) {

        if (scanf("%d %15s %d %d",
                  &registros[i].id,
                  registros[i].nombre,
                  &registros[i].config.tipo,
                  &registros[i].config.p) != 4) {

            printf("ERROR\n");
            return 0;
        }

        /* Leer las muestras de cada registro */
        for (j = 0; j < m; j++) {

            if (scanf("%d", &muestras[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }
        }

        /* Inicializar resultados */
        registros[i].score = 0;
        registros[i].estado = 0;
    }

    return 0;
}
