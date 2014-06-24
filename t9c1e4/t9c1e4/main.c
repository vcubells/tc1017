//
//  main.c
//  t9c1e4
//
//  Created by Vicente Cubells Nonell on 23/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 1000

void histograma(int frecuencia);
int menosFrecuencia(int a[N]);
int masFrecuencia(int a[N]);
int existeNRepeticiones(int a[N], int buscado);

int main(int argc, const char * argv[])
{
    /* Declarar las variables */
    int contadores[N] = {0};
    int numero;
    
    /* Establecer el valor inicial del algoritmo random */
    srand((int)time(NULL));
    
    for (int i = 0; i < M; ++i) {
        numero = rand() % N;
        
        ++contadores[numero];
    }
    
    /* Mostrar resultados */
    for (int i= 0; i < N; ++i) {
        printf("%4d\t%6d\t", i, contadores[i] );
        histograma(contadores[i]);
    }
    
    /* Mostrar el número con menos repeticiones */
    int  menos = menosFrecuencia(contadores);
    
    printf("El número con menos repeticiones es %d con %d \n", menos, contadores[menos]);
    
    /* Mostrar el número con mas repeticiones */
    int  mas = masFrecuencia(contadores);
    
    printf("El número con mas repeticiones es %d con %d \n", mas, contadores[mas]);
    
    /* Encontrar si existe un índice con 30 repeticiones */
    int buscado = 15;
    int existe = existeNRepeticiones(contadores, buscado);
    
    if (existe == -1)
    {
        printf("Ningún número de repitió %d veces \n", buscado);
    }
    else {
        printf("El número %d se repitió %d veces \n", existe, buscado);
    }
    
    return 0;
}

void histograma(int frecuencia)
{
    for (int i = 0; i < frecuencia; ++i) {
        printf("*");
    }
    
    printf("\n");
}

int menosFrecuencia(int a[N])
{
    int menor = 1000000;
    int posicion = 0;
    
    for (int i = 0; i < N; ++i) {
        if (menor > a[i]) {
            menor = a[i];
            posicion = i;
        }
    }
    
    return posicion;
}

int masFrecuencia(int a[N])
{
    int mas = 0;
    int posicion = 0;
    
    for (int i = 0; i < N; ++i) {
        if (mas < a[i]) {
            mas = a[i];
            posicion = i;
        }
    }
    
    return posicion;
}

int existeNRepeticiones(int a[N], int buscado)
{
    int existe = -1;
    int i = 0;
    while (i < N && existe == -1)
    {
        if (a[i] == buscado) {
            existe = i;
        }
        
        ++i;
    }
    
    return existe;
}
