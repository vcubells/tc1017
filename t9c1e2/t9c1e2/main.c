//
//  main.c
//  t9c1e2
//
//  Created by Vicente Cubells Nonell on 08/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[])
{

    int i;
    float precios[N];
    float total = 0;
    float mayor;
    int indice;
    
    /* El usuario entra N precios y se almacenan en el arreglo */
    for (i = 0; i < N; ++i) {
        printf("Entra el precio #%d: ", i+1);
        scanf("%f", &precios[i]);
    }
    
    /* Calcular el promedio */
    for (i = 0; i < N; ++i) {
        total += precios[i];
    }
    
    printf("El promedio de los precios es = %.2f \n", total / N);
    
    /* Obtener precio más alto */
    mayor = precios[0];
    indice = 0;
    for (i = 1; i < N; ++i) {
        if (precios[i] > mayor) {
            mayor = precios[i];
            indice = i;
        }
    }
    
    printf("El mayor de los precios es = %.2f y fue el precio %d\n", mayor, indice+1);
        
    
    return 0;
}

