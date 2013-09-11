//
//  main.c
//  Aritmética
//
//  Created by Vicente Cubells Nonell on 16/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

/* la función main inicia la ejecución del programa */
int main(int argc, const char * argv[])
{
    int entero1; /* primer número introducido por el usuario  */
    int entero2; /* segundo número introducido por el usuario */
    int suma;    /* variable en la cual se almacena la suma   */
    
    printf( "Introduzca el primer entero: " ); /* indicador */
    scanf( "%d", &entero1 );          /* lee un entero */
    
    printf( "Introduzca el segundo entero: " ); /* indicador */
    scanf( "%d", &entero2 );          /* lee un entero */
    
    suma = entero1 + entero2; /* asigna el total a suma */
    
    printf( "La suma es %d\n", suma ); /* imprime la suma */
    
    return 0; /* indica que el programa terminó con éxito */
    
} /* fin de la función main */
