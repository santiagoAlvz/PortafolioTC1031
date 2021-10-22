/* Archivo principal del programa 
 * Santiago Álvarez <A01640172@itesm.mx>
 * 15 de septiembre de 2021
 */

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Registro.h"
#include "Algoritmos.h"
#include "DoubleLinkedList.h"

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main(){
	
	//Función principal del programa
	
	time_t fInicio,fFin;
	Node <Registro> *inicio, *fin;
	DoubleLinkedList<Registro> bitacora;
	
	try{
		
		//Lee el archivo bitácora y lo ordena
		auto start = std::chrono::high_resolution_clock::now();
		leerArchivo(bitacora,"bitacora.txt");
		bitacora.sort();
		auto stop = std::chrono::high_resolution_clock::now();
		auto total = stop-start;
		
		//Crea un archivo con el resultado del ordenamiento
		bitacora.escribirArchivo(0,bitacora.getNumElements(),"bitacora_ordenada.txt");
		
		cout<<"Ingresa la fecha de Inicio: ";
		fInicio = leerFecha();
		Registro reg1(fInicio);
		
		start = std::chrono::high_resolution_clock::now();
		inicio = bitacora.search(reg1);
		stop = std::chrono::high_resolution_clock::now();
		total += stop-start;
		
		cout<<"Ingresa la fecha de Fin: ";
		fFin = leerFecha();
		Registro reg2(fFin);
		
		//Ejecuta las búsquedas con las fechas buscadas
		start = std::chrono::high_resolution_clock::now();
		fin = bitacora.search(reg2);
		stop = std::chrono::high_resolution_clock::now();
		total += stop-start;
		
		cout<<endl<<total/std::chrono::milliseconds(1)
					<<" ms (ordenamiento y búsqueda)"<<endl;
		bitacora.imprimir(inicio,fin,"Fecha y Hora     IP:Puerto               Razón",80);
		bitacora.escribirArchivo(inicio,fin,"resultado_busqueda.txt");
		
	} catch(const char* e){
		//Si se pasó una excepción de alguna función, muestra el error
		cout<<" **Error. "<<e<<endl;
		return -1;
	}
	
	return 0;
}
