#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;

typedef struct Cola * ColaPtr;

NodoPtr getUltimoCola(ColaPtr cola);
NodoPtr getPrimeroCola(ColaPtr cola);

void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo);
void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero);

ColaPtr crearCola();
void encolar(ColaPtr cola, DatoPtr dato); ///ENCOLAR - ENQUEUE
DatoPtr desencolar(ColaPtr cola); ///DESENCOLAR - DEQUEUE
ColaPtr duplicarCola(ColaPtr cola);
void liberarCola(ColaPtr cola);

#endif // LISTA_H_INCLUDED
