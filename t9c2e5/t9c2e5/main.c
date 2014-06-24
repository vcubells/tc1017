//
//  main.c
//  t9c2e5
//
//  Created by Vicente Cubells Nonell on 24/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 15

void imprimirArreglo(int a[N]);

void imprimirCadena(char a[N], int longitud);

int longitudCadena(char cadena[N]);

int main(int argc, const char * argv[])
{
    int numeros[N];
    
    srand((int) time(NULL));
    
    for (int i = 0; i < N; ++i) {
        numeros[i] = rand() % 100;
    }
    
    imprimirArreglo(numeros);
    
    int aux;
    
    // Invertir los números
    for (int i = 0, j = N-1; i < j; ++i, --j) {
        aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;
    }
    
    imprimirArreglo(numeros);
    
    // Invertir una cadena
    char cadena[N];
    
    printf("Entre una cadena sin espacios: ");
    scanf("%s", cadena);
    
    int longitud = strlen(cadena);
    
    imprimirCadena(cadena, longitud);
    
    char auxchar;
    
    // Invertir los números
    for (int i = 0, j = longitud-1; i < j; ++i, --j) {
        auxchar = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = auxchar;
    }

    imprimirCadena(cadena, longitud);
    
    printf("La longitud de la cadena es %d caracteres \n", longitudCadena(cadena));
    
    return 0;
}

void imprimirArreglo(int a[N])
{
    for (int i = 0; i < N; ++i) {
        printf("%4d", a[i]);
    }
    
    printf("\n");
}

void imprimirCadena(char a[N], int longitud)
{
    for (int i = 0; i < longitud; ++i) {
        printf("%4c", a[i]);
    }
    
    printf("\n");
}

int longitudCadena(char cadena[N])
{
    int contador = 0;
    int indice = 0;
    
    while (cadena[indice] != '\0') {
        ++contador;
        ++indice;
    }
    
    return contador;
}


