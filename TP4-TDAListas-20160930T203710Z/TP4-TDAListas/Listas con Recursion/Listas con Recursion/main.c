#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
1. Recorrer una lista y mostrarla en forma invertida.
*/

void mostrarListaInvertidaR(nodo * lista)
{
    if(lista!=NULL)
    {
        mostrarListaInvertidaR(lista->siguiente);
        mostrar(lista);
    }
}

/*
2. Sumar los elementos de una lista.
*/

int sumaContenidoListaR(nodo *lista)
{
    int rta=0;
    if(lista!=NULL)
    {
        rta=lista->dato+sumaContenidoListaR(lista->siguiente);
    }
    return rta;
}

/*
3. Mostrar los elementos de una lista ubicados en un lugar par.
*/

void muestraPosParR (nodo *lista, int pos)
{
    if(lista!=NULL)
    {
        if(pos%2==0)
        {
            mostrar(lista);
        }
        muestraPosParR(lista->siguiente, pos+1);
    }
}

/*
4. Invertir una lista cambiando los vínculos.
*/

nodo * invertirRecursivo (nodo * lista)
{
    /*
        si esta vacia, retorno NULL
        si tiene un solo nodo, retorna lista
        si tiene mas de un nodo, tomo el 1er nodo, invierto lo que sigue y
        lo agrego al final de la lista invertida

        nos vamos a ayudar con la funcion agregar al final

        primero tengo que desvicular al nodo de la lista
        OJO no perder las referencias...
    */
    nodo * rta=NULL;
    nodo * primero=NULL;

    if(lista!=NULL)
    {
        primero=lista;  // guardo el primero nodo
        lista=lista->siguiente;   // avanzo en la lista
        primero->siguiente=NULL;  // desvinculo el primero nodo
        rta=agregarFinal(invertirRecursivo(lista),primero);
    }
    return rta;

}
/*
5. Borrar un nodo de una lista.
*/

nodo * borrarNodoR( nodo * lista, int dato)
{
    nodo * aBorrar =NULL;

    if(lista!=NULL)
    {
        if(lista->dato==dato)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente=borrarNodoR(lista->siguiente,dato);
        }
    }
    return lista;
}

/*
6. Insertar un nodo en una lista (que ya está ordenada) en forma recursiva.
*/

nodo* insertarEnOrdenR(nodo * lista, nodo * nuevo)
{

    if(lista == NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato < lista->dato)
        {
            nuevo->siguiente = lista;
            lista = nuevo;
        }
        else
        {
            lista->siguiente = insertarEnOrdenR(lista->siguiente, nuevo);
        }
    }
    return lista;
}

int main()
{
    printf("Hello listas con recursion!\n");

    nodo * lista = inicLista();
    nodo * nuevo;
    int i=0;
    for(i=0;i<10;i++)
    {
        nuevo=crearNodo(i);
        lista= agregarFinal(lista, nuevo);
    }

    printf("\nContenido de la lista:");
    recorrerYmostrar(lista);

    printf("\nContenido de la lista invertido:");
    mostrarListaInvertidaR(lista);

    int suma=sumaContenidoListaR(lista);
    printf("\n\nLa suma de la lista es: %d \n",suma);

    printf("\nContenido de la lista en las posiciones pares:");
    muestraPosParR(lista,0);

    lista=invertirRecursivo(lista);
    printf("\n\nContenido de la lista despues de invertirla:");
    recorrerYmostrar(lista);

    lista=borrarNodoR(lista, 5);
    printf("\nContenido de la lista despues de borrar un dato:");
    recorrerYmostrar(lista);

    lista=invertirRecursivo(lista);

    lista=insertarEnOrdenR(lista, crearNodo(4));
    printf("\nContenido de la lista despues de insertar un dato:");
    recorrerYmostrar(lista);
    return 0;
}
