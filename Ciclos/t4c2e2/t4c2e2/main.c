//
//  main.c
//  t4c2e2
//
//  Created by Vicente Cubells Nonell on 06/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void dibuja(char *, int);

int main(int argc, const char * argv[])
{
    int bolillos, huevos, leche, frijol, arroz, total, opcion;
    
    total = opcion = bolillos = huevos = leche = frijol = arroz = 0;
    
    do {
        printf("Menú de productos:\n");
        printf("1-Bolillo \n 2-Huevos \n 3-Leche \n 4-Frijol \n 5-Arroz \n 0-Terminar \n");
        printf("Seleccione una opción: ");
        
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ++bolillos;
                break;
            case 2:
                ++huevos;
                break;
            case 3:
                ++leche;
                break;
            case 4:
                ++frijol;
                break;
            case 5:
                ++arroz;
                break;
        }
        
    } while (opcion != 0);
    
    /* Visualizar los resultados */
    
    printf("Cantidad de Bolillos vendidos = %d \n", bolillos);
    printf("Cantidad de Huevos vendidos = %d \n", huevos);
    printf("Cantidad de Lts de Leche vendidos = %d \n", leche);
    printf("Cantidad de Kgs de Frijol vendidos = %d \n", frijol);
    printf("Cantidad de Kgs de Arroz vendidos = %d \n", arroz);
    
    total = bolillos + huevos + leche + frijol + arroz;
    
    printf("La cantidad total de productos vendidos = %d \n", total);

    /* Imprimir histograma */
    
   /* dibuja("Bolillos", bolillos);
    dibuja("Huevos", huevos);
    dibuja("Leche", leche);
    dibuja("Frijol", frijol);
    dibuja("Arroz", arroz);
*/

    return 0;
}

void dibuja(char * producto, int cantidad)
{
    int i;
    
    if (strlen(producto) <= 6 )
        printf("%s \t \t", producto);
    else
        printf("%s \t", producto);
    
    
    for (i = 0; i < cantidad; ++i) {
        printf("*");
    }
    printf("\n");
}


