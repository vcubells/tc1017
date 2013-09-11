//
//  main.c
//  EF3_P2
//
//  Created by Vicente Cubells Nonell on 13/05/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 5

void generaMatriz(int A[N][N]);
void imprimeMatriz(int A[N][N]);
void transpuestaMatriz(int A[N][N], int B[N][N]);
void generaArchivo(int A[N][N]);


int main(int argc, const char * argv[])
{
    int A[N][N] = {0};
    int B[N][N] = {0};
    
    srand(time(NULL));
    
    generaMatriz(A);
    imprimeMatriz(A);
    
    transpuestaMatriz(A, B);
    imprimeMatriz(B);
    
    generaArchivo(A);
    generaArchivo(B);
    
    return 0;
}

void generaMatriz(int A[N][N])
{
    int f,c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            A[f][c] = rand() % 20;
        }
    }
}

void imprimeMatriz(int A[N][N])
{
    int f,c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            printf("%5d", A[f][c]);
        }
        printf("\n");
    }
    
    printf("\n");
}


void transpuestaMatriz(int A[N][N], int B[N][N])
{
    int f,c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            B[f][c] = A[c][f];
        }
    }
    
}

void generaArchivo(int A[N][N])
{
    FILE * fd;
    int f, c;
    
    fd = fopen("/Users/vcubells/Desktop/matrices.csv", "a");
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            fprintf(fd, "%d,", A[f][c]);
        }
        fprintf(fd,"\n");
    }
    
    fclose(fd);
}
