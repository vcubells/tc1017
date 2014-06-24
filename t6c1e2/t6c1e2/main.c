//
//  main.c
//  t6c1e2
//
//  Created by Vicente Cubells Nonell on 16/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declarar constantes */

#define N 1000

/* Declarar funciones en caso de que existan */
void histograma(int numero, int frecuencia);

int main(int argc, const char * argv[])
{
    /* Declarar variables */
    int numero;
    int cont1, cont2, cont3, cont4, cont5, cont6, cont7, cont8, cont9, cont10;
    
    /* Inicializar contadores en 0 */
    cont1 = cont2 = cont3 = cont4 = cont5 = 0;
    cont6 = cont7 = cont8 = cont9 = cont10 = 0;
    
    srand((int) time(NULL));
    
    /* Ciclo que se repite N veces */
    for (int i = 0; i < N; ++i) {
        
        /* Generar el número aleatorio */
        numero = rand() % 10 + 1;
        
        switch (numero) {
            case 1:
                ++cont1;
                break;
            
            case 2:
                ++cont2;
                break;
                
            case 3:
                ++cont3;
                break;
                
            case 4:
                ++cont4;
                break;
                
            case 5:
                ++cont5;
                break;
                
            case 6:
                ++cont6;
                break;
            
            case 7:
                ++cont7;
                break;
                
            case 8:
                ++cont8;
                break;
                
            case 9:
                ++cont9;
                break;
                
            case 10:
                ++cont10;
                break;
        } /* Fin del switch */
        
        
    } /* Fin del for */
    
    /* Generar el reporte y el histograma */
    histograma(1, cont1);
    histograma(2, cont2);
    histograma(3, cont3);
    histograma(4, cont4);
    histograma(5, cont5);
    histograma(6, cont6);
    histograma(7, cont7);
    histograma(8, cont8);
    histograma(9, cont9);
    histograma(10, cont10);
    
    return 0;
}


void histograma(int numero, int frecuencia)
{
    printf("%02d\t%+04d\t", numero, frecuencia);
    
    /* Factor de reducción */
    int longitud = frecuencia * 0.3;
    
    /* Imprimir caracter de barra horizontal */
    for (int i = 0; i < longitud; ++i) {
        printf("-");
    }
    
    printf("\n");
    
}

