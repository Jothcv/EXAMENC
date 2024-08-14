# SEGUNDO EXAMEN DEL LENGUAJE C

## Documentacion

### Programa1

#### PASO1

primero cree el programa llamado programa.c despues en el codigo importen las librerias

1) <stdio.h> para las entradas y salidas
2) <stdlib.h> para la gestion de memoria dinamica
3) <String.h> para poder manipular mejor las cadenas de texto

#### PASO2

despues hice la funcion principal el main despues de realiarlo hice una estructura que almacena los datos del nombre, codigo, sueldo y horas trabajadas lo hice con un typeref para tener referencia de la estructura con cual nos vamos a referir pues yo le puse para refernos como Empleado.

#### PASO3

despues de todo hago el menu para poder ingresar a los trabajadores para preguntas frecuentes o genreales como tambien preguntar o buscar a un trabajador por su nombre

#### PASO4

despues de crear el menu creo la primera cosa que devemos de hacer es decir vamos a pedir que nos ingresen cuantos trabajadores queremos que nos ingresen posteriormente pidimos el nombre, codigo, horas tranajados salacio etc.. despues de hacer el programa llamamos hasta arriba a la funcion y por ultimo llamamos a la funcion en el menu aqui el ejemplo de la funcion que hace este proceso

    void ingresarTrabajadores(Empleado **empleados, int *n) {
    int nuevos; 
    printf("cuantos usuarios desea ingresar");
    scanf("%d", &nuevos);  
    *empleados = (Empleado *) realloc(*empleados, (*n + nuevos) * sizeof(Empleado));  
    for (int i = 0; i < nuevos; i++) {
            printf("empleados:  %d:\n", *n + 1);
            printf("nombre de empleado: ");
            scanf("%s", (*empleados)[*n].nombre);  
            printf("codigo de empleado:  ");
            scanf("%d", &(*empleados)[*n].codigo); 
            printf("suedlo de empleado: ");
            scanf("%f", &(*empleados)[*n].sueldo);  
            printf("horas de empleado: ");
            scanf("%d", &(*empleados)[*n].horasDeTrabajo); 
            (*n)++; 
        }
    }

y recuerden que devemos anclarlo al menu entonces debajo de la estructura llamamos a la funcion

    void ingresarTrabajadores(Empleado **empleados, int *n)

y por ultimo lo llamamos pero dentro del menu:

    switch (opcion) {
            case 1:
                ingresarTrabajadores(&empleados, &n);  
                break;
    }

Y listo eso seria opara la primera funcion

#### PASo5

Aqui realizamos la segunda funcion que muestra a los usuarios o datos del empleado como tambien los ordena de forma automaticamente para esto use un qsort pues  ah y recuerden que devemos ingresar la funcion al principio por debajo de la estructura

    void MostrarTrabajadores(Empleado *empleados, int n) 
    qsort(empleados, n, sizeof(Empleado), CompararNombres);  // Se ordenan los empleados alfabéticamente por nombre

    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Codigo: %d, Sueldo: %.2f, Horas trabajadas: %d\n",
               empleados[i].nombre, empleados[i].codigo, empleados[i].sueldo, empleados[i].HorasTrabajadas);  // Se muestran los datos del empleado
    }

luego lo colocamos por debajo de la esteructura mas o menos aqu asi

    void MostrarTrabajadores(Empleado *empleados, int n);     // Función para mostrar todos los trabajadores

pero recuerda que en esta funcion tambien esta pra organizar entonces tambien tenemos que llamar a la funcion de organizar esto lo hice en una sola funcion para poder llamarlo juntos en el menu aqui un entonces hata arriba solo lo llamamos desde  arriba y en el menu solo llamamos a mostrar ya que aqui se encuentran los dos

    int CompararNombres(const void *a, const void *b); // Función para comparar nombres (usada en qsort)

esto para llamar a la funcion ahora en el menu solo llamamos a la de mostrarTrabajadores asi es como va quedando nuestro codigo

    printf("\nMenu:\n");
        printf("1. Ingresar Trabajadores\n");
        printf("2. Consultas generales\n");
        printf("3. Consultas por clave\n");
        printf("4. Consultas por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);  // Se lee la opción seleccionada por el usuario

        switch (opcion) 
            case 1:
                IngresaTrabajadores(&empleados, &n);  // Llamada a la función para ingresar trabajadores
                break;
            case 2:
                MostrarTrabajadores(empleados, n);  // Llamada a la función para mostrar todos los trabajadores
                break;

#### PASO6

ahora vamos a hacer la funcion de buscar por el codigo este el cual buscara a los trabajadores ingresados y si no aparesen dira un mensaje de que no fueron encotrados esto lo hare con un simople for y un if que compare si existe o no

    void BuscarCodigo(Empleado *empleados, int n, int codigo) 
    for (int i = 0; i < n; i++) {
        if (empleados[i].codigo == codigo) {  // Se compara el código buscado con el de cada empleado
            printf("Nombre: %s, Codigo: %d, Sueldo: %.2f, Horas trabajadas: %d\n",
                   empleados[i].nombre, empleados[i].codigo, empleados[i].sueldo, empleados[i].HorasTrabajadas);  // Si se encuentra, se muestran los datos
            return;
        }
    }
    printf("No se encontro un empleado con ese codigo.\n");  // Si no se encuentra, se muestra un mensaje de error

esto seria la funcion que buscaria al trabajador por el codigo ingresado

Y como siempre solo tenemos que llamar a la funcon de Buscarcodgio debajo de la estructura asi

    void BuscarCodigo(Empleado *empleados, int n, int codigo); // Función para buscar un empleado por su código

ahora lo llamaos a nuestro menu asi se veria nuestro menu hasta hora:

    do 
        // Menú de opciones para el usuario
        printf("\nMenu:\n");
        printf("1. Ingresar Trabajadores\n");
        printf("2. Consultas generales\n");
        printf("3. Consultas por clave\n");
        printf("4. Consultas por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);  // Se lee la opción seleccionada por el usuario

        switch (opcion) 
            case 1:
                IngresaTrabajadores(&empleados, &n);  // Llamada a la función para ingresar trabajadores
                break;
            case 2:
                MostrarTrabajadores(empleados, n);  // Llamada a la función para mostrar todos los trabajadores
                break;
            case 3:
                printf("Ingrese el codigo del trabajador: ");
                scanf("%d", &codigo);  // Se lee el código del trabajador que se busca
                BuscarCodigo(empleados, n, codigo);  // Llamada a la función para buscar por código
                break;

#### PASO7

ahora tenemos qwue bsucar a los usuarios por el nombre este seria igual a a la funcion anterior ahora que envez de comparar la estructura.codigo compararemops la estructura.nombre

    // Función para buscar un empleado por nombre
    void BuscarNombre(Empleado *empleados, int n, char *nombre) 
    for (int i = 0; i < n; i++) {
        if (strcmp(empleados[i].nombre, nombre) == 0) {  // Se compara el nombre buscado con el de cada empleado
            printf("Nombre: %s, Codigo: %d, Sueldo: %.2f, Horas trabajadas: %d\n",
                   empleados[i].nombre, empleados[i].codigo, empleados[i].sueldo, empleados[i].HorasTrabajadas);  // Si se encuentra, se muestran los datos
            return;
        }
    }
    printf("No se encontro un empleado con ese nombre.\n");  // Si no se encuentra, se muestra un mensaje de error

Listo una vez echo esto con un for y un if donde comparamos simplemente que empleados[i].nombre,nombre==0 como en el codigo una vez echo esto lo llamamos al principio y tambien en el menu
asi se veria como lo llamariamos debajo del struct

    void BuscarNombre(Empleado *empleados, int n, char *nombre); // Función para buscar un empleado por su nombre

ahora lo llamamos desde la funcion principal para el menu asi se veria nuestro menu a como vamos

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
                IngresaTrabajadores(&empleados, &n);  // Llamada a la función para ingresar trabajadores
                break;
            case 2:
                MostrarTrabajadores(empleados, n);  // Llamada a la función para mostrar todos los trabajadores
                break;
            case 3:
                printf("Ingrese el codigo del trabajador: ");
                scanf("%d", &codigo);  // Se lee el código del trabajador que se busca
                BuscarCodigo(empleados, n, codigo);  // Llamada a la función para buscar por código
                break;
            case 4:
                printf("Ingrese el nombre del trabajador: ");
                scanf("%s", nombre);  // Se lee el nombre del trabajador que se busca
                BuscarNombre(empleados, n, nombre);  // Llamada a la función para buscar por nombre
                break;

#### PASO8

y perfecto casi terminamos ahora simplemente tenemos que hacer la condicion del while para que me repita el menu hasta que yo quiero como tambien el salir simplemente eso y asi quedaria nuestro menu ah y recuerden que como estamos usando memoria dinamica tenemos que liberar memoria y como lo hacemos  simplemente seria: free(empleados);

asi se veria nuestro menu Hasta la fecha :)

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
                IngresaTrabajadores(&empleados, &n);  // Llamada a la función para ingresar trabajadores
                break;
            case 2:
                MostrarTrabajadores(empleados, n);  // Llamada a la función para mostrar todos los trabajadores
                break;
            case 3:
                printf("Ingrese el codigo del trabajador: ");
                scanf("%d", &codigo);  // Se lee el código del trabajador que se busca
                BuscarCodigo(empleados, n, codigo);  // Llamada a la función para buscar por código
                break;
            case 4:
                printf("Ingrese el nombre del trabajador: ");
                scanf("%s", nombre);  // Se lee el nombre del trabajador que se busca
                BuscarNombre(empleados, n, nombre);  // Llamada a la función para buscar por nombre
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

Perfecto emos terminado nuestro primer porgrama todo ya unido se veria tal como:

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
            