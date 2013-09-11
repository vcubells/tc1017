//
//  main.c
//  t9c2e1.1
//
//  Created by Vicente Cubells Nonell on 01/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int longitud(char c[]);
void invertir(char c[]);

int main(int argc, const char * argv[])
{
    char cadena[] = "Esto es una cadena";
    
    printf("%s \n", cadena);
    
    int caracteres = strlen(cadena);
    
    printf("La cadena tiene %d caracteres \n", caracteres);
    
    invertir(cadena);
    
     printf("%s \n", cadena);
    
    invertir(cadena);
    
    printf("%s \n", cadena);

    
    return 0;
}

int longitud(char c[])
{
    int total = 0;
    int i = 0;
    
    while (c[i++] != '\0') {
        ++total;
    }
    
    return total;
}

void invertir(char c[])
{
    int i, j;
    char temp;
    
    i = 0;
    j = longitud(c) - 1;
    
    while (i < j)
    {
        temp = c[i];
        c[i] = c[j];
        c[j] = temp;
        ++i;
        --j;
    }
}
