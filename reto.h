
#ifndef RETO_H
#define RETO_H

/* Capacidades maximas del programa */
#define MAX_REGISTROS 20
#define MAX_MUESTRAS 8
#define MAX_NOMBRE 16

/* Configuracion de cada registro */
typedef struct {
    int tipo;
    int p;
} Configuracion;

/* Informacion de cada unidad */
typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    Configuracion config;
    int score;
    int estado;
} Registro;

/* Prototipos de las funciones */
int calcular(const int muestras[], int m, int tipo, int p,
             const char nombre[], int *estado);

int total_rec(const Registro registros[], int n);

void ordenar(Registro registros[], int n);

void ordenar_por_id(Registro registros[], int n);

int buscar(const Registro registros[], int n, int id);

#endif
