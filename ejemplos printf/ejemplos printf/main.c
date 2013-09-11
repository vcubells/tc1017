//
//  main.c
//  ejemplos printf
//
//  Created by Vicente Cubells Nonell on 28/02/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void histograma(int frecuencia);

int main(int argc, const char * argv[])
{
    srand(time(NULL));
    
    int i;
    int numero;
    int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = c10 = 0;
    
    for (i = 0; i < 1000; ++i) {
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
    
    /* Imprimir el reporte */
    printf("%6s\t%6s\n", "Número", "Veces");

    printf("%6d\t%6d\t", 1, c1);
    histograma(c1);
    
    printf("%6d\t%6d\t", 2, c2);
    histograma(c2);
    
    printf("%6d\t%6d\t", 3, c3);
    histograma(c3);
    
    printf("%6d\t%6d\t", 4, c4);
    histograma(c4);
    
    printf("%6d\t%6d\t", 5, c5);
    histograma(c5);
    
    printf("%6d\t%6d\t", 6, c6);
    histograma(c6);
    
    printf("%6d\t%6d\t", 7, c7);
    histograma(c7);
    
    printf("%6d\t%6d\t", 8, c8);
    histograma(c8);
    
    printf("%6d\t%6d\t", 9, c9);
    histograma(c9);
    
    printf("%6d\t%6d\t", 10, c10);
    histograma(c10);
    
    return 0;
}

void histograma(int frecuencia)
{
    int i;
    
    /* Aplicar factor de escala */
    frecuencia *= .5;
    for (i = 0; i < frecuencia; ++i) {
        printf("-");
    }
    
    printf("\n");
}
