#ifndef LIBARBOLES_H_INCLUDED
#define LIBARBOLES_H_INCLUDED
#include "libPilas.h"

typedef struct{

char dni[MAXDIM];
char nombrePersona[MAXDIM];
char numTelefono[100];
int estado; /// 1 si puede pedir mas libros, 0 si no
int cantPrestamos;
float precioMultas;

}stCliente;

typedef struct
{

    stCliente cliente;
    struct arbolCliente* izquierda;
    struct arbolCliente* derecha;


} arbolCliente;

stCliente cargarUnCliente(char dniAux[]);
void mostrarUnCliente(stCliente cliente);
void mostrarEstado(int estado);

arbolCliente* inicArbol();
arbolCliente* crearNodoArbol(stCliente dato);
arbolCliente* insertar(arbolCliente* arbol, arbolCliente* nuevoNodo);
void inOrder(arbolCliente* arbol);
arbolCliente* cargarMuchosClientes(arbolCliente* arbol);
int convertirStringConNumerosAEntero(char aux[]);
void preguntarString (char cadena[]);
arbolCliente* buscar(arbolCliente* arbol, char dni[]);
int esHoja(arbolCliente* arbol);
arbolCliente* NMD (arbolCliente* raiz);
arbolCliente* NMI (arbolCliente* raiz);
arbolCliente* borrarNodo(arbolCliente* raiz, char dni[]);
int validarDniEnArbol(arbolCliente* arbol, char dni[]);
void guardarArbolEnArchivo(arbolCliente* arbol, FILE* archi);
void arbolToArchivo(char archivo[], arbolCliente* arbol);
arbolCliente* archivoToArbol(char archivo[]);
arbolCliente* insertarDesdeArchivo(FILE* archi);
void mostrarArchivoClientes(char archivo[]);
arbolCliente* buscarClienteMaxPrestamos(arbolCliente* arbol);
void precioMultasToPila(arbolCliente* arbol, Pila* pila);


#endif // LIBARBOLES_H_INCLUDED
