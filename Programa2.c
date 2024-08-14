#include <stdio.h>  // Biblioteca estándar de entrada y salida
#include <stdlib.h> // Biblioteca para gestión de memoria dinámica
#include <string.h> // Biblioteca para manejo de cadenas

// Definición de la estructura para almacenar los datos de los estudiantes
typedef struct {
    int carnet;         // Número de carnet del estudiante
    char nombre[50];    // Nombre del estudiante
    char grado[20];     // Grado del estudiante
    char departamento[30]; // Departamento del estudiante
    int edad;           // Edad del estudiante
} Estudiante;

// Función para registrar un nuevo estudiante
void registrarEstudiante(FILE *archivo) {
    Estudiante estudiante; // Declarar una variable de tipo Estudiante

    // Solicitar datos del estudiante
    printf("Ingrese el numero de carnet: ");
    scanf("%d", &estudiante.carnet); // Leer el número de carnet del estudiante
    printf("Ingrese el nombre: ");
    scanf("%s", estudiante.nombre); // Leer el nombre del estudiante
    printf("Ingrese el grado: ");
    scanf("%s", estudiante.grado); // Leer el grado del estudiante
    printf("Ingrese el departamento: ");
    scanf("%s", estudiante.departamento); // Leer el departamento del estudiante
    printf("Ingrese la edad: ");
    scanf("%d", &estudiante.edad); // Leer la edad del estudiante

    // Escribir los datos del estudiante en el archivo de texto
    // fprintf: Escribe los datos formateados en el archivo
    fprintf(archivo, "%d %s %s %s %d\n", estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, estudiante.edad);
}

// Función para buscar un estudiante por carnet
void buscarEstudiante(FILE *archivo, int carnet) {
    Estudiante estudiante; // Declarar una variable de tipo Estudiante
    rewind(archivo); // Mover el puntero del archivo al inicio para empezar a leer desde el principio

    // Leer los datos del archivo y buscar el estudiante
    // fscanf: Lee los datos formateados del archivo
    while (fscanf(archivo, "%d %s %s %s %d", &estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, &estudiante.edad) == 5) {
        if (estudiante.carnet == carnet) { // Comparar el carnet leído con el carnet buscado
            // Mostrar los datos del estudiante encontrado
            printf("Carnet: %d, Nombre: %s, Grado: %s, Departamento: %s, Edad: %d\n",
                   estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, estudiante.edad);
            return; // Salir de la función si se encuentra el estudiante
        }
    }
    printf("Estudiante con carnet %d no encontrado.\n", carnet); // Mensaje si no se encuentra el estudiante
}

// Función para listar estudiantes por grado
void listarEstudiantesPorGrado(FILE *archivo, char *grado) {
    Estudiante estudiante; // Declarar una variable de tipo Estudiante
    rewind(archivo); // Mover el puntero del archivo al inicio para empezar a leer desde el principio

    // Leer los datos del archivo y listar los estudiantes del grado especificado
    // fscanf: Lee los datos formateados del archivo
    while (fscanf(archivo, "%d %s %s %s %d", &estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, &estudiante.edad) == 5) {
        if (strcmp(estudiante.grado, grado) == 0) { // Comparar el grado leído con el grado buscado
            // Mostrar los datos del estudiante si el grado coincide
            printf("Carnet: %d, Nombre: %s, Grado: %s, Departamento: %s, Edad: %d\n",
                   estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, estudiante.edad);
        }
    }
}

// Función para editar los datos de un estudiante
void editarEstudiante(FILE *archivo, int carnet) {
    Estudiante estudiante; // Declarar una variable de tipo Estudiante
    FILE *temp = fopen("temp.txt", "w"); // Crear un archivo temporal para almacenar los datos modificados
    rewind(archivo); // Mover el puntero del archivo al inicio para empezar a leer desde el principio

    // Leer los datos del archivo y buscar el estudiante a editar
    // fscanf: Lee los datos formateados del archivo
    while (fscanf(archivo, "%d %s %s %s %d", &estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, &estudiante.edad) == 5) {
        if (estudiante.carnet == carnet) { // Comparar el carnet leído con el carnet buscado
            // Solicitar nuevos datos del estudiante
            printf("Ingrese el nuevo nombre: ");
            scanf("%s", estudiante.nombre); // Leer el nuevo nombre del estudiante
            printf("Ingrese el nuevo grado: ");
            scanf("%s", estudiante.grado); // Leer el nuevo grado del estudiante
            printf("Ingrese el nuevo departamento: ");
            scanf("%s", estudiante.departamento); // Leer el nuevo departamento del estudiante
            printf("Ingrese la nueva edad: ");
            scanf("%d", &estudiante.edad); // Leer la nueva edad del estudiante
        }
        // Escribir los datos (modificados o no) en el archivo temporal
        // fprintf: Escribe los datos formateados en el archivo temporal
        fprintf(temp, "%d %s %s %s %d\n", estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, estudiante.edad);
    }

    fclose(archivo); // Cerrar el archivo original
    fclose(temp); // Cerrar el archivo temporal
    remove("archivo2.txt"); // Eliminar el archivo original
    rename("temp.txt", "archivo2.txt"); // Renombrar el archivo temporal como el archivo original
}

int main() {
    // fopen: Abre el archivo en modo de lectura/escritura, crea el archivo si no existe
    FILE *archivo = fopen("archivo2.txt", "a+");
    if (archivo == NULL) { // Verificar si el archivo se abrió correctamente
        printf("Error al abrir el archivo.\n");
        return 1; // Salir del programa si hay un error al abrir el archivo
    }

    int opcion; // Variable para almacenar la opción del menú
    do {
        // Mostrar el menú de opciones
        printf("\nMenu:\n");
        printf("1. Registrar estudiante\n");
        printf("2. Buscar estudiante por carnet\n");
        printf("3. Lista de estudiantes por grado\n");
        printf("4. Editar un estudiante\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion); // Leer la opción del usuario

        switch (opcion) {
            case 1:
                registrarEstudiante(archivo); // Registrar un nuevo estudiante
                break;
            case 2: {
                int carnet; // Variable para almacenar el carnet del estudiante a buscar
                printf("Ingrese el numero de carnet: ");
                scanf("%d", &carnet); // Leer el número de carnet
                buscarEstudiante(archivo, carnet); // Buscar estudiante por carnet
                break;
            }
            case 3: {
                char grado[20]; // Variable para almacenar el grado a buscar
                printf("Ingrese el grado: ");
                scanf("%s", grado); // Leer el grado
                listarEstudiantesPorGrado(archivo, grado); // Listar estudiantes por grado
                break;
            }
            case 4: {
                int carnet; // Variable para almacenar el carnet del estudiante a editar
                printf("Ingrese el numero de carnet del estudiante a editar: ");
                scanf("%d", &carnet); // Leer el número de carnet
                editarEstudiante(archivo, carnet); // Editar los datos del estudiante
                // Reabrir el archivo después de editar
                archivo = fopen("archivo2.txt", "a+");
                break;
            }
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 5); // Repetir el menú hasta que el usuario elija salir

    fclose(archivo); // Cerrar el archivo al finalizar
    return 0; // Finalizar el programa
}
