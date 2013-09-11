//
//  main.c
//  t6c2e2
//
//  Created by Vicente Cubells Nonell on 24/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void grafica(int numero, int c);

int main(int argc, const char * argv[])
{
    int i, n, numero;
    int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    
    c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = c10 = 0;
    
    printf("Entra la cantidad de números a generar: ");
    scanf("%d", &n);
    
    srand(time(NULL));
    
    for (i = 0; i < n; ++i) {
        numero = rand() % 10 + 1;
        
        switch (numero) {
            case 1:
                ++c1;
                break;
            case 2:
                ++c2;
                break;
            case 3:
                ++c3;
                break;
            case 4:
                ++c4;
                break;
            case 5:
                ++c5;
                break;
            case 6:
                ++c6;
                break;
            case 7:
                ++c7;
                break;
            case 8:
                ++c8;
                break;
            case 9:
                ++c9;
                break;
            case 10:
                ++c10;
            break;
        }
    }
    
    /* Generar reporte tabular */
    
    printf("%6s %6s \n", "Número", "Veces");
    printf("%6d %6d \n", 1, c1);
    printf("%6d %6d \n", 2, c2);
    printf("%6d %6d \n", 3, c3);
    printf("%6d %6d \n", 4, c4);
    printf("%6d %6d \n", 5, c5);
    printf("%6d %6d \n", 6, c6);
    printf("%6d %6d \n", 7, c7);
    printf("%6d %6d \n", 8, c8);
    printf("%6d %6d \n", 9, c9);
    printf("%6d %6d \n", 10, c10);
    
    /* Generar la gráfica */
    grafica(10, c10);
    grafica(9, c9);
    grafica(8, c8);
    grafica(7, c7);
    grafica(6, c6);
    grafica(5, c5);
    grafica(4, c4);
    grafica(3, c3);
    grafica(2, c3);
    grafica(1, c1);
    
    return 0;
}

void grafica(int numero, int c)
{
    int i;
    int factor = 10;
    factor = c / 10;
    
    printf("%3d - ", numero);
    for (i = 0; i < factor; ++i)
        printf("*");
    
    printf("\n");
}

