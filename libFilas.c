#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXDIM 70
#include "libFilas.h"
#include "libPrestamos.h"



void inicFila(filaPrestamos* fila)
{
    fila->primero=inicListaDoble();
    fila->ultimo=inicListaDoble();

}

void agregarPrestamo(filaPrestamos* fila, stPrestamo aux)
{
    nodoDoble* nuevo=crearNodoPrestamo(aux);
    if(fila->primero==NULL)
    {
        fila->primero=nuevo;
        fila->ultimo=nuevo;
    }
    else
    {
        fila->primero=agregarAlFinalDoble(fila->primero, nuevo);
        fila->ultimo=nuevo;
    }


}


stPrestamo extraer(filaPrestamos* fila)
{
    stPrestamo aux;

    if(fila->primero!=NULL)
    {
        aux=verPrimero(fila->primero);
        fila->primero=borrarPrimero(fila->primero);
        if(fila->primero==NULL)
        {
            fila->ultimo=inicListaDoble();
        }

    }


    return aux;
}


void mostrarFila(filaPrestamos* fila)
{

        nodoDoble *seg=fila->primero;
        puts("----------------------------INICIO----------------------------");
        while(seg!=NULL)
        {
            printf("libro:%s\n", seg->dato.nombreLibro);
            printf("DNI cliente:%s\n", seg->dato.dniCliente);
            puts("------------------------------------------------------------------------");
            seg=seg->siguiente;
        }
        puts("----------------------------FINAL----------------------------");
    }


void filaToArchivo(filaPrestamos *fila, char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo, "wb");
    stPrestamo aux;
    if(archi!=NULL)
    {
        nodoDoble *seg = fila->primero;
        while (seg != NULL)
        {
            strcpy(aux.nombreLibro, seg->dato.nombreLibro);
            strcpy(aux.dniCliente, seg->dato.dniCliente);
            fwrite(&aux, sizeof(stPrestamo), 1, archi);
            seg=seg->siguiente;
        }

        fclose(archi);
    }

}

void archivoToFila(filaPrestamos *fila, char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo, "rb");
    stPrestamo aux;
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stPrestamo),1,archi))
        {
            agregarPrestamo(fila,aux);
        }
        fclose(archi);
    }
}
