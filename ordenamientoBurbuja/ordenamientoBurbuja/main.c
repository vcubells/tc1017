//
//  main.c
//  ordenamientoBurbuja
//
//  Created by Vicente Cubells Nonell on 01/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void imprimeArreglo(int n[]);
void burbuja(int n[]);
int busquedaSecuencial(int n[], int buscar);

int main(int argc, const char * argv[])
{
    int i;
    
    int numeros[N];
    int buscar;
    int encontrado;
    
    srand(time(NULL));
    
    /* Inicializar el arreglo con números aleatorios */
    
    for (i = 0; i < N; ++i) {
        numeros[i] = rand() % 100;
    }
    
    /* Imprimir el arreglo */
    imprimeArreglo(numeros);
    
    /* Buscar un número */
    printf("Entre el número a buscar: ");
    scanf("%d", &buscar );
    
    encontrado = busquedaSecuencial(numeros, buscar);
    
    if (encontrado != -1)
    {
        printf("El número %d se encontró en la posición %d \n", buscar, encontrado);
    }
    else {
        printf("El número %d no se encuentra \n", buscar);
    }
    
    /* Ordenar */
    burbuja(numeros);
    
    /* Imprimir el arreglo */
    imprimeArreglo(numeros);
    
    return 0;
}

void imprimeArreglo(int n[])
{
    int i = 0;
    
    for (i = 0; i < N; ++i) {
        printf("%3d", n[i]);
    }
    
    printf("\n");
}

void burbuja(int n[])
{
    int i, j, temp;
    
    for (i = 0; i < N; ++i) {
        for (j = N - 1; j > i; --j) {
            if (n[j-1] > n[j])
            {
                temp = n[j-1];
                n[j-1] = n[j];
                n[j] = temp;
            }
        }
    }
}

int busquedaSecuencial(int n[], int buscar)
{
    int encontrado = -1;
    
    int i = 0;
    
    while (i < N && encontrado == -1) {
        if (n[i] == buscar) {
            encontrado = i;
        }
        ++i;
    }
    
    return encontrado;
}
