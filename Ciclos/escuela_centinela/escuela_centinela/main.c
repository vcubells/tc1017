//
//  main.c
//  escuela
//
//  Created by Vicente Cubells Nonell on 14/02/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int aprobados, reprobados, contador, valor;
    int centinela = 1;
    
    aprobados = reprobados = contador = 0;
    
    printf("Desea entrar un valor (1-Si / 0-No)?: ");
    scanf("%d", &centinela);
    
    // Entrada de valores
    while (centinela == 1)
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
        
        printf("Desea entrar otro valor (1-Si / 0-No)?: ");
        scanf("%d", &centinela);
    }
    
    // Mostrar los resultados
    
    printf("Aprobados = %d \n", aprobados);
    printf("Reprobados = %d \n", reprobados);
    
    if (contador * .8 < aprobados)
    {
        printf("Se cumplió el objetivo");
    }
    
    return 0;
}

