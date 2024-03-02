#ifndef LIBFILAS_H_INCLUDED
#define LIBFILAS_H_INCLUDED
#include "libPrestamos.h"

typedef struct
{
    struct nodoDoble* primero;
    struct nodoDoble* ultimo;

}filaPrestamos;


void inicFila(filaPrestamos* fila);
void agregarPrestamo(filaPrestamos* fila, stPrestamo aux);
stPrestamo extraer(filaPrestamos* fila);
void mostrarFila(filaPrestamos* fila);
void filaToArchivo(filaPrestamos *fila, char nombreArchivo[]);
void archivoToFila(filaPrestamos *fila, char nombreArchivo[]);
#endif // LIBFILAS_H_INCLUDED
