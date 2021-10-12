#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "convert.h"
#include "strings.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_NO_HAY_MEMORIA 2
#define ERROR_OVERFLOW 3
#define ERROR_ENTRADA_LONGITUD_INVALIDA 4
#define ERROR_ENTRADA_CARACTER_INVALIDO 6
#define ERROR_ENTRADA_DIGITO_BASE_ORIGEN 7
#define ERROR_ENTRADA_BASES_INVALIDAS 8
#define precisionEntera 10
#define precisionFraccional 5

/**
* Muestra un mensaje de error y finaliza erroneamente el programa
* @param ERROR numero que indica el tipo de error ocurrido
*/
void abortar(int ERROR){
    switch (ERROR){
        case 2:
            printf("Ocurrio un error: memoria insuficiente");
            break;
        case 3:
            printf("Ocurrio un error de OVERFLOW debido a que la parte entera del numero no puede ser representada con %d digitos en la base solicitada", precisionEntera);
            break;
        case 4:
            printf("Ocurrio un error: la parte entera ingresada debe tener como maximo %d digitos y la parte decimal como maximo %d", precisionEntera, precisionFraccional);
            break;
        case 6:
            printf("Ocurrio un error: uno/s de los digitos ingresados en el numero no es/son valido/s");
            break;
        case 7:
            printf("Ocurrio un error: existe/n digito/s en el numero que no pertenecen a la base origen ingresada");
            break;
        case 8:
            printf("Ocurrio un error: las bases deben pertenecer al rango [2, 16]");
            break;
    }
    exit(EXIT_FAILURE);
}

/**
* Lee los valores ingresados por consola y se los asigna a las distintas variables
* @param argc numero de caracteres ingresados por consola
* @param argv array de punteros a caracteres
*/
void leer_consola(int* argc, char* argv[])
{
    int* i;
    int* sonIgualesAux;
    i = (int*) malloc(sizeof(int));
    sonIgualesAux = (int*) malloc(sizeof(int));
    if(i == NULL || sonIgualesAux == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    for(*i = 0; *i < *argc; (*i)++){

        son_cadenas_iguales(argv[*i], "-n", sonIgualesAux);
        if(*sonIgualesAux){
            int* longitudCadena = (int*) malloc(sizeof(int));

            if(longitudCadena == NULL)
                abortar(ERROR_NO_HAY_MEMORIA);

            longitud_cadena(argv[(*i + 1)], longitudCadena);
            parte_entera(argv[(*i + 1)], longitudCadena, numeroParteEnteraChar);

            parte_decimal(argv[(*i + 1)], longitudCadena, numeroParteFraccionariaChar);

            free(longitudCadena);
            *sonIgualesAux = 0;
            continue;
        }

        son_cadenas_iguales(argv[*i], "-s", sonIgualesAux);
        if(*sonIgualesAux){
            *baseOrigen = atoi(argv[*i + 1]);
            *sonIgualesAux = 0;
            continue;
        }

        son_cadenas_iguales(argv[*i], "-d", sonIgualesAux);
        if(*sonIgualesAux){
            *baseDestino = atoi(argv[*i + 1]);
            *sonIgualesAux = 0;
            continue;
        }

        son_cadenas_iguales(argv[*i], "-v", sonIgualesAux);
        if(*sonIgualesAux){
            *mostrarPasos = 1;
            *sonIgualesAux = 0;
            continue;
        }

        son_cadenas_iguales(argv[*i], "-h", sonIgualesAux);
        if(*sonIgualesAux){
            *mostrarAyuda = 1;
            *sonIgualesAux = 0;
            continue;
        }
    }

    free(i);
    free(sonIgualesAux);
}

/**
* Muestra una ayuda si el usuario ingreso -h por consola y finaliza exitosamente el programa
*/
void mostrar_ayuda_consola(){
    if(*mostrarAyuda){
        printf("El programa permite realizar una conversi%cn de bases dado un cierto n%cmero. Las bases permitidas son del 2 al 16.\n", 162, 163);
        printf("Comandos disponibles:\n");
        printf(" * -n <numero>: OBLIGATORIO. El n%cmero ingresado es el que se convertir%c en la base deseada.\n", 163, 160);
        printf(" * -s <baseOrigen>: OPCIONAL. Indica la base en la que est%c representado el n%cmero ingresado. Por defecto es 10.\n", 160, 163);
        printf(" * -d <baseDestino>: OPCIONAL. Indica la base en que se pretende convertir el n%cmero ingresado. Por defecto es 10.\n", 163);
        printf(" * -h: OPCIONAL: Muestra un men%c de ayuda. \n", 163);
        printf(" * -v: OPCIONAL. Muestra los c%cmputos realizados en el proceso de conversi%cn.", 162, 162);
        exit(EXIT_SUCCESS);
    }
}

