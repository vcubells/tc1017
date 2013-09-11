//
//  main.c
//  t9c1e1.3
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
    
    /* Calcular el promedio */
    for (contador = 0; contador < N; ++contador) {
        suma += numeros[contador];
    }
    
    printf("El promedio de los números es: %3d\n", suma / N);
    
    
    
    return 0;
}

