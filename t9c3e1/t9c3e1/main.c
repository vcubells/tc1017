//
//  main.c
//  t9c3e1
//
//  Created by Vicente Cubells Nonell on 15/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char palabra[25];
    int i = 0, j, mitad;
    int n;
    char temp;

    printf("Entre una palabra: ");
    scanf("%s", palabra);
    
    /* Variante uno sin afectar la cadena original */
    printf("Variante 1\n");
    
    n = strlen(palabra);
    
    for (i = n-1; i >= 0; --i) {
        printf("%c", palabra[i]);
    }
    
    /* Variante dos modificando la cadena original */
    printf("\nVariante 2\n");
    
    
    mitad = n / 2;
    
    for (i = 0, j = n-1; i < j; ++i, --j) {
        temp = palabra[i];
        palabra[i] = palabra[j];
        palabra[j] = temp;
    }
    
    for (i = 0; i < n; ++i) {
        printf("%c", palabra[i]);
    }
    
    return 0;
}

