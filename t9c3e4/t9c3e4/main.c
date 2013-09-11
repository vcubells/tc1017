//
//  main.c
//  t9c3e4
//
//  Created by Vicente Cubells Nonell on 15/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define N 5

struct persona {
    char nombre[30];
    int edad;
};

int main(int argc, const char * argv[])
{
    struct persona personas[N];
    int i;
    
    for (i = 0; i < N; ++i) {
        printf("Datos de persona #%d:\n", i+1);
        
        printf("Entre el nombre: ");
        scanf("%s", personas[i].nombre);
        
        printf("Entre la edad: ");
        scanf("%d", &personas[i].edad);
    }
    
    /* Reporte tabular de las personas */
    printf("%-2s\t%-30s\t%-4s\n", "No", "Nombre", "Edad");
    for (i = 0; i < N; ++i) {
        printf("%2d\t%-30s\t%3d\n", i+1, personas[i].nombre, personas[i].edad);
    }
    
    return 0;
}

