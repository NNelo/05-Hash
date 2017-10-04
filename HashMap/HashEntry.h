#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class K, class T>  //K key
class HashEntry {
private:
    K key;
    T dato;

public:
    HashEntry(K key, T dato) : key(key), dato(dato) {}


    K getKey() const {
        return key;
    }

    void setKey(K key) {
        HashEntry::key = key;
    }

    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        HashEntry::dato = dato;
    }
};

#endif //HASHENTRY_H