#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXDIM 70
#include "libLibros.h"
#include "validaciones.h"


int idGenero=0;

stLibro cargarUnLibro() {


    stLibro librito;

    do {

        printf("ingrese el nombre del libro\n");
        fflush(stdin);
        gets(librito.nombreLibro);

    } while(validarChar(librito.nombreLibro)==0);


    do {

        printf("ingrese el nombre del autor\n");
        fflush(stdin);
        gets(librito.autor);


    } while(validarChar(librito.autor)==0 || tieneDigitos(librito.autor)==1);

    do {

        printf("ingrese el nombre de la editorial\n");
        fflush(stdin);
        gets(librito.editorial);

    } while(validarChar(librito.editorial)==0 || tieneDigitos(librito.editorial)==1);


    ingresarGenero(librito.genero);


    librito.estadoLibro=1; ///Cuando lo creamos siempre va a estar disponible, despues se modifica


    librito.cantReservas=0;

    librito.ISBN=rand()   %  999999999 + 111111111  ;

    return librito;

}


void opcionesGeneros() {
    puts("Ingrese 1 para asignarle  'Drama'");
    puts("Ingrese 2 para asignarle  'Terror'");
    puts("Ingrese 3 para asignarle  'Leyenda'");
    puts("Ingrese 4 para asignarle  'Romantico'");
    puts("Ingrese 5 para asignarle  'Comic'");
    puts("Ingrese 6 para asignarle  'De estudio'");
    puts("Ingrese 7 para asignarle  'Comedia'");
    puts("Ingrese 8 para asignarle  'Fantasia'");
    puts("Ingrese 9 para asignarle  'Criminales'");
    puts("Ingrese 10 para asignarle 'Otros");
}

void ingresarGenero(char genero[]) {
    int aux=0;
    opcionesGeneros();
    int flag=0;

    do {

        puts("Ingrese el genero:");
        fflush(stdin);
        scanf("%i", &aux);

        switch(aux) {
        case 1:
            strcpy(genero, "Drama");
            flag=1;
            break;

        case 2:
            strcpy(genero, "Terror");
            flag=1;
            break;

        case 3:
            strcpy(genero, "Leyenda");
            flag=1;
            break;

        case 4:
            strcpy(genero, "Romantico");
            flag=1;
            break;

        case 5:
            strcpy(genero, "Comic");
            flag=1;
            break;

        case 6:
            strcpy(genero, "De Estudio");
            flag=1;
            break;

        case 7:

            strcpy(genero, "Comedia");
            flag=1;
            break;

        case 8:
            strcpy(genero, "Fantasia");
            flag=1;
            break;

        case 9:
            strcpy(genero, "Criminales");
            flag=1;
            break;

        case 10:
            strcpy(genero, "Otros");
            flag=1;
            break;

        default:
            puts("ERROR, DATO INGRESADO ERRONEO");
            break;

        }

    } while(flag==0);




}


void mostrarUnLibro(stLibro librito) {
    puts("===================================");
    printf("Nombre Del Libro:%s\n", librito.nombreLibro);
    printf("Autor: %s\n", librito.autor);
    printf("Editorial: %s\n", librito.editorial);
    printf("Genero: %s\n", librito.genero);
    printf("Estado Del Libro: %i\n", librito.estadoLibro);
    printf("Cantidad De reservas: %i\n", librito.cantReservas);
    printf("ISBN: %i\n", librito.ISBN);
    puts("===================================\n");
}


nodoSimple *inicListaSimple() {
    return NULL;
}

nodoSimple *crearUnNodoSimple(stLibro dato) {
    nodoSimple *nuevoNodo=(nodoSimple*)malloc(sizeof(nodoSimple));
    nuevoNodo->librito=dato;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}


nodoSimple *agregarAlPpio(nodoSimple *pLista, nodoSimple *nuevoNodo) { ///agregar al principio
    if(pLista==NULL) {
        pLista=nuevoNodo;
    } else {
        nuevoNodo->siguiente=pLista;
    }
    pLista=nuevoNodo;
    return pLista;

}

nodoSimple *agregarEnOrden(nodoSimple *pLista, nodoSimple *nuevoNodo) { ///agregar en orden por nombre
    if(pLista==NULL) {
        pLista=nuevoNodo;
    } else {
        if(pLista->librito.ISBN > nuevoNodo->librito.ISBN) {
            pLista=agregarAlPpio(pLista, nuevoNodo);
        } else {
            nodoSimple *seg=pLista;
            nodoSimple *ante;
            while(seg!=NULL && seg->librito.ISBN < nuevoNodo->librito.ISBN) {
                ante=seg;
                seg=seg->siguiente;
            }
            if(ante!=NULL) {
                ante->siguiente=nuevoNodo;
            }
            nuevoNodo->siguiente=seg;
        }
    }
    return pLista;
}

void mostrarListaSimpleDeLibros(nodoSimple *pLista) {
    ///directamente mostramosUnlibro cabroo
    nodoSimple *seg=pLista;
    while(seg!=NULL) {
        mostrarUnLibro(seg->librito);
        seg=seg->siguiente;

    }
}


void cambiarEstadoDeLibroAPrestado(nodoSimple *pLista, char nombreLibro[]) {


    while(pLista!=NULL) {
        if(strcmp(pLista->librito.nombreLibro, nombreLibro)==0) { /// Verificamos el nombre de los libros ya creados, con el nuevo y modificamos el estado
            pLista->librito.estadoLibro=2;
            pLista->librito.cantReservas+=1;

        }
        pLista=pLista->siguiente;

    }

}
void cambiarEstadoDeLibroADisponible(nodoSimple *pLista, char nombreLibro[]) {
    while(pLista!=NULL) {
        if(strcmp(pLista->librito.nombreLibro, nombreLibro)==0) { /// Verificamos el nombre de los libros ya creados, con el nuevo y modificamos el estado a disp.
            pLista->librito.estadoLibro=1;
        }
        pLista=pLista->siguiente;
    }
}

void mostrarLibrosDisponiblesPrestamo(nodoSimple* lista) {
    nodoSimple* seg=lista;
    while(seg!=NULL) {
        if(seg->librito.estadoLibro==1) {
            mostrarUnLibro(seg->librito);
        }
        seg=seg->siguiente;
    }


}

nodoSimple *modificarLibros(nodoSimple *pLista, char nombreLibro[]) {
    int opcion=0;
    char modificacion[MAXDIM];
    if (pLista!=NULL) {

        printf("ingrese el campo que quiere modificar, 0 para salir\n");
        printf("1_Nombre, 2_Autor, 3_Genero, 4_ISBN, 5_Editorial, 6_Cantidad de Reservas, 7_Estado\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");

        switch(opcion) {
        case 1:
            do {
                printf("ingrese el nombre del libro\n");
                fflush(stdin);
                gets(modificacion);
                strcpy(pLista->librito.nombreLibro, modificacion);
                system("cls");
            } while(validarChar(modificacion)==0);

            break;
        case 2:

            do {

                printf("ingrese el autor del libro\n");
                fflush(stdin);
                gets(modificacion);
                strcpy(pLista->librito.autor, modificacion);
                system("pause");
                system("cls");

            } while(validarChar(modificacion)==0 || tieneDigitos(modificacion)==1);

            break;
        case 3:
            ingresarGenero(modificacion);
            strcpy(pLista->librito.genero, modificacion);
            system("cls");
            break;
        case 4:
            pLista->librito.ISBN=rand()   %  999999999 + 111111111;
            system("cls");
            break;
        case 5:
            do {
                printf("ingrese la editorial del libro\n");
                fflush(stdin);
                gets(modificacion);
                strcpy(pLista->librito.editorial, modificacion);
                system("cls");
            } while(validarChar(modificacion)==0 || tieneDigitos(modificacion)==1);

            break;
        case 6:
            do {

                printf("ingrese la cantidad de reservas del libro\n");
                fflush(stdin);
                scanf("%i", &pLista->librito.cantReservas);
                system("cls");
            } while(pLista->librito.cantReservas<0);

            break;
        case 7:
            printf("ingrese el estado del libro\n");
            fflush(stdin);
            scanf("%i", &pLista->librito.estadoLibro);
            system("cls");
            break;
        default:
            printf("opcion no valida");
            system("cls");
            break;
        }
        printf("el libro se ha modificado con exito\n");
    }

    return pLista;

}

nodoSimple *buscarUltimo(nodoSimple *pLista) { /// Buscar ultimo en lista simple
    nodoSimple *rta;
    rta=pLista;
    while(rta->siguiente!=NULL) {
        rta=rta->siguiente;
    }
    return rta;
}

nodoSimple* buscarLibroMasPopular(nodoSimple* lista) { /// Buscamos el libro mas popular, verificando la cant de reservas que tiene
    nodoSimple* rta=lista;
    nodoSimple* seg=lista->siguiente;

    while(lista!=NULL) {
        while(seg!=NULL) {
            if(seg->librito.cantReservas > rta->librito.cantReservas) {
                rta=seg;
            }
            seg=seg->siguiente;
        }

        lista=lista->siguiente;

        if(lista!=NULL) {
            seg=lista->siguiente;
        }
    }

    return rta;
}

int pasarDeArchivoToADL(celdaBiblioteca AR[], int dimension, char archivo[]) {

    stLibro aux;
    FILE* archi=fopen(archivo, "rb");
    int validos=0;
    if(archi!=NULL) {
        while(fread(&aux, sizeof(stLibro), 1, archi)) {
            validos=alta(AR, validos, aux);
        }
        fclose(archi);
    }


    return validos;
}

void pasarDeAdlToArchivo(celdaBiblioteca AR[], int dimension, char archivo[]) {
    FILE *archi=fopen(archivo, "wb");
    int i=0;

    stLibro aux;
    if(archi!=NULL) {
        for(i=0; i<dimension; i++) {
            nodoSimple *seg=AR[i].listaLibros; /// Creamos la seguidora que tiene los datos
            while(seg!=NULL) {
                                                      /// copiamos los datos al stLibro aux, que luego lo mandamos al archivo, para la persistencia de datos
                strcpy(aux.autor, seg->librito.autor);
                strcpy(aux.editorial, seg->librito.editorial);
                strcpy(aux.genero, seg->librito.genero);
                strcpy(aux.nombreLibro, seg->librito.nombreLibro);
                aux.cantReservas = seg->librito.cantReservas;
                aux.estadoLibro = seg->librito.estadoLibro;
                aux.ISBN = seg->librito.ISBN;

                fwrite(&aux, sizeof(stLibro), 1, archi);

                seg = seg->siguiente;
            }

        }
        fclose(archi);
    }

}

nodoSimple* agregarAlFinal(nodoSimple* lista, nodoSimple* nuevoNodo) {
    if(lista==NULL) {
        lista=nuevoNodo;
    } else {
        nodoSimple* ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
    }


    return lista;
}



nodoSimple *buscarPorNombreArreglo(celdaBiblioteca AR[], int validos) {
    char nombreLibro[MAXDIM];
    nodoSimple *rta=NULL;
    printf("Ingrese el nombre del libro: \n");
    fflush(stdin);
    gets(nombreLibro);
    for(int i=0; i<validos; i++) { /// Recorremos el arreglo usando un for, y usamos el strcmpi para verificar el nombre si es identico
        nodoSimple *seg=AR[i].listaLibros;
        while(seg!=NULL && rta==NULL) {
            if(strcmpi(seg->librito.nombreLibro, nombreLibro)==0) {
                rta=seg;
            }
            seg=seg->siguiente;
        }
    }
    return rta;
}

///ARREGLO DE LISTAS (biblioteca)

int asignarGenero(celdaBiblioteca arreglo[], int validos, char genero[]) {
    strcpy(arreglo[validos].generoCelda, genero);
    idGenero++;
    arreglo[validos].idCelda=idGenero;
    arreglo[validos].listaLibros=inicListaSimple();
    validos++;

    return validos;
}

int buscarPosGenero(celdaBiblioteca arreglo[], int validos, char genero[]) {
    int pos=-1;
    int i=0;
    while(i<validos && pos==-1) { /// Recorremos el arreglo buscando el genero
        if(strcmpi(arreglo[i].generoCelda, genero)==0) {
            pos=i;
        }
        i++;
    }


    return pos;

}


int alta(celdaBiblioteca arreglo[], int validos, stLibro aux) {
    int pos=buscarPosGenero(arreglo, validos, aux.genero);

    if(pos==-1) {
        validos=asignarGenero(arreglo, validos, aux.genero);
        pos=validos-1;
    }

    nodoSimple* nuevo=crearUnNodoSimple(aux);
    arreglo[pos].listaLibros=agregarAlPpio(arreglo[pos].listaLibros, nuevo);


    return validos;
}

int ingresarABiblioteca(celdaBiblioteca arreglo[], int validos) { /// Funcion de carga de libros, mediante el alta y el cargarUnLibro

    char op='s';
    stLibro aux;
    while((op=='s' || op=='S') && validos<MAXDIM) {
        aux=cargarUnLibro();
        validos=alta(arreglo, validos,aux);
        puts("Desea cargar mas libros(s/n)");
        fflush(stdin);
        scanf("%c", &op);
    }

    return validos;
}



void mostrarBiblioteca(celdaBiblioteca arreglo[], int validos) {
    for(int i=0; i<validos; i++) {
        printf("\n------------------------------------------------------------Celda N: %i------------------------------------------------------------\n\n", arreglo[i].idCelda);
        printf("\nGENERO: %s\n\n", arreglo[i].generoCelda);
        mostrarListaSimpleDeLibros(arreglo[i].listaLibros);
        printf("\n\n-----------------------------------------------------------Fin Celda--------------------------------------------------------------\n\n");
    }

}
