/* Declaración e Implementación de la clase DoubeLinkedList
 * Santiago Álvarez <A01640172@itesm.mx>
 * 14 de octubre de 2021
 */

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>
#include "Node.h"
#include "BusquedaOrdenamiento.h"

using std::string;

template <class T>
class DoubleLinkedList{
	private:
		Node<T> *head;
		Node<T> *tail;
		int numElements = 0;
		
	public:
		DoubleLinkedList();
		~DoubleLinkedList();
		void addFirst(T value);
		void addLast(T value);
		void escribirArchivo(int start, int end, std::string nombre);
		void imprimir(int start, int end, std::string header, int maxSize);
		void imprimir(Node <T> *start, Node <T> *end, std::string header, int maxSize);
		int getNumElements();
		void sort();
		Node <T>* search(T key);
		void escribirArchivo(Node <T> *start, Node <T> *end, string nombre);
		
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
	//Constructor de la clase
	this->head = nullptr;
	this->tail = nullptr;
	this->numElements = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	//Destructor de la Clase
	Node <T> *p, *q;
	p = this->head;
	
	while( p != nullptr){
		q = p->next;
		delete p;
		p = q;
	}
	
	this->head = nullptr;
	this->tail = nullptr;
	this->numElements = 0;
}

template <class T>
void DoubleLinkedList<T>::addFirst(T value){
	//Añade un elemento al principio de la lista
	Node<T> *newNode = new Node <T> (value);
	
	if(this->head == nullptr){
		this->head = newNode;
		this->tail = newNode;
	} else {
		newNode->next = this->head;
		this->head->prev = newNode;
		this->head = newNode;
	}
	this->numElements++;
}

template <class T>
void DoubleLinkedList<T>::addLast(T value){
	//Añade un elemento al final de la lista
	
	if(this->head == nullptr){
		addFirst(value);
	} else {
		Node<T> *newNode = new Node <T> (value);
		this->tail->next = newNode;
		newNode->prev = this->tail;
		this->tail = newNode;
		this->numElements++;
	}
}

template <class T>
void DoubleLinkedList<T>::escribirArchivo(int start, int end, string nombre){
	//Escribe la información del vector a un archivo con el nombre especificado
	//Rango dado por posición

	string temp;
	std::ofstream archivo;
	
	archivo.open(nombre);
	Node<T> *p = head;
	
	for(int i = 0; i < start; i++){
		//Alcanzar el elemento inicial
		p = p->next;
	}
	
	for(int i = start; i < end; i++){
		archivo<<p->data<<std::endl;
		p = p->next;
	}
	
	archivo.close();
}

template <class T>
void DoubleLinkedList<T>::escribirArchivo(Node <T> *start, Node <T> *end, string nombre){
	//Escribe la información del vector a un archivo con el nombre especificado
	//Rango dado por referencias
	
	string temp;
	std::ofstream archivo;
	
	archivo.open(nombre);
	
	while(start != end && start->next->next != nullptr){
		//Recorre los elementos de la lista
		archivo<< start->data <<std::endl;
		start = start->next;
	}
	
	archivo<< start->next->data <<std::endl;
	
	archivo.close();
}

template <class T>
void DoubleLinkedList<T>::imprimir(int start, int end, string header, int maxSize){
	//Imprime los elementos de un vector
	//Rango dado por posición
	
	std::cout<<string(maxSize,'-')<<std::endl;
	std::cout<<header<<std::endl;
	std::cout<<string(maxSize,'-')<<std::endl;
	
	Node<T> *p = head;
	
	for(int i = 0; i < start; i++){
		//Alcanzar el elemento inicial
		p = p->next;
	}
	
	for(int i = start; i < end; i++){
		std::cout<<p->data<<std::endl;
		p = p->next;
	}
}

template <class T>
void DoubleLinkedList<T>::imprimir(Node <T> *start, Node <T> *end, string header, int maxSize){
	//Imprime los elementos de un vector
	//Rango dado por referencias
	
	std::cout<<string(maxSize,'-')<<std::endl;
	std::cout<<header<<std::endl;
	std::cout<<string(maxSize,'-')<<std::endl;
	
	while(start != end){
		std::cout<< start->data <<std::endl;
		start = start->next;
	}
	
	std::cout<< end->data <<std::endl;
}

template <class T>
int DoubleLinkedList<T>::getNumElements(){
	//Regresa el número de elementos de la lista
	return this->numElements;
}

template <class T>
void DoubleLinkedList<T>::sort(){
	//Ordena el arreglo
	
	QuickSort(this->head, this->tail);
	
}

template <class T>
Node<T>* DoubleLinkedList<T>::search(T key){
	//Busca un determinado elemento
	Node<T>* temp = binarySearch(key, this->head, this->tail);
	if(temp != nullptr){
		return temp;
	} else throw "Los valores que se deseó buscar no existen";
}

#endif
