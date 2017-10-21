//
// Created by Nelo on 21/10/2017.
//

#ifndef INC_05_HASH_LISTA_H
#define INC_05_HASH_LISTA_H

#include <iostream>

template<class T>
class Nodo {
private:
    T dato;
    Nodo *next;

public:
    Nodo() {
        next = NULL;
    }

    Nodo(T d, Nodo *n) {
        dato = d;
        next = n;
    }

    T getDato() {
        return dato;
    }

    void setDato(T d) {
        dato = d;
    }

    Nodo *getNext() {
        return next;
    }

    void setNext(Nodo *n) {
        next = n;
    }
};

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    void remover(T);

    void remover(Nodo<T> *);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    bool pertenece(T);

    Nodo<T> *delataNodo(T);

    Nodo<T> *getInicio() const;
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = NULL;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {
    inicio = new Nodo<T>();

    Nodo<T> *auxli = li.inicio;
    Nodo<T> *auxnn = inicio;

    while (auxli != NULL) {
//        this->insertarUltimo(auxli->getDato());
//        auxli = auxli->getNext();

//        auxnn->setDato(auxli->getDato());
        Nodo<T> *newNode = new Nodo<T>;
        auxnn->setDato(auxli->getDato());

        auxnn->setNext(newNode);

        auxnn = auxnn->getNext();
        auxli = auxli->getNext();
    }
}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
    vaciar();
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() {
    return inicio == NULL;
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int cont = 0;

    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    return cont;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    int cont = 0;
    Nodo<T> *aux = inicio;

    if (pos == 0) {
        Nodo<T> *nn = new Nodo<T>(dato, inicio);
        inicio = nn;
        return;
    }

    while (cont < pos - 1 && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == NULL)
        throw 1;

    Nodo<T> *nn = new Nodo<T>(dato, aux->getNext());
    aux->setNext(nn);
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    Nodo<T> *nn = new Nodo<T>(dato, inicio);
    inicio = nn;
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    if (NULL == inicio) {
        inicio = new Nodo<T>(dato, NULL);
        return;
    }

    Nodo<T> *aux = inicio;
    while (aux->getNext() != NULL) {
        aux = aux->getNext();
    }
    Nodo<T> *nn = new Nodo<T>(dato, NULL);
    aux->setNext(nn);
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    int cont = 0;
    Nodo<T> *aux = inicio;

    if (pos == 0) {

        if (inicio == NULL)
            throw 1;

        inicio = inicio->getNext();
        delete[] aux;
        return;
    }

    while (cont < pos - 1 && aux->getNext() != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (aux->getNext() == NULL)
        throw 1;

    Nodo<T> *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete[] tmp;
}

template<class T>
void Lista<T>::remover(T valor) {
    Nodo<T> *aux = inicio;
    Nodo<T> *ant = nullptr;

    while (aux != valor && aux != nullptr) {
        ant = aux;
        aux = aux->getNext();
    }

    if (nullptr == aux)
        throw -1;

    if (nullptr == ant)
        inicio = inicio->getNext();
    else
        ant->setNext(aux->getNext());

    delete aux;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    int i = 0;
    Nodo<T> *aux = inicio;
    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 1;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    int i = 0;
    Nodo<T> *aux = inicio;
    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 1;

    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *borr;
    Nodo<T> *aux = inicio;

    while (aux != NULL) {
        borr = aux;
        aux = aux->getNext();
        delete[] borr;
    }
    inicio = NULL;
}

template<class T>
bool Lista<T>::pertenece(T dato) {
    Nodo<T> *aux = inicio;
    while (aux != NULL) {
        if (aux->getDato() == dato)
            return true;
        aux = aux->getNext();
    }
    return false;
}

/**
 * Función que devuelve la ubicacion de un nodo con un valor especifico
 * @tparam T valor que se espera del nodo
 * NOTE: se implementa para cambiar el valor de un vertice en un grafo
 */
template<class T>
Nodo<T> *Lista<T>::delataNodo(T buscado) {
    Nodo<T> *aux = inicio;

    while (nullptr != aux && aux->getDato() != buscado)
        aux = aux->getNext();

    if (nullptr == aux)
        throw -1;

    return aux;
}

template<class T>
Nodo<T> *Lista<T>::getInicio() const {
    return inicio;
}


#endif //INC_05_HASH_LISTA_H
