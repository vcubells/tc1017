//
//  main.c
//  t9c1e5
//
//  Created by Vicente Cubells Nonell on 23/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[])
{
    /* Declarar las variables */
    int numeros[N];
    
    /* Inicializar el arreglo */
    for (int i = 0; i < N; ++i) {
        numeros[i] = i * i;
    }

    /* Mostrar los resultados */
    for (int i = 0; i < N; ++i) {
        printf("%4d\t%6d\n", i, numeros[i]);
    }
    
    return 0;
}

