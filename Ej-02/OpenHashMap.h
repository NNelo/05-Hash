//
// Created by Nelo on 21/10/2017.
//

#ifndef INC_05_HASH_OPENHASHMAP_H
#define INC_05_HASH_OPENHASHMAP_H

#include "../HashMap/HashEntry.h"
#include "Lista.h"

template<class K, class T>
class OpenHashMap {
private:
    Lista<HashEntry<K, T>> *tabla;

    unsigned int size;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    OpenHashMap(unsigned int);

    OpenHashMap(unsigned int, unsigned int (*)(K));

    ~OpenHashMap();

    void put(K, T);

    T get(K);

    void remove(K);

    bool esVacio();
};

template<class K, class T>
OpenHashMap<K, T>::OpenHashMap(unsigned int m) : size(m), hashFuncP(hashFunc) {
    tabla = new Lista<HashEntry<K, T>>[m];  //inicializar listas con constructor por defecto?
}

template<class K, class T>
OpenHashMap<K, T>::OpenHashMap(unsigned int tam, unsigned int (*fp)(K)) : size(tam), hashFuncP(fp) {
    tabla = new Lista<HashEntry<K, T>>[tam];
}

template<class K, class T>
OpenHashMap<K, T>::~OpenHashMap() {
    for (int i = 0; i < size; ++i)
        tabla[i].vaciar();
    delete tabla;
}

template<class K, class T>
void OpenHashMap<K, T>::put(K clave, T elemento) {
    tabla[hashFunc(clave) % size].insertarUltimo({clave, elemento});
}

template<class K, class T>
T OpenHashMap<K, T>::get(K clave) {
    Lista<HashEntry<K, T>> *aux = &tabla[hashFunc(clave)];
    for (int i = 0; i < aux->getTamanio(); ++i)   //ya recorrio una vez la lista :(
        if (aux->getDato(i).getKey() == clave)
            return aux->getDato(i);
    throw -1;
}

template<class K, class T>
void OpenHashMap<K, T>::remove(K clave) {
    Lista<HashEntry<K, T>> *aux = &tabla[hashFunc(clave)];
    for (int i = 0; i < aux->getTamanio(); ++i)
        if (aux->getDato(i).getKey() == clave)
            aux->remover(i);
    throw -1;
}

template<class K, class T>
bool OpenHashMap<K, T>::esVacio() {
    return size == 0;
}

template <class K, class T>
unsigned int OpenHashMap<K,T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

#endif //INC_05_HASH_OPENHASHMAP_H