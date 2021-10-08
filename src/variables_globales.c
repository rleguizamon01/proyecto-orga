#include <stdio.h>
#include <stdlib.h>
#include "../headers/variables_globales.h"
#include "../headers/convert.h"
#define ERROR_NO_HAY_MEMORIA 1

void inicializar_variables(){
    numero_a_convertir = (double*) malloc(sizeof(double));
    base_origen = (int*) malloc(sizeof(int));
    base_destino = (int*) malloc(sizeof(int));
    mostrar_pasos = (int*) malloc(sizeof(int));
    mostrar_ayuda = (int*) malloc(sizeof(int));

    if(numero_a_convertir == NULL || base_origen == NULL || base_destino == NULL || mostrar_pasos == NULL || mostrar_ayuda == NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    *numero_a_convertir = 0;
    *base_origen = 10;
    *base_destino = 10;
    *mostrar_pasos = 0;
    *mostrar_ayuda = 0;
}
