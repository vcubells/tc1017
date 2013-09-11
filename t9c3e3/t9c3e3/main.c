//
//  main.c
//  t9c3e3
//
//  Created by Vicente Cubells Nonell on 15/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define M 10

int main(int argc, const char * argv[])
{
    int frecuencia[M] = {0};
    int i, j, numero;
    
    srand(time(NULL));
    
    for (i = 0; i < N; ++i) {
        numero = rand() % M;
        ++frecuencia[numero];
    }
    
    /* Generar histograma */
    for (i = 0; i < M; ++i) {
        printf("%3d\t(%3d)\t", i, frecuencia[i]);
        for ( j = 0; j < frecuencia[i]; ++j)
            printf("=");
        
        printf("\n");
    }
    return 0;
}

