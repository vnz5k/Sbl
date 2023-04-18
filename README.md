# SblRUT,Nombre,Entradas_solicitadas


Cada línea representa un cliente y debe incluir el RUT, el nombre del cliente y la cantidad de entradas solicitadas, separados por comas.

Ejemplo:

12345678-9,Carlos Perez,4
98765432-1,Ana González,1
24681357-K,Luisa Martínez,3


## Licencia

Este programa es de código abierto y se distribuye bajo la licencia MIT.


# Distribución de Entradas

Este programa, escrito en C, distribuye un número limitado de entradas entre los clientes que las solicitan. El programa lee los datos de los clientes y la cantidad de entradas solicitadas desde un archivo llamado "clientes.txt". Luego, asigna las entradas disponibles de manera justa y equitativa entre los clientes, con un máximo de 2 entradas por cliente.

## Características

* Lee las solicitudes de entradas desde un archivo de texto ("clientes.txt").
* Asigna un máximo de 2 entradas por cliente.
* Genera dos archivos de salida: "asignadas.txt" y "espera.txt".
* "asignadas.txt" contiene la lista de clientes que recibieron entradas y la cantidad asignada.
* "espera.txt" contiene la lista de clientes que no recibieron todas las entradas solicitadas y la cantidad de entradas pendientes.

## Requisitos

* Compilador de C (GCC, por ejemplo).
* Code::Blocks u otro IDE compatible con C.

## Uso

1. Asegúrate de que "clientes.txt" esté en la misma carpeta que el archivo de código fuente.
2. Compila y ejecuta el programa en tu IDE de C favorito.
3. Revisa los archivos "asignadas.txt" y "espera.txt" para ver los resultados de la distribución de entradas.

## Formato de archivo de entrada

El archivo "clientes.txt" debe tener el siguiente formato:

RUT,Nombre,Entradas_solicitadas


Cada línea representa un cliente y debe incluir el RUT, el nombre del cliente y la cantidad de entradas solicitadas, separados por comas.

Ejemplo:

12345678-9,Carlos Perez,4
98765432-1,Ana González,1
24681357-K,Luisa Martínez,3


## Licencia

Este programa es de código abierto y se distribuye bajo la licencia MIT.
