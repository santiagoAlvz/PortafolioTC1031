/* Declaración e Implementación de la clase Stack (Pila)
 * Santiago Álvarez <A01640172@itesm.mx>
 * 14 de octubre de 2021
 */

#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <class T>
class Stack{
	private:
	Node <T> *top;
	int numElements;
	
	public:
	Stack();
	~Stack();
	void push(T value);
	T pop();
	int getNumElements();
};

template <class T>
Stack<T>::Stack(){
	//Constructor de Stack
	this->top = nullptr;
	this->numElements = 0;
}

template <class T>
Stack<T>::~Stack(){
	//Destructor de Stack
	Node <T> *p, *q;
	p = top;
	while (p != NULL){
		q = p->next;
		delete p;
		p = q;
	}
	top = nullptr;
	this->numElements = 0;
}

template<class T>
void Stack<T>::push(T value){
	//Añade un elemento al Stack
    Node<T> *newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    numElements++;
}

template<class T>
T Stack<T>::pop(){
	//Elimina el último elemento del Stack, y lo regresa
	Node<T> *p = top;
	T value = top->data;
	top = p->next;
	delete p;
	numElements--;
    return value;
}

template<class T>
int Stack<T>::getNumElements(){
	//Regresa el número de elementos actuales
	return this->numElements;
}

#endif
