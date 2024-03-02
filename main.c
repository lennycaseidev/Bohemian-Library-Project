#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXDIM 70
#include "libLibros.h"
#include "libFilas.h"
#include "libArboles.h"
#include "libPrestamos.h"
#include "libFilas.h"
#include <time.h>
#include "menu.h"
#include "libPilas.h"

int main() {

    srand(time(NULL));
    char archivoPrestamos[MAXDIM] = "archivoPrestamos";
    char archivoLibros[MAXDIM] = "archivoLibros";
    char archivoClientes[MAXDIM]="archivoClientes";
    char archivoPila[MAXDIM]="archivoMultasDiarias";
    int validos=0;
    nodoDoble *listaPrestamos=inicListaDoble();
    arbolCliente *arbol=inicArbol();
    celdaBiblioteca arreglo[MAXDIM];
    filaPrestamos *fila;
    inicFila(&fila);
    Pila p;
    inicPila(&p);

    arbol = archivoToArbol(archivoClientes);
    archivoToPila(&p, archivoPila);
    menuPrincipal(validos, arreglo,listaPrestamos,arbol, archivoLibros, archivoPrestamos, archivoClientes, &p, archivoPila);
    pilaToArchivo(&p, archivoPila);
    dibujosDespedida();


    return 0;
}
