#include <stdio.h>
#include <stdlib.h>
#include "../headers/validacion.h"
#include "../headers/convert.h"
#include "../headers/strings.h"
#define ERROR_NO_HAY_MEMORIA 1
#define SUCCESS_AYUDA 3

void leer_consola(int* argc, char* argv[])
{
    int* i;
    int* sonIgualesAux;
    i = (int*) malloc(sizeof(int));
    sonIgualesAux = (int*) malloc(sizeof(int));
    if(i == NULL || sonIgualesAux == NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    for(*i = 0; *i < *argc; *i += 1){
        #ifdef DEBUG
        printf("REPETICION NUM %d y el elem es %s\n", *i, argv[*i]);
        #endif

        son_cadenas_iguales(argv[*i], "-n", sonIgualesAux);
        if(*sonIgualesAux){
            #ifdef DEBUG
             printf("detecto -n %s\n", argv[*i]);
            #endif
            *numero_a_convertir = atof(argv[(*i) + 1]);
        }
        son_cadenas_iguales(argv[*i], "-s", sonIgualesAux);
        if(*sonIgualesAux){
            #ifdef DEBUG
             printf("detecto -s %s\n", argv[*i]);
            #endif
            *base_origen = atoi(argv[*i + 1]);
        }
        son_cadenas_iguales(argv[*i], "-d", sonIgualesAux);
        if(*sonIgualesAux){
            *base_destino = atoi(argv[*i + 1]);
        }
        son_cadenas_iguales(argv[*i], "-v", sonIgualesAux);
        if(*sonIgualesAux){
            *mostrar_pasos = 1;
        }
        son_cadenas_iguales(argv[*i], "-h", sonIgualesAux);
        if(*sonIgualesAux){
            *mostrar_ayuda = 1;
        }
    }

    free(i);
    free(sonIgualesAux);
}

void mostrar_ayuda_consola(){
    if(*mostrar_ayuda){
        printf("El programa permite realizar una conversi%cn de bases dado un cierto n%cmero. Las bases permitidas son del 2 al 16.\n", 162, 163);
        printf("Comandos disponibles:\n");
        printf(" * -n <numero>: OBLIGATORIO. El n%cmero ingresado es el que se convertir%c en la base deseada.\n", 163, 160);
        printf(" * -s <base_origen>: OPCIONAL. Indica la base en la que est%c representado el n%cmero ingresado. Por defecto es 10.\n", 160, 163);
        printf(" * -d <base_destino>: OPCIONAL. Indica la base en que se pretende convertir el n%cmero ingresado. Por defecto es 10.\n", 163);
        printf(" * -h: OPCIONAL: Muestra un men%c de ayuda. \n", 163);
        printf(" * -v: OPCIONAL. Muestra los c%cmputos realizados en el proceso de conversi%cn.", 162, 162);
        exit(SUCCESS_AYUDA);
    }
}
