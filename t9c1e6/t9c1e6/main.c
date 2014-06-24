//
//  main.c
//  t9c1e6
//
//  Created by Vicente Cubells Nonell on 23/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define N 10
int main(int argc, const char * argv[])
{
    /* Declarar las variables */
    int edades[N] = {17, 23, 21, 20, 19, 18, 25, 17, 18, 21};
    int suma = 0;
    
    /* Mostrar el contenido del arreglo */
    for (int i = 0; i < N; ++i) {
        printf("%4d\t%4d\n", i, edades[i]);
    }
    
    /* Obtener el promedio */
    for (int i = 0; i < N; ++i) {
        suma = suma + edades[i];
    }
    
    printf("El promedio de las edades es = %d\n", (suma / N));
    
    return 0;
}

