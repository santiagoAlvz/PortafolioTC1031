#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <vector>
#include <stdexcept>
#include "HashNode.h"

template<class K, class T>
class HashTable {
  private:
    std::vector<HashNode<K,T>> table;
    int size;
    int colisiones = 0;
    int maxSize; // preferible un numero primo

  public:
    HashTable();
    HashTable(int selectedMaxSize);
    int getHashIndex(K keyVal);
    int getSize();
    void print();
    void add(K keyVal, T value);
    int find(K keyVal);
    T getDataAt(int index);
    void remove(K keyVal);
    int getColisiones();
};

template <class K, class T>
HashTable<K,T>::HashTable(){ //Complejidad O(1)
  size = 0;
  maxSize = 0;
}

template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize) { //Complejidad O(1)
  maxSize = selectedMaxSize;
  size = 0;
  table = std::vector<HashNode<K,T>>(maxSize);
}

template<class K, class T>
int HashTable<K, T>::getHashIndex(K keyVal) { //Complejidad O(1)
  return keyVal % maxSize;
}

template<class K, class T>
int HashTable<K, T>::getSize() { //Complejidad O(1)
  return size;
}

template<class K, class T>
void HashTable<K,T>::print() { //Complejidad O(n)
  std::cout << "Content of the hash table: " << std::endl;
  for (int i = 0; i < maxSize; i++) {
    if (table.at(i).getStatus()==1) // Cell is used
      std::cout << "Cell: " << i << " Key: " << table.at(i).getKey() << ", Value: " << table.at(i).getData() << ", Overflow.size: " << table.at(i).getOverflowSize() << std::endl;
  }
}

template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) { //Complejidad O(n)
  if (size == maxSize) {
    throw std::out_of_range("Hash Table is full");
  }
  // Compute the index of the table using a key and a hash function
  int hashVal = getHashIndex(keyVal); 
  HashNode<K, T> node = table.at(hashVal);
  // The cell in the table is not taken
  if (node.getStatus() != 1) {
    node.setKey(keyVal);
    node.setData(value);
    table.at(hashVal) = node;
  }
  else { // The cell in the table is already taken
    // Find next free space using quadratic probing
    int i = 1;
    int currentHashVal = getHashIndex(hashVal + i * i);
    HashNode<K, T> currentNode = table.at(currentHashVal);
    while (currentNode.getStatus() == 1) {
      colisiones++;
      i++;
      currentHashVal = getHashIndex(hashVal + i * i);
      currentNode = table.at(currentHashVal);
    }
    currentNode.setKey(keyVal);
    currentNode.setData(value);
    node.addToOverflow(currentHashVal);
    table.at(currentHashVal) = currentNode;
    table.at(hashVal) = node;
  }
  size++;
}  

template<class K, class T>
int HashTable<K,T>::find(K keyVal) { //Complejidad O(n)
  int hashVal = getHashIndex(keyVal); 
  HashNode<K, T> node = table.at(hashVal);
  // Cell in the table is taken
  if (node.getStatus() == 1) {
    if (node.getKey() == keyVal) {
      return hashVal;
    }
    for (int i = 0; i < node.getOverflowSize(); i++) {
      int overflowIndex = node.getOverflowAt(i);
      if (table.at(overflowIndex).getKey() == keyVal) {
        return overflowIndex;
      }
    }
    return -1;
  }
  return -1;
}

template<class K, class T>
T HashTable<K,T>::getDataAt(int index) { //Complejidad O(1)
  return table.at(index).getData();
}

template<class K, class T>
void HashTable<K,T>::remove(K keyVal) { //Complejidad O(1)
  int pos, hashVal;
  pos = find(keyVal);
  if (pos == -1) {
    throw std::invalid_argument("Element does not exist in hash table");
  }
  hashVal = getHashIndex(keyVal);
  if (pos != hashVal) {
    HashNode<K, T> node = table.at(hashVal);
    node.removeFromOverflow(pos);
    table.at(hashVal) = node;
  }
  table.at(pos).clearData(); 
}

template<class K, class T>
int HashTable<K,T>::getColisiones(){ //Complejidad O(1)
  return colisiones;
}


#endif // __HASH_TABLE_H_

