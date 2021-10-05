#include <stdio.h>
#define precisionEntera 10
#define precisionFraccional 5

void imprimir_arreglo_char(char* num,int tam){
    printf("------------- \n",tam);
    for(int i=0;i<tam;i++){
        printf("%c ",num[i]);
    }
    printf("\n------------- \n",tam);
}

void imprimir_arreglo_int(int* num,int tam){
    printf("------------- \n",tam);
    for(int i=0;i<tam;i++){
        printf("%d ",num[i]);
    }
    printf("\n------------- \n",tam);
}

int char_to_int(char c) {
    int num = c;

    if( (48<=num) && (num <=57)) {
        num -= 48;
    } else if( (65<=num) && (num <=70)) {
        num -= 55;
    } else if( (97<=num) && (num <=102)) {
        num -= 87;
    }

    return num;
}

char int_to_char(int num) {
    char c = num;
    if(10<=num)
        c += 55;
    else
        c += 48;
    return c;
}


void arreglo_char_to_int(char* arrViejo,int* arrNuevo,int tam){
    for(int i=0;i<tam;i++){
        arrNuevo[i]=char_to_int(arrViejo[i]);
    }
}

void arreglo_int_to_char(int* arrViejo,char* arrNuevo,int tam){
    for(int i=0;i<tam;i++){
        arrNuevo[i]=int_to_char(arrViejo[i]);
    }
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

void base_a_decimal_fraccional(int* numeroViejo,int baseOrigen, int* numeroNuevo){

    double aux;
    aux=0;
    double factor=baseOrigen;

    for(int i=0;i<precisionFraccional;i++){
        aux+=numeroViejo[i] / factor;
        factor*=baseOrigen;
    }

    for(int i=0;i<precisionFraccional;i++){
        numeroNuevo[i]=aux;
        aux-=numeroNuevo[i];
        aux*=10;
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
   // parteFraccionalNueva
    //numeroConvertido=

}

int main(void){
	char numeroChar[precisionEntera]= {'0','0','0','0','0','A', '2', 'd', '4', 'F'};
	int numeroInt[precisionEntera]= {0,0,0,0,0,2,1,5,3,6};
    int numeroIntConvertido[precisionEntera];

	char fraccionChar[precisionFraccional]= {'A', '2', 'd', '4', 'F'};
	int fraccionInt[precisionFraccional]= {7,6,3,2,0};
    int fraccionIntConvertido[precisionFraccional];


    //imprimir_arreglo_char(numeroChar,precisionEntera);
    //arreglo_char_to_int(numeroChar,numeroInt,precisionEntera);
    //base_a_decimal_entero(numeroInt,16,numeroIntConvertido);

    //decimal_a_base_entero(numeroInt,8,numeroIntConvertido);
    //imprimir_arreglo_int(numeroIntConvertido,precisionEntera);

    base_a_decimal_fraccional(fraccionInt,8,fraccionIntConvertido);
    imprimir_arreglo_int(fraccionIntConvertido,precisionFraccional);


	system("pause");
	return (0);


}
