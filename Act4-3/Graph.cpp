#include "Graph.h"
#include <fstream>
#include <iostream>
#include "HeapTree.h"

Graph::~Graph(){ //Destructor. Complejidad O(1)
  adjList.clear(); //Elimina la lista de adyacencia
}

Graph::Graph(std::string fileName){ //Lee el archivo para encontrar los valores de las IP. Complejidad O(n^2)
  IP origen, destino;
  std::string temp;
	std::ifstream archivo;

  direcciones.push_back(origen);
	
	archivo.open(fileName);

  getline(archivo,temp);
  std::stringstream tempss(temp); //Archivo temporal con el string

  getline(tempss, temp, ' '); //Aísla el número de nodos del archivo
  this->numNodes = stoi(temp);
  getline(tempss, temp); //Aísla el número de Edges del archivo
  this->numEdges = stoi(temp);
  this->adjList.resize(numEdges+1);

  int i = 1;
  while(i <= this->numNodes){
    //Obtiene todos los nodos (direcciones)
    getline(archivo,temp);
    origen = IP(temp);
    direcciones.push_back(origen);
    i++;
  }

  this->sortDirections(1,this->numNodes);

  while(getline(archivo,temp)){
    std::stringstream tempss(temp);
    //Escanea todas las relaciones (ataques)
    for(int j = 0; j < 3; j++){
      getline(tempss,temp,' ');
    }
    
    getline(tempss,temp,':');
    origen = IP(temp);

    getline(tempss,temp,' ');

    getline(tempss,temp,':');

    destino = IP(temp);//Obtiene el valor numérico de la IP de destino
    
    int pos = this->search(origen);
    if(pos == -1){
      cout<<"No encontrado"<<endl;
    } else{
    adjList[pos].push_back(destino);
    }
    i++;
  }
}

int Graph::search(IP key){ //Búsqueda Binaria. Complejidad O(nlogn)

  //Regresa la posición, en el vector direcciones, de una IP determinada
  //int numkey = key.getValue();
  int l = 1, r = this->numNodes, m = 0;
  while(l<=r){
    m = (l+r)/2;
    if(direcciones[m] == key){
      return m;
    } else if(direcciones[m] < key){
      l = m+1;
    } else r = m-1;
  } 
  return -1;
}

void Graph::sortDirections(int l, int r){ //Complejidad O(n^2)
  //Algoritmo de Ordenamiento QuickSort
	
	int pi;
	if(l < r){
		//Divide el arreglo y hace una llamada recursiva
		pi = particion(l, r);
		sortDirections(l,pi-1);
		sortDirections(pi+1,r);
	}
}

int Graph::particion(int l, int r){ //Complejidad O(n)
	//Función de división del arreglo, forma parte de QuickSort
	
	IP pivote = direcciones[r];
	IP temp;
	int i = l-1;
	
	for(int j = l;j<r;j++){
		if(direcciones[j] < pivote){ //Si el valor del vector es menos al pivote, hacer el cambio
			i++;
			temp = direcciones[i];
			direcciones[i] = direcciones[j];
			direcciones[j] = temp;
		}
	}
	
  //Actualizar el valor
	temp = direcciones[i+1];
	direcciones[i+1] = direcciones[r];
	direcciones[r] = temp;
	return i+1;
}

int Graph::getNumNodes(){ //Complejidad O(1)
  return numNodes;
}

void Graph::getDegree(){ //Obtener el grado de cada nodo del grafo. Complejiad O(n)
  //HeapTree <IPGrado> maxheap;
  ofstream Salida("grados_ips.txt");
  for(int i = 1; i <= numNodes; i++ ){ //Recorre los nodos de la lista de adyacencia
    Salida<<"Dirección IP: "<<direcciones[i]<<"\t\t\t"<<"Grado: "<<
    adjList[i].size()<<endl;
    maxheap.push(IPGrado(direcciones[i],adjList[i].size()));
  }
  Salida.close();
  mostAttacked();
}

void Graph::mostAttacked(){ //Complejidad O(n)
  ofstream Salida2("mayores_grados_ips.txt");
  for( int i = 0; i < 5; i++){ //Realiza 5 pop para encontrar las 5 IP's más vulneradas
    if(i == 0){ //El primer pop es el bootmaster (Más incidencias)
      IPGrado bootMaster = maxheap.pop();
      Salida2 << bootMaster << endl;
      cout<<"El bootmaster de la red fue: "<<bootMaster<<endl;
    }
    else{ //Seguir haciendo pops del maxheap
      IPGrado attackedIP = maxheap.pop();
      Salida2<<attackedIP<<endl;
    }
  }
  Salida2.close();
}
