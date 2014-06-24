//
//  main.c
//  t9c2e6
//
//  Created by Vicente Cubells Nonell on 24/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define N 30
#define PERSONAS 10

int main(int argc, const char * argv[])
{
    // Declarar variables
    int edadMasJoven = 1000;
    int edadMasViejo = 0;
    
    char nombreMasJoven[N];
    char nombreMasViejo[N];
    
    int edad;
    char nombre[N];
    
    for (int i = 1; i <= PERSONAS; ++i) {
        printf("Entre el nombre de la persona %d:", i);
        scanf("%s", nombre);
        
        printf("Entre la edad de la persona %d:", i);
        scanf("%d", &edad);
        
        if (edad < edadMasJoven) {
            edadMasJoven = edad;
            strcpy(nombreMasJoven, nombre);
        }
        
        if (edad > edadMasViejo) {
            edadMasViejo = edad;
            strcpy(nombreMasViejo, nombre);
        }
    }
    
    printf("La persona mas joven es %s con %d años\n", nombreMasJoven, edadMasJoven);
    printf("La persona mas vieja es %s con %d años\n", nombreMasViejo, edadMasViejo);
    
    return 0;
}

