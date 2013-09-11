//
//  main.c
//  t9c2e2
//
//  Created by Vicente Cubells Nonell on 11/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

float promedio(int a[], int n);
int mediana(int a[], int n);
void ordenaBurbuja(int a[], int n);
void imprime(int a[], int n);

int main(int argc, const char * argv[])
{
    int numeros[N];
    int i;
    
    /* Cambiar la semilla del generador de números aleatorios */
    srand(time(NULL));
    
    /* Inicializar el arreglo */
    for (i = 0; i < N; ++i) {
        numeros[i] = rand() % 100;
    }
    
    imprime(numeros, N);
    
    printf("El promedio es = %.2f \n", promedio(numeros, N));
    
    ordenaBurbuja(numeros, N);
    
    imprime(numeros, N);
    
    printf("La mediana es = %d \n", mediana(numeros, N));
    
    return 0;
}

float promedio(int a[], int n)
{
    int i;
    int suma = 0;
    
    for (i = 0; i < n; ++i) {
        suma += a[i];
    }
    
    return (float)suma / n;
}

int mediana(int a[], int n)
{
    int mitad;
    
    mitad = n / 2;
    
    return a[mitad];
}

void ordenaBurbuja(int a[], int n)
{
    int temp;
    int i, j;
    
    for ( i = 0; i < n; i++)
    {
		for ( j = n; j > i; j--)
		{
			if (a[j-1] > a[j])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
        }
    }
}

void imprime(int a[], int n)
{
    int i;
    
    for (i = 0; i < n; ++i) {
        printf("%3d", a[i]);
    }
    
    printf("\n");
}
