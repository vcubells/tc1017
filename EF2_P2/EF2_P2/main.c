//
//  main.c
//  EF2_P2
//
//  Created by Vicente Cubells Nonell on 13/05/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 5
#define M 9

void generaMatriz(int A[N][M]);
void imprimeMatriz(int A[N][M]);
void transformaMatriz(int A[N][M], int B[N][M]);
void generaArchivo(int A[N][M]);


int main(int argc, const char * argv[])
{
    int A[N][M] = {0};
    int B[N][M] = {0};
    
    
    generaMatriz(A);
    imprimeMatriz(A);
    
    transformaMatriz(A, B);
    imprimeMatriz(B);
    
    generaArchivo(A);
    generaArchivo(B);
    
    return 0;
}

void generaMatriz(int A[N][M])
{
    int f,c;
    int inicio, fin;
    
    inicio = (M / 2) - 1;
    
    if (M % 2 == 0)
    {
        fin = inicio + 1;
    }
    else {
        inicio++;
        fin = inicio;
    }
    
    for (f = 0; f < N; ++f) {
        
        for (c = inicio; c <= fin; ++c) {
            A[f][c] = f+1;
        }
        
        inicio--;
        fin++;
    }
}

void imprimeMatriz(int A[N][M])
{
    int f,c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < M; ++c) {
            if (A[f][c] != 0)
                printf("%5d", A[f][c]);
            else
                printf("%5s", " ");
        }
        printf("\n");
    }
}


void transformaMatriz(int A[N][M], int B[N][M])
{
    int f,c, nf;
    
    for (f = 0; f < N; ++f) {
        
        nf = N-f-1;
        
        for (c = 0; c < M; ++c) {
            B[f][c] = A[nf][c];
        }
    }
    
}

void generaArchivo(int A[N][M])
{
    FILE * fd;
    int f, c;
    
    fd = fopen("/Users/vcubells/Desktop/matrices.csv", "a");
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < M; ++c) {
            if (A[f][c] != 0)
                fprintf(fd, "%d,", A[f][c]);
            else
                fprintf(fd, "%s,", " ");
        }
        fprintf(fd,"\n");
    }
    
    fclose(fd);
}
