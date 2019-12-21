#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    char apellido[30];
    int edad;
    struct nodo * siguiente;
} nodo;

//DECLARACION DE FUNCIONES:

//FUNCIONES BASICAS PARA EL MANEJO DE LISTAS:
nodo * inicLista();
nodo * crearNodo(char nombre[20], int edad);
nodo * buscarNodo(char nombre[20], nodo * lista);
nodo * borrarNodo(char nombre[20], nodo * lista);
nodo * agregarPpio(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * borrarTodaLaLista(nodo * lista);

int sumarEdadesLista(nodo * lista);

///FUNCIONES QUE USAN LAS FUNCIONES DE LA LISTA, SIRVEN PARA ARMAR EL SISTEMA:

void mostrarNodo(nodo * aux);
void recorrerYmostrar(nodo * lista);
nodo * SubprogramaIngresarDatosAlFinal(nodo * lista);
nodo * SubprogramaingresarDatosAlPpio(nodo * lista);
nodo * SubprogramaAgregarUnNodoEnOrden(nodo * lista);
nodo * SubprogramaCrearListaOrdenada(nodo * lista);
void SubprogramaBusquedaDeUnNodo(nodo * lista);
nodo * SubprogramaBorrarNodo(nodo * lista);
void menu();

/// Eliminar ultimo nodo
nodo * eliminaUltimoNodo(nodo * lista);

/// Eliminar primer nodo

nodo * eliminaPrimerNodo(nodo * lista);

/// ////////////////////////////////////////////////////////////////////////
/// Practico 4
/// ////////////////////////////////////////////////////////////////////////

/// puntos 1, 2 y 3 no son complicados, plantearlos en clases

/// punto 4
nodo * intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C);
void SubprogramaIntercalarDosListas(nodo *listaA, nodo *listaB, nodo *listaC);

/// punto 5

/// lo hago en proyecto aparte


/// punto 6

nodo * invertirLista(nodo * lista);

int main()
{
    nodo * lista;
    nodo * listaA;
    nodo * listaB;
    nodo * listaC;

    int continuar, suma;

    lista = inicLista();
    listaA =inicLista();
    listaB =inicLista();
    listaC=inicLista();

    do
    {
        menu();
        printf("\nIngrese opcion: ");
        scanf("%d", &continuar);
        printf("\n");
        switch(continuar)
        {
        case 1:
            lista = SubprogramaingresarDatosAlPpio(lista);
            break;
        case 2:
            lista = SubprogramaIngresarDatosAlFinal(lista);
            break;
        case 3:
            lista = SubprogramaCrearListaOrdenada(lista);
            break;
        case 4:
            SubprogramaBusquedaDeUnNodo(lista);
            break;
        case 5:
            lista = SubprogramaBorrarNodo(lista);
            break;
        case 6:
            lista = SubprogramaAgregarUnNodoEnOrden(lista);
            break;
        case 7:
            recorrerYmostrar(lista);
            break;
        case 8:
            suma = sumarEdadesLista(lista);
            printf("Suma de edades : %d \n",suma);
            break;
        case 9:
            SubprogramaIntercalarDosListas(listaA,listaB,listaC);
            break;
        case 10:
            printf("Lista original: \n");
            recorrerYmostrar(lista);
            lista=invertirLista(lista);
            system("pause");
            printf("Lista invertida: \n");
            recorrerYmostrar(lista);
            break;
        }
        system("pause");

    }
    while(continuar!=0);

    return 0;
}


nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(char nombre[20], int edad)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->edad = edad;
    strcpy(aux->nombre, nombre);
    aux->siguiente = NULL;
    return aux;
}


void agregarPpio(nodo ** lista, nodo * nuevoNodo)
{
    if((*lista) == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

}

//supongo una lista distinta de NULL.
nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    while(seg->siguiente != NULL)
    {
        seg = seg->siguiente;
    }
    return seg;
}

nodo * buscarNodo(char nombre[20], nodo * lista)
//busca un nodo por nombre y retorna su posici¢n de memoria
//si no lo encuentra retorna NULL.
{
    nodo * seg;		//apunta al nodo de la lista que est  siendo leido.
    seg = lista;  	//con esto evito cambiar el valor de la variable
    //lista, que contiene un puntero al primer nodo de la
    //lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->nombre)!=0 ))
        //busco mientras me quede lista por recorrer y no haya encontrado el nombre
    {
        seg=seg->siguiente;	//avanzo hacia el siguiente nodo.
    }
    //en este punto puede ha fallado alguna de las dos condiciones del while
    //si fall¢ la primera es debido a que no encontr lo que buscaba (seg es NULL)
    //si fall¢ la segunda es debido a que se encontr¢ el nodo buscado.
    return seg;
}


nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo * borrarNodo(char nombre[20], nodo * lista)
// elimino un nodo de la lista y retorno un puntero al primer elemento de la misma.
// esto ultimo es necesario para el caso en que se elimina el primer elemento de la lista,
// se modifica el contenido de la variable lista, y eso no se puede hacer de la forma en
// que esta declarada. Para poder hacerlo deber¡a poner **lista. :)
{
    nodo * seg;
    nodo * ante;	//apunta al nodo anterior que seg.

    if((lista != NULL) && (strcmp(nombre, lista->nombre)==0 ))
    {
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->nombre)!=0 ))
        {
            ante = seg;	//adelanto una posicion la var ante.
            seg = seg->siguiente; //avanzo al siguiente nodo.
        }
        //en este punto tengo en la variable ante la direccion de memoria del
        //nodo anterior al buscado, y en la variable seg, la dir de memoria del
        //nodo que quiero borrar.
        if( seg!= NULL)
        {
            ante->siguiente = seg->siguiente; //salteo el nodo que quiero eliminar.
            free(seg); //elimino el nodo.
        }
    }
    return lista; //debo retornar el puntero al primer nodo, por el tipo de pasaje de parametros.
    //No puedo modificar el contenido de la var lista, que no es lo mismo
    //que modificar *lista (contenido de la direccion de memoria apuntada
    //por lista.
    //Otra forma de resolverlo es poner el par metro **lista. :)
}


nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
// agrega un nuevo nodo a la lista manteniendo el orden.
{
    //Si la lista esta vacia agrego el primer elemento.
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        // si el nuevo elemento es menor que el primero de la lista,
        // agrego al principio.
        if(strcmp(nuevoNodo->nombre,lista->nombre)<0)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {
            // busco el lugar en donde insertar el nuevo elemento.
            // necesito mantener la direccion de memoria del nodo anterior
            // al nodo que tiene un nombre mayor al del nuevo nodo.
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while( (seg != NULL)&&(strcmp(nuevoNodo->nombre,seg->nombre)>=0) )
            {
                ante = seg;
                seg = seg->siguiente;
            }
            // inserto el nuevo nodo en el lugar indicado.
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;

}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;//tomo la dir del siguiente.
        free(seg);//borro el actual.
        seg = proximo;//actualizo el actual con la dir del siguiente, para avanzar
    }
    return seg;
}

int sumarEdadesLista(nodo * lista)
//recorro la lista y sumo las edades de los socios.
{
    int suma =  0;
    nodo * seg = lista;
    while (seg != NULL)
    {
        suma = suma + seg->edad;
        seg = seg->siguiente;
    }
    return suma;
}

// FUNCIONES QUE USAN LAS FUNCIONES DE LA LISTA
// SIRVEN PARA ARMAR EL SISTEMA.

nodo * eliminaUltimoNodo(nodo * lista)
{
    nodo * aux=lista;
    nodo * ante;
    while(aux->siguiente!=NULL)
    {
        ante=aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

nodo * eliminaPrimerNodo(nodo * lista)
{
    nodo * aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

nodo * SubprogramaIngresarNuevoDato()
{
    int edad;
    char nombre[20];
    nodo * nuevoNodo;
    fflush(stdin);
    printf("ingrese nombre: ");
    scanf("%s", nombre);
    fflush(stdin);
    printf("ingrese edad:");
    scanf("%d", &edad);
    nuevoNodo = crearNodo(nombre, edad);
    return nuevoNodo;
}

void mostrarNodo(nodo * aux)
{
    printf("nombre: %s \n", aux->nombre);
    printf("edad: %d \n\n", aux->edad);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
}
nodo * SubprogramaIngresarDatosAlFinal(nodo * lista)
//subprograma para ingresar los datos en una lista en forma de fila, o sea
//al final de la lista.
{
    nodo * nuevoNodo;
    char cont = 's';
    while (cont=='s')
    {
        //pide los datos por pantalla y crea un nuevo nodo.
        nuevoNodo = SubprogramaIngresarNuevoDato();
        // agrega a la fila un nuevo nodo al final.
        lista = agregarFinal(lista, nuevoNodo);
        printf("desea continuar s/n: ");
        fflush(stdin);
        scanf("%c", &cont);
        printf("\n");
    }
    return lista;
}



nodo * SubprogramaingresarDatosAlPpio(nodo * lista)
//subprograma para ingresar los datos en una lista en forma de pila
{
    nodo * nuevoNodo;
    char cont = 's';
    while (cont=='s')
    {
        //pide los datos por pantalla y crea un nuevo nodo.
        nuevoNodo = SubprogramaIngresarNuevoDato();
        // agrega a la fila un nuevo nodo al final.
        lista = agregarPpio(lista, nuevoNodo);
        printf("desea continuar s/n: ");
        fflush(stdin);
        scanf("%c", &cont);
        printf("\n");
    }
    return lista;
}

nodo * SubprogramaAgregarUnNodoEnOrden(nodo * lista)
{

    nodo * nuevoNodo = SubprogramaIngresarNuevoDato();
    lista = agregarEnOrden(lista, nuevoNodo);
    return lista;
}

nodo * SubprogramaCrearListaOrdenada(nodo * lista)
{

    char cont = 's';
    while (cont=='s')
    {
        lista = SubprogramaAgregarUnNodoEnOrden(lista);
        printf("desea continuar s/n: ");
        fflush(stdin);
        scanf("%c", &cont);
        printf("\n");
    }
    return lista;
}

void SubprogramaBusquedaDeUnNodo(nodo * lista)
//subprograma de busqueda y muestra de un nodo
{
    //clrscr();
    char nombre[20];	//nombre a buscar
    nodo * nodoBuscado;	//contiene el nodo encontrado o NULL;
    printf("Ingrese nombre:");
    scanf("%s",nombre);
    printf("\n");
    nodoBuscado = buscarNodo(nombre, lista);
    if(nodoBuscado != NULL)
        mostrarNodo(nodoBuscado);
    else
        printf("No se ha encontrado ese nodo\n");
}

nodo * SubprogramaBorrarNodo(nodo * lista)
// pide al usuario un apellido, que es el criterio de busqueda para eliminar
// el nodo. Con este dat, invoca a la funci¢n borrarNodo().
{
    char nombre[20];
    //clrscr();
    printf("ingrese un nombre para eliminarlo de la lista:");
    scanf("%s",nombre);
    lista = borrarNodo(nombre,lista);
    return lista;
}

/// practico 4, punto 4
nodo * intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    // al final de todo debo hacer listaA y listaB = NULL??
    nodo * aux;

    while((lista_A!=NULL)&&(lista_B!=NULL))
    {
        if(lista_A->edad < lista_B->edad)
        {
            aux=lista_A;

            lista_A = lista_A->siguiente; // avanzo uno en la lista A...

            aux->siguiente=NULL;

            lista_C=agregarFinal(lista_C, aux); // agrego al final en lista C
        }
        else
        {
            aux=lista_B;


            lista_B=lista_B->siguiente; // avanzo uno en la lista b...

            aux->siguiente=NULL; // lo desvinculo

            lista_C=agregarFinal(lista_C, aux); // agrego al final en lista C
        }
    }

    // si quedara algo en la lista A
    if(lista_A!=NULL)
    {

        lista_C=agregarFinal(lista_C, lista_A); // agrego al final en lista C
    }

    // si quedara algo en la lista B
    if(lista_B!=NULL)
    {

        lista_C=agregarFinal(lista_C, lista_B); // agrego al final en lista C
    }

    return lista_C;
}

void SubprogramaIntercalarDosListas(nodo * listaA, nodo * listaB, nodo * listaC)
{
    printf("Cargando Lista A\n");
    listaA=SubprogramaIngresarDatosAlFinal(listaA);

    printf("Cargando Lista B\n");
    listaB=SubprogramaIngresarDatosAlFinal(listaB);

    printf("Lista A\n");
    recorrerYmostrar(listaA);

    printf("Lista B\n");
    recorrerYmostrar(listaB);

    listaC=intercalarListas(listaA, listaB, listaC);

    printf("Lista C\n");
    recorrerYmostrar(listaC);

}

/// punto 6
nodo * invertirLista(nodo * lista)
{
    // la idea es extraer el primero de la lista original
    // y luego agregarlo al principio de la nueva lista
    // retornamos el puntero al inicio de la nueva lista
    // para pisar la referencia del main

    nodo * listaInvertida=NULL;
    nodo * aux;
    while(lista!=NULL)
    {
        // extraemos el primero
        aux=lista;

        lista=lista->siguiente;

        aux->siguiente=NULL;

        // lo agregamos al principio de la nueva lista invertida
        listaInvertida = agregarPpio(listaInvertida, aux);
    }

    return listaInvertida;

}

void menu()
{

    printf("LISTAS VINCULADAS CON PUNTEROS\n\n");
    printf("1: ingresar como pila\n");
    printf("2: ingresar como fila\n");
    printf("3: ingresar como lista ordenada por nombre(muchos nodos)\n");
    printf("4: buscar un nodo\n");
    printf("5: borrar un nodo\n");
    printf("6: insertar un nodo nuevo en orden alfabetico\n");
    printf("7: recorrer la lista\n");
    printf("8: sumar todas las edades de la lista\n");
    printf("9: intercalar dos listas\n");
    printf("10: invertir lista\n");
    printf("\n");
    printf("0: salir\n\n");
}
