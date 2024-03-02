#ifndef LIBPRESTAMOS_H_INCLUDED
#define LIBPRESTAMOS_H_INCLUDED
#include "libArboles.h"
#include "libLibros.h"
typedef struct{
char dniCliente[MAXDIM];
int diaInicio;
int mesInicio;
int anioInicio;
int diaVencimiento;
int mesVencimiento;
int anioVencimiento;
char nombreLibro[MAXDIM];
}stPrestamo;

typedef struct{
stPrestamo dato;
struct nodoDoble *siguiente;
struct nodoDoble *anterior;
}nodoDoble;

nodoDoble *inicListaDoble();
nodoDoble *crearNodoPrestamo(stPrestamo dato);
nodoDoble *agregarAlPpioDoble(nodoDoble *pLista, nodoDoble *nuevoNodo);
nodoDoble *agregarEnOrdenDoble(nodoDoble *pLista, nodoDoble *nuevoNodo);
nodoDoble *cargarPrestamoEnLista(nodoDoble *pLista);
void mostrarUnPrestamo(stPrestamo dato);
void mostrarListaPrestamo(nodoDoble *pLista);
void nodoDobleToArchivo(char nombreArchivo[], nodoDoble *pLista);
nodoDoble * prestarUnLibro(nodoDoble *pLista, arbolCliente *arbol, char dni[], celdaBiblioteca AR[], int validos, char archivoPrestamos[]);
nodoDoble *devolverUnLibro(nodoDoble *pLista, arbolCliente *arbol, char dni[], celdaBiblioteca AR[], int validos, char archivoPrestamos[]);
nodoDoble *actualizarPrestamo(nodoDoble *pLista, arbolCliente *arbol, char dni[], celdaBiblioteca AR[], int validos, char archivoPrestamos[]);
nodoDoble *buscarPrestadoPorDni(nodoDoble *pLista, char dni[], char nombreLibro[]);
stPrestamo verPrimero(nodoDoble* lista);
nodoDoble* borrarPrimero(nodoDoble* lista);
nodoDoble* borrarNodoDoble(nodoDoble* lista, char dni[]);
nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* buscarUltimoDoble(nodoDoble* lista);
nodoDoble *archivoToNodoDoble(char nombreArchivo[], nodoDoble *pLista);

#endif // LIBPRESTAMOS_H_INCLUDED
