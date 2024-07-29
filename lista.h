#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

NodoPtr getPrimeroLista(ListaPtr lista);
void setPrimeroLista(ListaPtr lista, NodoPtr nuevoPrimero);

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);


DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

int obtenerTamanio(ListaPtr lista);

int comparacionInt(DatoPtr d1, DatoPtr d2);
int comparacionFloat(DatoPtr d1, DatoPtr d2);
int comparacionChar(DatoPtr d1, DatoPtr d2);
void ordenarListaBurbujeo(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
void ordenarListaSeleccion(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
void ordenarListaInsersion(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
ListaPtr ordenarListaCopia(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
ListaPtr duplicarLista(ListaPtr lista);

int buscarInt(DatoPtr d1, DatoPtr d2);
int buscarFloat(DatoPtr d1, DatoPtr d2);
int buscarChar(DatoPtr d1, DatoPtr d2);
int buscarElemento(ListaPtr lista, DatoPtr datoQBusco, int(*resultadoComparacion)(DatoPtr, DatoPtr));
int busquedaBinaria(ListaPtr lista, DatoPtr datoQBusco, int(*resultadoComparacion)(DatoPtr, DatoPtr), int(*resultadoIgualacion)(DatoPtr, DatoPtr));

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int(*resultadoComparacion)(DatoPtr, DatoPtr));

void mostrarListaGenerico(ListaPtr lista, void(*ptrFuncionMostrar)(DatoPtr));

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
