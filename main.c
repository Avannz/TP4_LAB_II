#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int dato;
    struct nodo* sig;

} nodo;

nodo* IniciarNodo ();
nodo* agregarPpio(nodo* lista, nodo* nuevoNodo);
nodo* cargarNodo(nodo* lista);
nodo* cargarNodoARCHI(nodo* lista, FILE* archivo);
nodo* pasarDatosLIS(nodo* lista, FILE* archivo);
nodo* ordenarNodo (nodo* lista, nodo* nuevoNodo);
nodo* cargarNodoOrdenado(nodo* lista);
nodo* intercalarListas (nodo* lista1, nodo* lista2, nodo* lista3);
void recorrerLista (nodo* lista);
void escribir(nodo* aux);
void cargarArchivo();
int recorrerArchivo (FILE* archivo);
int cargarUnArchivo();


int main()
{
    int opc;
    nodo* lista;
    nodo* lista2;
    nodo* lista3;
    FILE* archivo;
    int menor;
    int dato;
    int flag = 0;

    printf("Ingresa el ejercicio: ");
    fflush(stdin);
    scanf("%d", &opc);

    switch(opc)
    {

    case 1:

        lista = IniciarNodo();

        printf(" + Datos de mi Archivo: \n\n");
        mostrarArchivo(archivo);

//                lista = cargarNodo(lista);
//                recorrerLista(lista);


        printf("\n + Datos de la lista: \n\n");
        archivo = fopen("miArchivo.bin", "rb");
        lista = cargarNodoARCHI(lista, archivo);
        fclose(archivo);

        recorrerLista(lista);


        break;

    case 2:

//        archivo = fopen("miArchivo.bin", "ab");
//        cargarArchivo(archivo);
//        fclose(archivo);

        lista = cargarNodoOrdenado(lista);
        recorrerLista(lista); //NO FUNCA. nose PQ!

        break;

    case 3:

            lista = cargarNodo(lista);

            printf("Ingresa el dato ha encontrar: ");
            fflush(stdin);
            scanf("%d", &dato);

            flag = busquedaDatoNodo(lista, dato);

            if(flag == 1)
            {

                printf("Dato existente :D");
            }
            /*else if(flag == 0)        //PQ NO ME DICE QUE NO EXISTE???
            {

                printf("Dato inexistente D:");
            }*/

        break;

    case 4:

            lista = IniciarNodo();
            lista2 = IniciarNodo();
            lista3 = IniciarNodo();

            lista = cargarNodo(lista);
            lista2 = cargarNodo(lista2);

            lista3 = intercalarListas(lista, lista2, lista3);
            recorrerLista(lista3);

        break;

    case 5:

        break;

    case 6:

        break;

    case 7:

        break;
    }
}

nodo* IniciarNodo ()
{

    return NULL;
}
nodo* crearNodo(int dato)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->sig = NULL;

    return aux;
}
nodo* agregarPpio(nodo* lista, nodo* nuevoNodo)
{

    if(lista == NULL)
    {

        lista = nuevoNodo;
    }
    else
    {

        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }

    return lista;
}
nodo* cargarNodo(nodo* lista)
{

    nodo* nuevoNodo;
    char elecc = 's';
    int num;

    while(elecc == 's')
    {

        printf("Ingresa un dato a la lista: ");
        fflush(stdin);
        scanf("%d", &num);

        nuevoNodo = crearNodo(num);

        lista = agregarPpio(lista, nuevoNodo);

        printf("Ingresa 's' para continuar: ");
        fflush(stdin);
        scanf("%c", &elecc);

    }

    return lista;
}
void recorrerLista (nodo* lista)
{

    nodo * seg = lista;
    while(lista != NULL)
    {

        escribir(seg);
        seg = seg->sig;
    }
}
void escribir(nodo* seg)
{

    printf("| %i |", seg->dato);
}
nodo* cargarNodoARCHI(nodo* lista, FILE* archivo)
{

    nodo* nuevoNodo;
    int num;

    while(fread(&num, sizeof(int), 1, archivo) > 0)
    {

        nuevoNodo = crearNodo(num);

        lista = agregarPpio(lista, nuevoNodo);
    }

    return lista;
}
nodo* cargarNodoOrdenado(nodo* lista)
{
    FILE* archivo;
    archivo = fopen("miArchivo.bin", "rb");

    nodo* nuevoNodo;
    int num;

    if(archivo != NULL)
    {
        printf("EL ARCHIVO SE HA ABIERTO\n");

        while(!feof(archivo))
        {
            fread(&num, sizeof(int), 1, archivo);
            nuevoNodo = crearNodo(num);
            lista = ordenarNodo(lista, nuevoNodo);
        }

        fclose(archivo);
    }
    else
    {

        printf("EL ARCHIVO ES INEXISTENTE");
    }

    return lista;
}
nodo* ordenarNodo (nodo* lista, nodo* nuevoNodo)
{

    nodo* seg;
    nodo* ante;

    ante = lista;
    seg = lista->sig;

    /*COMPROBACION DE EXISTENCIA*/

    if(lista == NULL)
    {

        lista = nuevoNodo;
    }
    else
    {

        /*RECORRIDO DE LA LISTA, HASTA EL INSERTAR*/

        while(ante->dato > nuevoNodo->dato && ante != NULL)
        {

            ante = ante->sig;
            seg = seg->sig;
        }

        nuevoNodo->sig = seg;
        ante->sig = nuevoNodo;
    }

    return ante;
}
int busquedaDatoNodo(nodo* lista, int dato)
{
    int flag = 0;

    while(lista != NULL){

        if(lista->dato == dato)
        {

            flag = 1;
            return flag;
        }
        else
        {
            lista = lista->sig;
            flag = 0;
        }
    }

    return flag;
}

nodo* intercalarListas (nodo* lista1, nodo* lista2, nodo* lista3)
{

    nodo* aux, *aux2;

    while(lista1 != NULL & lista2 != NULL)
    {
        if(lista1->dato > lista2->dato)
        {
            aux2 = lista2;
            lista2 = lista2->sig;

            aux2->sig = NULL;
            lista3 = agregarPpio(lista3, aux2);
        }
        else
        {
            aux = lista1;
            lista1 = lista1->sig;

            aux->sig = NULL;
            lista3 = agregarPpio(lista3, aux);
        }
    }

    return lista3;
}



/*ARCHIVOS*/


int cargarUnArchivo()
{

    FILE* archi;
    archi = fopen("miArchivo.bin", "ab");

    int num;

    if(archi != NULL)
    {

        printf("Ingresa un valor al archivo");
        fflush(stdin);
        scanf("%d", &num);

        fwrite(&num, sizeof(int), 1, archi);

        fclose(archi);
    }

}
void cargarArchivo()
{



    FILE* archi;
    archi = fopen("miArchivo.bin", "ab");

    char letra = 's';

    if(archi != NULL)
    {
        while(letra == 's')

        {

            cargarUnArchivo();

            printf("Ingrese 's' para continuar: ");
            fflush(stdin);
            scanf("%c", &letra);

        }

        fclose(archi);
    }
}
void mostrarArchivo(FILE* archivo)
{
    archivo = fopen("miArchivo.bin", "rb");
    int num;

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            fread(&num, sizeof(int),1, archivo);

            if(!feof(archivo))
            {
                printf("/ %d ", num);
            }
        }
        fclose(archivo);
    }
}
