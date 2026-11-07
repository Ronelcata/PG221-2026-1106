
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

int calcular(const int muestras[], int m, int tipo, int p,
             const char nombre[], int *estado) {

    int score = 0;
    int j;
    int posicion;
    int caracter;
    int longitud = (int)strlen(nombre);

    *estado = 0;

    if (longitud == 0) {
        return 0;
    }

    for (j = 0; j < m; j++) {

        posicion = (j + p) % longitud;
        caracter = toupper((unsigned char)nombre[posicion]);

        if (tipo == 0) {
            if (caracter == 'A' || caracter == 'E' ||
                caracter == 'I' || caracter == 'O' ||
                caracter == 'U') {

                score += muestras[j];
                *estado = 1;
            }
        }
        else if (tipo == 1) {
            if (caracter >= '0' && caracter <= '9') {
                score += muestras[j];
                *estado = 1;
            }
        }
    }

    return score;
}

int leer_nombre(char nombre[MAX_NOMBRE]) {

    int caracter;
    int largo = 0;
    int excedido = 0;

    do {
        caracter = getchar();
    } while (caracter != EOF && isspace((unsigned char)caracter));

    if (caracter == EOF) {
        return 0;
    }

    while (caracter != EOF && !isspace((unsigned char)caracter)) {

        if (largo < MAX_NOMBRE - 1) {
            nombre[largo] = (char)caracter;
        } else {
            excedido = 1;
        }

        largo++;
        caracter = getchar();
    }

    if (excedido || largo == 0) {
        return 0;
    }

    nombre[largo] = '\0';

    return 1;
}

int nombre_valido(const char nombre[]) {

    int i;
    char c;

    for (i = 0; nombre[i] != '\0'; i++) {

        c = nombre[i];

        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              c == '_')) {

            return 0;
        }
    }

    return 1;
}

void convertir_mayusculas(char nombre[]) {

    int i;

    for (i = 0; nombre[i] != '\0'; i++) {
        if (nombre[i] >= 'a' && nombre[i] <= 'z') {
            nombre[i] -= ('a' - 'A');
        }
    }
}

int id_repetido(const Registro registros[],
                int cantidad, int id) {

    int i;

    for (i = 0; i < cantidad; i++) {
        if (registros[i].id == id) {
            return 1;
        }
    }

    return 0;
}

int main(void) {

    int n, m, q;
    int i, j;
    char extra;

    Registro registros[MAX_REGISTROS];
    int muestras[MAX_REGISTROS][MAX_MUESTRAS];

    if (scanf("%d %d %d", &n, &m, &q) != 3) {
        goto error;
    }

    if (n < 1 || n > MAX_REGISTROS ||
        m < 1 || m > MAX_MUESTRAS ||
        q < 1 || q > 9999) {
        goto error;
    }

    for (i = 0; i < n; i++) {

        if (scanf("%d", &registros[i].id) != 1) {
            goto error;
        }

        if (registros[i].id < 1 ||
            registros[i].id > 9999 ||
            id_repetido(registros, i, registros[i].id)) {
            goto error;
        }

        if (!leer_nombre(registros[i].nombre)) {
            goto error;
        }

        if (!nombre_valido(registros[i].nombre)) {
            goto error;
        }

        convertir_mayusculas(registros[i].nombre);

        if (scanf("%d %d",
                  &registros[i].config.tipo,
                  &registros[i].config.p) != 2) {
            goto error;
        }

        if ((registros[i].config.tipo != 0 &&
             registros[i].config.tipo != 1) ||
            registros[i].config.p < 0 ||
            registros[i].config.p > 100) {
            goto error;
        }

        for (j = 0; j < m; j++) {

            if (scanf("%d", &muestras[i][j]) != 1) {
                goto error;
            }

            if (muestras[i][j] < 0 || muestras[i][j] > 100) {
                goto error;
            }
        }

        registros[i].score = 0;
        registros[i].estado = 0;
    }

    if (scanf(" %c", &extra) == 1) {
        goto error;
    }

    for (i = 0; i < n; i++) {
        registros[i].score = calcular(
            muestras[i],
            m,
            registros[i].config.tipo,
            registros[i].config.p,
            registros[i].nombre,
            &registros[i].estado
        );
    }

    for (i = 0; i < n; i++) {
        printf("%d %s %d %d\n",
               registros[i].id,
               registros[i].nombre,
               registros[i].score,
               registros[i].estado);
    }

    return 0;

error:
    printf("ERROR\n");
    return 0;
}
