#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lista.h"

struct Lista{

    NodoPtr primero;

};

NodoPtr getPrimeroLista(ListaPtr lista){

    return lista->primero;

};

void setPrimeroLista(ListaPtr lista, NodoPtr nuevoPrimero){

    lista->primero = nuevoPrimero;

};

ListaPtr crearLista(){

    ListaPtr lista = (ListaPtr)malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};


void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};


void insertarUltimo(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    NodoPtr actual = lista->primero;

    if(actual == NULL){

        insertarPrimero(lista, dato);

    }else{

        while(getSiguiente(actual) != NULL){

            actual = getSiguiente(actual);

        }

        setSiguiente(actual, nuevoNodo);
    }

};

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){

    int tam = obtenerTamanio(lista);

    if(posicion > tam+1){

        printf("\nERROR!! LA POSICION INGRESADA NO EXISTE\n");

    }else{

        if(posicion < 0){

            printf("\nERROR!! NO SE PUEDE INGRESAR EN POSICIONES NEGATIVAS\n");

        }else{

            if(posicion == 0){

                insertarPrimero(lista, dato);

            }else{

                if(posicion == tam){

                    insertarUltimo(lista, dato);

                }else{

                    NodoPtr actual = lista->primero;

                    for(int i=0; i<posicion-1; i++){

                        actual = getSiguiente(actual);

                    }

                    NodoPtr nuevoNodo = crearNodo(dato, getSiguiente(actual));

                    setSiguiente(actual, nuevoNodo);

                }

            }

        }

    }

};


DatoPtr obtenerPrimero(ListaPtr lista){

    return getDato(lista->primero);

};

DatoPtr obtenerUltimo(ListaPtr lista){

    NodoPtr actual = lista->primero;

    while(getSiguiente(actual) != NULL){

        actual = getSiguiente(actual);

    }

    return getDato(actual);

};

DatoPtr obtenerPosicion(ListaPtr lista, int posicion){

    int tam = obtenerTamanio(lista);

    if(posicion >= tam){

        printf("\nERROR!! LA POSICION INGRESADA NO EXISTE\n");

    }else{

        if(posicion < 0){

            printf("\nERROR!! LA POSICION INGRESADA NO EXISTE\n");

        }else{

            if(posicion == 0){

                return getDato(lista->primero);

            }else{

                if(posicion == tam-1){

                    return obtenerUltimo(lista);

                }else{

                    NodoPtr actual = lista->primero;

                    for(int i=0; i<posicion; i++){

                        actual = getSiguiente(actual);

                    }

                    return getDato(actual);

                }

            }

        }

    }

    return NULL;

};

DatoPtr eliminarPrimero(ListaPtr lista){

    if(lista->primero == NULL){

        printf("\nLA LISTA ESTA VACIA\n");

    }

    DatoPtr valor = getDato(lista->primero);

    NodoPtr aux = lista->primero;

    lista->primero = getSiguiente(lista->primero);

    liberarNodo(aux);

    return valor;

};

DatoPtr eliminarUltimo(ListaPtr lista){

    if(lista->primero == NULL){

        printf("\nLA LISTA ESTA VACIA\n");

    }

    if(getSiguiente(lista->primero) == NULL){

        DatoPtr valor = getDato(lista->primero);

        NodoPtr aux = lista->primero;

        lista->primero = NULL;

        free(aux);

        return valor;

    }

    NodoPtr actual = lista->primero;

    while(getSiguiente(getSiguiente(actual)) != NULL){

        actual = getSiguiente(actual);

    }

    DatoPtr valor = getDato(getSiguiente(actual));

    NodoPtr aux = getSiguiente(actual);

    setSiguiente(actual, NULL);

    free(aux);

    return valor;

};

DatoPtr eliminarPosicion(ListaPtr lista, int posicion){

    int tam = obtenerTamanio(lista);

    if(posicion >= tam){

        printf("\nERROR!! LA POSICION QUE DESEA ELIMINAR NO EXISTE\n");

    }else{

        if(posicion < 0){

            printf("\nERROR!! LA POSICION QUE DESEA ELIMINAR NO EXISTE\n");

        }else{

            if(posicion == 0){

                return eliminarPrimero(lista);

            }else{

                if(posicion == tam-1){

                    return eliminarUltimo(lista);

                }else{

                    NodoPtr actual = lista->primero;

                    for(int i=0; i<posicion-1; i++){

                        actual = getSiguiente(actual);

                    }

                    NodoPtr aux = getSiguiente(actual);

                    DatoPtr valor = getDato(aux);

                    setSiguiente(actual, getSiguiente(aux));

                    free(aux);

                    return valor;

                }

            }

        }

    }

    return NULL;

};

int obtenerTamanio(ListaPtr lista){

    int tam = 0;

    NodoPtr actual = lista->primero;

    while(actual != NULL){

        tam++;
        actual = getSiguiente(actual);

    }

    return tam;

};

int comparacionInt(DatoPtr d1, DatoPtr d2){

    int num1 = *(int*)d1;
    int num2 = *(int*)d2;

    return num1 > num2;

};

int comparacionFloat(DatoPtr d1, DatoPtr d2){

    float num1 = *(float*)d1;
    float num2 = *(float*)d2;

    return num1 > num2;

};

int comparacionChar(DatoPtr d1, DatoPtr d2){

    char* nom1 = (char*)d1;
    char* nom2 = (char*)d2;

    int resultado = strcmp(nom1, nom2);

    if(resultado > 0){

        return 1;

    }else{

        return 0;

    }

};

void ordenarListaBurbujeo(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int permutacion;
    DatoPtr aux;
    NodoPtr actual;

    if(obtenerTamanio(lista) < 2){
        //Ya está ordenada
    }else{

        do{
            permutacion = 0;
            actual = lista->primero;

            while(getSiguiente(actual) != NULL){

                if(resultadoComparacion(getDato(actual), getDato(getSiguiente(actual)))){

                    aux = getDato(actual);
                    setDato(actual, getDato(getSiguiente(actual)));
                    setDato(getSiguiente(actual), aux);
                    permutacion = 1;

                }

                actual = getSiguiente(actual);

            }


        }while(permutacion != 0);

    }

};

void ordenarListaSeleccion(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int permutacion;
    DatoPtr aux;
    NodoPtr minimo = lista->primero;
    NodoPtr actual;

    if(obtenerTamanio(lista) < 2){
        //Ya está ordenada
    }else{

        do{
            permutacion = 0;
            actual = getSiguiente(minimo);

            while(actual != NULL){

                if(resultadoComparacion(getDato(minimo), getDato(actual))){

                    aux = getDato(minimo);
                    setDato(minimo, getDato(actual));
                    setDato(actual, aux);
                    permutacion = 1;

                }

                actual = getSiguiente(actual);

            }

            minimo = getSiguiente(minimo);

        }while(permutacion != 0);

    }

};

void ordenarListaInsersion(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int permutacion;
    DatoPtr aux;
    NodoPtr actual = getSiguiente(lista->primero);
    NodoPtr izquierda;
    int cont = 0;
    int cont2 = 0;

    if(obtenerTamanio(lista) < 2){
        //Ya está ordenada
    }else{

        while(actual != NULL){

            permutacion = 0;
            aux = getDato(actual);
            izquierda = lista->primero;
            cont = cont2;

            for(int i=0; i<cont; i++){

                    izquierda = getSiguiente(izquierda);

            }

            while((resultadoComparacion(getDato(izquierda), aux)) && (cont >= 0)){

                setDato(getSiguiente(izquierda), getDato(izquierda));
                cont--;
                permutacion = 1;

                izquierda = lista->primero;

                for(int i=0; i<cont; i++){

                    izquierda = getSiguiente(izquierda);

                }

            }

            if(permutacion == 1){

                if(cont == -1){

                    setDato(izquierda, aux);

                }else{

                setDato(getSiguiente(izquierda), aux);

                }
            }

            actual = getSiguiente(actual);
            cont2++;

        }

    }

};

ListaPtr ordenarListaCopia(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    ListaPtr listaDuplicadaOrdenada = duplicarLista(lista);

    ordenarListaBurbujeo(listaDuplicadaOrdenada, resultadoComparacion);

    return listaDuplicadaOrdenada;

};

ListaPtr duplicarLista(ListaPtr lista){

    ListaPtr listaDuplicada = crearLista();

    NodoPtr actual = lista->primero;

    while(actual != NULL){

        insertarUltimo(listaDuplicada, getDato(actual));

        actual = getSiguiente(actual);

    }

    return listaDuplicada;

};

int buscarInt(DatoPtr d1, DatoPtr d2){

    int num1 = *(int*)d1;
    int num2 = *(int*)d2;

    return num1 == num2;

};

int buscarFloat(DatoPtr d1, DatoPtr d2){

    float num1 = *(float*)d1;
    float num2 = *(float*)d2;

    return num1 == num2;

};

int buscarChar(DatoPtr d1, DatoPtr d2){

    char* num1 = (char*)d1;
    char* num2 = (char*)d2;

    int resultado = strcmp(num1, num2);

    if(resultado == 0){

        return 1;

    }else{

        return 0;

    }

};

int buscarElemento(ListaPtr lista, DatoPtr datoQBusco, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int posc = 0;

    NodoPtr actual = lista->primero;

    while(actual != NULL){

        if(resultadoComparacion(datoQBusco, getDato(actual))){

            return posc;

        }

        actual = getSiguiente(actual);

        posc++;

    }

    return -1; //El dato buscado no fue encontrado

};

int busquedaBinaria(ListaPtr lista, DatoPtr datoQBusco, int(*resultadoComparacion)(DatoPtr, DatoPtr), int(*resultadoIgualacion)(DatoPtr, DatoPtr)){

    int izquierda = 0;
    int derecha = obtenerTamanio(lista)-1;
    NodoPtr actual;

    while(izquierda <= derecha){

        int centro = floor((izquierda+derecha)/2);
        actual = lista->primero;

        for(int i=0; i<centro; i++){

            actual = getSiguiente(actual);

        }

        DatoPtr datoDelCentro = getDato(actual);

        if(resultadoIgualacion(datoQBusco, datoDelCentro)){

            return centro;

        }

        if(resultadoComparacion(datoDelCentro, datoQBusco)){

            derecha = centro - 1;

        }
        else{

            izquierda = centro + 1;

        }

    }

    return -1; //El dato buscado no fue encontrado

};

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    NodoPtr actual = lista->primero;

    if(actual == NULL){

        insertarPrimero(lista, dato);

    }else{

        if(getSiguiente(actual) == NULL){

            if(resultadoComparacion(getDato(actual), dato)){

                insertarPrimero(lista, dato);

            }else{

                insertarUltimo(lista, dato);

            }

        }else{

            if(resultadoComparacion(getDato(actual), dato)){

                insertarPrimero(lista, dato);

            }else{

                int posc = 0;

                while(getSiguiente(actual) != NULL && resultadoComparacion(dato, getDato(getSiguiente(actual))) ){

                    actual = getSiguiente(actual);

                    posc++;

                }

                    insertarPosicion(lista, dato, posc+1);

            }

        }

    }

};

void mostrarListaGenerico(ListaPtr lista, void(*ptrFuncionMostrar)(DatoPtr)){

    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;

    while (actual != NULL){

        mostrarNodoGenerico(actual, ptrFuncionMostrar);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};

void liberarLista(ListaPtr lista){

    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL){

        aux = actual;
        actual = getSiguiente(actual);
        free(aux);

    };
};

