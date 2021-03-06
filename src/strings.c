#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "convert.h"
#include "validacion.h"
#include "consola.h"

#define ERROR_NO_HAY_MEMORIA 1
#define precisionEntera 10
#define precisionFraccional 5

/**
* Convierte el parametro numeroNuevo en un arreglo de char desde el comienzo hasta encontrar el caracter "."
* @param numero arreglo de caracteres que representan un numero en cierta base
* @param longNumero longitud del arreglo numero
* @param numeroNuevo arreglo de caracteres cuyos elementos apuntados son modificados
*/
void parte_entera(char* numero, int* longNumero, char* numeroNuevo){
    int* i;
    int* j;

    i = (int*) malloc(sizeof(int));
    j = (int*) malloc(sizeof(int));

    if(i == NULL || j == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    // Si el primer digito es un menos, le da valor 1 a esNegativo y comienza a recorrer el numero por el indice 1 (para esquivar el menos)
    if(numero[0] == '-'){
        *esNegativo = 1;
        *i = 1;
    } else
        *i = 0;

    *j = 0;

    // Copia el numero ingresado por consola a otra variable desde el comienzo hasta encontrar un punto
    while((*j < *longNumero) && (numero[*i] != '.')){
        numeroNuevo[*j] = numero[*i];
        (*i)++;
        (*j)++;
    }

    // Si no ingreso parte entera, la completa con un cero
    if(*j == 0){
        numeroNuevo[*j] = '0';
        (*j)++;
    }


    numeroNuevo[*j] = '\0';

    free(i);
    free(j);
}

/**
* Convierte el parametro numeroNuevo en un arreglo de char despues de la aparicion del caracter "." hasta el final
* @param numero arreglo de caracteres que representan un numero en cierta base
* @param longNumero longitud del arreglo numero
* @param numeroNuevo arreglo de caracteres cuyos elementos apuntados son modificados
*/
void parte_decimal(char* numero, int* longNumero, char* numeroNuevo){

    int* i;
    int* indiceAlEncontrarPunto;
    int* encontroPunto;
    int* longitudParteFraccionaria;

    i = (int*) malloc(sizeof(int));
    encontroPunto = (int*) malloc(sizeof(int));
    indiceAlEncontrarPunto = (int*) malloc(sizeof(int));
    longitudParteFraccionaria = (int*) malloc(sizeof(int));

    if(i == NULL || encontroPunto == NULL || indiceAlEncontrarPunto == NULL || longitudParteFraccionaria == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    *i = 0;
    *indiceAlEncontrarPunto = 0;
    *encontroPunto = 0;


    while(numero[*i] != '\0'){
        if(*encontroPunto){
            numeroNuevo[*indiceAlEncontrarPunto] = numero[*i];
            (*indiceAlEncontrarPunto)++;
        }
        if(numero[*i] == '.')
            *encontroPunto = 1;
        (*i)++;
    }

    // Si no encontro un punto, completa la parte decimal con un cero
    if(*indiceAlEncontrarPunto == 0){
        numeroNuevo[0] = '0';
        (*indiceAlEncontrarPunto)++;
    }

    numeroNuevo[*indiceAlEncontrarPunto] = '\0';

    free(i);
    free(indiceAlEncontrarPunto);
    free(encontroPunto);
    free(longitudParteFraccionaria);
}

/**
* Rellena el comienzo de la cadena de la parte entera del numero con ceros para poder facilitar los calculos en las conversiones
*/
void rellenar_parte_entera_con_ceros(){
    int* i;
    int* longitudParteEntera;
    char* cadenaAux;

    i = (int*) malloc(sizeof(int));
    longitudParteEntera = (int*) malloc(sizeof(int));
    cadenaAux = (char*) malloc(sizeof(char) * precisionEntera + 1);

    if(i == NULL || cadenaAux == NULL || longitudParteEntera == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    // Copia el numero pasado por consola a una variable auxiliar
    longitud_cadena(numeroParteEnteraChar, longitudParteEntera);

    for(*i = 0; *i < *longitudParteEntera; (*i)++){
        cadenaAux[*i] = numeroParteEnteraChar[*i];
    }

    // Si el numero pasado por consola es menor a la precision entera (por defecto 10), completa el comienzo con ceros
    for(*i = 0; *i < precisionEntera; (*i)++){
        if(*i < precisionEntera - *longitudParteEntera)
            numeroParteEnteraChar[*i] = '0';
        else
            numeroParteEnteraChar[*i] = cadenaAux[*i - precisionEntera + *longitudParteEntera];
    }

    // Completa el ultimo elemento de la cadena con \0
    numeroParteEnteraChar[precisionEntera] = '\0';

    free(cadenaAux);
    free(i);
    free(longitudParteEntera);
}

/**
* Rellena el final de la parte decimal con ceros para poder facilitar la conversion de bases
*/

void rellenar_parte_fraccionaria_con_ceros(){
    int* i;
    int* longitudParteFraccionaria;
    char* cadenaAux;

    i = (int*) malloc(sizeof(int));
    longitudParteFraccionaria = (int*) malloc(sizeof(int));
    cadenaAux = (char*) malloc(sizeof(char) * precisionFraccional + 1);

    if(i == NULL || cadenaAux == NULL || longitudParteFraccionaria == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    longitud_cadena(numeroParteFraccionariaChar, longitudParteFraccionaria);

    for(*i = 0; *i < *longitudParteFraccionaria; (*i)++){
        cadenaAux[*i] = numeroParteFraccionariaChar[*i];
    }

    for(*i = precisionFraccional; *i > 0; (*i)--){
        if(*i >= *longitudParteFraccionaria)
            numeroParteFraccionariaChar[*i] = '0';
        else
            numeroParteFraccionariaChar[*i] = cadenaAux[*i];
    }
    numeroParteFraccionariaChar[precisionFraccional] = '\0';

    free(cadenaAux);
    free(i);
    free(longitudParteFraccionaria);
}

/**
* Convierte al caracter apuntado por caracterRetorno a letra minuscula si es una letra mayuscula
* @param caracter puntero de caracter de una cadena
* @param caracterRetorno puntero de caracter cuyo valor es modificado
*/
void convertir_a_minuscula(char* caracter, char* caracterRetorno){
    *caracterRetorno = *caracter;
    if(*caracter >= 65 && *caracter <= 90)
        *caracterRetorno += 32;
}

/**
* Verifica si dos arrays de caracteres son iguales, sin importar si son mayuscula o minuscula
* @param cadena1 arreglo de caracteres a comparar con cadena2
* @param cadena2 arreglo de caracteres a comparar con cadena1
* @param sonIguales punto de entero cuyo valor es 1 si las cadenas son iguales y 0 si no lo son
*/
void son_cadenas_iguales(char* cadena1, char* cadena2, int* sonIguales){

    int* i;
    int* sonIgualesAux;
    char* caracterAux1;
    char* caracterAux2;

    i = (int*) malloc(sizeof(int));
    sonIgualesAux = (int*) malloc(sizeof(int));
    caracterAux1 = (char*) malloc(sizeof(char));
    caracterAux2 = (char*) malloc(sizeof(char));

    if(i == NULL || sonIgualesAux == NULL || caracterAux1 == NULL || caracterAux2 == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    *i = 0;
    *sonIgualesAux = 1;

    //size_t n = sizeof(a)/sizeof(a[0]);

    while(cadena1[*i] != '\0' && *sonIgualesAux){
        // Convierte a los caracteres auxiliares en minusculas para que pueda comparar indistintamente de la grafia
        convertir_a_minuscula(&cadena1[*i], caracterAux1);
        convertir_a_minuscula(&cadena2[*i], caracterAux2);
        // Si los caracteres son distintos, termina el bucle y devuelve 0 (que representa el falso)
        if(*caracterAux1 != *caracterAux2)
            *sonIgualesAux = 0;
        *i += 1;
    }

    *sonIguales = *sonIgualesAux;
    #ifdef DEBUG
        printf("## soniguales(): %s y %s son iguales: %d\n", cadena1, cadena2, *sonIguales);
    #endif
    free(i);
    free(sonIgualesAux);
    free(caracterAux1);
    free(caracterAux2);
}

/**
* Modifica el valor apuntado por 'longitud' tal que su valor sea la longitud de la cadena de caracteres pasada por parametro
* @param cadena cadena de caracteres cuya longitud es analizada
* @param longitud puntero de entero cuyo valor es modificado a la longitud de la cadena
*/
void longitud_cadena(char* cadena, int* longitud){
    *longitud = 0;

    while(cadena[*longitud] != '\0')
        (*longitud)++;
}
