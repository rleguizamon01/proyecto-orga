#include <stdio.h>
#include <stdlib.h>
#include "../headers/strings.h"

#define ERROR_NO_HAY_MEMORIA 1

/*
Convierte el parametro numeroNuevo en un arreglo de char desde el comienzo hasta encontrar el caracter "."
parametros:
char* numero (arreglo de caracteres que representan un numero en cierta base)
int* longNumero (longitud del arreglo numero)
char* numeroNuevo (arreglo de caracteres cuyos elementos apuntados son modificados)
*/
void parte_entera(char* numero, int* longNumero, char* numeroNuevo){
    int* i;
    i = (int*) malloc(sizeof(int));
    if(i == NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    *i = 0;

    while(numero[*i] != '.'){
        numeroNuevo[*i] = numero[*i];
        i++;
    }

    free(i);
}

/*
Convierte el parametro numeroNuevo en un arreglo de char despues de la aparicion del caracter "." hasta el final
parametros:
char* numero (arreglo de caracteres que representan un numero en cierta base)
int* longNumero (longitud del arreglo numero)
char* numeroNuevo (arreglo de caracteres cuyos elementos apuntados son modificados)
*/
void parte_decimal(char* numero, int* longNumero, char* numeroNuevo){
    int* i;
    int* indiceAlEncontrarPunto;
    int* encontroPunto;


    i = (int*) malloc(sizeof(int));
    encontroPunto = (int*) malloc(sizeof(int));
    indiceAlEncontrarPunto = (int*) malloc(sizeof(int));

    if(i == NULL || encontroPunto == NULL || indiceAlEncontrarPunto == NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    *i = 0;
    *indiceAlEncontrarPunto = 0;
    *encontroPunto = 0;

    while(numero[*i] != '\0'){
        if(numero[*i] == '.')
            *encontroPunto = 1;
        if(*encontroPunto){
            numeroNuevo[*indiceAlEncontrarPunto] = numero[*i];
            indiceAlEncontrarPunto++;
        }
        i++;
    }

    free(i);
    free(indiceAlEncontrarPunto);
    free(encontroPunto);
}

/*
Convierte al caracter apuntado por caracterRetorno a letra minuscula si es una letra mayuscula
*/
void convertir_a_minuscula(char* caracter, char* caracterRetorno){
    *caracterRetorno = *caracter;
    if(*caracter >= 65 && *caracter <= 90)
        *caracterRetorno += 32;
}

/*
Verifica si dos arrays de caracteres son iguales, sin importar si son mayuscula o minuscula
parametros:
char* cadena1 (arreglo de caracteres a comparar con cadena2)
char* cadena2 (arreglo de caracteres a comparar con cadena1)
return:
1 si las cadenas son iguales
0 si son distintas
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
        exit(ERROR_NO_HAY_MEMORIA);

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
    free(i);
    free(sonIgualesAux);
    free(caracterAux1);
    free(caracterAux2);
}

/*
Devuelve la longitud de la cadena de caracteres pasada por parametro
parametro: char* cadena (cadena de caracteres cuya longitud es analizada)
return: entero cuyo valor es la longitud de la cadena
*/
int longitud_cadena(char* cadena){
    int* i;
    i = (int*) malloc(sizeof(int));
    if(i == NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    *i = 0;

    while(cadena[*i] != '\0')
        i++;

    return *i;
}

/*
Muestra cada caracter del arreglo por consola
*/
void mostrar_cadena_consola(char* cadena){
    int* i;
    i = (int*) malloc(sizeof(int));
    if(i == NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    *i = 0;

    printf("[");
    while(cadena[*i] != '\0')
        printf("%c, ", cadena[*i]);
    printf("]");

    free(i);
}
