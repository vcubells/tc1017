//
//  main.c
//  promedio_con_contador
//
//  Created by Vicente Cubells Nonell on 09/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#define N 10

int main(int argc, const char * argv[])
{

    // Definir las variables
    float calificacion;
    int  contador;
    float suma;
    float promedio;
    
    // Inicializar variables
    calificacion = 0;
    suma = 0;
    promedio = 0;
    
    // Ciclo para sumar valor
    for (contador = 1; contador <= N; ++contador) {
        
        // Entrar la siguiente calificación
        printf("Entre la calificación %d: ", contador);
        scanf("%f", &calificacion);
        
        // Acumular la suma
        suma = suma + calificacion;
        
    }
    
    /*
     contador = 1;
     while (contador <= 10)
     {
        // Entrar la siguiente calificación
        printf("Entre la calificación %d: ", contador);
        scanf("%f", &calificacion);
     
        // Acumular la suma
        suma = suma + calificacion;
     
        ++contador;
     }
     
     
     */
    
    // Calcular el promedio
    promedio = suma / N;
    
    // Mostrar el resultado
    printf("El promedio es %f\n", promedio);
    
    
    return 0;
}

