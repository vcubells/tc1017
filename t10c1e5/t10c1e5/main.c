//
//  main.c
//  t10c1e5
//
//  Created by Vicente Cubells Nonell on 25/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 5

int main(int argc, const char * argv[])
{
    // Declarar una matriz de números enteros de FILAS x COLUMNAS
    int matriz[FILAS][COLUMNAS];
    int suma = 0;
    int sumaFila;
    
    srand((int) time(NULL));
    
    printf("%6s\t|C0 |C1 |C2 |C3 |C4 |\n", " ");
    
    // Generar la matriz
    for (int fila = 0; fila < FILAS; ++fila) {
        
        printf("-----------------------------\n");
        printf("Fila-%d\t|", fila);
        
        sumaFila = 0;
        
        for (int columna = 0; columna < COLUMNAS; ++columna) {
            matriz[fila][columna] = rand() % 100;
            printf("%3d|", matriz[fila][columna]);
            
            suma += matriz[fila][columna];
            sumaFila += matriz[fila][columna];
        }
        
        printf("\t ∑ = %4d\n", sumaFila);
    }
    
    printf("\nLa suma de los elementos de la matriz es: %d \n", suma);

    return 0;
}

