//
//  main.c
//  t9c1e1.5
//
//  Created by Vicente Cubells Nonell on 21/03/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(int argc, const char * argv[])
{
    int numeros[N], otros[N];
    int contador;
    
    srand(time(NULL));
    
    /* Generar arreglos aleatorios */
    for (contador = 0; contador < N; ++contador) {
        numeros[contador] = rand() % 10;
        otros[contador] = rand() % 10;
    }
    
    /* Imprimir arreglos */
    printf("%10s\t", "Arreglo 1");
    for (contador = 0; contador < N; ++contador) {
        printf("%3d", numeros[contador]);
    }
    
    printf("\n");

    printf("%10s\t", "Arreglo 2");
    for (contador = 0; contador < N; ++contador) {
        printf("%3d", otros[contador]);
    }
    
    printf("\n");
    
    /* Imprimir la suma de los vectores */
    printf("%10s\t", "Suma");
    for (contador = 0; contador < N; ++contador) {
        printf("%3d", numeros[contador] + otros[contador]);
    }
    
    printf("\n");
    
    return 0;
}

