#include <stdio.h>
#include <stdlib.h>
#include "../headers/variables_globales.h"
#include "../headers/convert.h"

#define ERROR_NO_HAY_MEMORIA 1
#define precisionEntera 10
#define precisionFraccional 5

/**
* Asigna variables a la memoria dinamica y las inicializa con valores por defecto
*/
void inicializar_variables(){
    esNegativo = (int*) malloc(sizeof(int));
    numeroParteEnteraChar = (char*) malloc (sizeof(char) * precisionEntera + 1);
    numeroParteFraccionariaChar = (char*) malloc (sizeof(char) * precisionFraccional + 1);
    baseOrigen = (int*) malloc(sizeof(int));
    baseDestino = (int*) malloc(sizeof(int));
    mostrarPasos = (int*) malloc(sizeof(int));
    mostrarAyuda = (int*) malloc(sizeof(int));

    if(numeroParteEnteraChar == NULL || numeroParteFraccionariaChar == NULL || baseOrigen == NULL || baseDestino == NULL || mostrarPasos == NULL || mostrarAyuda == NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    *esNegativo = 0;
    *baseOrigen = 10;
    *baseDestino = 10;
    *mostrarPasos = 0;
    *mostrarAyuda = 0;
}
/**
* Desasigna variables de la memoria dinamica
*/
void liberar_variables(){
    free(esNegativo);
    free(numeroParteEnteraChar);
    free(numeroParteFraccionariaChar);
    free(baseOrigen);
    free(baseDestino);
    free(mostrarPasos);
    free(mostrarAyuda);
}
