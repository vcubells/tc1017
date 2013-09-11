//
//  main.c
//  t9c1e1
//
//  Created by Vicente Cubells Nonell on 08/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
#define CARAS 6

void grafica(int n);

int main(int argc, const char * argv[])
{
    int i;
    int numeros[N];
    int frecuencia[CARAS] = {0};
    
    srand(time(NULL));
    
    /* Inicializar un arreglo de N elementos con números aleatorios */
    for (i = 0; i < N; ++i) {
        numeros[i] = rand() % 6;
    }
    
    /* Contar la cantidad de veces que se genera cada número */
    for (i = 0; i < N; ++i) {
        frecuencia[ numeros[i] ]++;
    }
    
    /* Mostrar el contenido del arreglo */
    for (i = 0; i < CARAS; ++i) {
        printf("%3d %10d ", i+1, frecuencia[i]);
        grafica(frecuencia[i]);
        printf("\n");
    }
    
    return 0;
}

void grafica(int n)
{
    int i;
    n /= 100;
    for (i = 0; i < n; ++i)
        printf("%2c", '-');
    
}
