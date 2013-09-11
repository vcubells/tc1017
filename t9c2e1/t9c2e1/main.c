//
//  main.c
//  t9c2e1
//
//  Created by Vicente Cubells Nonell on 11/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10

int suma(int a[], int n);
void modifica(int a[], int n);
void cambiar(char c[]);

int main(int argc, const char * argv[])
{
    int numeros[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    char cadena[] = "Esto funciona";
    
    modifica(numeros, N);
    
    printf("La suma de los elementos del arreglo es = %d \n", suma(numeros, N));
    
    printf("La cadena es = %s \n", cadena);
    
    cambiar(cadena);
    
    printf("La cadena es = %s \n", cadena);
    
    return 0;
}

void cambiar(char c[])
{
    c[0] = '*';
}

void modifica(int a[], int n)
{
    a[5] = 100;
}

int suma(int a[], int n)
{
    int s = 0;
    int i;
    
    
    for (i = 0; i < n; ++i) {
        s += a[i];
    }
    
    return s;
    
}

