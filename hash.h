//
//  hash.h

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    void* data;
    long key;
}HashElem;

typedef struct{
    HashElem** hashArray;
    int size; //cant. elementos no nulos
    int capac; //Dimension tabla
    int current;
}HashMap;

//crea un mapa hash y devuelve un puntero a el
HashMap* create_hashmap(int size);
//inserta un nuevo elemento a la tabla hash
void insert(HashMap* map, void* data, long key);
//elimina el elemento de la tabla hash con la llave ingresada
void erase(HashMap* map, long key);
//devuelve el elemento relacionado a la llave
void* search(HashMap* map ,long key);
//retorna el elemento en la primera posicion del mapa hash
void* first(HashMap* map);
//retorna el siguiente elemento en el hashmap(siguiente del current)
void* next(HashMap* map);

//////////////////////////////////////////////////////////////////////////////////
//FUNCIONES AUXILIARES
//agranda el tamaÒo del hashmap y reordena los punteros
void enlarge(HashMap* map);
//funcion para asignar un lugar en el arreglo a cada llave
int hash(long key,int capac);
//resuelve las oclisiones de llave en el hashmap
void solve_colition(HashMap* map, HashElem* element);



#endif // HASH_H_INCLUDED
