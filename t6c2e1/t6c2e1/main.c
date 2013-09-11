//
//  main.c
//  t6c2e1
//
//  Created by Vicente Cubells Nonell on 24/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int i, j;
    int n, n2;
    
    printf("Entre por teclado el valor de n: ");
    scanf("%d", &n);
    
    /* Generar reporte tabular con un solo ciclo */
    printf("Reporte con un solo ciclo \n");
    n2 = n * n;
    for (i=1; i <= n2; ++i)
    {
        printf("%3d", i);
        if (i % n == 0)
            printf("\n");
    }
    
    /* Generar reporte tabular con dos ciclos */
    printf("\n Reporte con dos ciclos anidados \n");
    for (i = 0; i < n; ++i)
    {
        for (j = 1 ; j <= n; ++j) {
            printf("%3d", (i * n) + j);
        }
        
        printf("\n");
    }
    
    return 0;
}

