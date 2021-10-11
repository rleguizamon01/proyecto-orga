#include <stdio.h>
#include <stdlib.h>
#include "../headers/convert.h"
#include "../headers/consola.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_NO_HAY_MEMORIA 2
#define ERROR_OVERFLOW 3
#define ERROR_ENTRADA_LONGITUD_INVALIDA 4
#define precisionEntera 10
#define precisionFraccional 5

void imprimir_arreglo_char(char* num, int* tam){

    //declaramos las variables
    char* arrAux;
    int* i;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if(i == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    arrAux = num;

    for(*i = 0; *i < *tam; (*i)++){
        printf("%c", *arrAux);
        arrAux++;
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
}

void imprimir_arreglo_char_parte_entera(char* num, int* tam){

    //declaramos las variables
    char* arrAux;
    int* i;
    int* encontroNumDistintoACero = 0;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));
    encontroNumDistintoACero = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if(i == NULL || encontroNumDistintoACero == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    arrAux = num;
    *encontroNumDistintoACero = 0;

    if(*esNegativo)
        printf("-");

    for(*i = 0; *i < *tam; (*i)++){
        if(*arrAux!= '0')
            *encontroNumDistintoACero = 1;
        if(*encontroNumDistintoACero)
            printf("%c", *arrAux);
        arrAux++;
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
    free(encontroNumDistintoACero);
}

void imprimir_arreglo_int(int* num, int* tam){

    //declaramos las variables
    int* arrAux;
    int* i;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if(i == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    arrAux = num;

    for(*i = 0; *i < *tam; (*i)++){
        printf("%d", *arrAux);
        arrAux++;
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
}

void char_to_int(char* c,int* num){

    *num = *c;

    if((48 <= *num) && (*num <= 57)){
        *num -= 48;
    } else if((65 <= *num) && (*num <= 70)){
        *num -= 55;
    } else if((97 <= *num) && (*num <=102)){
        *num -= 87;
    }

}
void int_to_char(int* num,char* c){

    *c = *num;

    if(10 <= *num)
        *c += 55;
    else
        *c += 48;
}
void arreglo_char_to_int(char* arrViejo, int* arrNuevo, int* tam){

    //declaramos las variables
    char* arrAux;
    int* arrAux2;
    int* i;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if (i == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    arrAux = arrViejo;
    arrAux2 = arrNuevo;

    for(*i = 0; *i < *tam; (*i)++){
        char_to_int(arrAux, arrAux2);
        arrAux2++;
        arrAux++;
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
}
void arreglo_int_to_char(int* arrViejo, char* arrNuevo, int* tam){

    //declaramos las variables
    int* arrAux;
    char* arrAux2;
    int* i;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if (i == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    arrAux = arrViejo;
    arrAux2 = arrNuevo;

    for(*i = 0; *i < *tam; (*i)++){
        int_to_char(arrAux, arrAux2);
        arrAux2++;
        arrAux++;
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
}
void arr_to_long(int* arrViejo, long long int* numeroLong){

    //declaramos las variables
    int* i;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if (i == NULL)
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    *numeroLong = 0;

    for(*i = 0; *i < precisionEntera; (*i)++){
        *numeroLong = *numeroLong * 10 + *arrViejo;
        arrViejo++;
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
}

void long_to_arr(long long int* numeroLong, char* arrNuevo){

    //declaramos las variables
    int* i;
    int* numAux;

    //reservamos un espacio en la memoria dinamica
    i = (void*) malloc (sizeof(int));
    numAux = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if ((i == NULL) || (numAux == NULL))
        abortar(ERROR_NO_HAY_MEMORIA);
    //inicializamos
    *numAux = 0;

    arrNuevo += precisionEntera - 1;
    for(*i = precisionEntera - 1; *i >= 0 ; (*i)--){
        *numAux = *numeroLong % 10;
        int_to_char(numAux, arrNuevo);
        *numeroLong /= 10;
        arrNuevo--;
    }
    if (*numeroLong != 0)
        abortar(ERROR_OVERFLOW);

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(i);
    free(numAux);
}

void base_a_decimal_entero(int* numeroViejo, int* baseOrigen, long long int* numeroNuevo){


    //declaramos las variables
    long long int* numAux;
    int* i;
    long long int* factor;

    //reservamos un espacio en la memoria dinamica
    numAux = (void*) malloc (sizeof(long long int));
    i = (void*) malloc (sizeof(int));
    factor = (void*) malloc (sizeof(long long int));

    //verificamos que no nos hayamos quedado sin memoria
    if ((numAux == NULL) || (i == NULL) || (factor == NULL))
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    *numAux = 0;
    *factor = 1;

    numeroViejo += precisionEntera - 1;

    for(*i = precisionEntera - 1; *i >= 0; (*i)--){
        *numAux += (long long int) *numeroViejo * (*factor);
        if (*mostrarPasos){
            if (*numeroViejo != 0){
                if (*i != precisionEntera - 1)
                    printf(" + ");
                printf("%d x %d^%d", *numeroViejo, *baseOrigen,precisionEntera - 1 - *i);
            }
        }
        *factor *= *baseOrigen;
        numeroViejo--;
    }

    if (*mostrarPasos)
        printf(" = %I64d", *numAux);

    *numeroNuevo = *numAux;
    if (*mostrarPasos)
        printf(" en base 10 \n");

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(numAux);
    free(factor);
    free(i);
}
void decimal_a_base_entero(long long int* numeroViejo, int* baseDestino, char* numeroNuevo){

    //declaramos las variables
    int* numAux;
    char* arrAux;
    int* tam;
    int* i;

    //reservamos un espacio en la memoria dinamica
    numAux = (void*) malloc (sizeof( int));
    tam = (void*) malloc (sizeof(int));
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if ((numAux == NULL) || (tam == NULL) || (i == NULL))
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    *numAux = 0;
    arrAux = numeroNuevo;
    *tam = precisionEntera;

    arrAux += precisionEntera - 1;
    for(*i = precisionEntera - 1; *i >= 0; (*i)--){
        *numAux = *numeroViejo % *baseDestino;
        if (*mostrarPasos && (*numeroViejo != 0))
            printf("%I64d mod %d = %d y (%I64d-%d)/%d = ", *numeroViejo, *baseDestino, *numAux, *numeroViejo, *numAux, *baseDestino);
        int_to_char(numAux, arrAux);
        *numeroViejo /= *baseDestino;
        if (*mostrarPasos && (*numeroViejo != 0))
            printf("%I64d\n", *numeroViejo);
        arrAux--;
    }
    if (*numeroViejo != 0)
        abortar(ERROR_OVERFLOW);

    if (*mostrarPasos)
        printf("0\n");
    if (*mostrarPasos){
            printf("Por lo que la parte entera del numero es ");
            imprimir_arreglo_char(numeroNuevo, tam);
            printf(", en base %d \n", *baseDestino);
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(numAux);
    free(tam);
    free(i);
}
void base_a_decimal_fraccional(int* numeroViejo,int* baseOrigen, int* numeroNuevo){

    //declaramos las variables
    double* numAux;
    double* factor;
    int* arrAux;
    int* i;

    //reservamos un espacio en la memoria dinamica
    numAux = (void*) malloc (sizeof(double));
    factor = (void*) malloc (sizeof(double));
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if ((numAux == NULL) || (i == NULL) || (factor == NULL))
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    *numAux = 0;
    *factor = *baseOrigen;
    arrAux = numeroNuevo;



    if (*mostrarPasos)
        printf("((((((((((");
    for(*i = 0; *i < precisionFraccional; (*i)++){
        *numAux += *numeroViejo / (*factor);
        *factor *= *baseOrigen;
        if (*mostrarPasos)
            printf("+%d)/%d)", *numeroViejo, *baseOrigen);
        numeroViejo++;
    }
    if (*mostrarPasos)
        printf(" = 0.");
    for(*i = 0; *i < precisionFraccional; (*i)++){
        *numAux *= 10;
        *arrAux = *numAux;
        *numAux -= *arrAux;
        if (*mostrarPasos)
            printf("%d",*arrAux);
        arrAux++;
    }
    if (*mostrarPasos)
        printf(" en base 10 con precision %d\n", precisionFraccional);

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(numAux);
    free(factor);
    free(i);
}
void decimal_a_base_fraccional(int* numeroViejo, int* baseDestino, char* numeroNuevo){

    //declaramos las variables
    double* numAux;
    int* numAux2;
    char* arrAux;
    int* tam;
    int* i;

    //reservamos un espacio en la memoria dinamica
    numAux = (void*) malloc (sizeof(double));
    numAux2 = (void*) malloc (sizeof(int));
    tam = (void*) malloc (sizeof(int));
    i = (void*) malloc (sizeof(int));

    //verificamos que no nos hayamos quedado sin memoria
    if ((numAux == NULL) || (numAux2 == NULL) || (i == NULL) || (tam == NULL))
        abortar(ERROR_NO_HAY_MEMORIA);

    //inicializamos
    *numAux = 0;
    *numAux2 = 0;
    arrAux = numeroNuevo;
    *tam = precisionFraccional;

    numeroViejo += precisionFraccional - 1;
    for(*i = precisionFraccional - 1; *i >= 0; (*i)--){
        *numAux = *numAux * 0.1 + *numeroViejo * 0.1;
        numeroViejo--;
    }

    for(*i = 0; *i < precisionFraccional; (*i)++){
        if (*mostrarPasos)
            printf("%.5f x %d", *numAux, *baseDestino);
        *numAux *= *baseDestino;
        *numAux2 = *numAux;
        int_to_char(numAux2, arrAux);
        if (*mostrarPasos)
            printf("= %.5f, por lo que  X^(-%d)=%c\n", *numAux, *i + 1, *arrAux);
        *numAux -= *numAux2;
        arrAux++;
    }
    if (*mostrarPasos){
            printf("Por lo que la parte fraccional del numero es 0.");
            imprimir_arreglo_char(numeroNuevo, tam);
            printf(", en base %d con precision %d \n", *baseDestino, precisionFraccional);
    }

    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(numAux);
    free(numAux2);
    free(i);
    free(tam);
}

void conversor_base_a_base(){

    // Declaramos las variables
    int* parteEnteraTrabajable;
    char* parteEnteraFinal;
    long long int* numeroLong;
    int* parteFraccionalTrabajable;
    int* parteFraccionalIntermedia;
    char* parteFraccionalFinal;
    int* tamEntero;
    int* tamFraccion;

    // Reservamos espacio en la memoria dinamica
    parteEnteraTrabajable = (void*) malloc (sizeof(int)* precisionEntera);
    parteEnteraFinal = (void*) malloc (sizeof(char) * precisionEntera + 1);
    numeroLong = (void*) malloc (sizeof(long long int));
    parteFraccionalTrabajable = (void*) malloc (sizeof(int) * precisionFraccional);
    parteFraccionalIntermedia = (void*) malloc (sizeof(int) * precisionFraccional);
    parteFraccionalFinal = (void*) malloc (sizeof(char) * precisionFraccional);
    tamEntero = (void*) malloc (sizeof(int));
    tamFraccion = (void*) malloc (sizeof(int));

    // Verificamos que no nos hayamos quedado sin memoria
    if ((parteEnteraTrabajable == NULL) || (parteEnteraFinal == NULL) || (numeroLong == NULL) || (parteFraccionalTrabajable == NULL) || (parteFraccionalIntermedia == NULL) || (parteFraccionalFinal == NULL) || (tamEntero == NULL)||(tamFraccion==NULL))
        abortar(ERROR_NO_HAY_MEMORIA);

    // Inicializamos las variables
    *tamEntero = precisionEntera;
    *tamFraccion = precisionFraccional;

    arreglo_char_to_int(numeroParteEnteraChar, parteEnteraTrabajable, tamEntero);
    arreglo_char_to_int(numeroParteFraccionariaChar, parteFraccionalTrabajable, tamFraccion);

    if (*baseOrigen == *baseDestino){
        printf("El numero ingresado ya se encuentra en la base solicitada");
    } else{ if (*baseOrigen == 10){
        arr_to_long(parteEnteraTrabajable, numeroLong);
        if(*mostrarPasos)
            printf("Convierto la parte entera de base %d a base %d:\n\n", *baseOrigen, *baseDestino);
        decimal_a_base_entero(numeroLong, baseDestino, parteEnteraFinal);

        if(*mostrarPasos)
            printf("\nConvierto la parte fraccional de base %d a base %d:\n\n", *baseOrigen, *baseDestino);
        decimal_a_base_fraccional(parteFraccionalTrabajable, baseDestino, parteFraccionalFinal);

    } else if(*baseDestino == 10){
        if(*mostrarPasos)
            printf("Convierto la parte entera de base %d a base %d:\n\n", *baseOrigen, *baseDestino);
        base_a_decimal_entero(parteEnteraTrabajable, baseOrigen, numeroLong);
        long_to_arr(numeroLong, parteEnteraFinal);
        if(*mostrarPasos)
            printf("\nConvierto la parte fraccional de base %d a base %d:\n\n", *baseOrigen, *baseDestino);
        base_a_decimal_fraccional(parteFraccionalTrabajable, baseDestino, parteFraccionalIntermedia);
        arreglo_int_to_char(parteFraccionalIntermedia, parteFraccionalFinal, tamFraccion);
    } else {
        if(*mostrarPasos)
            printf("Para la parte entera: \nPrimero la convierto de base %d a base 10:\n\n", *baseOrigen);
        base_a_decimal_entero(parteEnteraTrabajable, baseOrigen, numeroLong);
        if(*mostrarPasos)
            printf("\nLuego la convierto de base 10 a base %d:\n\n", *baseDestino);
        decimal_a_base_entero(numeroLong, baseDestino, parteEnteraFinal);

        if(*mostrarPasos)
            printf("\nPara la parte fraccional: \nPrimero la convierto de base %d a base 10:\n\n", *baseOrigen);
        base_a_decimal_fraccional(parteFraccionalTrabajable, baseDestino, parteFraccionalIntermedia);
        if(*mostrarPasos)
            printf("\nLuego la convierto de base 10 a base %d:\n\n", *baseDestino);
        decimal_a_base_fraccional(parteFraccionalIntermedia, baseDestino, parteFraccionalFinal);
    }
    printf("\nFinalmente, el resultado es ");
    imprimir_arreglo_char_parte_entera(parteEnteraFinal, tamEntero);
    printf(".");
    imprimir_arreglo_char(parteFraccionalFinal, tamFraccion);
    printf(" en base %d, con precision %d", *baseDestino, precisionFraccional);
    }
    //liberamos el espacio que habiamos reservado en la memoria dinamica
    free(parteEnteraTrabajable);
    free(parteEnteraFinal);
    free(numeroLong);
    free(parteFraccionalTrabajable);
    free(parteFraccionalIntermedia);
    free(parteFraccionalFinal);
    free(tamEntero);
    free(tamFraccion);


}

