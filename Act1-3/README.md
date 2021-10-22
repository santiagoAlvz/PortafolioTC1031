Act 1.3
===========

Este programa es una implementación de algoritmos de ordenamiento y búsqueda, aplicados a una serie de registros de incidencias. Más detalles se listan a continuación

Instrucciones de Compilación
-----------------------------

1. Descarga todos los archivos en una máquina local
2. Utilizando la terminal o consola, navega al directorio src
3. Una vez en el directorio src, ejecuta el siguiente comando:
     `g++ -o Act1-3 *.cpp`
    En el directorio no debe haber ningún otro archivo .cpp o .h más que los incluidos
     
Instrucciones de Ejecución
-----------------------------

Una vez compilado el programa, ejecututa el programa generado
con el comando correspondiente para el sistema. Para Linux/Unix
usar `./Act1-3` (Estando el el directorio src).
     
Resumen de Ejecución
--------------------------

El programa recogerá los datos del archivo `bitacora.txt` incluido, almacenando cada registro de incidencia (cada línea) tras procesarlo, y después ordenará los registros por fecha, y los copiará en un archivo nuevo llamado `bitacora_ordenada.txt`

Después, se pedirá al usuario que ingrese dos fechas (inicio y fin). Dichas fechas se buscarán, y se imprimirá en pantalla una lista de todos los registros que se encuentren entre dichas fechas.

En caso de que las fechas especificadas no existan, se informará de ello al usuario, y la ejecución del programa terminará.
  
Tecnologías empleadas
----------------------

El presente programa está escrito en C++. Se utilizan sólo librerías estándar, por lo que el programa debería ser compilado sin problemas en cualquier compilador relativamente reciente.

El compilador usado para el desarrollo del programa es g++, versión 10.3.0
