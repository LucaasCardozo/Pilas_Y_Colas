#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct Nodo {

    DatoPtr dato;
    NodoPtr siguiente;

};

DatoPtr getDato(NodoPtr nodo){

    return nodo->dato;

};

NodoPtr getSiguiente(NodoPtr nodo){

    return nodo->siguiente;

};

void setDato(NodoPtr nodo, DatoPtr d){

    nodo->dato = d;

};

void setSiguiente(NodoPtr nodo, NodoPtr sig){

    nodo->siguiente = sig;

};

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){

    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

void mostrarNodoInt(NodoPtr nodo){

    printf("{ %d }", *(int*)(nodo->dato));

};

void mostrarNodoIntDatoPtr(void * dato){

    NodoPtr n = dato;

    mostrarNodoInt(n);

};

void mostrarNodoFloat(NodoPtr nodo){

    printf("{ %.2f }", *(float*)(nodo->dato));

};

void mostrarNodoFloatDatoPtr(void * dato){

    NodoPtr f = dato;

    mostrarNodoFloat(f);

};

void mostrarNodoChar(NodoPtr nodo){

    printf("{ %s }", (char*)(nodo->dato));

};

void mostrarNodoCharDatoPtr(void * dato){

    NodoPtr c = dato;

    mostrarNodoChar(c);

};

void mostrarNodoGenerico(NodoPtr nodo, void(*ptrFuncionMostrarNodo)(DatoPtr)){

    ptrFuncionMostrarNodo(nodo);

};

void liberarNodo(NodoPtr nodo){

    free(nodo);


};
