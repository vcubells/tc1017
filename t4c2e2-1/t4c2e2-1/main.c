//
//  main.c
//  t4c2e2-1
//
//  Created by Vicente Cubells Nonell on 10/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

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
    printf("Cantidad vendida de pan = %d (bolsas)\n", pan);
    printf("Cantidad vendida de tortilla = %d (Kgs)\n", tortilla);
    printf("Cantidad vendida de leche = %d (litros)\n", leche);
    printf("Cantidad vendida de huevos = %d (cartones) \n", huevos);
    printf("Cantidad vendida de queso = %d (Kgs)\n", queso);
    
    int total = pan + tortilla + leche + huevos + queso;
    
    printf("Se vendieron en total %d productos\n", total);
    
    return 0;
}

