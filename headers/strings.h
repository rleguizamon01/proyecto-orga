#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

void parte_entera(char* numero, int* longNumero, char* numeroNuevo);

void parte_decimal(char* numero, int* longNumero, char* numeroNuevo);

void convertir_a_minuscula(char* caracter, char* caracterRetorno);

void son_cadenas_iguales(char* cadena1, char* cadena2, int* sonIguales);

int longitud_cadena(char* cadena);

void mostrar_cadena_consola(char* cadena);
#endif // STRING_H_INCLUDED
