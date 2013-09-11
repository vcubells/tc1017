//
//  main.c
//  escuela
//
//  Created by Vicente Cubells Nonell on 14/02/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10

int main(int argc, const char * argv[])
{
    int aprobados, reprobados, contador, valor;
    
    aprobados = reprobados = contador = 0;
    
    // Entrada de valores
    while (contador < N)
    {
        printf("Entre un valor (1-Aprob. / 2-Reprob.): ");
        scanf("%d", &valor);
        
        if (valor == 1) {
            ++aprobados;  // Procesamiento
            ++contador;
        }
        else if (valor == 2)
        {
            ++reprobados; // Procesamiento
            ++contador;
        }
        else {
            printf("Opción no válida\n");
        }
    }
    
    // Mostrar los resultados
    
    printf("Aprobados = %d \n", aprobados);
    printf("Reprobados = %d \n", reprobados);
    
    if (N * .8 < aprobados)
    {
        printf("Se cumplió el objetivo");
    }

    return 0;
}

