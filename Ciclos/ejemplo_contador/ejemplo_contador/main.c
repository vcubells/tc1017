//
//  main.c
//  ejemplo_contador
//
//  Created by Vicente Cubells Nonell on 11/02/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

/* Constante simbólica */
#define N 10


int main(int argc, const char * argv[])
{
    int suma = 0;
    int contador;
    int numero;
    
    for (contador = 0; contador < N; ++contador) {
        printf("Entre un número: ");
        scanf("%d", &numero);
        
        /* Operación de acumulación */
        suma += numero;
    }
    
    printf("El promedio = %.2f", (float)suma / N);
    
    return 0;
}

