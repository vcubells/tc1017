//
//  main.c
//  EF1_P2
//
//  Created by Vicente Cubells Nonell on 13/05/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 2

void generaMatriz(int A[N][N]);
void imprimeMatriz(int A[N][N]);
void transformaMatriz(int A[N][N], int B[N][N]);
void generaArchivo(int A[N][N]);


int main(int argc, const char * argv[])
{
    int A[N][N] = {0};
    int B[N][N] = {0};

    
    generaMatriz(A);
    imprimeMatriz(A);
    
    transformaMatriz(A, B);
    imprimeMatriz(B);
    
    generaArchivo(A);
    generaArchivo(B);
    
    return 0;
}

void generaMatriz(int A[N][N])
{
    int f,c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < (N-f); ++c) {
            A[f][c] = f + c + 1;
        }
    }
}

void imprimeMatriz(int A[N][N])
{
    int f,c;
    
    for (f = 0; f < N; ++f) {
        for (c = 0; c < N; ++c) {
            if (A[f][c] != 0)
                printf("%5d", A[f][c]);
            else
                printf("%5s", " ");
        }
        printf("\n");
    }
}


void transformaMatriz(int A[N][N], int B[N][N])
{
    int f,c, nf;
    
    for (f = 0; f < N; ++f) {
        
        nf = N-f-1;
        
        for (c = 0; c < N; ++c) {
            B[f][c] = A[nf][N-c-1];
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
            if (A[f][c] != 0)
                fprintf(fd, "%d,", A[f][c]);
            else
                fprintf(fd, "%s,", " ");
        }
        fprintf(fd,"\n");
    }
    
    fclose(fd);
}
