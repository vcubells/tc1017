//
//  main.c
//  factorial
//
//  Created by Vicente Cubells Nonell on 09/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int contador;
    int n;
    int factorial = 1;
    
    printf("Entre el número: ");
    scanf("%d", &n);
    
    for (contador = 1; contador <= n; ++contador) {
        factorial = factorial * contador;
        printf(" contador = %d, factorial = %d \n", contador, factorial);
    }
    
    printf("El factorial de %d = %d \n", n, factorial);
    
    return 0;
}

