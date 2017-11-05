//
// Created by nelon on 5/11/2017.
//

#ifndef INC_05_HASH_REHASHMAP_H
#define INC_05_HASH_REHASHMAP_H

#include "../HashMap/HashEntry.h"

template<class K, class T>
class ReHashMap {
private:
    HashEntry<K, T> **tabla;
    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    ReHashMap(unsigned int tamanio);

    ReHashMap(unsigned int tamanio, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~ReHashMap();

    bool esVacio();

    void reHashing(unsigned int);

};

template<class K, class T>
ReHashMap<K, T>::ReHashMap(unsigned int tamanio) {
    this->tamanio = tamanio;
    hashFuncP = hashFunc;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; ++i) {
        tabla[i] = nullptr;
    }
}

template<class K, class T>
ReHashMap<K, T>::~ReHashMap() {
    for (int i = 0; i < tamanio; ++i)
        if (tabla[i] != nullptr)
            delete tabla[i];
}

template<class K, class T>
T ReHashMap<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos] == nullptr)
        throw 2;
    return tabla[pos]->getDato();
}

template<class K, class T>
void ReHashMap<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;   //saneada
    if (tabla[pos] != nullptr)
        throw 1;

    tabla[pos] = new HashEntry<K, T>(clave, valor);
}

template<class K, class T>
void ReHashMap<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;
    if (tabla[pos] != nullptr) {
        delete tabla[pos];
        tabla[pos] = nullptr;
    }
}

template<class K, class T>
bool ReHashMap<K, T>::esVacio() {
    for (int i = 0; i < this->tamanio; ++i)
        if (tabla[i] != nullptr)
            return false;
    return true;
}

template<class K, class T>
unsigned int ReHashMap<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

template<class K, class T>
void ReHashMap<K, T>::reHashing(unsigned int nuevo_tamanio) {
    HashEntry<K, T> **Ntabla = new HashEntry<K, T> *[nuevo_tamanio];
    for (int j = 0; j < nuevo_tamanio; ++j)
        Ntabla[j] = nullptr;
    // toda la nueva tabla esta vacia apuntando a null

    unsigned int tamanio_anterior = tamanio;
    this->tamanio = nuevo_tamanio;

    for (int i = 0; i < tamanio_anterior; ++i) {
        if (this->tabla[i] != nullptr) {
            unsigned int pos = this->hashFuncP(tabla[i]->getKey()) % this->tamanio;

            if (Ntabla[pos] != nullptr)
                throw -1;

            Ntabla[pos] = new HashEntry<K, T>(tabla[i]->getKey(), tabla[i]->getDato());

            delete this->tabla[i];
        }
    }
    delete this->tabla;
    this->tabla = Ntabla;
}

//constructor
template<class K, class T>
ReHashMap<K, T>::ReHashMap(unsigned int tamanio, unsigned int (*fp)(K)) {
    this->tamanio = tamanio;
    this->hashFuncP = fp;
    tabla = new HashEntry<K, T> *[tamanio];
    for (int i = 0; i < tamanio; ++i) {
        tabla[i] = nullptr;
    }
}

#endif //INC_05_HASH_REHASHMAP_H