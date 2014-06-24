//
//  main.c
//  t9c2e4
//
//  Created by Vicente Cubells Nonell on 24/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 21

void imprimirArreglo(int a[N]);
void imprimirArregloChar(char a[N]);

void ordenaBurbuja(int a[N]);
void ordenaBurbujaChar(char a[N]);

int main(int argc, const char * argv[])
{
    // Definir las variables
    int numeros[N];
    
    srand((int) time(NULL));
    
    // Inicializar el arreglo con números aleatorios
    for (int i = 0; i < N; ++i) {
        numeros[i] = rand() % 25;
    }
    
    // Mostrar el arreglo
    imprimirArreglo(numeros);
    
    // Ordenar números
    ordenaBurbuja(numeros);
    
    imprimirArreglo(numeros);
    
    // Obtener la mediana del arreglo
    int pos = N/2;
    int mediana = numeros[pos];
    
    printf("La mediana es %4d que se encuentra en la posición %4d\n", mediana, pos);
    
    
    
    // Ordenar caracteres
    char cadena[N] = "programar es facil";
    
    unsigned long longitud = strlen(cadena);
    
    printf("La longitud es %ld\n", longitud);

    imprimirArregloChar(cadena);
    
    ordenaBurbujaChar(cadena);
    
    imprimirArregloChar(cadena);
    
    
    
    return 0;
}

void imprimirArreglo(int a[N])
{
    for (int i = 0; i < N; ++i) {
        printf("%4d", a[i]);
    }
    
    printf("\n");
}

void imprimirArregloChar(char a[N])
{
    for (int i = 0; i < N; ++i) {
        printf("%4c", a[i]);
    }
    
    printf("\n");
}

void ordenaBurbuja(int a[N])
{
    int aux;
    
    for (int i = 0; i < N; ++i) {
        for (int j = N-1; j > i; --j) {
            if (a[j-1] > a[j]) {
                aux = a[j-1];
                a[j-1] = a[j];
                a[j] = aux;
            }
        }
    }
}

void ordenaBurbujaChar(char a[N])
{
    char aux;
    
    for (int i = 0; i < N; ++i) {
        for (int j = N-1; j > i; --j) {
            if (a[j-1] > a[j]) {
                aux = a[j-1];
                a[j-1] = a[j];
                a[j] = aux;
            }
        }
    }
}