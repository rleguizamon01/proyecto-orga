#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG

void leer_consola(int* argc, char* argv[]);

int numero = 0;
int base_origen = 10;
int base_destino = 10;

int main(int argc, char* argv[])
{
    leer_consola(&argc, argv);
    printf("numero es %d\n base_or es %d\n base_dest es %d\n", numero, base_origen, base_destino);
    return 0;
}

void leer_consola(int* argc, char* argv[])
{
    int i;
    for(i = 0; i < *argc; i++){
        #ifdef DEBUG
         printf("REPETICION NUM %d y el elem es %s\n", i, argv[i]);
        #endif

        if(!strcasecmp(argv[i], "-n")){
            #ifdef DEBUG
             printf("detecto -n %s\n", argv[i]);
            #endif
            numero = atoi(argv[i + 1]);
        }
        else if(!strcasecmp(argv[i], "-s")){
            base_origen = atoi(argv[i + 1]);
        }
        else if(!strcasecmp(argv[i], "-d")){
            base_destino = atoi(argv[i + 1]);
        }
    }
}
