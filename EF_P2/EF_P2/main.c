//
//  main.c
//  EF_P2
//
//  Created by Vicente Cubells Nonell on 21/11/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void generaMatriz(int m[N][N]);
void imprimeMatriz(int m[N][N]);
void itemsAnoenB(int A[N][N], int B[N][N]);

int main(int argc, const char * argv[])
{
    int A[N][N], B[N][N];
    
    srand(time(NULL));
    
    /* Generar las matrices de manera automática */
    generaMatriz(A);
    generaMatriz(B);
    
    /* Imprimir las matrices generadas */
    printf("Matriz A: \n");
    imprimeMatriz(A);
    
    printf("Matriz B: \n");
    imprimeMatriz(B);
    
    /* Mostrar elementos de A que no están en B */
    printf("Elemento de A que no están en B: \n");
    itemsAnoenB(A, B);
    
    return 0;
}

void generaMatriz(int m[N][N])
{
    int i, j;
    
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            m[i][j] = rand() % 20;
        }
    }
}

void imprimeMatriz(int m[N][N])
{
    int i, j;
    
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void itemsAnoenB(int A[N][N], int B[N][N])
{
    int i, j;
    int k, m;
    int existe;
    
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            existe = 0;
            for (k = 0; k < N; ++k) {
                for (m = 0; m < N; ++m) {
                    if (A[i][j] == B[k][m])
                        existe = 1;
                }
            }
            
            if (existe == 1) {
                printf("%4s", "-");
            }
            else
                printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}