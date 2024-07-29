#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

struct Cola{

    NodoPtr primero;
    NodoPtr ultimo;

};

NodoPtr getUltimoCola(ColaPtr cola){

    return cola->ultimo;

};

NodoPtr getPrimeroCola(ColaPtr cola){

    return cola->primero;

};

void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo){

    cola->ultimo = nuevoUltimo;

};

void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero){

    cola->primero = nuevoPrimero;

};

ColaPtr crearCola(){

    ColaPtr cola = (ColaPtr)malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;

};

void encolar(ColaPtr cola, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if(cola->primero == NULL){

        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;

    }else{

        setSiguiente(cola->ultimo, nuevoNodo);

        cola->ultimo = nuevoNodo;

    }

}; ///ENCOLAR - ENQUEUE

DatoPtr desencolar(ColaPtr cola){

    if(cola->primero == NULL){

        printf("\nLA COLA ESTA VACIA\n");

        return NULL;

    }else{

        DatoPtr valor = getDato(cola->primero);

        NodoPtr aux = cola->primero;
        cola->primero = getSiguiente(cola->primero);

        liberarNodo(aux);

        return valor;

    }

}; ///DESENCOLAR - DEQUEUE

ColaPtr duplicarCola(ColaPtr cola){

    ColaPtr colaDuplicada = crearCola();

    while(cola->primero != NULL){

        encolar(colaDuplicada, desencolar(cola));

    }

    return colaDuplicada;

};

void liberarCola(ColaPtr cola){

    while(cola->primero != NULL){

        desencolar(cola);

    }

    free(cola);

};
