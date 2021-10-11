#include <stdio.h>
#include <stdlib.h>
#include "../headers/validacion.h"
#include "../headers/strings.h"
#include "../headers/convert.h"
#include "../headers/variables_globales.h"
#include "../headers/conversiones.h"
#include "../headers/consola.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_NO_HAY_MEMORIA 2
#define ERROR_OVERFLOW 3
#define ERROR_ENTRADA_LONGITUD_INVALIDA 4
#define ERROR_ENTRADA_CARACTER_INVALIDO 6
#define ERROR_ENTRADA_DIGITO_BASE_ORIGEN 7
#define ERROR_ENTRADA_BASES_INVALIDAS 8
#define precisionEntera 10
#define precisionFraccional 5

int* esNegativo; // 1 es negativo 0 es positivo
char* numeroParteEnteraChar;
char* numeroParteFraccionariaChar;
int* baseOrigen;
int* baseDestino;
int* mostrarPasos;
int* mostrarAyuda;

/**
* Funcion principal que inicia el programa
* @param argc numero de caracteres ingresados por consola
* @param argv array de punteros a caracteres
*/
int main(int argc, char* argv[]){
    inicializar_variables(); // asigna las variables en memoria dinamica (variables_globales.c)
    leer_consola(&argc, argv); // lee los valores ingresados por consola y los asigna a las variables (consola.c)
    mostrar_ayuda_consola(); // si el usuario ingreso -h por consola, muestra una ayuda y finaliza el programa (consola.c)
    validar_datos_consola(); // valida los valores ingresados por consola (validacion.c)
    rellenar_parte_entera_con_ceros(); // completa el comienzo de la parte entera con ceros para facilitar el calculo de conversiones (string.c)
    conversor_base_a_base(); // convierte el numero en la base destino (conversiones.c)
    printf("\nEs negativo (1 negativo 0 positivo): %d\n", *esNegativo);
    liberar_variables(); // libera las variables de la memoria dinamica (variables_globales.c)
    return 0;
}
