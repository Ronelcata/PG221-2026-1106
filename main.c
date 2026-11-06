
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "reto.h"

/* Leer el nombre completo y comprobar su longitud */
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

/* Comprobar que el nombre tenga caracteres permitidos */
int nombre_valido(const char nombre[]) {

    int i;

    for (i = 0; nombre[i] != '\0'; i++) {

        char c = nombre[i];

        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              c == '_')) {

            return 0;
        }
    }

    return 1;
}

/* Convertir el nombre a mayusculas ASCII */
void convertir_mayusculas(char nombre[]) {

    int i;

    for (i = 0; nombre[i] != '\0'; i++) {

        if (nombre[i] >= 'a' && nombre[i] <= 'z') {
            nombre[i] = nombre[i] - ('a' - 'A');
        }
    }
}

/* Verificar si un identificador ya existe */
int id_repetido(const Registro registros[], int cantidad, int id) {

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

    /* Leer la cabecera */
    if (scanf("%d %d %d", &n, &m, &q) != 3) {
        goto error;
    }

    /* Validar la cabecera */
    if (n < 1 || n > MAX_REGISTROS ||
        m < 1 || m > MAX_MUESTRAS ||
        q < 1 || q > 9999) {

        goto error;
    }

    /* Leer y validar cada registro */
    for (i = 0; i < n; i++) {

        if (scanf("%d", &registros[i].id) != 1) {
            goto error;
        }

        /* Validar identificador */
        if (registros[i].id < 1 ||
            registros[i].id > 9999 ||
            id_repetido(registros, i, registros[i].id)) {

            goto error;
        }

        /* Leer y validar nombre */
        if (!leer_nombre(registros[i].nombre)) {
            goto error;
        }

        if (!nombre_valido(registros[i].nombre)) {
            goto error;
        }

        convertir_mayusculas(registros[i].nombre);

        /* Leer configuracion */
        if (scanf("%d %d",
                  &registros[i].config.tipo,
                  &registros[i].config.p) != 2) {

            goto error;
        }

        /* Validar configuracion */
        if ((registros[i].config.tipo != 0 &&
             registros[i].config.tipo != 1) ||
            registros[i].config.p < 0 ||
            registros[i].config.p > 100) {

            goto error;
        }

        /* Leer y validar las muestras */
        for (j = 0; j < m; j++) {

            if (scanf("%d", &muestras[i][j]) != 1) {
                goto error;
            }

            if (muestras[i][j] < 0 ||
                muestras[i][j] > 100) {

                goto error;
            }
        }

        /* Inicializar resultados */
        registros[i].score = 0;
        registros[i].estado = 0;
    }

    /* Detectar tokens adicionales */
    if (scanf(" %c", &extra) == 1) {
        goto error;
    }

    return 0;

error:

    printf("ERROR\n");

    return 0;
}
