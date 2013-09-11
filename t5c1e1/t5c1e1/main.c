//
//  main.c
//  t5c1e1
//
//  Created by Vicente Cubells Nonell on 10/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Prototipo de las funciones */
int Tortuga(int);
int Liebre(int);
void Imprime(int, int);
int Verifica(int, int);

int main(int argc, const char * argv[])
{
    int tortuga = 1; /* Posición actual de la tortuga */
    int liebre = 1; /* Posición actual de la liebre */
    int gano = 0; /* Centinela */
    
    /* Establecer la semila del generador de números aleatorios */
    srand((int)time(NULL));
    
    do {
        /* Actualizar la posición de la tortuga */
        tortuga = Tortuga(tortuga);
        
        /* Actualizar la posición de la liebre */
        liebre = Liebre(liebre);
        
        /* Imprimir las posiciones actuales */
        Imprime(tortuga, liebre);
        
        /* Verificar si alguno ganó */
        gano = Verifica(tortuga, liebre);
        
        /* Pausa de 1 segundo */
        sleep(1);
        
    }
    while (!gano);
    
    return 0;
}

int Tortuga(int posicion)
{
    int i;
    
    /* Generar número aleatorio acotado entre 1 y 10 */
    i = rand() % 10 + 1;
    
    if (i >= 1 && i <= 5) { /* Paso rápido */
        posicion += 3;
    }
    else if (i >= 6 && i <= 7) { /* Caída */
        posicion -= 6;
        if (posicion < 1) { /* Caso en que se ajusta si retrocede a valores negativos */
            posicion = 1;
        }
    }
    else { /* Paso lento */
        posicion += 1;
    }
    
    return posicion;
}

int Liebre(int posicion)
{
    int i;
    
    /* Generara número aleatorio acotado entre 1 y 10 */
    i = rand() % 10 + 1;
    
    if (i >= 1 && i <= 2) {
        /* No se mueve */
    }
    else if (i >= 3 && i <= 4) { /* Paso rápido */
        posicion += 9;
    }
    else if (i == 5) { /* Caída grande */
        posicion -= 12;
        if (posicion < 1) {
            posicion = 1;
        }
    }
    else if (i >= 6 && i <= 8) { /* Salto pequeño */
        posicion += 1;
    }
    else {  /* Caída pequeña */
        posicion -= 2;
        if (posicion < 1) {
            posicion = 1;
        }
    }
    
    return posicion;
}

void Imprime(int tortuga, int liebre)
{
    int c;
    
    for ( c = 1; c <= 70; ++c) {
        if (tortuga == liebre && tortuga == c) {
            printf("OUCH!!!");
        }
        else if (tortuga == c) {
            printf("T");
        }
        else if (liebre == c) {
            printf("L");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}

int Verifica(int tortuga, int liebre)
{
    int centinela = 0;
    
    if (tortuga >= 70) {
        printf("VIVA!!! Ganó la tortuga");
        centinela = 1;
    }
    else if (liebre >= 70) {
        printf("Yupi!!! Ganó la liebre");
        centinela = 1;
    }
    
    return centinela;
}
