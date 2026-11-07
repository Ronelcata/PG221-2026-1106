# PG221 - Indice de caracteres de una editorial

## 1. Descripcion del problema

El programa consiste en desarrollar una aplicacion de consola
en lenguaje C que procese varios registros de una editorial.

Cada registro contiene un identificador, un nombre, una
configuracion y una serie de muestras numericas.

El objetivo es calcular una puntuacion (score) dependiendo
de los caracteres seleccionados del nombre y los valores
de las muestras.

## 2. Datos de entrada

El programa recibe:

- n: cantidad de registros.
- m: cantidad de muestras por registro.
- q: identificador que se desea buscar.
- id: identificador unico de cada registro.
- nombre: cadena de caracteres.
- tipo: indica si se evaluan vocales o digitos.
- p: posicion inicial para seleccionar caracteres.
- x: valores numericos de las muestras.

## 3. Restricciones

- La cantidad de registros debe estar entre 1 y 20.
- La cantidad de muestras debe estar entre 1 y 8.
- Los identificadores deben estar entre 1 y 9999.
- Los nombres pueden tener entre 1 y 15 caracteres.
- El tipo solamente puede ser 0 o 1.
- La posicion p debe estar entre 0 y 100.
- Cada muestra debe estar entre 0 y 100.
- No se permiten identificadores repetidos.

## 4. Procesamiento

Para cada registro se debe:

1. Obtener la longitud del nombre.
2. Recorrer las muestras.
3. Seleccionar el caracter correspondiente utilizando
   la posicion (j + p) % L.
4. Comprobar si el caracter cumple la condicion del tipo.
5. Sumar el valor de la muestra cuando corresponda.
6. Actualizar el estado cuando exista al menos
   un caracter que cumpla la condicion.

Cada registro debe calcularse independientemente.

## 5. Resultados esperados

El programa debe mostrar:

- Los registros en su orden original.
- El identificador, nombre en mayusculas, score y estado.
- La suma total de los scores.
- Los identificadores ordenados por score descendente
  y por ID ascendente en caso de empate.
- El resultado de la busqueda del identificador q.

Si la entrada contiene algun dato invalido,
el programa debe imprimir unicamente ERROR.

## 6. Funciones principales

- calcular(): calcula el score y el estado.
- total_rec(): suma los scores mediante recursividad.
- ordenar(): organiza los registros.
- buscar(): realiza una busqueda binaria por identificador.

## 7. Estructuras de datos

Se utilizaran:

- Una matriz de enteros para almacenar las muestras.
- Una estructura Configuracion para guardar tipo y p.
- Una estructura Registro para almacenar los datos de cada unidad.
- Una copia de los registros para realizar la busqueda ordenada por ID.

## 8. Pseudocodigo

INICIO

Leer n, m y q.

Validar que los valores esten dentro de sus rangos.

PARA cada registro:
    Leer identificador.
    Comprobar que sea valido y no este repetido.
    Leer nombre y validar sus caracteres.
    Convertir nombre a mayusculas.
    Leer tipo y posicion.
    Validar configuracion.
    Leer las muestras.
    Validar cada muestra.

Si existe algun error:
    Imprimir ERROR.
    Terminar.

PARA cada registro:
    Calcular score y estado.

Calcular el total mediante recursividad.
Calcular la media utilizando double.

Crear copias de los registros.
Ordenar una copia por score.
Ordenar otra copia por identificador.
Realizar busqueda binaria de q.

Imprimir los registros en orden original.
Imprimir TOTAL, ORDER y FIND.

FIN

## 9. Validacion

Se ejecutaron seis pruebas publicas:
- Grupo 1: calculo normal.
- Grupo 2: valores minimos.
- Grupo 3: empates y busqueda existente.
- Grupo 4: secuencias y configuraciones.
- Grupo 5: busqueda ausente y reinicio de acumuladores.
- Grupo 6: entrada invalida.

Resultado obtenido: 6/6 pruebas correctas.

Tambien se ejecutaron cuatro pruebas propias:
- P1: dos registros con diferentes configuraciones.
- P2: identificador y valores en limites superiores.
- P3: score cero y busqueda sin coincidencia.
- P4: identificadores duplicados.

Resultado obtenido: 4/4 pruebas correctas.

La compilacion se realizo con GCC y las opciones
-std=c11 -Wall -Wextra -Wpedantic.

Las pruebas se ejecutaron utilizando evaluar.py.