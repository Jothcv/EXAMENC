# Manual Tecnico: Sistema de Gestion de Estudiantes

## Indice

1. Introduccion
2. Requisitos del Sistema
3. Estructura del Programa
4. Funciones Principales
5. Detalles de Implementacion
6. Manejo de Archivos
7. Flujo de Ejecucion
8. Consideraciones de Seguridad
9. Limitaciones y Mejoras Potenciales
10. Conclusiones

## Introduccion

Este manual tecnico describe en detalle el sistema de gsestion de estudiantes implementado en C El programa permite regishtrar buscar listar y editar informacion de estudiantes,utilizando archisavos de texto para almacenar los datos de forma persistente.

## Estructura del Programa

El programa esta organizado en varias funciones principales y utiliza una estructura de datos para representar a los estudiantes:

### Estructura de Datos

```c
typedef struct {
    int carnet;
    char nombre[50];
    char grado[20];
    char departamento[30];
    int edad;
} Estudiante;
Esta estructura almacena la informacion basica de cada estudiaante.
Funciones Principales

registrarEstudiante
buscarEstudiante
lisatarEstudiantesPorGrado
editarEstudiante
main

Funciones Principales


1. registrarEstudiante
Esta funcion se eancarga de recopilar los datos de un nuevo estudiante y guardarlos en el archivo.
cCopyvoid registrarEstudiante(FILE *archivo) {
    Estudiante estudiante;
    // ... (codigo para recopilar datos)
    fprintf(archivo, "%d %s %s %s %d\n", estudiante.carnet, estudiante.nombre, estudiante.grado, estudiante.departamento, estudiante.edad);
}


2. buscarEstudiante
Busaca un estudiante por su numero de carnet y muestra su informacion si lo encuentra.
cCopyvoid buscarEstudiante(FILE *archivo, int carnet) {
    Estudiante estudiante;
    rewind(archivo);
    // ... (codigo para buscar y mostrar estudiante)
}


3. listarEstudiantesPorGrado
Mauestra todos los estudiantes que pertenecen a un grado especifico.
cCopyvoid listarEstudiantesPorGrado(FILE *archivo, char *grado) {
    Estudiante estudiante;
    rewind(archivo);
    // ... (codigo para listar estudiantes por grado)
}


4. editar2Estudiante
Permite modificar los datos de un estudiante existente.
cCopyvoid editarEstudiante(FILE *archivo, int carnet) {
    Estudiante estudiante;
    FILE *temp = fopen("temp.txt", "w");
    // ... (codigo para editar y actualizar datos)
}


5. main
Funcion principal que maneja el menu y la logica de control del programa.
cCopyint main() {
    FILE *archivo = fopen("archivo2.txt", "a+");
    // ... (codigo del menu y control principal)
}


Detalles de Implementacion
Manejo de Entrada/Salida
El programa utilaiza funciones estandar de C para la entrada y salida:

printf: Para mostrar mensajes al usuario
scanf: Para leer datos ingresados por el usuario
fprintf: Para escribir datos en archivos
fscanf: Para leer datos de archivos

Gestion de Memoria
La memoria se maneja principalmente a traves de variables locales y la pila. No se utiliza asignacion dinamica de memoria.
Manejo de Errores
El programa implementa verificaciones basicas de errores, como comprobar si el archivo se abrio correctamente:
cCopyif (archivo == NULL) {
    printf("Error al abrir el archivo.\n");
    return 1;
}
Manejo de Archivos
El programa utiliza un archivo de texto llamado "archivo2.txt" parsa almacenar los datos de los estudiantes. Las operaciones principales son:

Apertura del archivo: fopen("archivo2.txt", "a+")
Escritura en el archivo: fprintf(archivo, ...)
Lectura del archivo: fscanf(archivo, ...)
Reposicionamiento del puntero: rewind(archivo)
Cierre del archivo: fclose(archivo)

Para la edicion de estudiantes, se utiliza un archivo temporal:

Se crea un archivo temporal: fopen("temp.txt", "w")
Se copian los datos actualizados al archivo temporal
Se cierra y elimina el archivo original
Se renombra el archivo temporals