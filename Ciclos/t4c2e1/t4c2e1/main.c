//
//  main.c
//  t4c2e1
//
//  Created by Vicente Cubells Nonell on 03/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//


#include <stdio.h>

#define N 10    // Define el número de estudiantes */

int main(int argc, const char * argv[])
{

    int aprobados, reprobados, contador, estado; /* Definir variables contadoras */
    
    aprobados = 0;  /* Inicializar los contadores */
    reprobados = 0;
    contador = 1;
    
    while (contador <= N)
    {
        printf("Entre el estado del estudiante #%d (1-Aprob / 2-Reprob): ", contador);
        scanf("%d", &estado);
        
        /* Comparar el valor de estado para acumular en la variable correspondiente */
        if (estado == 1)
        {
            aprobados++;
            ++contador; /* Incrementar el contador del ciclo */
        }
        else if (estado == 2)
        {
            reprobados++;
            ++contador; /* Incrementar el contador del ciclo */
        }
        else
        {
            printf("Estado no válido \n");
        }
    } /* fin del while */
    
    /* Imprimir resultados */
    printf("El número de aprobados es %d \n", aprobados);
    printf("El número de reprobados es %d \n", reprobados);
    
    if ( (N * .8) <= aprobados )
    {
        printf("Se cumplió el objetivo");
    }
    
    return 0;
}

