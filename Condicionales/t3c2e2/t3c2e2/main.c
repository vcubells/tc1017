//
//  main.c
//  t3c2e2
//
//  Created by Vicente Cubells Nonell on 23/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int a, b;
    /*
    printf("Entre el valor de a: ");
    scanf("%d", &a);
    
    printf("Entre el valor de b: ");
    scanf("%d", &b);
    */
    
    printf("Entre los valores de a y b en el formato: a,b:");
    scanf("%d,%d", &a, &b);
    
    
    if (a < b)
    {
        printf("El resultado de multiplicar b, a veces por 2 = %d", b << a);
    }
    else
    {
        printf("El resultado de dividir a, b veces entre 2 = %d", a >> b);
    }
    
    return 0;
}

