#ifndef HEAP_H_			//Reciclado del código visto en clase del viernes 18 Oct
#define HEAP_H_			//adaptado a los requerimientos de mi clase Vehiculo

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>
#include "Vehiculo.h" 

template <class T>
class Heap {
public:
	T *data;
	unsigned int size;
	unsigned int count;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

	Heap(unsigned int) ;
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T) ;
	T remove(float) ;
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int sze)  {
	size = sze;
	data = new T[size];
	if (data == 0) {
		throw OutOfMemory();
	}
	count = 0;
}

template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = 0;
	size = 0;
	count = 0;
}

template <class T>
bool Heap<T>::empty() const {
	return (count == 0);
}

template <class T>
bool Heap<T>::full() const {
	return (count == size);
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;

	// Comparar usando el precio del Vehiculo
	if (le < count && data[le].getPrecio() < data[min].getPrecio()) {
		min = le;
	}
	if (ri < count && data[ri].getPrecio() < data[min].getPrecio()) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::add(T val)  {
	unsigned int pos;
	if (full()) {
		throw Overflow();
	}

	pos = count;
	data[count++] = val;  // Agregar directamente el valor y aumentar el contador
	while (pos > 0 && data[pos].getPrecio() < data[parent(pos)].getPrecio()) {
		swap(pos, parent(pos));
		pos = parent(pos);
	}
}

template <class T>
T Heap<T>::remove(float precio) {
    if (empty()) {
        throw NoSuchElement();
    }
    
    unsigned int index = count;
    for (unsigned int i = 0; i < count; i++) {
        if (data[i].getPrecio() == precio) {
            index = i;
            break;
        }
    }
    
    if (index == count) {
        throw NoSuchElement();
    }

    T aux = data[index];
    data[index] = data[--count]; 
    heapify(index);
    return aux;
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i].getDatos();
	}
	aux << "]";
	return aux.str();
}

#endif
