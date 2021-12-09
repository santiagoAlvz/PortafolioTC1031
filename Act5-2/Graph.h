#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "IP.h"
#include "HeapTree.h"
#include "IPGrado.h"
#include "HashTable.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    
    // Lista de adyacencia (vector de vectores)
    std::vector<IP> direcciones;
    std::vector<std::vector<IP>> adjList;
    void printAdjList();
    void explore(int);
    
    //HeapTree <IPGrado> maxheap;
    HashTable<int,IPGrado> tabla; //HashTable del tamaño del número primo más cercano al número de nodos del grafo

    
  
  public:
    Graph(int representacion, std::istream& input);
    Graph(int representacion);
    Graph(std::string fileName);
    ~Graph();
    int getNumNodes();
    int search(IP key);
    void printGraph();
    void copyGraph(int, Graph&);
    void sortDirections(std::vector<IP>& direcciones,int l, int r);
    int particion(std::vector<IP>& direcciones,int l, int r);
    void getDegree();
    void mostAttacked();
    void createTable();
    void getIPSummary(std::string direccion);
};




#endif // __GRAPH_H_