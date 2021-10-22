/* Implementación de los algoritmos de bbúsqueda y ordenamiento
 * Santiago Álvarez <A01640172@itesm.mx>
 * 15 de septiembre de 2021
 */

#include "Node.h"
#include "stack.h"

template <class T>
Node <T>* partition(Node <T> *left, Node <T> *right){
	//Algoritmo de partición, parte de QuickSort
	Node <T> *pivot = right;
	Node <T> *i = left->prev;
	
	for(Node <T> *j = left; j != right; j = j->next){
		if(j->data <= pivot->data){
			i = (i == nullptr ? left : i->next);
            T temp = i->data;
            i->data = j->data;
            j->data = temp;
		}
	}
	i = (i == NULL ? left : i->next);
    T temp = i->data;
    i->data = pivot->data;
    pivot->data = temp;
	return i;
}

template <class T>
void QuickSort(Node <T> *left, Node <T> *right) {
	//Algoritmo de ordenamiento QuickSort, para listas doblemente ligadas
	Node <T> *p, *temp;
	
	struct pair{
		//Estructura usada para almacenar los datos a guardar en el Stack
		Node <T> * first;
		Node <T> * second;
	} conjunto;
	
	
	//Se crea el stack, y se almacenan los primeros dos datos
	Stack <struct pair> mistack;
	conjunto.first = left;
	conjunto.second = right;
	mistack.push(conjunto);
	
	while(mistack.getNumElements() > 0){
	//Mientras haya elementos en el Stack
		
		conjunto = mistack.pop(); //Remueve último par
		
		if( conjunto.second != nullptr && 
			conjunto.first != conjunto.second && 
			conjunto.first != conjunto.second->next){
			//Si el último par puede ser ordenado, lo hará la próxima iteración
			
			p = partition(conjunto.first, conjunto.second);
			
			temp = conjunto.second;
			conjunto.second = p->prev;
			mistack.push(conjunto);
			
			conjunto.first = p->next;
			conjunto.second = temp;
			mistack.push(conjunto);
		}
		//Si no, el arreglo ahora tiene un elemento menos
	}
}

template <class T>
Node <T>* binarySearch(T key, Node <T>* start, Node <T>* end){
	//Algoritmo de Búsqueda binaria para listas doblemente ligadas
	
	if(start == end){
		//Si inicio y fin están son la misma posición
		
		if(start->data == key) 
			//Se encontró en la última posición
			return start;
		else return nullptr; //El elemento no está
		
	} else {
		
		//Crea dos punteros, que irán recorriendo la lista en direcciones
		//opuestas
		Node <T> *ptrl = start, *ptrr = end;
		
		while(ptrl != ptrr){
			//Va recorriendo los punteros lugar en lugar, hasta que estos
			//coincidan (la mitad)
			
			ptrl = ptrl->next;
			if(ptrl == ptrr){
				break;
			}
			ptrr = ptrr->prev;
		}
		
		//De acuerdo al valor encontrado en la mitad
		if(ptrl->data == key){
			return ptrl;
		} else if (ptrl->data > key){
			return binarySearch(key,start,ptrl->prev);
		} else {
			return binarySearch(key,ptrl->next,end);
		}
	}
}

/*función original de QuickSort
 * 
if (right != nullptr && left != right && left != right->next)
{
	Node <T> *p = partition(left, right);
	
	if(left < )
	QuickSort(left, p->prev);
	QuickSort(p->next, right);
}*/
