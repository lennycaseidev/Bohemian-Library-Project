#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXDIM 70
#include "libArboles.h"
#include "validaciones.h"
#include "libPrestamos.h"

int validarChar (char cadena[]) {
    int flag=0;

    if (strlen(cadena)<3 || strlen(cadena)>45) { /// Verifica la longitud del string
        printf("ERROR. Dato ingresado incorrecto (Tiene que ser entre 3 y 45 caracteres). REINTENTAR: \n");
        flag = 0;
    } else
        flag = 1;


    return flag;
}

int tieneDigitos(char cadena[]) { /// revisa si hay un numero en una cadena de caracteres
    int flag=0;
    int longi=strlen(cadena);

    for(int i=0; i<longi; i++) {
        if(isdigit(cadena[i])) {
            flag=1;
        }
    }
    if(flag==1)
        puts("ERROR, no se permiten caracteres especiales.. REINTENTAR");

    return flag;
}

int tieneCaracteres(char cadena[]) {
    int flag=0;

    for(int i=0; i<strlen(cadena); i++) {
        if(isalpha(cadena[i])) { /// la funcion isAlpha verifica si un carácter es una letra del alfabeto. Devuelve un valor distinto de cero si el carácter es una letra y cero si no lo es.
            flag=1;
        }
    }
    if (flag==1)
        puts("ERROR, asignacion invalida(caracter encontrado).. REINTENTAR");

    return flag;
}

int validarMes(int mes) {
    int flag=0;
    if(mes <=12 && mes>= 1) {
        flag=1;
    }
    return flag;
}



int validarDia(int dia) {
    int flag=0;
    if(dia <=31 && dia >=1) {
        flag=1;
    }

    return flag;
}

int validarFecha(int dia, int mes) { /// Se valida la fecha, teniendo en cuenta los meses, y sus dias totales
    int flag=0;
    switch(mes) {
    case 1:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    case 2:
        if(dia>28) {
            printf("el dia es incorrecto, febrero no tiene mas de 28 dias\n");
        } else {
            printf("se ha cargado correctamente\n");
            flag=1;
        }
        system("pause");
        system("cls");
        break;
    case 3:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    case 4:
        if(dia>30) {
            printf("el dia es incorrecto, abril no tiene mas de 30 dias\n");
        } else {
            flag=1;
        }
        system("pause");
        system("cls");
        break;
    case 5:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    case 6:
        if(dia>30) {
            printf("el dia es incorrecto, junio no tiene mas de 30 dias\n");
        } else {
            flag=1;
        }
        system("pause");
        system("cls");
        break;
    case 7:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    case 8:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    case 9:
        if(dia>30) {
            printf("el dia es incorrecto, septiembre no tiene mas de 30 dias\n");
        } else {
            flag=1;
        }
        system("pause");
        system("cls");
        break;
    case 10:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    case 11:
        if(dia>30) {
            printf("el dia es incorrecto, noviembre no tiene mas de 30 dias\n");
        } else {
            flag=1;
        }
        system("pause");
        system("cls");
        break;
    case 12:
        printf("se ha cargado correctamente\n");
        flag=1;
        system("pause");
        system("cls");
        break;
    }

    return flag;
}


