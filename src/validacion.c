#include <stdio.h>
#include <stdlib.h>
#include "../headers/validacion.h"
#include "../headers/convert.h"
#include "../headers/consola.h"
#include "../headers/strings.h"

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
* Valida los datos ingresados por consola. Si son invalidos, finaliza erroneamente el programa.
*/
void validar_datos_consola(){
    int* i = (int*) malloc(sizeof(int));
    int* longitudCadenaNumero = (int*) malloc(sizeof(int));

    if(i == NULL || longitudCadenaNumero == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    // Valida que las bases se encuentren en el rango [2, 16]
    if(2 > *baseOrigen || *baseOrigen > 16 || 2 > *baseDestino || *baseDestino > 16){
        abortar(ERROR_ENTRADA_BASES_INVALIDAS);
    }

    // Valida que los caracteres del numero sean validos (0-9, a-f, A-F) y pertenezcan a la base de origen

    // Comienza validando la parte entera
    longitud_cadena(numeroParteEnteraChar, longitudCadenaNumero); // funcion de strings.c

    for(*i = 0; *i < *longitudCadenaNumero; (*i)++){
        if((48 <= numeroParteEnteraChar[*i] && numeroParteEnteraChar[*i] <= 57) ||(65 <= numeroParteEnteraChar[*i] && numeroParteEnteraChar[*i] <= 70) ||
           (97 <= numeroParteEnteraChar[*i] && numeroParteEnteraChar[*i] <= 102)){
            validar_pertenece_a_base_origen(&numeroParteEnteraChar[*i]);
        } else {
            abortar(ERROR_ENTRADA_CARACTER_INVALIDO);
        }
    }

    // Valida la parte fraccionaria
    longitud_cadena(numeroParteFraccionariaChar, longitudCadenaNumero); // funcion de strings.c

    for(*i = 0; *i < *longitudCadenaNumero; (*i)++){
        if((48 <= numeroParteFraccionariaChar[*i] && numeroParteFraccionariaChar[*i] <= 57) || (65 <= numeroParteFraccionariaChar[*i] && numeroParteFraccionariaChar[*i] <= 70) ||
           (97 <= numeroParteFraccionariaChar[*i] && numeroParteFraccionariaChar[*i] <= 102)){
            validar_pertenece_a_base_origen(&numeroParteFraccionariaChar[*i]);
        } else {
            abortar(ERROR_ENTRADA_CARACTER_INVALIDO);
        }
    }

    free(i);
    free(longitudCadenaNumero);
}
/**
* Valida que el valor del caracter ingresado por parametro pertenezca a la base de origen ingresada por consola
* @param caracter puntero de un caracter
*/
void validar_pertenece_a_base_origen(char* caracter){
    if(48 <= *caracter && *caracter <= 57){
        if(*caracter - '0' >= *baseOrigen){
            abortar(ERROR_ENTRADA_DIGITO_BASE_ORIGEN);
        }
    } else if(65 <= *caracter && *caracter <= 70){
        if(*caracter - 54 > *baseOrigen){
            abortar(ERROR_ENTRADA_DIGITO_BASE_ORIGEN);
        }
    } else if (97 <= *caracter && *caracter <= 102) {
        if(*caracter - 86 > *baseOrigen){
            abortar(ERROR_ENTRADA_DIGITO_BASE_ORIGEN);
        }
    }
}
