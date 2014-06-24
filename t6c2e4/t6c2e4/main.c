//
//  main.c
//  t6c2e4
//
//  Created by Vicente Cubells Nonell on 17/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

void histograma(int frecuencia);

int main(int argc, const char * argv[])
{
    // Declarar las variables contadoras
    int pan, tortilla, leche, huevos, queso, opcion, cantidad;
    pan = tortilla = leche = huevos = queso = opcion = cantidad = 0;
    
    do {
        // Mostrar el menú de productos
        printf("Menú de productos:\n");
        printf("--------------------\n");
        printf("1- Pan \n2- Tortilla\n3- Leche\n4- Huevos\n5- Queso\n0- Cerrar el supermercado\n");
        
        //entrar la opción seleccionada
        printf("Seleccione el producto:");
        scanf("%d", &opcion);
        
        if (opcion != 0) {
            printf("Entre la cantidad a comprar: ");
            scanf("%d", &cantidad);
        }
        
        // Incrementar el contador del producto seleccionado
        switch (opcion) {
            case 1:
                pan = pan + cantidad;
                break;
            case 2:
                tortilla += cantidad;
                break;
            case 3:
                leche += cantidad;
                break;
            case 4:
                huevos += cantidad;
                break;
            case 5:
                queso += cantidad;
                break;
        }
        
    } while (opcion != 0);
    
    // Mostrar los resultados
    printf("============================================================\n");
    printf("%-10s\t|%10s\t|%-10s\t|%s\n", "Producto", "Cantidad", "Unidad", "Histograma");
    printf("============================================================\n");
    printf("%-10s\t|%10d\t|%-10s\t|", "Pan", pan, "bolsas");
    histograma(pan);
    printf("------------------------------------------------------------\n");
    
    printf("%-10s\t|%10d\t|%-10s\t|", "Tortilla", tortilla, "Kgs");
    histograma(tortilla);
    printf("------------------------------------------------------------\n");
    
    printf("%-10s\t|%10d\t|%-10s\t|", "Leche", leche, "litros");
    histograma(leche);
    printf("------------------------------------------------------------\n");
    
    printf("%-10s\t|%10d\t|%-10s\t|", "Huevos", huevos, "cartones");
    histograma(huevos);
    printf("------------------------------------------------------------\n");
    
    printf("%-10s\t|%10d\t|%-10s\t|", "Queso", queso, "Kgs");
    histograma(queso);
    
    printf("============================================================\n");
    int total = pan + tortilla + leche + huevos + queso;
    
    printf("Total = %d productos\n", total);
    
    return 0;
}

void histograma(int frecuencia)
{
    int i;
    
    /* Aplicar factor de escala */
    frecuencia *= .3;
    for (i = 0; i < frecuencia; ++i) {
        printf("*");
    }
    
    printf("\n");
}


