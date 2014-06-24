//
//  main.c
//  Operaciones
//
//  Created by Vicente Cubells Nonell on 21/01/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    // Definir variables
    int a;
    int b;
    
    // Asignar valores a las variables
    a = 58;
    b = 70;
    
    // Realizar las operaciones
    printf("La suma de %d + %d = %d \n", a, b, a+b);
    printf("La resta de %d - %d = %d \n", a, b, a-b);
    printf("La multiplicación de %d * %d = %d \n", a, b, a*b);
    printf("La división de %d / %d = %f \n", a, b, (float)a / b);
    
    // Operadores pre-incremento, post-incremento
    printf("%d++ = %d \n", a, a++);
    
    return 0;
}

