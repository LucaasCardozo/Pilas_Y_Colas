#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"
#include "lista.h"
#include "cola.h"
#include "pila.h"

int main()
{

    printf("\n ****************** COLAS ******************\n");

    ColaPtr cola = crearCola();

    int n1 = 10, n2 = 56, n3 = 5, n4 = 98, n5 = 1, n6 = 46;

    encolar(cola, &n1);
    encolar(cola, &n2);
    encolar(cola, &n3);
    encolar(cola, &n4);
    encolar(cola, &n5);
    encolar(cola, &n6);

    printf("\n ----- COLA INT -----\n");
    printf("\nELIMINAMOS EL NUMERO %d DE LA COLA\n", *(int*)desencolar(cola));
    printf("\nELIMINAMOS EL NUMERO %d DE LA COLA\n", *(int*)desencolar(cola));
    printf("\nELIMINAMOS EL NUMERO %d DE LA COLA\n", *(int*)desencolar(cola));

    ColaPtr colaDuplicada = duplicarCola(cola);

    printf("\n ----- COLA INT DUPLICADA -----\n");
    printf("\nELIMINAMOS EL NUMERO %d DE LA COLA\n", *(int*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %d DE LA COLA\n", *(int*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %d DE LA COLA\n", *(int*)desencolar(colaDuplicada));
    desencolar(cola);

    liberarCola(cola);
    liberarCola(colaDuplicada);

    cola = crearCola();

    float f1 = 1.26, f2 = 75.21, f3 = 48.63, f4 = 4, f5 = 7.13, f6 = 17.98;

    encolar(cola, &f1);
    encolar(cola, &f2);
    encolar(cola, &f3);
    encolar(cola, &f4);
    encolar(cola, &f5);
    encolar(cola, &f6);

    printf("\n\n ----- COLA FLOAT -----\n");
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA COLA\n", *(float*)desencolar(cola));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA COLA\n", *(float*)desencolar(cola));

    colaDuplicada = duplicarCola(cola);

    printf("\n ----- COLA FLOAT DUPLICADA -----\n");
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA COLA\n", *(float*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA COLA\n", *(float*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA COLA\n", *(float*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA COLA\n", *(float*)desencolar(colaDuplicada));
    desencolar(colaDuplicada);

    liberarCola(cola);
    liberarCola(colaDuplicada);

    cola = crearCola();

    char nom1[] = "Julian", nom2[] = "Franco", nom3[] = "Luz", nom4[] = "Norma", nom5[] = "Federico";

    encolar(cola, nom1);
    encolar(cola, nom2);
    encolar(cola, nom3);
    encolar(cola, nom4);
    encolar(cola, nom5);

    printf("\n\n ----- COLA CHAR -----\n");
    printf("\nELIMINAMOS EL NOMBRE '%s' DE LA COLA\n", (char*)desencolar(cola));

    colaDuplicada = duplicarCola(cola);

    printf("\n ----- COLA CHAR DUPLICADA -----\n");
    printf("\nELIMINAMOS EL NOMBRE '%s' DE LA COLA\n", (char*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NOMBRE '%s' DE LA COLA\n", (char*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NOMBRE '%s' DE LA COLA\n", (char*)desencolar(colaDuplicada));
    printf("\nELIMINAMOS EL NOMBRE '%s' DE LA COLA\n", (char*)desencolar(colaDuplicada));
    desencolar(colaDuplicada);

    liberarCola(cola);
    liberarCola(colaDuplicada);

    printf("\n\n\n ****************** PILAS ******************\n");

    printf("\n ----- PILA INT  -----\n");

    PilaPtr pila = crearPila();

    int num1 = 50, num2 = 31, num3 = 75, num4 = 45, num5 = 36, num6 = 107;

    apilar(pila, &num1);
    apilar(pila, &num2);
    apilar(pila, &num3);
    apilar(pila, &num4);
    apilar(pila, &num5);
    apilar(pila, &num6);

    printf("\nELIMINAMOS EL NUMERO %d DE LA PILA\n", *(int*)desapilar(pila));
    printf("\nELIMINAMOS EL NUMERO %d DE LA PILA\n", *(int*)desapilar(pila));
    printf("\nELIMINAMOS EL NUMERO %d DE LA PILA\n", *(int*)desapilar(pila));
    printf("\nELIMINAMOS EL NUMERO %d DE LA PILA\n", *(int*)desapilar(pila));

    printf("\n ----- PILA INT DUPLICADA -----\n");

    PilaPtr pilaDuplicada = duplicarPila(pila);

    printf("\nELIMINAMOS EL NUMERO %d DE LA PILA\n", *(int*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %d DE LA PILA\n", *(int*)desapilar(pilaDuplicada));
    desapilar(pilaDuplicada);

    liberarPila(pila);
    liberarPila(pilaDuplicada);

    printf("\n\n ----- PILA FLOAT  -----\n");

    pila = crearPila();

    float fl1 = 110.52, fl2 = 3.19, fl3 = 7.55, fl4 = 4.56, fl5 = 3.62, fl6 = 13.7;

    apilar(pila, &fl1);
    apilar(pila, &fl2);
    apilar(pila, &fl3);
    apilar(pila, &fl4);
    apilar(pila, &fl5);
    apilar(pila, &fl6);

    printf("\nELIMINAMOS EL NUMERO %.2f DE LA PILA\n", *(float*)desapilar(pila));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA PILA\n", *(float*)desapilar(pila));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA PILA\n", *(float*)desapilar(pila));

    printf("\n ----- PILA FLOAT DUPLICADA -----\n");

    pilaDuplicada = duplicarPila(pila);

    printf("\nELIMINAMOS EL NUMERO %.2f DE LA PILA\n", *(float*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA PILA\n", *(float*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL NUMERO %.2f DE LA PILA\n", *(float*)desapilar(pilaDuplicada));
    desapilar(pilaDuplicada);

    liberarPila(pila);
    liberarPila(pilaDuplicada);

    printf("\n\n ----- PILA CHAR  -----\n");

    pila = crearPila();

    char apellido1[] = "Messi", apellido2[] = "Suarez", apellido3[] = "Peralta", apellido4[] = "Toledo", apellido5[] = "Vera", apellido6[] = "Martinez";

    apilar(pila, apellido1);
    apilar(pila, apellido2);
    apilar(pila, apellido3);
    apilar(pila, apellido4);
    apilar(pila, apellido5);
    apilar(pila, apellido6);

    printf("\nELIMINAMOS EL APELLIDO '%s' DE LA PILA\n", (char*)desapilar(pila));

    printf("\n ----- PILA CHAR DUPLICADA -----\n");

    pilaDuplicada = duplicarPila(pila);

    printf("\nELIMINAMOS EL APELLIDO '%s' DE LA PILA\n", (char*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL APELLIDO '%s' DE LA PILA\n", (char*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL APELLIDO '%s' DE LA PILA\n", (char*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL APELLIDO '%s' DE LA PILA\n", (char*)desapilar(pilaDuplicada));
    printf("\nELIMINAMOS EL APELLIDO '%s' DE LA PILA\n", (char*)desapilar(pilaDuplicada));
    desapilar(pilaDuplicada);

    liberarPila(pila);
    liberarPila(pilaDuplicada);

    return 0;
}
