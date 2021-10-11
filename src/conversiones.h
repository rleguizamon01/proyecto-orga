#ifndef CONVERSIONES_H_INCLUDED
#define CONVERSIONES_H_INCLUDED

void imprimir_arreglo_char(char* num,int* tam);

void imprimir_arreglo_char_parte_entera(char* num, int* tam);

void imprimir_arreglo_int(int* num, int* tam);

void char_to_int(char* c,int* num);

void int_to_char(int* num,char* c);

void arreglo_char_to_int(char* arrViejo, int* arrNuevo, int* tam);

void arreglo_int_to_char(int* arrViejo, char* arrNuevo, int* tam);

void arr_to_long(int* arrViejo, long long int* numeroLong);

void long_to_arr(long long int* numeroLong, char* arrNuevo);

void base_a_decimal_entero(int* numeroViejo, int* baseOrigen, long long int* numeroNuevo);

void decimal_a_base_entero(long long int* numeroViejo, int* baseDestino, char* numeroNuevo);

void base_a_decimal_fraccional(int* numeroViejo,int* baseOrigen, int* numeroNuevo);

void decimal_a_base_fraccional(int* numeroViejo,int *baseDestino, char* numeroNuevo);

void conversor_base_a_base();



#endif // CONVERSIONES_H_INCLUDED
