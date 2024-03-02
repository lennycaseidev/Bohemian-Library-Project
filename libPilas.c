#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libPilas.h"

nodoPila* iniclistaPila() {
    return NULL;
}

nodoPila* crearNodoPila(int dato) {
    nodoPila* nuevo=(nodoPila*)malloc(sizeof(nodoPila));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}

nodoPila* agregarPpioPila(nodoPila* lista, nodoPila* nuevoNodo) {
    if(lista!=NULL) {
        nuevoNodo->siguiente=lista;
    }

    return nuevoNodo;
}

nodoPila* buscarUltimoPila(nodoPila* lista) {
    while(lista!=NULL && lista->siguiente!=NULL) {
        lista=lista->siguiente;
    }

    return lista;
}

nodoPila* agregarAlFinalPila(nodoPila* lista, nodoPila* nuevoNodo) {
    if(lista==NULL) {
        lista=nuevoNodo;
    } else {
        nodoPila* ultimo=buscarUltimoPila(lista);
        ultimo->siguiente=nuevoNodo;
    }


    return lista;
}

void mostrarLista(nodoPila* lista) {
    nodoPila* seg=lista;
    while(seg!=NULL) {
        printf("DATO: %i\n", seg->dato);
        seg=seg->siguiente;
    }

}

nodoPila* borrarNodoPrimero (nodoPila* lista) {
    if (lista!=NULL) {
        nodoPila* aux=lista;
        lista=lista->siguiente; /// Nos movemos un lugar y borramos el primero
        free(aux);
    }
    return lista;
}

///FUNCIONES PILAS

void inicPila(Pila* p) {
    p->lista=iniclistaPila();
}

int pilaVacia(Pila* p) {
    return p->lista==NULL?1:0;
}

void apilar(Pila* p, int dato) {
    p->lista=agregarPpioPila(p->lista,crearNodoPila(dato));
}

int desapilar (Pila* p) {
    int aux = ((nodoPila*)(p->lista))->dato;
    p->lista = borrarNodoPrimero(p->lista);

    return aux;

}

int tope(Pila* p) {
    return ((nodoPila*)(p->lista))->dato;
}

void leer(Pila * p) {
    int aux=0;
    puts("Ingrese un dato:");
    fflush(stdin);
    scanf("%i", &aux);
    p->lista=agregarPpioPila(p->lista,crearNodoPila(aux));

}

void mostrarPila(Pila p) {
    nodoPila* aux=p.lista;
    puts("-------------------------TOPE-------------------------");
    while(aux!=NULL) {
        printf("VALOR DE MULTA: %i\n", aux->dato);
        aux=aux->siguiente;
    }
    puts("-------------------------BASE-------------------------");
}



void pilaToArchivo(Pila* p, char archivo[]) {
    FILE* archi = fopen(archivo, "wb");
    if(archi!=NULL) {
        nodoPila* aux=p->lista;

        while(aux!=NULL) {
            fwrite(&(aux->dato), sizeof(int), 1, archi); /// Mandamos dato por dato, al archivo para la persistencia de datos
            aux=aux->siguiente;
        }

        fclose(archi);
    }
}

void archivoToPila(Pila* p, char archivo[]) {
    FILE* archi =fopen(archivo, "rb");
    if(archi!=NULL) {
        int dato;
        while (fread(&dato, sizeof(int), 1, archi)> 0) {
            apilar(p, dato);
        }

        fclose(archi);
    }
}
