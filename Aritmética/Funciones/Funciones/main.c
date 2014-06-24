//
//  main.c
//  Funciones
//
//  Created by Vicente Cubells Nonell on 16/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <math.h>

/* Prototipo de función */
int suma(int, int);
int resta(int, int);
float divide(float, float);
int multiplica(int, int);


int main(int argc, const char * argv[])
{
    int a, b;
    
    printf("Entre el número 1: ");
    scanf("%d", &a);
    
    printf("Entre el número 2: ");
    scanf("%d", &b);
    
    printf("La suma de %d + %d = %d \n", a, b, suma(a,b));
    printf("La resta de %d - %d = %d \n", a, b, resta(a,b));
    printf("La división de %d / %d = %5.2f \n", a, b, divide(a,b));
    printf("La multiplicación de %d * %d = %d \n", a, b, multiplica(a,b));
    
    printf("%d ^ %d = %f \n", a, b, pow(a,b));
    
    printf("La raíz cuadrada de %d = %f \n", a, sqrt(a));
    
    return 0;
}

/* Implementación de la función de usuario suma
 Parámetros: n1, n2 enteros a sumar
 Regresa: un entero resultante de sumar n1 y n2
 */
int suma(int n1, int n2)
{
    return n1 + n2;
}


/* Implementación de la función de usuario resta
 Parámetros: n1, n2 enteros a restar
 Regresa: un entero resultante de restar n1 - n2
 */
int resta(int n1, int n2)
{
    return n1 - n2;
}


/* Implementación de la función de usuario divide
 Parámetros: n1, n2 enteros a dividir
 Regresa: un flotante resultante de dividir n1 entre n2
 */
float divide(float n1, float n2)
{
    return n1 / n2;
}


/* Implementación de la función de usuario multiplica
 Parámetros: n1, n2 enteros a multiplicar
 Regresa: un entero resultante de multiplicar n1 por n2
 */
int multiplica(int n1, int n2)
{
    return n1 * n2;
}