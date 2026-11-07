# PG221 - Índice de caracteres de una editorial

**Asignatura:** Programación para Mecatrónicos  
**Estudiante:** Ronel Catalino Hernandez  
**Matrícula:** 2026-1106  
**Correo institucional:** 20261106@itla.edu.do  
**Lenguaje:** C11

## 1. Descripción del proyecto

Este proyecto consiste en desarrollar un programa de consola en lenguaje C que procesa registros de una editorial.

Cada registro contiene un identificador, un nombre, una configuración y una cantidad determinada de muestras numéricas.

El programa calcula un score dependiendo de los caracteres seleccionados del nombre y los valores de las muestras.

También permite calcular el total de los scores, ordenar los registros y buscar un identificador mediante búsqueda binaria.

## 2. Estructura del proyecto

- `main.c`: contiene la función principal, lectura, validaciones y procesamiento.
- `reto.h`: contiene las constantes, estructuras y prototipos.
- `plan.md`: contiene el análisis y pseudocódigo.
- `evaluar.py`: ejecuta automáticamente las pruebas.
- `publicas.json`: contiene los seis casos públicos.
- `pruebas/`: contiene los resultados y pruebas propias.
- `.gitignore`: evita subir ejecutables y archivos objeto.

## 3. Funcionamiento del programa

El programa recibe la cantidad de registros, las muestras por registro y el identificador que se desea buscar.

Para cada registro se selecciona un carácter utilizando la expresión:

`(j + p) % L`

Donde L representa la longitud del nombre.

Existen dos tipos de evaluación:

- Tipo 0: comprueba si el carácter seleccionado es una vocal.
- Tipo 1: comprueba si el carácter seleccionado es un dígito.

Cuando el carácter cumple la condición, su muestra se suma al score y el estado cambia a 1.

El cálculo se realiza independientemente para cada registro.

## 4. Funciones utilizadas

| Función | Descripción |
|---|---|
| `calcular()` | Calcula el score y el estado mediante un apuntador. |
| `total_rec()` | Suma los scores utilizando recursividad. |
| `ordenar()` | Ordena por score descendente e ID ascendente. |
| `ordenar_por_id()` | Ordena una copia de registros por identificador. |
| `buscar()` | Realiza una búsqueda binaria por ID. |
| `leer_nombre()` | Lee y comprueba la longitud del nombre. |
| `nombre_valido()` | Comprueba los caracteres permitidos. |
| `convertir_mayusculas()` | Convierte el nombre a mayúsculas ASCII. |
| `id_repetido()` | Detecta identificadores duplicados. |

## 5. Estructuras de datos

Se utiliza una matriz de enteros de capacidad 20 × 8 para almacenar las muestras.

También se utilizan dos estructuras:

**Configuracion:** contiene `tipo` y `p`.

**Registro:** contiene `id`, `nombre`, `config`, `score` y `estado`.

Se mantienen copias de los registros para realizar el ordenamiento por score y la búsqueda por ID sin modificar el orden original.

## 6. Validaciones

El programa comprueba:

- Cantidad de registros entre 1 y 20.
- Cantidad de muestras entre 1 y 8.
- Identificadores entre 1 y 9999.
- Nombres de 1 a 15 caracteres.
- Tipo igual a 0 o 1.
- Posición entre 0 y 100.
- Muestras entre 0 y 100.
- Identificadores únicos.
- Entrada completa y ausencia de tokens adicionales.

Cuando encuentra una entrada inválida, muestra únicamente `ERROR`.

## 7. Compilación y ejecución

Se utilizó GCC compatible con C11.

Comando de compilación:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto.exe
```

Ejecución en Windows:

```powershell
.\reto.exe < caso.in
```

Ejecutar las pruebas públicas:

```powershell
python evaluar.py publicas.json .\reto.exe
```

Ejecutar las pruebas propias:

```powershell
python evaluar.py .\pruebas\propias\propias.json .\reto.exe
```

## 8. Pruebas realizadas

Se ejecutaron los seis grupos públicos y cuatro pruebas propias.

**Resultados públicos:**

| Grupo | Resultado |
|---|---|
| 1 | OK |
| 2 | OK |
| 3 | OK |
| 4 | OK |
| 5 | OK |
| 6 | OK |

Total: 6 de 6 casos correctos.

**Resultados propios:**

| Prueba | Descripción | Resultado |
|---|---|---|
| P1 | Dos registros con diferentes configuraciones | OK |
| P2 | ID 9999 y límites superiores | OK |
| P3 | Score cero y búsqueda inexistente | OK |
| P4 | Identificadores duplicados | OK |

Total: 4 de 4 casos correctos.

Las evidencias se encuentran en:

- `pruebas/resultados.txt`
- `pruebas/propias/resultados.txt`

## 9. Cálculo de la media

La media se calcula utilizando el tipo `double`:

```c
media = total / (double)n;
```

Algunos resultados obtenidos:

| Grupo | Total | Registros | Media |
|---|---:|---:|---:|
| 1 | 160 | 2 | 80.00 |
| 2 | 0 | 1 | 0.00 |
| 3 | 180 | 3 | 60.00 |
| 4 | 26 | 2 | 13.00 |
| 5 | 0 | 2 | 0.00 |

La media no se imprime en la salida del programa.

## 10. Fuentes consultadas

Corona Nakamura, M. A. y Ancona Valdez, M. de los Á. (2011). *Diseño de algoritmos y su codificación en lenguaje C*. McGraw-Hill, primera edición. ISBN 978-607-15-0571-2.

En particular, se utilizaron como referencia los temas de vectores, matrices, cadenas, funciones, recursividad, estructuras, ordenamiento, búsqueda binaria y apuntadores.

## 11. Historial de commits

Los siguientes hashes corresponden a los nueve commits anteriores a la documentación final.

| N.º | Descripción | Hash completo |
|---:|---|---|
| 1 | Estructura inicial y análisis | `1ec6866f44a2bce89ceb048bf7f6e974b8c9c98a` |
| 2 | Lectura y validación de cabecera | `8fc58ad4d0f702ec3c3a63ba3219d9d843b766b3` |
| 3 | Lectura de registros y muestras | `6e1f809f68264c4a534af44accd67beb5a886b36` |
| 4 | Validación completa de registros | `4c6c49f353fe50ff4d7255c570e30f3e04fb17d1` |
| 5 | Cálculo de score y estado | `98532ec593ab938f7a51c229a70bb78b9872ad9b` |
| 6 | Suma recursiva y cálculo de media | `e7ed4be6ac00c48dbcb1adfb67848c516c7dc05f` |
| 7 | Ordenamiento por score e identificador | `cde54b10bdbde86bf28cf860fc249259135c1400` |
| 8 | Búsqueda binaria por identificador | `4b91cd72307448770721b4a0b43325ef30012a3d` |
| 9 | Banco público y pruebas propias | `c0ef7e2971cbfcc0994646d1054c5ab6226570eb` |

## 12. Repositorio

GitHub: https://github.com/Ronelcata/PG221-2026-1106

**Commit final:** se indicará mediante el hash completo después de publicar la documentación final.