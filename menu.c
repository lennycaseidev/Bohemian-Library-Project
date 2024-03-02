#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXDIM 70
#include "libLibros.h"
#include "libArboles.h"
#include "validaciones.h"
#include "libPrestamos.h"

void dibujo() {
    puts("                                   ......");
    puts("                  .:=+#%#****++***##*+=:..");
    puts("                  -=---::::::::::::::::::+#*:..");
    puts("                  *---::::::::::::::::::::::::*@-.");
    puts("                .++---::-++*+==--::::::::::::::::-**.........-*%%%#*+=---=+*##%*-..");
    puts("                :%----:::::::::::::-=++:::::::::::::=*+=#*==::::::::::::::::::::::==**-.....");
    puts("               .+=---:::::::::::::::::::=+-::::::::--=--:::::::::::::::::::::::::::::::=**-..");
    puts("               .#----::::::::::::::::::::::==::::::--+--::::::::::::::::::::::::::::::::--=*+..");
    puts("              .#*---::::::::::::::::::::::::::::::--=+-::::::-==+#***##+==-:::::::::::::----++...");
    puts("              =%----::::::::::::-*#*--::::::::::::--%--:::=*:::::::::::::::::==-::::::::----%#%-");
    puts("             :@=---::::::::::::::::::::+#:::::::::-+=-:::::::::::::::::::::::::::--:::::---=%#%..");
    puts("            .#%=---:::::::::::::::::::::::=+:::::--#--::::::::::::::::::::::::::::::::::---#%#*..");
    puts("            :@*----:::=***###+-::::::::::::::::::-#=-::::::::-+*+--=+*+:::::::::::::::::--=@#%-..");
    puts("           .@%----:::::::::::::::-++*=::::::::::-=#-::::::--::::::::::::::=-=:::::::::::--*%##.");
    puts("           +%+----:::::::::::::::::::::+=-::::::-++-:::::::::::::::::::::::::::=-:::::::--%###.");
    puts("          .%@=---:::::::::::::::::::::::::+::::--%-::::::::::::::::::::::::::::::::::::--*%#%=.                Antonelli-Blanco-Casei");
    puts("         .%%*----::::::---:::::::::::::::::::::-#=-::::::::---*%%%%#+::-:::::::::::::::-=@##%..");
    puts("         -%%-----:::::::::::::-#@#::::::::::::-=#-::::::::::::::::::::::::*=:::::::::::-*%##+..");
    puts("        .#@*-----:::::::::::::::::::-*=:::::::-=+-:::::::::::::::::::::::::::-=::::::::-%##%-..");
    puts("        *%%-----:::::::::::::::::::::::-==::::-%-:::::::::::::::::::::::::::::::-:::::-+%##%.");
    puts("       :%%=-----::::::::::-=+=*-::::::::::-::-=%-::::::::::::-+****+=-::::::::::::::::-%%#%=.");
    puts("      .*%%------:::::::::::::::::=+=-::::::::-*--::::::==+-::::::::::::-++=-:::::::::-=%##%..");
    puts("      =%@+-----::::::::::::::::::::::-+-::::--*-:::::::::::::::::::::::::::::+-::::::-#%##+..");
    puts("     .#%#----------::::::::::::::::::::::-::-=*-:::::::::----------::::::::::::::::::-@##%-..");
    puts("     =%@=#%#+==========+%@%#-:::::::::::::::-%--::::=+-::::::::::::::-+*::::::::::::-*@##%...");
    puts("    :%#%%%%%#*=--------------=+*%*:::::::::-=+-:::::::::::::::::::::::::::-+:::::::--#%#%:");
    puts("    .:-=*%@%%%%##%%%%%%##+--------=*#+:::::-+=-:::::::::::::::::::::::::::::::::::--=%###.");
    puts("              ..:=++#%%%%###%%%#*+=---*#=::----:::::::=++++++++=-::::::::::::::::---*%#%=");
    puts("                         ..:+**#%%%%%%%*+#*----=+##+=-------------=+##*+-:::::::----%%#%..");
    puts("                             ........:#@##%%@@@@%%%%#*++====-------------+#*-::----+@#%-..");
    puts("                                     -%%%########%##@%@%####%%@@@%#+==-------+#----#%##...");
    puts("                                        .....-+%@%@+........-+%@@@%####%%@@%*------%#%=..");
    puts("                                                   ..................:-=*%@@%%%%%%#%##..");
    puts("                                                                            ...-=*%%%-..");
    puts("                                                                                    ...");
    system("pause");
    system("cls");
}

void dibujosDespedida() {
    puts("\t                    @@@@@@@    @@@@@@@@@      @@@@      @@@@@@@@   @@      @@@      @@@@@@@    @@    @@ ");
    puts("\t                  @@@     @@@  @@     @@@     @@@@     @@@    @@@  @@     @@@@@    @@@   @@@   @@    @@ ");
    puts("\t       @@@   @@   @@           @@@    @@@    @@ @@@   @@@          @@    @@@ @@     @@@@       @@    @@ ");
    puts("\t                  @@    @@@@@  @@@@@@@@     @@   @@@  @@@          @@    @@   @@      @@@@@@   @@    @@");
    puts("\t        @    @@   @@      @@@  @@    @@@   @@@@@@@@@   @@     @@@  @@   @@@@@@@@@  @@     @@@  @@      ");
    puts("\t        @    @@    @@@@ @@@@@  @@     @@@  @@     @@@   @@@@@@@@   @@  @@@     @@@ @@@@  @@@   @@    @@");
    puts("\t       @@@   @@      @@@@@     @@      @@@@@       @@      @@      @@  @@       @@   @@@@@     @@    @@");
    puts("\t       @@@   @@                                                           @                            ");
    puts("\t                                                              @@         @@@                           ");
    puts("\t                                                              @@@        @@@                             ");
    puts("\t                                                              @@@@        @@                            ");
    puts("\t                                                 @@@@@         @@@@        @@                           ");
    puts("\t                                                  @@@@@@       @@@@@        @@                           ");
    puts("\t                                                    @@@@@       @@@@         @@                          ");
    puts("\t                                                      @@@        @@@@         @@                        ");
    puts("\t                                                       @@@        @@@         @@                       ");
    puts("\t                                                        @@@        @@@                                 ");
    puts("\t                                                         @@@       @@@                                 ");
    puts("\t                                       @@@@@@@            @@@       @@@                                ");
    puts("\t                                       @@@@@@@@@@         @@@                     @@                   ");
    puts("\t                                             @@@@@@        @@                      @@                  ");
    puts("\t                                                @@@@                                 @@               ");
    puts("\t                                                  @@@                                 @@              ");
    puts("\t                                @@@                @@                                  @@            ");
    puts("\t                                @@@@@@@                                                     @@@      ");
    puts("\t                                  @@@@@@@@@                                                     @@ ");
    puts("\t                                       @@@@@@@                           @@                     @@@");
    puts("\t                                          @@@@                          @@@@                   @@@");
    puts("\t                                                           @@           @@@@                 @@@@ ");
    puts("\t                                                          @@@@           @@@                 @@  ");
    puts("\t                                                          @@@@                              @@@");
    puts("\t                                                           @@@                              @@");
    puts("\t                                            @@                                              @@");
    puts("\t                                            @@                                              @@@");
    puts("\t                                            @@@                                             @@@");
    puts("\t                                            @@@                                 @           @@@");
    puts("\t                                             @@                                @@@          @@@");
    puts("\t           @@@             @@                @@@                              @@@           @@@");
    puts("\t            @@@@           @@@                @@           @                 @@@            @@@ ");
    puts("\t            @@@@@         @@@@                 @@          @@@             @@@             @@@ ");
    puts("\t              @@@@         @@@                 @@            @@@@@      @@@@@              @@@");
    puts("\t               @@@         @@@                  @@@             @@@@@@@@@@@                @@@");
    puts("\t                @@@        @@@                   @@@                                      @@@@");
    puts("\t                @@@@       @@@                    @@@                                     @@@@");
    puts("\t    @             @@@@     @@@                      @@@                                  @@@@@                 @ ");
    puts("\t    @@              @@@    @@                         @@@@                              @@@@@@@@              @@");
    puts("\t     @@@             @@@@  @@@                            @@@@                       @@@@     @@@           @@@@");
    puts("\t     @@@@@@           @@@@@@@@                                @@@@@@@@@@@@       @@@@@@@        @@         @@@  ");
    puts("\t        @@@@@@@@      @@@@@@@@                                   @@@@@@@@@@@@@@@@@@@@@@          @@      @@@  ");
    puts("\t             @@@@@@@@@@@@@@@@@                                    @@@@@   @@@@@@@@               @@@   @@@   ");
    puts("\t                   @@@@@@@@@@@@@                                  @@@                             @@@@@@    ");
    puts("\t                    @@@@@@@@@@@@@@@@@@@@                          @@                               @@@@      ");
    puts("\t                  @@@@@@             @@@@@@@@@@@@@@@@            @@                                  @@      ");
    puts("\t    @@@@@@@@@@@@@@@@@@                     @@@@@@@@@@@@@@@@@@@@@@@@                                  @@      ");
    puts("\t        @ @@@@@                                             @@@@@@                                    @@     ");
    puts("\t                                                              @@@                                      @@     ");
    puts("\t                                                              @@                                        @@@    ");
    puts("\t                                                              @                                          @@   ");
    puts("\t                                                             @@                                               ");
    puts("\t                                                           @@@                                               ");
    puts("\t                                                          @@@                                                ");
    puts("\t                                                         @@@                                                ");
    puts("\n\n\nimagen link: https://www.infocatolica.com/blog/puertadedamasco.php/1108241040-es-de-bien-nacidos");
    puts("Reescalado en: https://www.asciiart.eu/image-to-ascii");








}

void menuPrincipal (int validos, celdaBiblioteca arreglo[], nodoDoble *listaDoble, arbolCliente *arbol, char archivoLibros[], char archivoPrestamos[], char archivoClientes[], Pila* p, char archivoPila[]) {

    dibujo();
    int op1,opC = 0;
    char op2;
    char auxGenero[MAXDIM];
    char dniABuscar[MAXDIM];
    char contSw;
    arbolCliente* rta=inicArbol();
    nodoSimple *auxLista = inicListaSimple();
    nodoSimple *auxNombreLibro=inicListaSimple();
    validos=pasarDeArchivoToADL(arreglo, MAXDIM, archivoLibros);
    listaDoble=archivoToNodoDoble(archivoPrestamos, listaDoble);

    int posGenero = 0;
    do {
        puts("Seleccione una de las siguientes opciones: ");
        puts("1:Novedades de la biblioteca");
        puts("2:Cargar un libro");
        puts("3:Buscar un libro por criterio");
        puts("4:Mostrar libros disponibles");
        puts("5:Mostrar todos los libros de la Biblioteca");
        puts("6:Actualizar informacion de un libro");
        puts("7:Sacar prestamo de un libro");
        puts("8:Devolver un libro prestado");
        puts("9:Renovar un prestamo");
        puts("10:Mostrar lista de prestamos");
        puts("11:Registrar nuevos miembros");
        puts("12:Mostrar los miembros");
        puts("13:Buscar un miembro por DNI");
        puts("14:Guardar registro Historico de multas");
        puts("15:Mostrar registro Historico de multas");
        puts("16:salir");
        scanf("%i",&op1);
        system("cls");
        switch(op1) {
        case 1:
            puts("BIENVENIDO\n");
            puts("Ingrese el genero para asi buscar el libro mas famoso en nuestra biblioteca!");
            fflush(stdin);
            gets(auxGenero);
            posGenero=buscarPosGenero(arreglo, validos, auxGenero);
            if(posGenero==-1) {
                puts("ERROR, genero ingresado incorrecto..");
            } else {
                auxLista=buscarLibroMasPopular(arreglo[posGenero].listaLibros);

                if(auxLista==NULL) {
                    puts("No hay libros con las suficientes cantidades de reservas(0)");
                } else
                    mostrarUnLibro(auxLista->librito);
            }
            puts("\n\n Y una honorable mencion a nuestro cliente con el mayor numero de prestamos!!:\n");
            rta=buscarClienteMaxPrestamos(arbol);
            if(rta==NULL) {
                puts("No hay clientes que hayan pedido un libro :(    (todavia)");
            } else {

                mostrarUnCliente(rta->cliente);

                puts("Le deseamos lo  mejor, y que siga asi!\n");
            }
            system("pause");
            system("cls");
            break;

        case 2:
            validos=ingresarABiblioteca(arreglo, validos);
            pasarDeAdlToArchivo(arreglo, validos, archivoLibros);
            system("pause");
            system("cls");
            break;

        case 3:
            do {
                puts("Ingrese el critero:\n1- Genero \n2- Nombre del Libro");
                scanf("%i",&opC);
                switch(opC) {
                case 1:
                    puts("Que genero desea buscar?");
                    fflush(stdin);
                    gets(auxGenero);

                    posGenero = buscarPosGenero(arreglo, validos, auxGenero);
                    if(posGenero == -1) {
                        puts("Genero ingresado no encontrado");
                    } else {
                        mostrarListaSimpleDeLibros(arreglo[posGenero].listaLibros);
                    }
                    break;
                case 2:
                    auxNombreLibro=buscarPorNombreArreglo(arreglo, validos);
                    if(auxNombreLibro==NULL) {
                        puts("no se ha encontrado el libro");
                    } else {
                        mostrarUnLibro(auxNombreLibro->librito);
                    }

                    break;
                default:
                    puts("Ingrese una opcion valida");
                    break;
                }
                puts("Desea buscar otro libro? (s/n)");
                fflush(stdin);
                scanf("%c",&contSw);
            } while(contSw == 's' || contSw == 'S');
            system("pause");
            system("cls");
            break;
        case 4:
            puts("===LIBROS DISPONIBLES===\n");
            for(int i=0; i<validos; i++) {
                mostrarLibrosDisponiblesPrestamo(arreglo[i].listaLibros);
            }

            system("pause");
            system("cls");
            break;
        case 5:
            mostrarBiblioteca(arreglo, validos);
            system("pause");
            system("cls");
            break;

        case 6:
            auxNombreLibro=buscarPorNombreArreglo(arreglo, validos);
            if(auxNombreLibro !=NULL) {
                auxNombreLibro=modificarLibros(auxNombreLibro, auxNombreLibro->librito.nombreLibro);
                pasarDeAdlToArchivo(arreglo, validos, archivoLibros);
            } else {
                puts("no se ha encontrado el libro\n");
            }
            system("pause");
            system("cls");

            break;

        case 7:
            printf("ingrese el dni del cliente\n");
            fflush(stdin);
            gets(dniABuscar);
            listaDoble=prestarUnLibro(listaDoble, arbol,dniABuscar, arreglo, validos, archivoPrestamos);
            pasarDeAdlToArchivo(arreglo,validos,archivoLibros);
            arbolToArchivo(archivoClientes, arbol);
            system("pause");
            system("cls");
            break;

        case 8:

            printf("ingrese el dni del cliente\n");
            fflush(stdin);
            gets(dniABuscar);
            listaDoble=devolverUnLibro(listaDoble, arbol, dniABuscar, arreglo, validos, archivoPrestamos);
            pasarDeAdlToArchivo(arreglo,validos,archivoLibros);
            arbolToArchivo(archivoClientes, arbol);
            system("pause");
            system("cls");
            break;

        case 9:

            printf("ingrese el dni del cliente\n");
            fflush(stdin);
            gets(dniABuscar);
            listaDoble=actualizarPrestamo(listaDoble, arbol, dniABuscar, arreglo, validos, archivoPrestamos);

            break;

        case 10:
            mostrarListaPrestamo(listaDoble);
            system("pause");
            system("cls");

            break;

        case 11:

            arbol = cargarMuchosClientes(arbol);
            arbolToArchivo(archivoClientes, arbol);
            system("pause");
            system("cls");



            break;

        case 12:

            inOrder(arbol);
            system("pause");
            system("cls");


            break;

        case 13:
            puts("Ingrese el DNI a buscar: ");
            fflush(stdin);
            gets(dniABuscar);
            rta = buscar(arbol, dniABuscar);
            if(rta!=NULL) {

                mostrarUnCliente(rta->cliente);
            } else {
                puts("No se encontro un Cliente con ese DNI..");
            }
            system("pause");
            system("cls");

            break;

        case 14:
            precioMultasToPila(arbol,p); /// Enviamos las multas hacia la pila
            system("pause");
            system("cls");
            break;

        case 15:
            mostrarPila(*p);
            system("pause");
            system("cls");
            break;
        case 16:
            system("cls");
            break;
        default:
            puts("opcion incorrecta");
            system("pause");
            system("cls");
            break;
        }
        puts("Desea continuar en el programa? (s/n)");
        fflush(stdin);
        scanf("%c",&op2);
        system("cls");
    } while(op2 == 's' || op2 == 'S');


}
