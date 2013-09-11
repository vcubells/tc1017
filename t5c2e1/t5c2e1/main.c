//
//  main.c
//  t5c2e1
//
//  Created by Vicente Cubells Nonell on 13/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototipos de funciones */
int vacio(int);
float porcentaje(float , float );
int mayor(int, int);

int main(int argc, const char * argv[])
{
    /* Definir variables */
    int seguir = 1;
    int entrada1 = 0;
    int entrada2 = 0;
    int salida1 = 0;
    int salida2 = 0;
    int total = 0;
    int coche = 0;
    int coches = 0;
    
    
    /* Cambiar la semilla del algoritmo de generación de números aleatorios */
    srand(time(NULL));
    
    do {
        coche = (rand() % 4) + 1;
        
        switch (coche) {
            case 1:
                ++entrada1;
                ++total;
                ++coches;
                printf("+ Entró un coche por E1 ....\n");
                break;
            case 2:
                ++entrada2;
                ++total;
                 ++coches;
                printf("+ Entró un coche por E2 ....\n");
                break;
            case 3:
                if ( !vacio(total) )
                {
                    ++salida1;
                    --total;
                    printf("- Salió un coche por S1 ....\n");
                }
                break;
            case 4:
                if ( !vacio(total) )
                {
                    ++salida2;
                    --total;
                    printf("- Salió un coche por S2 ....\n");
                }
                break;
        }
        
        /* Comprobar si el estacionamiento está vacío para preguntar si se cierra o no */
        if ( vacio(total) )
        {
            printf("¿Desea cerrar el estacionamiento (0-Si / 1-No)?: ");
            scanf("%d", &seguir);
        }
    }
    while (seguir == 1);
    
    /* Termina el estacionamiento y se genera el reporte */
    printf("------ Reporte de funcionamiento -------\n");
    printf("Autos por entrada 1 = %d y representa el %.2f\% \n", entrada1, porcentaje(entrada1, coches));
    printf("Autos por entrada 2 = %d y representa el %.2f\% \n", entrada2, porcentaje(entrada2, coches));
    printf("Autos por salida 1 = %d y representa el %.2f% \n", salida1, porcentaje(salida1, coches));
    printf("Autos por salida 2 = %d y representa el %.2f% \n", salida2, porcentaje(salida2, coches));
    printf("Autos que utilizaron el estacionamiento = %d \n", coches);
    printf("La entrada más usada = %d \n", mayor(entrada1, entrada2));
    printf("La salida más usada = %d \n", mayor(salida1, salida2));
    
    return 0;
}

/* Función que verifica si hay coches en el estacionamiento */
int vacio(int nc)
{
    return (nc == 0);
}

/* Función que calcula el procentaje */
float porcentaje(float numero, float total)
{
    float porciento = 0;
    if (total != 0)
    {
        porciento = numero * 100 / total;
    }
    
    return porciento;
}

/* Función para determinar el mayor de dos números */
int mayor(int n1, int n2)
{
    int may = (n1 > n2) ? 1 : 2;
    
    return may;
}
