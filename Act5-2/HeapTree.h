#ifndef HEAPTREE_H
#define HEAPTREE_H

#include <vector>

template <class T>
class HeapTree{
	private:
		std::vector <T> data;
		int nElements = 0;
		void acomodaAbajo(int pos);
		int parent(int i);
	public:
		void push(T newElement);
		T pop();
		int getNElements();
};

template <class T>
int HeapTree<T>::parent(int i){ //Complejidad O(1)
	return (i-1)/2;
}

template <class T>
void HeapTree<T>::push(T newElement){ //Complejidad O(n)
	//Añade un nuevo eleemtno al Heap
	this->data.push_back(newElement);
	this->nElements++;
	int i = this->nElements - 1;
	
	while(i != 0 && this->data[parent(i)] < this->data[i]){
		std::swap(this->data[parent(i)], this->data[i]);
		i = (i-1)/2;
	}
}

template <class T>
void HeapTree<T>::acomodaAbajo(int pos){ //Complejidad O(n)
	//Acomoda los nodos más abajo de la posición
	int hijos = 2*pos + 1, hijoMay;
	
	while(hijos < this->nElements){
		hijoMay = (this->data[hijos] > this->data[hijos+1] || hijos + 1 == this->nElements) ? hijos : hijos+1;
		
		if(this->data[hijoMay] > this->data[pos]){
			std::swap(this->data[pos], this->data[hijoMay]);
			pos = hijoMay;
			hijos = 2*pos;
		} else break;
		
	}
}

template <class T>
T HeapTree<T>::pop(){ //Complejidad O(n)
	//Elimina el nodo raíz del árbol
	
  T returnValue = this->data[0];
	std::swap(this->data[0], this->data[this->nElements-1]);
	this->data.erase(data.begin()+this->nElements-1);
	this->nElements--;
	
	int i = parent(this->nElements-1);
	
	while(i >= 0){
		acomodaAbajo(i);
		i--;
	}
	
	return returnValue;
}

template <class T>
int HeapTree<T>::getNElements(){ //Complejidad O(1)
	//Regresa el número de elementos del árbol
	return this->nElements;
}

#endif
