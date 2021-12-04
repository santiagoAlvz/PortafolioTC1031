#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "IP.h"
#include "HeapTree.h"
#include "IPGrado.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    
    // Lista de adyacencia (vector de vectores)
    std::vector<IP> direcciones;
    std::vector<std::vector<IP>> adjList;
    void printAdjList();
    void explore(int);
    HeapTree <IPGrado> maxheap;
    
  
  public:
    Graph(int representacion, std::istream& input);
    Graph(int representacion);
    Graph(std::string fileName);
    ~Graph();
    int getNumNodes();
    int search(IP key);
    void printGraph();
    void copyGraph(int, Graph&);
    void sortDirections(int l, int r);
    int particion(int l, int r);
    void getDegree();
    void mostAttacked();
};




#endif // __GRAPH_H_