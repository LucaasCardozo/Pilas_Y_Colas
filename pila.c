#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

struct Pila{

    NodoPtr ultimo;

};

NodoPtr getUltimoPila(PilaPtr pila){

    return pila->ultimo;

};

void setUltimoPila(PilaPtr pila, NodoPtr nuevoUltimo){

    pila->ultimo = nuevoUltimo;

};

PilaPtr crearPila(){

    PilaPtr pila = (PilaPtr)malloc(sizeof(struct Pila));

    pila->ultimo = NULL;

    return pila;

};

void apilar(PilaPtr pila, DatoPtr dato){

        NodoPtr nuevoNodo = crearNodo(dato, pila->ultimo);

        pila->ultimo = nuevoNodo;

}; ///APILAR - PUSH

DatoPtr desapilar(PilaPtr pila){

    if(pila->ultimo == NULL){

        printf("\nLA PILA ESTA VACIA\n");

        return NULL;

    }else{

        DatoPtr valor = getDato(pila->ultimo);

        NodoPtr aux = pila->ultimo;
        pila->ultimo = getSiguiente(pila->ultimo);

        liberarNodo(aux);

        return valor;

    }

}; ///DESAPILAR - POP

PilaPtr duplicarPila(PilaPtr pila){

    PilaPtr pilaTemporal = crearPila();

    while(pila->ultimo != NULL){

        apilar(pilaTemporal, desapilar(pila));

    }

    PilaPtr pilaDuplicada = crearPila();

    while(pilaTemporal->ultimo != NULL){

        apilar(pilaDuplicada, desapilar(pilaTemporal));

    }

    return pilaDuplicada;

};

void liberarPila(PilaPtr pila){

    while(pila->ultimo != NULL){

        desapilar(pila);

    }

    free(pila);

};
