//
//  main.c
//  t4c1e2
//
//  Created by Vicente Cubells Nonell on 27/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
        // Calcular el promedio de n valores definidos por el usuario
    float suma = 0; // Se declara e inicializa la variable suma
    float promedio, numero;
    int contador = 0;
    
    do {
        printf("Entra un número, -1 para terminar: ");
        scanf("%f", &numero);
        
        if (numero != -1) {
            suma = suma + numero;
            contador++;
        }
        
    } while (numero != -1);
    
    promedio = suma / contador;
    
    printf("El promedio de los números entrados es: %.2f \n", promedio);
    
        // ------------- Solución con while ------------------
    
    contador = 0;
    suma = 0;
    
    printf("Entra un número, -1 para terminar: ");
    scanf("%f", &numero);
    
    while (numero != -1) {
        suma = suma + numero;
        contador++;
        
        printf("Entra un número, -1 para terminar: ");
        scanf("%f", &numero);
    }
    
    promedio = suma / contador;
    
    printf("El promedio de los números entrados es: %.2f \n", promedio);
    
    return 0;
}

