#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;

typedef void * DatoPtr;

DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr d);
void setSiguiente(NodoPtr nodo, NodoPtr sig);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

void mostrarNodoInt(NodoPtr nodo);
void mostrarNodoIntDatoPtr(void * dato);
void mostrarNodoFloat(NodoPtr nodo);
void mostrarNodoFloatDatoPtr(void * dato);
void mostrarNodoChar(NodoPtr nodo);
void mostrarNodoCharDatoPtr(void * dato);
void mostrarNodoGenerico(NodoPtr nodo, void(*ptrFuncionMostrarNodo)(DatoPtr));

void liberarNodo(NodoPtr nodo);


//


#endif // NODO_H_INCLUDED
