//
//  main.c
//  t10c1e3
//
//  Created by Vicente Cubells Nonell on 08/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLS 8
#define FILAS 10

int main(int argc, const char * argv[])
{
    int fila, columna;
    int m[FILAS][COLS];
    
    srand(time(NULL));
    
    /* Inicializar los elementos de la matriz */
    for (fila = 0; fila < FILAS; ++fila) {
        for (columna = 0; columna < COLS; ++columna) {
            m[fila][columna] = rand() % 100;
        }
    }
    
    /* Imprimir solo los elementos pares de la matriz */
    for (fila = 0; fila < FILAS; ++fila) {
        for (columna = 0; columna < COLS; ++columna) {
            if ( m[fila][columna] % 2 == 0)
                printf("%5d", m[fila][columna]);
            else
                printf("%5c", '-');
        }
        printf("\n");
    }
    
    return 0;
}




