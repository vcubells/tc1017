//
//  main.c
//  t9c1e1.4
//
//  Created by Vicente Cubells Nonell on 21/03/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[])
{
    int numeros[N];
    int contador;
    int suma = 0;
    
    /* Entrar valores */
    for (contador = 0; contador < N; ++contador) {
        printf("Entre el número %d: ", contador+1);
        scanf("%d", &numeros[contador]);
    }
    
    /* Imprimir en orden de entrada */
    for (contador = 0; contador < N; ++contador) {
        printf("%3d", numeros[contador]);
    }
    
    printf("\n");
    
    /* Imprimir en orden inverso */
    for (contador = N-1; contador >= 0; --contador) {
        printf("%3d", numeros[contador]);
    }

    
    return 0;
}



