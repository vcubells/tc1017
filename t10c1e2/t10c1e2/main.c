//
//  main.c
//  t10c1e2
//
//  Created by Vicente Cubells Nonell on 08/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#define N 2

int main(int argc, const char * argv[])
{
    int i, j;
    int suma = 0;
    int m[N][N] = { {1,2}, {3, 4}};
    
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            suma += m[i][j];
        }
    }
    
    printf("La suma de los elementos de m = %d \n", suma);
    
    return 0;
}


