//
//  main.c
//  promedio_con_centinela
//
//  Created by Vicente Cubells Nonell on 09/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    
    // Definir las variables
    float calificacion;
    int  contador;
    float suma;
    float promedio;
    int centinela = -1;
    
    // Inicializar variables
    calificacion = 0;
    suma = 0;
    promedio = 0;
    
     contador = 0;
     while (centinela != 0)
     {
         // Entrar la siguiente calificación
         printf("Entre la calificación %d: ", contador + 1);
         scanf("%f", &calificacion);
         
         // Acumular la suma
         suma = suma + calificacion;
         
         ++contador;
         
         printf("¿Desea entrar otra calificación (1-Si / 0- No)?: ");
         scanf("%d", &centinela);
     }

    
    // Calcular el promedio
    if (contador > 0) {
         promedio = suma / contador;
    }
   
    // Mostrar el resultado
    printf("El promedio es %f\n", promedio);
    
    
    return 0;
}


