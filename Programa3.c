#include <stdio.h>  // Biblioteca estándar de entrada y salida
#include <stdlib.h> // Biblioteca para gestión de memoria dinámica
#include <string.h> // Biblioteca para manejo de cadenas

// Función para ingresar departamentos y guardarlos en un archivo
void ingresarDepartamentos(FILE *archivo, int n) {
    char departamento[50]; // Variable para almacenar el nombre del departamento

    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del departamento %d: ", i + 1);
        scanf("%s", departamento); // Leer el nombre del departamento
        // fprintf: Escribe el nombre del departamento en el archivo
        fprintf(archivo, "%s\n", departamento);
    }
}

// Función para comparar dos cadenas en orden inverso (de Z a A)
int comparar(const void *a, const void *b) {
    // Convertir los punteros a cadenas de caracteres
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    // strcmp: Compara las cadenas en orden inverso
    return strcmp(strB, strA);
}

// Función para mostrar los departamentos ordenados de Z a A
void mostrarDepartamentos(FILE *archivo) {
    char *departamentos[100]; // Array de punteros para almacenar los nombres de los departamentos
    int count = 0; // Contador para el número de departamentos

    rewind(archivo); // Mover el puntero del archivo al inicio para empezar a leer desde el principio

    // Leer los nombres de los departamentos del archivo
    while (1) {
        // Asignar memoria para cada nombre de departamento
        departamentos[count] = malloc(50 * sizeof(char));
        if (fscanf(archivo, "%s", departamentos[count]) != 1) {
            free(departamentos[count]); // Liberar la memoria si no se leyó correctamente
            break; // Salir del bucle si no se puede leer más
        }
        count++; // Incrementar el contador
    }

    // Ordenar los nombres de los departamentos de Z a A
    qsort(departamentos, count, sizeof(char *), comparar);

    // Mostrar los nombres de los departamentos ordenados
    for (int i = 0; i < count; i++) {
        printf("%s\n", departamentos[i]);
        free(departamentos[i]); // Liberar la memoria asignada para cada nombre de departamento
    }
}

int main() {
    // fopen: Abre el archivo en modo de lectura/escritura, crea el archivo si no existe
    FILE *archivo = fopen("departamentos.txt", "a+");
    if (archivo == NULL) { // Verificar si el archivo se abrió correctamente
        printf("Error al abrir el archivo.\n");
        return 1; // Salir del programa si hay un error al abrir el archivo
    }

    int n; // Variable para almacenar el número de departamentos
    printf("Ingrese el numero de departamentos: ");
    scanf("%d", &n); // Leer el número de departamentos

    ingresarDepartamentos(archivo, n); // Llamar a la función para ingresar los departamentos

    printf("\nDepartamentos ordenados de Z a A:\n");
    mostrarDepartamentos(archivo); // Llamar a la función para mostrar los departamentos ordenados

    fclose(archivo); // Cerrar el archivo al finalizar
    return 0; // Finalizar el programa
}
