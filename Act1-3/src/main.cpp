/* Archivo principal del programa 
 * Santiago Álvarez <A01640172@itesm.mx>
 * 15 de septiembre de 2021
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include "Registro.h"
#include "Algoritmos.h"

using std::cout;
using std::cin;
using std::vector;
using std::endl;

void leerArchivo(vector<Registro> &bitacora, string nombre){
	//Lee un archivo, almacenándolo en un vector de "Registros"
	
	string temp;
	std::ifstream archivo;
	Registro *tempr = NULL;
	
	archivo.open(nombre); //Abre el archivo
	
	while(getline(archivo,temp)){ //Para cada línea del archivo
		try{
			tempr = new Registro(temp);
		} catch(const char* e){
			//Si hay cualquier tipo de error, recoge la excepción
			throw e;
		}
		bitacora.push_back(*tempr); //Añade la información al vector
		delete tempr;
	}
	
	archivo.close();
}

void escribirArchivo(vector <Registro> &bitacora, string nombre){
	//Escribe la información del vector a un archivo con el nombre especificado
	string temp;
	std::ofstream archivo;
	
	archivo.open(nombre);
	
	for(int i = 0; i < int(bitacora.size()); i++){
		archivo<<bitacora[i].toStringSingleWhitespaces()<<endl;
	}
	
	archivo.close();
}

template <class T>
void imprimirVector(vector <T> &arr, int l, int r){
	//Imprime los elementos de un vector
	
	cout<<string(80,'-')<<endl;
	cout<<"Fecha y Hora     IP:Puerto               Razón"<<endl;
	cout<<string(80,'-')<<endl;
	for(int i = l; i<=r; i++){
		cout<<arr[i]<<endl;
	}
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

int main(){
	//Función principal del programa
	
	time_t fInicio,fFin;
	int l,r;
	std::vector <Registro> bitacora;
	
	try{
		
		//Lee el archivo bitácora y lo ordena
		auto start = std::chrono::high_resolution_clock::now();
		leerArchivo(bitacora,"bitacora.txt");
		quickSort(bitacora,0,bitacora.size()-1);
		auto stop = std::chrono::high_resolution_clock::now();
		auto total = stop-start;
		
		//Crea un archivo con el resultado del ordenamiento
		escribirArchivo(bitacora,"bitacora_ordenada.txt");
		
		cout<<"Ingresa la fecha de Inicio: ";
		fInicio = leerFecha();
		Registro reg1(fInicio);
		
		cout<<"Ingresa la fecha de Fin: ";
		fFin = leerFecha();
		Registro reg2(fFin);
		
		//Ejecuta las búsquedas con las fechas buscadas
		start = std::chrono::high_resolution_clock::now();
		l = busquedaBinaria(bitacora,reg1,0,bitacora.size()-1);
		r = busquedaBinaria(bitacora,reg2,0,bitacora.size()-1);
		stop = std::chrono::high_resolution_clock::now();
		total += stop-start;
		
		//Verifica que las fechas existan, y muestra resultados
		if(l != -1){
			if(r != -1){
				cout<<endl<<r-l+1<<" Resultados ("
					<<total/std::chrono::milliseconds(1)
					<<" milisegundos de ordenamiento y búsqueda)"<<endl;
					
			} else throw "La fecha de Fin no existe";
		} else throw "La fecha de Inicio no existe";
		imprimirVector(bitacora,l,r);
		
	} catch(const char* e){
		//Si se pasó una excepción de alguna función, muestra el error
		cout<<" **Error. "<<e<<endl;
		return -1;
	}
	
	return 0;
}
