#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXDIM 70
#include "libArboles.h"
#include "validaciones.h"
#include "libPilas.h"

stCliente cargarUnCliente(char dniAux[]) {
    stCliente cliente;
    do {
        printf("ingrese el nombre del cliente\n");
        fflush(stdin);
        gets(cliente.nombrePersona);
    } while(validarChar(cliente.nombrePersona)==0 || tieneDigitos(cliente.nombrePersona)==1);

    strcpy(cliente.dni, dniAux);

    do {
        printf("ingrese el numero de telefono del cliente\n");
        fflush(stdin);
        gets(cliente.numTelefono);

    } while(tieneCaracteres(cliente.numTelefono)==1);




    ///desde el estado para abajo son cosas que se pueden hardcodear o ir poniendolo en otra funcion
    ///en esta funcion que se usaria para cargar por primera vez el cliente tendria que estar todo inicializado en 0

    cliente.estado=1;

    cliente.cantPrestamos=0;

    cliente.precioMultas=0;

    return cliente;
}

void mostrarUnCliente(stCliente cliente) {
    puts("==================================");
    printf("Nombre Del Cliente: %s\n", cliente.nombrePersona);
    printf("DNI: %s\n", cliente.dni);
    printf("Num de Telefono: %s\n", cliente.numTelefono);
    mostrarEstado(cliente.estado);
    printf("Cantidad de Prestamos: %i\n", cliente.cantPrestamos);
    printf("total de multas: %.2f\n", cliente.precioMultas);
    puts("==================================\n");
}

void mostrarEstado(int estado) {
    if(estado<=3) {
        puts("Estado:--- Disponible Para Mas Prestamos");
    } else
        puts("Estado:--- No Disponible para Prestamos");
}

arbolCliente* inicArbol() {
    return NULL;
}

arbolCliente* crearNodoArbol(stCliente dato) {
    arbolCliente* nuevo=(arbolCliente*)malloc(sizeof(arbolCliente));
    nuevo->cliente=dato;
    nuevo->derecha=NULL;
    nuevo->izquierda=NULL;

    return nuevo;
}

int convertirStringConNumerosAEntero(char aux[]) {
    int dato=atoi(aux); /// funcion de la libreria ctype.h
    return dato;
}

arbolCliente* insertar(arbolCliente* arbol, arbolCliente* nuevoNodo) {
    if(arbol==NULL) {
        arbol=nuevoNodo;
    } else {
        int dniRaiz=convertirStringConNumerosAEntero(arbol->cliente.dni);
        int dniNuevo=convertirStringConNumerosAEntero(nuevoNodo->cliente.dni);
        if(dniNuevo > dniRaiz) { /// Si es mayor lo insertamos en la derecha del arbol
            arbol->derecha=insertar(arbol->derecha, nuevoNodo);
        } else {
            arbol->izquierda=insertar(arbol->izquierda, nuevoNodo); /// Si NO es mayor lo insertamos en la izquierda del arbol
        }

    }



    return arbol;
}

void inOrder(arbolCliente* arbol) { /// izquierda, raiz, derecha
    if(arbol!=NULL) {
        inOrder(arbol->izquierda);
        mostrarUnCliente(arbol->cliente);
        inOrder(arbol->derecha);
    }

}

arbolCliente* cargarMuchosClientes(arbolCliente* arbol) {
    char continuar='s';
    char dniAux[MAXDIM];
    do {
        /// system("cls");

        ///preguntar dni aca y validarlo

        do {

            puts("Ingrese el dni del Cliente:");
            fflush(stdin);
            gets(dniAux);

        } while(validarDniEnArbol(arbol, dniAux)==0 || (tieneCaracteres(dniAux)==1));

        arbol=insertar(arbol, crearNodoArbol(cargarUnCliente(dniAux)));
        puts("Desea cargar otro Cliente? Escriba S para continuar o N para Finalizar:");
        fflush(stdin);
        scanf("%c", &continuar);

    } while(continuar=='s' || continuar=='S');



    return arbol;
}

void preguntarString (char cadena[]) {
    puts("Ingrese el dato ahora:");
    fflush(stdin);
    gets(cadena);
}

arbolCliente* buscar(arbolCliente* arbol, char dni[]) {
    arbolCliente* rta=NULL;
    if(arbol!=NULL) {

        int dniRaiz=convertirStringConNumerosAEntero(arbol->cliente.dni);
        int dniABuscar=convertirStringConNumerosAEntero(dni);
        if(dniABuscar==dniRaiz) {
            rta=arbol;
        } else {
            if(dniABuscar>dniRaiz) {
                rta=buscar(arbol->derecha, dni);
            } else
                rta=buscar(arbol->izquierda, dni);
        }

    }

    return rta;

}


int esHoja(arbolCliente* arbol) { /// Ultimo nodo, que no tiene hijos, pero si padres
    if(arbol->derecha==NULL && arbol->izquierda==NULL) {
        return 1;
    } else
        return 0;


}

arbolCliente* NMD (arbolCliente* raiz) { /// Nodo mayor derecha
    if(raiz->derecha!=NULL) {
        raiz=NMD(raiz->derecha);
    }

    return raiz;
}


arbolCliente* NMI (arbolCliente* raiz) { /// Nodo mayor izquierda
    if(raiz->izquierda!=NULL) {
        raiz=NMI(raiz->izquierda);
    }

    return raiz;
}


arbolCliente* borrarNodo(arbolCliente* raiz, char dni[]) {
    if(raiz!=NULL) {
        int dniRaiz=convertirStringConNumerosAEntero(raiz->cliente.dni);
        int dniABuscar=convertirStringConNumerosAEntero(dni);

        if(dniRaiz==dniABuscar) {
            if(esHoja(raiz)==1) { /// Si es hoja el nodo a borrar, se borra de una
                free(raiz);
                raiz=NULL;

            } else if(raiz->izquierda!=NULL) { /// Sino se busca en el apartado derecho, para borrar uno de la izquierda y viceversa si es el de la derecha, el que hay que borrar ( por eso el NMI, NMD)
                arbolCliente* masDer=NMD(raiz->izquierda);
                raiz->cliente=masDer->cliente;
                raiz->izquierda=borrarNodo(raiz->izquierda, masDer->cliente.dni);

            } else if(raiz->derecha!=NULL) {
                arbolCliente* masIzq=NMI(raiz->derecha);
                raiz->cliente=masIzq->cliente;
                raiz->derecha=borrarNodo(raiz->derecha, masIzq->cliente.dni);
            }

        } else if(dniABuscar < dniRaiz) {
            raiz->izquierda=borrarNodo(raiz->izquierda, dni); /// llamada recursiva
        } else {
            raiz->derecha=borrarNodo(raiz->derecha, dni);
        }
    }

    return raiz;
}

int validarDniEnArbol(arbolCliente* arbol, char dni[]) {
    int flag=0;
    arbolCliente* aux=inicArbol();
    aux=buscar(arbol, dni);
    if(aux==NULL) {
        flag=1;
    } else
        puts("ERROR, DNI ya cargado, REINTENTAR");

    return flag;

}

void guardarArbolEnArchivo(arbolCliente* arbol, FILE* archi) {

    if (arbol != NULL) {
        guardarArbolEnArchivo(arbol->izquierda, archi);
        fwrite(&(arbol->cliente), sizeof(stCliente), 1, archi);
        guardarArbolEnArchivo(arbol->derecha, archi);
    }
}

void arbolToArchivo(char archivo[], arbolCliente* arbol) {
    FILE* archi=fopen(archivo, "wb");
    if(archi!=NULL) {
        guardarArbolEnArchivo(arbol, archi);
        fclose(archi);
    }


}

arbolCliente* archivoToArbol(char archivo[]) {
    arbolCliente* arbol=inicArbol();
    FILE* archi = fopen(archivo, "rb");
    if (archi != NULL) {
        arbol=insertarDesdeArchivo(archi);
        fclose(archi);

    }

    return arbol;
}

arbolCliente* insertarDesdeArchivo(FILE* archi) {
    stCliente aux;
    arbolCliente* arbol = inicArbol();

    while (fread(&aux, sizeof(stCliente), 1, archi) > 0) {
        arbol = insertar(arbol, crearNodoArbol(aux));
    }

    return arbol;
}

void mostrarArchivoClientes(char archivo[]) {
    stCliente aux;
    FILE* archi=fopen(archivo, "rb");
    if(archi!=NULL) {
        while(fread(&aux, sizeof(stCliente), 1, archi)>0) {
            mostrarUnCliente(aux);
        }
        fclose(archi);
    }
}

arbolCliente* buscarClienteMaxPrestamos(arbolCliente* arbol) {
    arbolCliente* rta=arbol;

    if(arbol!=NULL) {
        arbolCliente* maxIzquierda = buscarClienteMaxPrestamos(arbol->izquierda);
        arbolCliente* maxDerecha = buscarClienteMaxPrestamos(arbol->derecha);

        if(maxIzquierda!=NULL) { /// Recorremos la izquierda y derecha del arbol, comparando dato por dato, verificando cual es el mayor y lo retornamos
            if(maxIzquierda->cliente.cantPrestamos > rta->cliente.cantPrestamos) {
                rta=maxIzquierda;
            }
        }

        if(maxDerecha!=NULL) {

            if(maxDerecha->cliente.cantPrestamos > rta->cliente.cantPrestamos) {
                rta = maxDerecha;
            }

        }

    }
    return rta;
}

void precioMultasToPila(arbolCliente* arbol, Pila* pila) {
    Pila basura;
    inicPila(&basura);
    if (arbol != NULL) {
        precioMultasToPila(arbol->izquierda, pila);
        if(arbol->cliente.precioMultas==0) {
            apilar(&basura, arbol->cliente.precioMultas);
        } else {

            apilar(pila, arbol->cliente.precioMultas);

        }
        precioMultasToPila(arbol->derecha, pila);
    }
}

