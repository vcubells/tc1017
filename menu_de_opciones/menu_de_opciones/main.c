//
//  main.c
//  menu_de_opciones
//
//  Created by Vicente Cubells Nonell on 09/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

void areaRectangulo();
void perimetroRectangulo();
void otraFigura();

int main(int argc, const char * argv[])
{

    // Declarar centinela
    int centinela = -1;
    
    // Declarar variable de opcion seleccionada
    int opcion;
    
    while (centinela != 0) {
        printf("Menú de opciones:\n");
        printf("------------------\n");
        printf("1- Calcular área de rectángulo\n");
        printf("2- Calcular perímetro de rectángulo\n");
        printf("3- Calcular otra figura\n");
        printf("0- Salir del programa\n");
        
        printf("Seleccione la opción deseada: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                areaRectangulo();
                break;
            case 2:
                perimetroRectangulo();
                break;
            case 3:
                otraFigura();
                break;
        }
        
        // Cambiar el valor del centinela
        centinela = opcion;
    }
    
    
    return 0;
}

void areaRectangulo()
{
    printf("Esta función calcula el área de un rectángulo\n");
}

void perimetroRectangulo()
{
    printf("Esta función calcula el perímtro de un rectángulo\n");
}

void otraFigura()
{
    printf("Esta función calula las demás figuras\n");
}
