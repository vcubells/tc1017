//
//  main.c
//  t2c1e1
//
//  Created by Vicente Cubells Nonell on 04/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int polinomio(int a, int b, int c, int x);
void entrarValores(int * da, int * db, int * dc, int * dx);

int main(int argc, const char * argv[])
{
    // 1- Definir las variables
    int a;
    int b;
    int c;
    int x;
    int y;
    
    // Pasos del 2 al 9
    entrarValores(&a, &b, &c, &x);
    
    // 10- Resolver el polinomio
    // 11- Guardar el resultado en y
    // y = a * x * x + b * x + c;
    
    y = polinomio(a, b, c, x);
    
    // 12- Mostrar el resultado
    printf("El resultado es y = %d \n", y);
    
    entrarValores(&a, &b, &c, &x);
    y = polinomio(a, b, c, x);
    printf("El resultado es y = %d \n", y);
    
    entrarValores(&a, &b, &c, &x);
    y = polinomio(a, b, c, x);
    printf("El resultado es y = %d \n", y);
    
    
    return 0;
}

int polinomio(int a, int b, int c, int x)
{
    int resultado;
    
    resultado = a * x * x + b * x + c;
    
    return resultado;
}

void entrarValores(int * da, int * db, int * dc, int * dx)
{
    // 2- Obtener el valor de a
    printf("Entre el valor de a: ");
    
    // 3- Guardar el valor de a
    scanf("%d", da);
    
    // 4- Obtener el valor de b
    printf("Entre el valor de b: ");
    
    // 5- Guardar el valor de b
    scanf("%d", db);
    
    // 6- Obtener el valor de c
    printf("Entre el valor de c: ");
    
    // 7- Guardar el valor de c
    scanf("%d", dc);
    
    // 8- Obtener el valor de x
    printf("Entre el valor de x: ");
    
    // 9- Guardar el valor de x
    scanf("%d", dx);
}

