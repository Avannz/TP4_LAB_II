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
nodo* intercalarDatos(nodo* lista1, nodo* lista2);
void recorrerLista (nodo* lista);
void escribir(nodo* aux);
void cargarArchivo();
int recorrerArchivo (FILE* archivo);
int cargarUnArchivo();
int buscarDato(nodo*lista,int dato); //GIANINI


int main()
{
    int opc;
    nodo* lista;
    nodo* lista1;
    nodo* lista2;
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

        archivo = fopen("miArchivo.bin", "ab");
        cargarArchivo(archivo);
        fclose(archivo);
        lista = IniciarNodo();
        lista = cargarNodoOrdenado(lista);
        recorrerLista(lista);

        break;

    case 3:

        lista = cargarNodo(lista);

        printf("Ingresa el dato ha encontrar: ");
        fflush(stdin);
        scanf("%d", &dato);

        flag = buscarDato(lista, dato);

        if(flag == 1)
        {

            printf("Dato existente :D");
        }
        break;

    case 4:

        lista1 = IniciarNodo();
        lista2 = IniciarNodo();

        lista1 = cargarNodo(lista1);
        lista2 = cargarNodo(lista2);

        lista1 = intercalarDatos(lista1, lista2);

        recorrerLista(lista1);

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

        while(fread(&num, sizeof(int), 1, archivo) > 0)
        {
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



    /*COMPROBACION DE EXISTENCIA*/

    if(lista == NULL)
    {

        lista = nuevoNodo;
    }
    else
    {
        if(lista->dato > nuevoNodo->dato)
        {
            lista = agregarPpio(lista, nuevoNodo);

        }
        else
        {
            ante = lista;
            seg = lista->sig;
            /*RECORRIDO DE LA LISTA, HASTA EL INSERTAR*/

            while(seg != NULL && seg->dato < nuevoNodo->dato)
            {


                ante = ante->sig;
                seg = seg->sig;
            }

            nuevoNodo->sig = seg;
            ante->sig = nuevoNodo;
        }
    }
    return lista;
}

int busquedaDatoNodo(nodo* lista, int dato)
{
    int flag = 0;

    while(lista != NULL)
    {

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

int buscarDato(nodo*lista,int dato)
{
    int flag=0;
    while(lista!=NULL)
    {
        if(lista->dato==dato)
        {

            flag=1;
            return flag;
        }
        else
        {

            lista = lista->sig;
            flag=0;
        }

    }

    return flag;
}

nodo* intercalarDatos(nodo* lista1, nodo* lista2)
{

    nodo* ante;
    nodo* seg;

    nodo* ante2;
    nodo* seg2;

    nodo* aux;

    ante = lista1;
    seg = lista1->sig;

    ante2 = lista2;
    seg2 = lista2->sig;

    while(seg != NULL)
    {
        aux = ante2->dato;
        ante2 = ante2->sig;
        seg2 = seg2->sig;

        seg->sig = seg;
        aux->sig = seg;
        ante->sig = aux;
    }

    return lista1;
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

