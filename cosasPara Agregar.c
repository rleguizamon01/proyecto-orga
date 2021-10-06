#include <stdio.h>
#include <stdlib.h>
#define precisionEntera 10
#define precisionFraccional 5
#define ERROR_NO_HAY_MEMORIA 1

void imprimir_arreglo_char(char* num,int *tam){

    char * aux;
    aux=(void*) malloc (sizeof(char));
    if (aux==NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    aux=num;

    int * i;
    i=(void*) malloc (sizeof(int));
    if (i==NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    printf("------------- \n");
    for(*i=0;*i<*tam;(*i)++){
        printf("%c ",*aux);
        aux++;
    }
    printf("\n------------- \n");

    free(aux);
    free(i);
}

void imprimir_arreglo_int(int* num,int * tam){

    int * aux;
    aux=(void*) malloc (sizeof(int));
    if (aux==NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    aux=num;

    int * i;
    i=(void*) malloc (sizeof(int));
    if (i==NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    printf("------------- \n");
    for(*i=0;*i<*tam;(*i)++){
        printf("%d ",*aux);
        aux++;
    }
    printf("\n------------- \n");

    free(aux);
    free(i);
}

void char_to_int(char * c,int * num) {


    *num=*c;

    if( (48<=*num) && (*num <=57)) {
        *num -= 48;
    } else if( (65<=*num) && (*num <=70)) {
        *num -= 55;
    } else if( (97<=*num) && (*num <=102)) {
        *num -= 87;
    }

}

void int_to_char(int * num,char * c) {

    *c=*num;

    if(10<=*num)
        *c += 55;
    else
        *c += 48;

}

void arreglo_char_to_int(char* arrViejo,int* arrNuevo,int * tam){
    char * aux;
    aux=(void*) malloc (sizeof(char));
    if (aux==NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    aux=arrViejo;

    int * aux2;
    aux2=(void*) malloc (sizeof(int));
    if (aux2==NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    aux2=arrNuevo;

    int * i;
    i=(void*) malloc (sizeof(int));
    if (i==NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    for(*i=0;*i< *tam;(*i)++){
        char_to_int(aux,aux2);
        aux2++;
        aux++;
    }

    free(aux);
    free(aux2);
    free(i);
}

void arreglo_int_to_char(int* arrViejo,char* arrNuevo,int * tam){
    int * aux;
    aux=(void*) malloc (sizeof(int));
    if (aux==NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    aux=arrViejo;

    char * aux2;
    aux2=(void*) malloc (sizeof(char));
    if (aux2==NULL)
        exit(ERROR_NO_HAY_MEMORIA);
    aux2=arrNuevo;

    int * i;
    i=(void*) malloc (sizeof(int));
    if (i==NULL)
        exit(ERROR_NO_HAY_MEMORIA);

    for(*i=0;*i< *tam;(*i)++){
        int_to_char(aux,aux2);
        aux2++;
        aux++;
    }

    free(aux);
    free(aux2);
    free(i);
}

void base_a_decimal_entero(int* numeroViejo,int baseOrigen, int* numeroNuevo){
    int aux=0;
    int factor=1;

    for(int i=precisionEntera-1;i>=0;i--){
        aux+=numeroViejo[i] * factor;
        factor*=baseOrigen;
    }

    for(int i=precisionEntera-1;i>=0;i--){
        numeroNuevo[i]=aux %10;
        aux/=10;
    }

}

void decimal_a_base_entero(int* numeroViejo,int baseDestino, int* numeroNuevo){

    int aux=0;

    for(int i=0;i<precisionEntera;i++){
        aux=aux*10+numeroViejo[i];
    }

    for(int i=precisionEntera-1;i>=0 ;i--){
        numeroNuevo[i]=aux % baseDestino;
        aux/=baseDestino;
    }
}

void base_a_decimal_fraccional(int* numeroViejo,int *baseOrigen, int* numeroNuevo){


    double au, *aux;
    double fac,* factor;
    int  ii,* i;

    i=&ii;

    aux=&au;
    *aux=0;

    factor=&fac;
    *factor=*baseOrigen;


    for(*i=0;*i<precisionFraccional;(*i)++){
        *aux+= *numeroViejo / *factor;
        *factor*=*baseOrigen;
        numeroViejo++;
    }

        printf("%f \n",*aux);

    for(*i=0;*i<precisionFraccional;(*i)++){
        *aux*=10;
        *numeroNuevo=*aux;
        *aux-=*numeroNuevo;
        numeroNuevo++;
    }

}

void decimal_a_base_fraccional(int* numeroViejo,int baseDestino, int* numeroNuevo){

    double aux=0;


    for(int i=precisionFraccional-1;i>=0 ;i--){
        aux=aux*0.1+numeroViejo[i]*0.1;
    }

    for(int i=0;i<precisionFraccional;i++){
        aux*= baseDestino;
        numeroNuevo[i]=aux;
        aux-=numeroNuevo[i];
    }
}

void conversor_base_a_base(char* numeroViejo, int baseOrigen, int baseDestino, char* numeroConvertido){

    int parteEntera[precisionEntera];
    int parteEnteraNueva[precisionEntera];
    int parteEnteraAux[precisionEntera];


    int parteFraccional[precisionFraccional];
    int parteFraccionalNueva[precisionFraccional];
    int parteFraccionalAux[precisionFraccional];


    if (baseOrigen==10){
        decimal_a_base_entero(parteEntera,baseDestino,parteEnteraNueva);
        decimal_a_base_fraccional(parteFraccional,baseDestino,parteFraccionalNueva);

    }else if(baseDestino==10){

        base_a_decimal_entero(parteEntera,baseDestino,parteEnteraNueva);
        base_a_decimal_fraccional(parteFraccional,baseDestino,parteFraccionalNueva);

    }else {

        base_a_decimal_entero(parteEntera,baseDestino,parteEnteraAux);
        decimal_a_base_entero(parteEnteraAux,baseDestino,parteEnteraNueva);

        base_a_decimal_fraccional(parteFraccional,baseDestino,parteFraccionalAux);
        decimal_a_base_fraccional(parteFraccionalAux,baseDestino,parteFraccionalNueva);
    }

    //parteEnteraNueva
    //parteFraccionalNueva
    //numeroConvertido=

}

int main(void){
	char numeroChar[precisionEntera]= {'0','0','0','0','0','A', '2', 'd', '4', 'F'};
	int numeroInt[precisionEntera]= {0,0,0,0,0,2,1,5,3,6};
    int numeroIntConvertido[precisionEntera];
    char numeroIntImprimible[precisionEntera];

    int bas, *base;
    base=&bas;
    *base=5;

	char fraccionChar[precisionFraccional]= {'A', '2', 'd', '4', 'F'};
	int fraccionInt[precisionFraccional]= {7,1,4,11,15};
    int fraccionIntConvertido[precisionFraccional];
    char fraccionIntImprimible[precisionFraccional];

    arreglo_int_to_char(fraccionInt,fraccionIntImprimible,base);
    imprimir_arreglo_char(fraccionIntImprimible,base);

	system("pause");
	return (0);


}
