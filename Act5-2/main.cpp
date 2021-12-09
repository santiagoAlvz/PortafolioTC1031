/** 
//Actividad Integral 4.3 - Grafos
//Autores: Diego Sú Gómez - A01620476
           Jesús Julián Madrid Castro - A00227101
           Santiago Álvarez Valdivia - A01640172

           Profesor: Dr. Eduardo Arturo Rodríguez Tello
//Fecha de creación: 28 de noviembre de 2021
//Descripción: Programa que implementa una Hash Table en donde se encontrarán las colisiones al ingresar la lista de adyacencia formada por el grafo de IP's, además de permitir buscar una IP en la tabla

//Liga de replit = https://replit.com/join/bbkwdagiwy-diegosu
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
*    g++ -std=c++17 -g -o3 main *.cpp 

* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main < petersen.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < petersen.txt
**/

#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"
#include "Queue.h"

using std::cout;
using std::endl;

int main(){
  Graph IPs("bitacoraGrafos.txt");
  IPs.createTable();
  std::string direccion;
  cout<<"Ingresa la dirección IP  a buscar (Ingresar IP sin puerto):"<<endl;
  cin>>direccion;
  IPs.getIPSummary(direccion);
  return 0;
}