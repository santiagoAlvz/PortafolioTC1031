#ifndef _QUEUE_H  
#define _QUEUE_H

  #include <climits>
  #include "Node.h"

  template <class T>
  class Queue {   
      private:
        Node<T>* front;
        Node<T>* rear;
        int numElements;

      public:
        Queue();
        ~Queue();
        bool isEmpty();
        int getNumElements();
        void printQueue();
        void enqueue(T value);
        T dequeue();

  };

  template<class T>
  Queue<T>::Queue() { //Constructor default. Complejidad O(1)
    front = rear = NULL;
    numElements = 0;
  }
  
  template<class T>
  Queue<T>::~Queue() { //Destructor. Complejidad O(n)
    if (!isEmpty()) {
      Node<T> *p, *q;
      p = front;
      while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
      }
      front = NULL;
      rear = NULL;
      numElements = 0;
    }
  }
  
  template<class T>
  bool Queue<T>::isEmpty(){ //Complejidad O(1)
    if (front == NULL && rear == NULL) {
      return true;
    }
    return false;
  }

  template<class T>
  int Queue<T>::getNumElements() { //Complejidad O(1)
    return numElements;
  }

  template <class T>
  void Queue<T>::printQueue(){ //Complejidad O(n)
    Node<T> *ptr = front;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template <class T>
  void Queue<T>::enqueue(T value) { //Complejidad O(1)
    Node<T> *p = new Node<T>(value);
    numElements++;
    // Si la fila esta vacia
    if (isEmpty()) {
      front = p;
      rear = p;
    }
    else { // La lista ya contiene elementos
      rear->next = p;
      rear = p;
    }
  }

  template <class T>
  T Queue<T>::dequeue() { //Complejidad O(1)
    T value = -1;
    if (isEmpty()) {
      return value;
    }
    else {
      Node<T>* p = front;
      value = p->data;
      front = front->next;
      if (front == NULL)
        rear = NULL;
      delete p;
      numElements--;
      return value;
    }
  }    
 
#endif //_QUEUE_H