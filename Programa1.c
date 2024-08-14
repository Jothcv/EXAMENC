#include <stdio.h>   // Biblioteca estándar para entrada y salida
#include <stdlib.h>  // Biblioteca estándar para funciones de gestión de memoria dinámica
#include <string.h>  // Biblioteca para funciones de manipulación de cadenas

// Estructura que representa a un empleado
typedef struct {
    char nombre[50];     // Almacena el nombre del empleado
    int codigo;          // Almacena el código del empleado
    float sueldo;        // Almacena el sueldo del empleado
    int horas_trabajadas;// Almacena las horas trabajadas del empleado
} Empleado;

// Prototipos de funciones
void ingresar_trabajadores(Empleado **empleados, int *n);  // Función para ingresar trabajadores
void mostrar_trabajadores(Empleado *empleados, int n);     // Función para mostrar todos los trabajadores
void buscar_por_codigo(Empleado *empleados, int n, int codigo); // Función para buscar un empleado por su código
void buscar_por_nombre(Empleado *empleados, int n, char *nombre); // Función para buscar un empleado por su nombre
int comparar_nombres(const void *a, const void *b); // Función para comparar nombres (usada en qsort)

int main() {
    Empleado *empleados = NULL;  // Puntero a la lista dinámica de empleados, inicialmente NULL
    int n = 0;  // Variable que almacenará el número de empleados
    int opcion; // Variable para la opción seleccionada por el usuario
    int codigo; // Variable para almacenar el código que se busca
    char nombre[50]; // Variable para almacenar el nombre que se busca

    do {
        // Menú de opciones para el usuario
        printf("\nMenu:\n");
        printf("1. Ingresar Trabajadores\n");
        printf("2. Consultas generales\n");
        printf("3. Consultas por clave\n");
        printf("4. Consultas por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);  // Se lee la opción seleccionada por el usuario

        switch (opcion) {
            case 1:
                ingresar_trabajadores(&empleados, &n);  // Llamada a la función para ingresar trabajadores
                break;
            case 2:
                mostrar_trabajadores(empleados, n);  // Llamada a la función para mostrar todos los trabajadores
                break;
            case 3:
                printf("Ingrese el codigo del trabajador: ");
                scanf("%d", &codigo);  // Se lee el código del trabajador que se busca
                buscar_por_codigo(empleados, n, codigo);  // Llamada a la función para buscar por código
                break;
            case 4:
                printf("Ingrese el nombre del trabajador: ");
                scanf("%s", nombre);  // Se lee el nombre del trabajador que se busca
                buscar_por_nombre(empleados, n, nombre);  // Llamada a la función para buscar por nombre
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);  // El bucle continúa hasta que el usuario elige salir

    free(empleados);  // Liberación de la memoria dinámica asignada
    return 0;  // Retorno exitoso del programa
}

// Función para ingresar trabajadores
void ingresar_trabajadores(Empleado **empleados, int *n) {
    int nuevos;  // Variable para el número de nuevos empleados a ingresar
    printf("Cuantos empleados desea ingresar? ");
    scanf("%d", &nuevos);  // Se lee el número de empleados a ingresar

    *empleados = (Empleado *) realloc(*empleados, (*n + nuevos) * sizeof(Empleado));  // Se asigna/reasigna memoria dinámica

    for (int i = 0; i < nuevos; i++) {
        printf("Empleado %d:\n", *n + 1);
        printf("Nombre: ");
        scanf("%s", (*empleados)[*n].nombre);  // Se almacena el nombre del empleado
        printf("Codigo: ");
        scanf("%d", &(*empleados)[*n].codigo);  // Se almacena el código del empleado
        printf("Sueldo: ");
        scanf("%f", &(*empleados)[*n].sueldo);  // Se almacena el sueldo del empleado
        printf("Horas trabajadas: ");
        scanf("%d", &(*empleados)[*n].horas_trabajadas);  // Se almacenan las horas trabajadas del empleado
        (*n)++;  // Se incrementa el número total de empleados
    }
}

// Función para mostrar todos los trabajadores
void mostrar_trabajadores(Empleado *empleados, int n) {
    qsort(empleados, n, sizeof(Empleado), comparar_nombres);  // Se ordenan los empleados alfabéticamente por nombre

    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Codigo: %d, Sueldo: %.2f, Horas trabajadas: %d\n",
               empleados[i].nombre, empleados[i].codigo, empleados[i].sueldo, empleados[i].horas_trabajadas);  // Se muestran los datos del empleado
    }
}

// Función para buscar un empleado por código
void buscar_por_codigo(Empleado *empleados, int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (empleados[i].codigo == codigo) {  // Se compara el código buscado con el de cada empleado
            printf("Nombre: %s, Codigo: %d, Sueldo: %.2f, Horas trabajadas: %d\n",
                   empleados[i].nombre, empleados[i].codigo, empleados[i].sueldo, empleados[i].horas_trabajadas);  // Si se encuentra, se muestran los datos
            return;
        }
    }
    printf("No se encontro un empleado con ese codigo.\n");  // Si no se encuentra, se muestra un mensaje de error
}

// Función para buscar un empleado por nombre
void buscar_por_nombre(Empleado *empleados, int n, char *nombre) {
    for (int i = 0; i < n; i++) {
        if (strcmp(empleados[i].nombre, nombre) == 0) {  // Se compara el nombre buscado con el de cada empleado
            printf("Nombre: %s, Codigo: %d, Sueldo: %.2f, Horas trabajadas: %d\n",
                   empleados[i].nombre, empleados[i].codigo, empleados[i].sueldo, empleados[i].horas_trabajadas);  // Si se encuentra, se muestran los datos
            return;
        }
    }
    printf("No se encontro un empleado con ese nombre.\n");  // Si no se encuentra, se muestra un mensaje de error
}

// Función para comparar nombres de empleados (usada en qsort)
int comparar_nombres(const void *a, const void *b) {
    return strcmp(((Empleado *)a)->nombre, ((Empleado *)b)->nombre);  // Se comparan los nombres de dos empleados
}