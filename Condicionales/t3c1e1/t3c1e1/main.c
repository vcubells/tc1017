//
//  main.c
//  t3c1e1
//
//  Created by Vicente Cubells Nonell on 28/01/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

/* Protipo de las funciones */
void opcion1();
void opcion2();
void opcion3();

int main(int argc, const char * argv[])
{
    int opcion;
    
    printf("Opciones \n \
           1-Entrar valores\n \
           2-Calcular \n \
           3-Mostrar resultados \n \
           4,5,6- Otra \n \
           Escoga su opción: ");
    

           
    scanf("%d", &opcion);
    
    switch (opcion) {
        
        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;
        case 3:
            opcion3();
            break;
        case 4:
        case 5:
        case 6:
            printf("Usted seleccionó la opción 4, 5 ó 6 \n");
            break;
        default:
            printf("Opción no válida");
            break;
        
    }
    return 0;
} // Fin del main

void opcion1()
{
    printf("Usted seleccionó la opción 1 \n");
}

void opcion2()
{
    printf("Usted seleccionó la opción 2 \n");
 
}

void opcion3()
{
    printf("Usted seleccionó la opción 3 \n");
}

