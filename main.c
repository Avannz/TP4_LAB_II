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
nodo* pasarDatosLIS(nodo* lista, FILE* archivo);
void recorrerLista (nodo* lista);
void escribir(nodo* aux);
void cargarArchivo();
int cargarUnArchivo();


int main()
{
    int opc;
    nodo* lista;
    FILE* archivo;

    printf("Ingresa el ejercicio: ");
    fflush(stdin);
    scanf("%d", &opc);

    switch(opc){

    case 1:

                lista = IniciarNodo();

                printf(" + Datos de mi Archivo: \n\n");
                mostrarArchivo(archivo);

                archivo = fopen("miArchivo.bin", "ab");
                lista = pasarDatosLIS(archivo, lista);
                fclose(archivo);

                recorrerLista(lista);

        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

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
    while(lista != NULL){

        escribir(seg);
        seg = seg->sig;
    }
}

void escribir(nodo* seg)
{

    printf("| %i |", seg->dato);
}

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

nodo* cargarNodoARCHI(nodo* lista, FILE* archivo)
{

    nodo* nuevoNodo;
    int num;

        fread(&num, sizeof(int), 1, archivo);

        nuevoNodo = crearNodo(num);

        lista = agregarPpio(lista, nuevoNodo);

    return lista;
}

nodo* pasarDatosLIS(nodo* lista, FILE* archivo)
{

    while(lista != NULL){

         lista = cargarNodoARCHI(lista, archivo);

    }

    return lista;
}
