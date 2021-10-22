/* Declaración e Implementación de la clase Node
 * Santiago Álvarez <A01640172@itesm.mx>
 * 14 de octubre de 2021
 */

#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
	public:
		T data;
		Node <T> *prev;
		Node <T> *next;
		Node();
		Node(T);
};

template <class T>
Node<T>::Node(){
	//Constructor de nodo
	this->next = nullptr;
	this->prev = nullptr;
}

template <class T>
Node<T>::Node(T value){
	//Constructor de nodo
	this->data = value;
	this->next = nullptr;
	this->prev = nullptr;
}

#endif
