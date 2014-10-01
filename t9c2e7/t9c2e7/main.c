//
//  main.c
//  t9c2e7
//
//  Created by Vicente Cubells Nonell on 25/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#define N 5

// Definir un tipo compuesto
struct persona {
    int edad;
    char nombre[30];
};

int main(int argc, const char * argv[])
{
    struct persona lista[N];
    
    // Leer la información de las personas
    for (int i = 0; i < N; ++i) {
        printf("Entre el nombre de la persona %d: ", i+1);
        scanf("%s", lista[i].nombre);
        
        printf("Entre la edad de la persona %d: ", i+1);
        scanf("%d", &lista[i].edad);
    }
    
    // Mostrar la lista de personas
    printf("%3s\t%30s\t%4s\n", "#", "Nombre", "Edad");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < N; ++i) {
        printf("%3d\t%30s\t%4d\n", i+1, lista[i].nombre, lista[i].edad);
    }
    
    // Buscar las persona con cierta edad
    int edad;
    
    printf("Entre la edad de la persona a buscar: ");
    scanf("%d", &edad);
    
    printf("Nombre de las personas con %d años:\n", edad);
    
    for (int i = 0; i < N; ++i) {
        if (lista[i].edad == edad) {
            printf("%s\n", lista[i].nombre);
        }
    }
    
    return 0;
}

