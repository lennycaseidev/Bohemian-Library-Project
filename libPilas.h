#ifndef LIBPILAS_H_INCLUDED
#define LIBPILAS_H_INCLUDED

typedef struct
{
    int dato;
    struct nodoPila* siguiente;


} nodoPila;

typedef struct
{
    struct nodoPila*lista;

}Pila;


nodoPila* iniclistaPila();
nodoPila* crearNodoPila(int dato);
nodoPila* agregarPpioPila(nodoPila* lista, nodoPila* nuevoNodo);
nodoPila* buscarUltimoPila(nodoPila* lista);
nodoPila* agregarAlFinalPila(nodoPila* lista, nodoPila* nuevoNodo);
void mostrarLista(nodoPila* lista);
void inicPila(Pila* p);
int pilaVacia(Pila* p);
void apilar(Pila* p, int dato);
int desapilar (Pila* p);
int tope(Pila* p);
void leer(Pila * p);
void mostrarPila(Pila p);
void pilaToArchivo(Pila* p, char archivo[]);
void archivoToPila(Pila* p, char archivo[]);


#endif // LIBPILAS_H_INCLUDED
