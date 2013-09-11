//
//  main.c
//  t9c1e1.2
//
//  Created by Vicente Cubells Nonell on 21/03/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define N 10

int main(int argc, const char * argv[])
{
    int numeros[N] = {0};
    int contador;
    int numero;
    int f;
    
    srand(time(NULL));
    
    /* Generar arreglo de frecuencias */
    for (contador = 0; contador < MAX; ++contador) {
        numero = rand() % 10;
        
        numeros[numero]++;
    }
    
    /* Histograma */
    for (contador = 0; contador < N; ++contador) {
        printf("%3d\t%5d\t\t", contador, numeros[contador]);
        
        numeros[contador] *= 0.5;
        
        for (f = 0; f < numeros[contador]; ++f) {
            printf("*");
        }
        
        printf("\n");
        
    }
    
    
    return 0;
}

