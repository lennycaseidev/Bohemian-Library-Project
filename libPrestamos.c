#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 70
#include "libLibros.h"
#include "libPrestamos.h"
#include "libArboles.h"
#include "validaciones.h"

nodoDoble *inicListaDoble()
{
    return NULL;
}

nodoDoble *crearNodoPrestamo(stPrestamo dato)
{
    nodoDoble *nuevoNodo=(nodoDoble *)malloc(sizeof(nodoDoble));
    nuevoNodo->dato=dato;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}

stPrestamo crearUnPrestamo()   /// Realizamos la creacion del prestamo, verificando siempre los meses y la fecha
{
    stPrestamo cliente;
    int verifDia=0;
    int verifMes=0;
    int veriFecha=0;
    int diaAux=0;
    int mesAux=0;

    printf("ingrese la fecha de inicio del prestamo, (DIA)\n");
    fflush(stdin);
    scanf("%i", &diaAux);

    while(verifDia=validarDia(diaAux)==0)
    {
        printf("ingrese un dia correcto\n");
        fflush(stdin);
        scanf("%i", &diaAux);
    }
    printf("ingrese la fecha de inicio del prestamo, (MES)\n");
    fflush(stdin);
    scanf("%i", &mesAux);

    while(verifMes=validarMes(mesAux)==0)
    {
        printf("ingrese un mes correcto\n");
        fflush(stdin);
        scanf("%i", &mesAux);
    }
    veriFecha=validarFecha(diaAux, mesAux);

    if(veriFecha==1)
    {
        cliente.diaInicio=diaAux;
        cliente.mesInicio=mesAux;
        cliente.anioInicio=2023;
        if(cliente.mesInicio ==12)   /// En el caso que sea el mes de diciembre, le asignamos el vencimiento nosotros
        {
            cliente.diaVencimiento=cliente.diaInicio;
            cliente.mesVencimiento=1;
            cliente.anioVencimiento=cliente.anioInicio+1;
        }
        else
        {
            cliente.mesVencimiento=cliente.mesInicio+1; /// Si no es diciembre, le sumamos 1 y listo al vencimiento (es 1 mes el prestamo)
            cliente.diaVencimiento=cliente.diaInicio;
            cliente.anioVencimiento=cliente.anioInicio;
        }
    }

    return cliente;
}

nodoDoble *agregarAlPpioDoble(nodoDoble *pLista, nodoDoble *nuevoNodo)
{
    if(pLista==NULL)
    {
        pLista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=pLista;
    }
    pLista->anterior=nuevoNodo;
    return nuevoNodo;
}

nodoDoble *agregarEnOrdenDoble(nodoDoble *pLista, nodoDoble *nuevoNodo)
{
    if(pLista==NULL)
    {
        pLista=nuevoNodo;
    }
    else
    {
        if(pLista->dato.dniCliente > nuevoNodo->dato.dniCliente)
        {
            pLista=agregarAlPpioDoble(pLista, nuevoNodo);
        }
        else
        {
            nodoDoble *seg=pLista;
            nodoDoble *ante;
            while(seg!=NULL && seg->dato.dniCliente < nuevoNodo->dato.dniCliente)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante;
            nuevoNodo->siguiente=seg;
            if(seg!=NULL)
            {
                seg->anterior=nuevoNodo;
            }

        }

    }
    return pLista;
}

nodoDoble *cargarPrestamoEnLista(nodoDoble *pLista)
{
    stPrestamo aux;
    nodoDoble *nuevoNodo=NULL;
    aux=crearUnPrestamo();
    if(aux.diaInicio!=0)
    {
        nuevoNodo=crearNodoPrestamo(aux);
        pLista=agregarEnOrdenDoble(pLista, nuevoNodo);
    }

    return pLista;
}


void mostrarUnPrestamo(stPrestamo dato)
{
    puts("==================================");
    printf("libro prestado:%s\n", dato.nombreLibro);
    printf("DNI del cliente:%s\n", dato.dniCliente);
    printf("fecha de inicio:%i/%i/%i\n", dato.diaInicio, dato.mesInicio, dato.anioInicio);
    printf("fecha de vencimiento:%i/%i/%i\n", dato.diaVencimiento, dato.mesVencimiento, dato.anioVencimiento);

    puts("==================================\n");

}

void mostrarListaPrestamo(nodoDoble *pLista)
{
    nodoDoble *seg=pLista;
    while(seg!=NULL)
    {
        mostrarUnPrestamo(seg->dato);
        seg=seg->siguiente;
    }

}

void nodoDobleToArchivo(char nombreArchivo[], nodoDoble *pLista)   /// Nodo to archivo, para la persistencia de datos, utilizando un auxiliar
{
    FILE *archi=fopen(nombreArchivo, "wb");
    nodoDoble *seg=pLista;
    stPrestamo aux;
    if(archi!=NULL)
    {
        while(seg!=NULL)
        {

            aux.anioInicio=seg->dato.anioInicio;
            aux.anioVencimiento=seg->dato.anioVencimiento;
            aux.diaInicio=seg->dato.diaInicio;
            aux.diaVencimiento=seg->dato.diaVencimiento;
            strcpy(aux.dniCliente, seg->dato.dniCliente);
            aux.mesInicio=seg->dato.mesInicio;
            aux.mesVencimiento=seg->dato.mesVencimiento;
            strcpy(aux.nombreLibro, seg->dato.nombreLibro);
            fwrite(&aux,sizeof(stPrestamo),1,archi);
            seg=seg->siguiente;
        }
        fclose(archi);
    }
}

nodoDoble *archivoToNodoDoble(char nombreArchivo[], nodoDoble *pLista)
{
    FILE *archi=fopen(nombreArchivo, "rb");
    stPrestamo prestamo;
    nodoDoble *nuevoNodo=NULL;
    if(archi!=NULL)
    {
        while(fread(&prestamo, sizeof(stPrestamo), 1, archi))
        {
            nuevoNodo=crearNodoPrestamo(prestamo);
            pLista=agregarAlFinalDoble(pLista, nuevoNodo);
        }
        fclose(archi);
    }
    return pLista;
}

nodoDoble *buscarPrestadoPorDni(nodoDoble *pLista, char dni[], char nombreLibro[])
{
    nodoDoble* rta=NULL;
    while(pLista!=NULL && rta==NULL)
    {
        if(strcmp(pLista->dato.dniCliente, dni)==0   &&  strcmp(pLista->dato.nombreLibro, nombreLibro)==0)   /// Verificamos los datos para saber si el dni y el nombre son identicos
        {
            rta=pLista;
        }
        pLista=pLista->siguiente;
    }
    return rta;
}

nodoDoble* borrarNodoDoble(nodoDoble* lista, char dni[])
{
    nodoDoble * aBorrar=NULL;
    nodoDoble * seg=NULL;

    if(lista!=NULL)
    {
        if(strcmp(lista->dato.dniCliente, dni)==0)
        {
            aBorrar=lista;

            lista=lista->siguiente;
            if(lista!=NULL)
            {
                lista->anterior=NULL;
            }
            free(aBorrar);
        }
        else
        {
            seg=lista->siguiente;
            while(seg!=NULL && strcmp(lista->dato.dniCliente, dni)!=0)
            {
                seg=seg->siguiente;
            }

            if( seg!= NULL)
            {
                nodoDoble * anterior=seg->anterior;

                anterior->siguiente = seg->siguiente;

                if(seg->siguiente)
                {
                    nodoDoble * siguiente = seg->siguiente;
                    siguiente->anterior=anterior;
                }
                free(seg);
            }

        }
    }

    return lista;

}

nodoDoble * prestarUnLibro(nodoDoble *pLista, arbolCliente *arbol, char dni[], celdaBiblioteca AR[], int validos, char archivoPrestamos[])
{
    arbolCliente *rta=NULL;
    nodoSimple *libro=NULL;
    rta=buscar(arbol, dni);
    libro=buscarPorNombreArreglo(AR, validos);
    if(rta==NULL)
    {
        printf("No se ha encontrado al cliente\n");
    }
    else
    {
        if(rta->cliente.estado < 4)
        {
            ///libro=buscarLibroPorNombre(pListaLibros, nombreLibro);
            if(libro==NULL)
            {
                printf("no hemos encontrado el libro\n");
            }
            else
            {
                if(libro->librito.estadoLibro == 1)
                {
                    pLista=cargarPrestamoEnLista(pLista);
                    strcpy(pLista->dato.dniCliente, dni);
                    strcpy(pLista->dato.nombreLibro,libro->librito.nombreLibro);
                    cambiarEstadoDeLibroAPrestado(libro, libro->librito.nombreLibro);
                    rta->cliente.cantPrestamos+=1;
                    rta->cliente.estado+=1;
                    nodoDobleToArchivo(archivoPrestamos, pLista);
                }
                else
                {
                    printf("El libro que esta buscando esta actualmente en prestamo\n");
                }
            }

        }
        else
        {
            printf("El cliente tiene demasiados libros prestados\n");
        }


    }
    return pLista;
}

nodoDoble *devolverUnLibro(nodoDoble *pLista, arbolCliente *arbol, char dni[], celdaBiblioteca AR[], int validos, char archivoPrestamos[])
{
    arbolCliente *rta=NULL;
    nodoSimple *libro=NULL;
    nodoDoble *aux=NULL;
    rta=buscar(arbol, dni);
    libro=buscarPorNombreArreglo(AR, validos); /// Consultamos acerca de que libro es, para luego verificar si esta prestado
    char control='s';

    if(rta==NULL)
    {
        printf("No se ha encontrado el cliente\n");
    }
    else
    {
        if(libro!=NULL)
        {
            if(libro->librito.estadoLibro == 1)
            {
                printf("El libro no esta prestado \n");
            }
            else
            {
                aux=buscarPrestadoPorDni(pLista, dni, libro->librito.nombreLibro); /// Si coincide que fue prestado a esa persona, cambiamos los estados y los seteamos a los default
                if(aux!=NULL)
                {
                    cambiarEstadoDeLibroADisponible(libro, libro->librito.nombreLibro);
                    rta->cliente.estado-=1;
                    printf("El cliente se atraso con la devolucion del libro? (s/n) \n"); /// Preguntamos si se atraso o si estaba en el periodo correcto
                    fflush(stdin);
                    scanf("%c", &control);
                    if(control=='s')
                    {
                        rta->cliente.precioMultas+=1000; /// En caso que si se haya atrasado, le colocamos una multa
                    }
                    pLista=borrarNodoDoble(pLista, dni); /// Y luego, borramos el prestamos previamente realizado
                    nodoDobleToArchivo(archivoPrestamos, pLista);
                }
                else
                {
                    printf("Este cliente no pidio prestado ese libro\n");
                }
            }

        }

    }
    return pLista;
}




nodoDoble *actualizarPrestamo(nodoDoble *pLista, arbolCliente *arbol, char dni[], celdaBiblioteca AR[], int validos, char archivoPrestamos[])
{
    nodoSimple *libro = NULL;
    arbolCliente *rta = NULL;
    nodoDoble *aux = NULL;
    rta=buscar(arbol, dni);
    libro=buscarPorNombreArreglo(AR, validos); /// Consultamos acerca de que libro es, para luego verificar si esta prestado
    if(rta == NULL)
    {
        printf("no se ha encontrado el cliente\n");
    }
    else
    {
        if(libro != NULL)
        {
            if(libro->librito.estadoLibro == 1)
            {
                printf("El libro no esta prestado\n");
            }
            else
            {
                aux=buscarPrestadoPorDni(pLista, dni, libro->librito.nombreLibro); /// Una vez verificado, se lo damos por un mes mas
                if(aux!=NULL)
                {
                    if(aux->dato.mesVencimiento == 12)
                    {
                        aux->dato.anioVencimiento=aux->dato.anioInicio + 1;
                        aux->dato.mesVencimiento = 1;
                    }
                    else
                    {
                        aux->dato.mesVencimiento=aux->dato.mesVencimiento + 1;
                    }
                    nodoDobleToArchivo(archivoPrestamos, pLista);
                }
                else
                {
                    printf("Este cliente no pidio prestado ese libro\n");
                }
            }
        }
        else
        {
            puts("No se ha encontrado el libro");
        }
    }

    return pLista;
}

stPrestamo verPrimero(nodoDoble* lista)
{
    stPrestamo aux;
    if(lista!=NULL)   /// verificamos si hay datos en la lista, y le asignamos al auxiliar, el dato de la lista
    {
        aux=lista->dato;
    }
    return aux;
}

nodoDoble* borrarPrimero(nodoDoble* lista)
{
    nodoDoble* aux=lista; /// creamos un nodo auxiliar, para ser borrado luego

    if(lista!=NULL)
    {
        lista=lista->siguiente; /// avanzamos en la lista

        if(lista!=NULL)

            lista->anterior=NULL; /// si siguen habiendo mas de un dato, borramos el anterior

        free(aux); /// Aca lo borramos
    }
    return lista;
}

nodoDoble* buscarUltimoDoble(nodoDoble* lista)
{
    while(lista->siguiente!=NULL)   /// avanzamos hasta que el siguiente sea == NULL y por ende ese es el ultimo, luego lo retornamos
    {
        lista=lista->siguiente;
    }

    return lista;
}

nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else     /// Para agregar al final en una lista, nos conviene utilizar la funcion de buscar el ultimo, ya posicionarnos ahi, y luego el siguiente a ese le asignamos el nuevo nodo.
    {
        nodoDoble* ultimo=buscarUltimoDoble(lista);
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo; /// Lo conectamos con el ultimo, asi no perder la relacion de los nodos
    }
    return lista;
}
