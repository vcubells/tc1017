//
//  main.c
//  t12c2e2
//
//  Created by Vicente Cubells Nonell on 29/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* Definir las funciones */

void inicializaMatriz(int m[N][N]);
void imprimeMatriz(int m[N][N]);
void AnoenB(int A[N][N], int B[N][N]);

int main(int argc, const char * argv[])
{
    int matrizA[N][N];
    int matrizB[N][N];
    
    srand(time(NULL));
    
    /* Inicializar las matrices */
    inicializaMatriz(matrizA);
    inicializaMatriz(matrizB);
    
    /* Imprimir las matrices */
    printf("\n------ Matriz A --------\n");
    imprimeMatriz(matrizA);
    
    printf("\n------ Matriz B --------\n");
    imprimeMatriz(matrizB);
    
    /* Elementos de A que no están en B */
    printf("\n------ A no en B --------\n");
    AnoenB(matrizA, matrizB);
    
    return 0;
}

void inicializaMatriz(int m[N][N])
{
    int f, c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            m[f][c] = rand() % 100;
        }
    }
}

void imprimeMatriz(int m[N][N])
{
    int f, c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            printf("%3d", m[f][c]);
        }
        
        printf("\n");
    }
}

void AnoenB(int A[N][N], int B[N][N])
{
    int fa, ca, fb, cb;
    int existe = 0;
    
    for (fa = 0; fa < N; ++fa) {
        for (ca = 0; ca < N; ++ca) {
            existe = 0;
            /* Recorrer toda la matriz B */
            for (fb = 0; fb < N; ++fb) {
                for (cb = 0; cb < N; ++cb) {
                    if (A[fa][ca] == B[fb][cb]) {
                        existe = 1;
                    }
                }
            }
            
            /* Imprimir si existe o no */
            
            if (existe) {
                printf("%3s", "-");
            }
            else {
                printf("%3d", A[fa][ca]);
            }
        }
        
        printf("\n");
    }
    
}


