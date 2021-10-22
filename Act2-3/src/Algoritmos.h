/* Implementación de los algoritmos adicionales para la implementación
 * del programa
 * Santiago Álvarez <A01640172@itesm.mx>
 * 15 de septiembre de 2021
 */
 
#include <iostream>
#include <vector>
#include <sstream>
#include "Registro.h"
#include "DoubleLinkedList.h"

using std::cin;
using std::cout;
using std::vector;
using std::endl;

void leerArchivo(DoubleLinkedList <Registro> &bitacora, string nombre){
	//Lee un archivo, almacenándolo en un vector de "Registros"
	
	string temp;
	std::ifstream archivo;
	Registro *tempr = nullptr;
	
	archivo.open(nombre); //Abre el archivo
	
	while(getline(archivo,temp)){ //Para cada línea del archivo
		
		try{
			tempr = new Registro(temp);
			bitacora.addLast(*tempr); //Añade la información al vector
		} catch(const char* e){
			//Si hay cualquier tipo de error, recoge la excepción
			throw e;
		}
		
		delete tempr;
	}
	archivo.close();
}

int leerFecha(){
	//Lee una fecha, ingresada por el teclado con el formato Mmm dd hh:mm:ss
	
	try{
		
		std::vector <string> MESES = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
								 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		string hora, temp;
		struct tm dateStruct;
		time_t res;
		dateStruct.tm_year = 2021-1900;
		
		//Leer mes
		cin>>temp;
		for(int i = 0; i<12; i++){
			if(MESES[i] == temp){
				dateStruct.tm_mon = i;
			}
		}
		
		//Leer día
		cin>>temp;
		dateStruct.tm_mday = stoi(temp);
		
		cin>>hora;
		std::stringstream ss(hora);
		
		getline(ss,temp,':');  //Hora
		dateStruct.tm_hour = stoi(temp);
		
		getline(ss,temp,':'); //Min
		dateStruct.tm_min = stoi(temp);
		
		getline(ss,temp,' '); //Seg
		dateStruct.tm_sec = stoi(temp);
		
		dateStruct.tm_isdst = -1;
		res = mktime(&dateStruct);
		return res;
	}catch(...){
		throw "El formato de la fecha introducida es distinto al esperado";
	}
}
