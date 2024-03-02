#ifndef LIBLIBROS_H_INCLUDED
#define LIBLIBROS_H_INCLUDED


typedef struct
{
    char nombreLibro[MAXDIM];
    char autor[MAXDIM];
    char genero[MAXDIM];
    int ISBN;
    char editorial[MAXDIM];
    int cantReservas;
    int estadoLibro; ///1 disponible, 2 reservado, 3 en prestamo etc

} stLibro;


typedef struct
{
    stLibro librito;
    struct nodoSimple* siguiente;
} nodoSimple;


typedef struct{

int idCelda;
char generoCelda[MAXDIM];
nodoSimple* listaLibros;

}celdaBiblioteca;

///UNLIBRO
stLibro cargarUnLibro();
void opcionesGeneros();
void mostrarUnLibro(stLibro librito);
void ingresarGenero(char genero[]);

///LISTAS
nodoSimple *inicListaSimple();
nodoSimple *crearUnNodoSimple(stLibro dato);
nodoSimple *agregarAlPpio(nodoSimple *pLista, nodoSimple *nuevoNodo);
nodoSimple *agregarEnOrden(nodoSimple *pLista, nodoSimple *nuevoNodo);
void mostrarListaSimpleDeLibros(nodoSimple *pLista);
void listaSimpleToArchivo(char nombreArchivo[], nodoSimple *pLista);
void cambiarEstadoDeLibroAPrestado(nodoSimple *pLista, char nombreLibro[]);
void cambiarEstadoDeLibroADisponible(nodoSimple *pLista, char nombreLibro[]);
void mostrarLibrosDisponiblesPrestamo(nodoSimple* lista);
nodoSimple *modificarLibros(nodoSimple *pLista, char nombreLibro[]);
nodoSimple *buscarUltimo(nodoSimple *pLista);
nodoSimple* buscarLibroMasPopular(nodoSimple* lista);
nodoSimple* agregarAlFinal(nodoSimple* lista, nodoSimple* nuevoNodo);

///ARREGLO DE LISTAS
int asignarGenero(celdaBiblioteca arreglo[], int validos, char genero[]);
int buscarPosGenero(celdaBiblioteca arreglo[], int validos, char genero[]);
int alta(celdaBiblioteca arreglo[], int validos, stLibro aux);
int ingresarABiblioteca(celdaBiblioteca arreglo[], int validos);
void mostrarBiblioteca(celdaBiblioteca arreglo[], int validos);
int pasarDeArchivoToADL(celdaBiblioteca AR[], int dimension, char archivo[]);
void pasarDeAdlToArchivo(celdaBiblioteca AR[], int dimension, char archivo[]);
nodoSimple *buscarPorNombreArreglo(celdaBiblioteca AR[], int validos);
#endif // LIBLIBROS_H_INCLUDED
