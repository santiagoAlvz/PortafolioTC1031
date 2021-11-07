Act 2.3
===========
Este programa es una implementación de algoritmos de ordenamiento y búsqueda, aplicados a una serie de registros de incidencias. Más detalles se listan a continuación

Instrucciones de Compilación
-----------------------------

1. Descarga todos los archivos en una máquina local
2. Utilizando la terminal o consola, navega al directorio /src
3. Una vez en el directorio src, ejecuta el siguiente comando:
     `g++ -O3 -o Act3-4 *.cpp`
    En el directorio no debe haber ningún otro archivo .cpp o .h más que los incluidos
     
Instrucciones de Ejecución
-----------------------------

Una vez compilado el programa, ejecututa el programa generado con el comando correspondiente para el sistema. Para Linux/Unix usar `./Act3-4` (Estando el el directorio src).

En Windows, puede hacer doble clic desde el explorador de archivos
     
Resumen de Ejecución
--------------------------

El programa recogerá los datos del archivo `bitacoraHeap.txt` incluido, almacenando cada registro de incidencia (cada línea) tras procesarlo, y después ordenará los registros por IP, y los copiará en un archivo nuevo llamado `bitacora_ordenada.txt`

Después, se contarán las incidencias agrupándolas por su IP. Las 5 direcciones IP con mayor número de ataques se mostrarán en pantalla, y todas las direcciones serán guardadas junto a su  número de ataques en orden descendente en un archivo llamado `ips_con_mayor_acceso.txt`
  
Tecnologías empleadas
----------------------

El presente programa está escrito en C++. Se utilizan sólo librerías estándar, por lo que el programa debería ser compilado sin problemas en cualquier compilador relativamente reciente.

El compilador usado para el desarrollo del programa es g++, versión 10.3.0
