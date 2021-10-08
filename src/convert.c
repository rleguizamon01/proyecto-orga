#include <stdio.h>
#include <stdlib.h>
#include "../headers/validacion.h"
#include "../headers/strings.h"
#include "../headers/convert.h"
#include "../headers/variables_globales.h"
#include "../headers/conversiones.h"
#include "../headers/consola.h"
#define DEBUG
#define ERROR_NO_HAY_MEMORIA 1

char* numero_parte_entera;
char* numero_parte_fraccionaria;
int* base_origen;
int* base_destino;
int* mostrar_pasos;
int* mostrar_ayuda;

int main(int argc, char* argv[]){
    inicializar_variables(); // variables_globales.c
    leer_consola(&argc, argv); // consola.c
    mostrar_ayuda_consola(); // consola.c
    convertir_letras_a_numeros(); // conversiones.c -> charlar si es necesario
    validar_datos_consola(); // validacion.c
    //convertir_a_base_x();
    printf("numero es %f\nbase_or es %d\nbase_dest es %d\nmostrar_pasos es %d\nmostrar_ayuda es %d", *numero_a_convertir, *base_origen, *base_destino, *mostrar_pasos, *mostrar_ayuda);
    return 0;
}
