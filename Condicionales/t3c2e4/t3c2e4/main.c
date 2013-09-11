//
//  main.c
//  t3c2e4
//
//  Created by Vicente Cubells Nonell on 31/01/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    /* Definir las variables a utilizar */
    int edad;
    char nombre[25];
    
    printf("Entre el nombre de la persona: ");
    scanf("%s", nombre);
    
    printf("Entre la edad de la persona: ");
    scanf("%d", &edad);
    
    
    
    /* Procesamiento de la variable */
    if (edad < 1)
    {
        printf("%s es un bebé \n", nombre);
    }
    else if (edad >= 1 && edad < 14)
    {
        printf("%s es un niño \n", nombre);
    }
    else if (edad >= 14 && edad < 20)
    {
        printf("%s es un adolescente \n", nombre);
    }
    else if (edad >= 20 && edad < 30)
    {
        printf("%s es un joven \n", nombre);
    }
    else if (edad >= 30 && edad < 60)
    {
        printf("%s es un adulto \n", nombre);
    }
    else
    {
        printf("%s es un adulto mayor \n", nombre);
    }
    
    return 0;
}

