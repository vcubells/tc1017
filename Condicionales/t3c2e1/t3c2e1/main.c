//
//  main.c
//  t3c2e1
//
//  Created by Vicente Cubells Nonell on 23/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

void clasificaPersona(int edad, char nombre[30]);

int main(int argc, const char * argv[])
{

    int edad;
    char nombre[30];
    
    printf("Entra el nombre de la persona: ");
    scanf("%s", nombre);
    
    printf("Entra la edad de %s:", nombre);
    scanf("%d", &edad);
    
    clasificaPersona(edad, nombre);
    
    return 0;
}

void clasificaPersona(int edad, char nombre[30] )
{
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
    else if (edad >= 60)
    {
        printf("%s es un adulto mayor \n", nombre);
    }
}

