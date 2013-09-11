//
//  main.c
//  t9c1e3
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
    float menor;
    int repite;
    
    /* El usuario entra N precios y se almacenan en el arreglo */
    for (i = 0; i < N; ++i) {
        printf("Entra el precio #%d: ", i+1);
        scanf("%f", &precios[i]);
    }
    
    /* Obtener precio menor */
    menor = precios[0];
    repite = 1;
    for (i = 1; i < N; ++i) {
        if (precios[i] < menor) {
            menor = precios[i];
            repite = 1;
        }
        else if (precios[i] == menor) {
            ++repite;
        }
            
    }
    
    printf("El menor de los precios es = %.2f y se repitió %d veces\n", menor, repite);
    
    
    return 0;
}

