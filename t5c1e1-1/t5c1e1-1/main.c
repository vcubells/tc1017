//
//  main.c
//  t5c1e1-1
//
//  Created by Vicente Cubells Nonell on 10/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int actualizaTortuga(int tortuga);
int actualizaLiebre(int liebre);
void imprimirTabla(int tortuga, int liebre);

int main(int argc, const char * argv[])
{
    // Declarar los contadores de posición
    int tortuga, liebre;
    int reloj = 1;
    
    tortuga = liebre = 0;
    
    // Establecer la semilla del generador de números aleatorios
    srand((int)time(NULL));
    
    // Ejecutar el juego
    while (tortuga < 70 && liebre < 70) {
        tortuga = actualizaTortuga(tortuga);
        liebre = actualizaLiebre(liebre);
        
        imprimirTabla(tortuga, liebre);
        
        //Esperar un segundo
        sleep(reloj);
    }
    
    if (tortuga >= 70 && liebre >= 70) {
        printf("EMPATE !!!");
    }
    else if (tortuga >= 70) {
        printf("GANO LA TORTUGA !!!\n");
    }
    else if (liebre >= 70)
    {
        printf("GANO LA LIEBRE !!!\n");
    }
    
    return 0;
}

int actualizaTortuga(int tortuga)
{
    int desplazamiento = 0;
    
    // Generar un número aleatorio entre 1..10
    desplazamiento = rand() % 10 + 1;
    
    // Paso rápido
    if (desplazamiento <= 5)
    {
        tortuga = tortuga + 3;
    }
    // Deslizamiento
    else if (desplazamiento > 5 && desplazamiento < 8)
    {
        tortuga = tortuga - 6;
        if (tortuga < 1) {
            tortuga = 1;
        }
    }
    // Paso lento
    else {
        tortuga = tortuga + 1;
    }
    
    return tortuga;
}

int actualizaLiebre(int liebre)
{
    int desplazamiento = 0;
    
    // Generar un número aleatorio entre 1..10
    desplazamiento = rand() % 10 + 1;
    
    // Dormir
    if (desplazamiento <= 2)
    {
        // No hay desplazamiento
    }
    // Paso rápido
    else if (desplazamiento > 2 && desplazamiento < 5)
    {
        liebre = liebre + 9;
    }
    // Deslizamiento grande
    else if (desplazamiento == 5)
    {
        liebre = liebre - 12;
        if (liebre < 1) {
            liebre = 1;
        }
        
    }
    // Paso lento
    else if (desplazamiento > 5 && desplazamiento < 9)
    {
        liebre = liebre + 1;
    }
    // Deslizamiento pequeño
    else {
        liebre = liebre - 2;
        if (liebre < 1) {
            liebre = 1;
        }
    }
    
    return liebre;
}

void imprimirTabla(int tortuga, int liebre)
{
    int posicion;
    
    for (posicion = 1; posicion <= 70; ++posicion) {
        if (tortuga == posicion && liebre == posicion) {
            printf("OUTCH");
        }
        else if (tortuga == posicion)
        {
            printf("T");
        }
        else if (liebre == posicion)
        {
            printf("L");
        }
        else {
            printf("-");
        }
    }
    
    printf("\n");
}

