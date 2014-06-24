//
//  main.c
//  t3c1e1-1
//
//  Created by Vicente Cubells Nonell on 05/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

void leerValores(int * n1, int * n2);
int mayor(int n1, int n2);
int menor(int n1, int n2);
int igual(int n1, int n2);

int main(int argc, const char * argv[])
{
    // Declaraciones de las variables
    int numero1;
    int numero2;
    
    leerValores(&numero1, &numero2);
    
    // 5- Comparar los números para determinar el mayor
    int numeroMayor = mayor(numero1, numero2);
    
    // 6- Mostrar el mayor de los números
    printf("El mayor es %d \n", numeroMayor);
    
    // Determinar el menor
    int numeroMenor = menor(numero1, numero2);
    printf("El menor es %d \n", numeroMenor);
    
    // Determinar si son iguales
    int sonIguales = igual(numero1, numero2);
    
    if (sonIguales == 1) {
        printf("El número %d es igual al número %d \n", numero1, numero2);
    }
    else {
        printf("Son diferentes \n");
    }
    
    return 0;
}

void leerValores(int * n1, int * n2)
{
    // 1- Entrar el valor de número 1
    printf("Entra el valor del primer número: ");
    
    // 2- Guardar el valor de número 1 en una variable
    scanf("%d", n1);
    
    // 3- Entrar el valor de número 2
    printf("Entra el valor del segundo número: ");
    
    // 4- Guardar el valor de número 2 en una variable
    scanf("%d", n2);
}

int mayor(int n1, int n2)
{
    if (n1 > n2) {
        return n1;
    } else {
        return n2;
    }
}

int menor(int n1, int n2)
{
    if (n1 < n2) {
        return n1;
    } else {
        return n2;
    }
}

int igual(int n1, int n2)
{
    if (n1 == n2) {
        return 1;
    } else {
        return 0;
    }
}


