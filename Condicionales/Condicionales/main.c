//
//  main.c
//  Condicionales
//
//  Created by Vicente Cubells Nonell on 20/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int a, b, c;
    
    printf("Entre el valor de a: ");
    scanf("%d", &a);
    
    printf("Entre el valor de b: ");
    scanf("%d", &b);
    
    printf("Entre el valor de c: ");
    scanf("%d", &c);
    
    if (a < b && a < c) {
        printf("El menor es a = %d \n", a);
    }
    else if (b < c) {
        printf("El menor es b = %d \n", b);
    }
    else {
        printf("El menor es c = %d \n", c);
    }
    
    /* Utilizando el operador ternario */
    (a < b && a < c) ? printf("El menor es a = %d \n", a) : ( (b < c) ? printf("El menor es b = %d \n", b) : printf("El menor es c = %d \n", c) );
    
    
    return 0;
}

