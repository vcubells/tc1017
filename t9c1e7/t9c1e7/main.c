//
//  main.c
//  t9c1e7
//
//  Created by Vicente Cubells Nonell on 23/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10

void modificaArreglo(int a[N], int otra);

int main(int argc, const char * argv[])
{
    int numeros[10] = {0};
    int otra = 0;
    
    for (int i = 0; i < N; ++i) {
        printf("%d\t", numeros[i]);
    }
    
    printf("Otra = %d\n", otra);
    
    /* Después de invocar a la función */
    modificaArreglo(numeros, otra);
    
    for (int i = 0; i < N; ++i) {
        printf("%d\t", numeros[i]);
    }
    
    printf("Otra = %d\n", otra);
    
    return 0;
}

void modificaArreglo(int a[N], int otra)
{
    for (int i = 0; i < N; ++i) {
        a[i] = i * i;
    }
    
    otra = -1;
}