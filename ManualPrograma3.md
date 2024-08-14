# Manual tecnico Para Examen en C

en este documento se describe como funsiona el programa en c proporcionado

## 1 configuracion inicial

para poder ejecutar el programa asegurese de tener un entorno de desarrollo c configurado y un compilador disponible el programa utiliza las bibliotecas estandar stdio h stdlib h y string h

## 2 ingreso de departamentos

la funsion `ingresarDepartamentos` se utiliza para leer los nombres de los departamentos desde la entrada estandar y guardarlos en un archivo

### ejemplo
cuando el programa solicita
```
Ingrese el nombre del departamento 1:
```
el usuario debe ingresar el nombre del departamento por ejemplo "Cantel" el nombre sera guardado en el archivo `departamentos txt`

## 3 comparacion de cadenas

la funsion `comparar` es utilizada para ordenar los nombres de los departamentos en orden inverso es decir de z a a se utiliza la funsion `strcmp` para realizar la comparacion de las cadenas de caracteres

### ejemplo
si se tienen los nombres "Xela" "Cantel" y "Pueblo" la comparacion resultara en el siguiente orden
```
Xela
Pueblo
Cantel
```

## 4 mostrar departamentos ordenados

la funsion `mostrarDepartamentos` se encarga de leer los nombres de los departamentos desde el archivo ordenarlos de z a a utilizando `qsort` y luego imprimirlos en pantalla se asigna memoria dinamicamente para almacenar los nombres de los departamentos y luego se libera esta memoria despues de que se hayan mostrado los nombres

### ejemplo
si los nombres almacenados en el archivo son
```
Cantel
Pueblo
Xela
```
el programa los imprimira en el siguiente orden
```
Xela
Pueblo
Cantel
```

## 5 flujo principal del programa

el programa principal `main` inicia abriendo el archivo `departamentos txt` en modo de lectura escritura si el archivo no existe se crea a continuacion se solicita al usuario que ingrese el numero de departamentos y se llama a la funsion `ingresarDepartamentos` para almacenar los nombres en el archivo finalmente se llama a `mostrarDepartamentos` para imprimir los nombres en orden inverso

### ejemplo completo
cuando se ejecuta el programa y el usuario ingresa tres departamentos "Xela" "Cantel" "Pueblo" el programa realiza las siguientes operaciones
1. guarda los nombres en el archivo
2. ordena los nombres de z a a
3. imprime en pantalla
```
Xela
Pueblo
Cantel
```