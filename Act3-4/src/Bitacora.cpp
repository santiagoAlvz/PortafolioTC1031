/* Implementación de la clase Bitacora
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#include "Bitacora.h"
#include "IPIncidencias.h"
#include "HeapTree.h"
#include <fstream>

Bitacora::Bitacora(std::string fileName){
	//Lee un archivo, almacenándolo en un vector de "Registros"
	
	string temp;
	std::ifstream archivo;
	Registro *tempr = nullptr;
	
	archivo.open(fileName); //Abre el archivo
	
	while(getline(archivo,temp)){ //Para cada línea del archivo
		
		try{
			tempr = new Registro(temp);
			this->data.push_back(*tempr); //Añade la información al vector
		} catch(const char* e){
			//Si hay cualquier tipo de error, recoge la excepción
			throw e;
		}
		
		delete tempr;
	}
	archivo.close();
}

Registro Bitacora::operator [](int position){
	return this->data[position];
}

void Bitacora::heapify(int n, int root){
	int largest = root;
	int l = 2*root +1;
	int r = 2*root +2;
	
	if(l < n && this->data[l] > this->data[largest]) largest = l;
	if(r < n && this->data[r] > this->data[largest]) largest = r;
	
	if(largest != root){
		std::swap(this->data[root], this->data[largest]);
		
		heapify(n,largest);
	}
	
}

void Bitacora::heapSort(){
	//Algoritmo de ordenamiento heapSort para los elementos de la biácora
	for(int i = this->data.size()/2; i >= 0; i--){
		this->heapify(this->data.size(),i);
	}
	
	for(int i = this->data.size()-1; i>=0; i--){
		std::swap(this->data[0], this->data[i]);
		heapify(i,0);
	}
}

void Bitacora::guardarArchivo(std::string fileName){
	//Almacena los registros de la bitácora en un archivo
	string temp;
	std::ofstream archivo;
	
	archivo.open(fileName);
	
	for(int i = 0; i < int(this->data.size()); i++){
		archivo<<this->data[i]<<std::endl;
	}
	
	archivo.close();
}

void Bitacora::contarIncidencias(std::string fileName){
	//Cuenta las incidencias de cada IP, las almacena en un MaxHeap
	//y regresa los resultados en orden descendente
	std::ofstream archivo;	
	IP temp = this->data[0].getIP(), temp2;
	IPIncidencias *tempInc = nullptr;
	HeapTree <IPIncidencias> arbolIncidencias;
	int cont = 1;
	
	archivo.open(fileName);
	
	//Almacena las incidencias en el árbol
	for(int i = 1; i < int(this->data.size()); i++){
		temp2 = this->data[i].getIP();
		if(temp2 == temp){
			cont++;
		} else {
			
			tempInc = new IPIncidencias(temp, cont);
			arbolIncidencias.push(*tempInc);
			delete tempInc;
			
			temp = temp2;
			cont = 1;
		}
	}
	
	tempInc = new IPIncidencias(temp, cont);
	arbolIncidencias.push(*tempInc);
	delete tempInc;
	
	std::cout<<"Las 5 IPs con más registros son:"<<std::endl;
	std::cout<<"-------------------------------------"<<std::endl;
	std::cout<<"IP            Numero de registros"<<std::endl;
	std::cout<<"-------------------------------------"<<std::endl;
	
	//Extrae las 5 IP con más registros, imprime en pantalla y en el archivo
	IPIncidencias res;
	for(int i = 0; i < 5; i++){
		if(arbolIncidencias.getNElements() > 0){
			res = arbolIncidencias.pop();
			
			std::cout<<res<<std::endl;
			archivo<<res<<std::endl;
			
		} else break;
	}
	
	//Para el resto de las IP, imprime sólo en el archivo
	while(arbolIncidencias.getNElements() > 0){
		res = arbolIncidencias.pop();
		archivo<<res<<std::endl;
		
	}
	
	archivo.close();
}
