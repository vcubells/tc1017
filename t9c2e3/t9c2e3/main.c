//
//  main.c
//  t9c2e3
//
//  Created by Vicente Cubells Nonell on 11/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int busquedaSecuencial(int a[], int n, int valor);
void imprime(int a[], int n);
int busquedaBinaria(int a[], int n, int valor);
void ordenaBurbuja(int a[], int n);

int main(int argc, const char * argv[])
{
    int numeros[N];
    int i;
    int buscar;
    
    /* Cambiar la semilla del generador de números aleatorios */
    srand(time(NULL));
    
    /* Inicializar el arreglo */
    for (i = 0; i < N; ++i) {
        numeros[i] = rand() % 100;
    }
    
    imprime(numeros, N);
    
    printf("Entre el número a buscar [0..99]?: ");
    scanf("%d", &buscar);
    
    /* Búsqueda secuencial */
    if (busquedaSecuencial(numeros, N, buscar)) {
        printf("El número %d SI se encuentra \n", buscar);
    }
    else {
        printf("El número %d NO se encuentra \n", buscar);
    }
    
    ordenaBurbuja(numeros, N);
    
    /* Búsqueda binaria */
    if (busquedaBinaria(numeros, N, buscar)) {
        printf("El número %d SI se encuentra \n", buscar);
    }
    else {
        printf("El número %d NO se encuentra \n", buscar);
    }

    return 0;
}

int busquedaSecuencial(int a[], int n, int valor)
{
	int i = 0;
	int encontrado = 0;
	while (encontrado == 0 && i < N)
	{
		if ( valor == a[i] ) { encontrado = 1; }
		i++;
	}
	return encontrado;
}

void imprime(int a[], int n)
{
    int i;
    
    for (i = 0; i < n; ++i) {
        printf("%3d", a[i]);
    }
    
    printf("\n");
}

int busquedaBinaria(int a[], int n, int valor)
{
	if (n == 0) { return 0; }
	
	int mitad, inf = 0, sup = n - 1;
	
	do {
		mitad = (inf + sup) / 2;
        
		if (valor > a[mitad]) { inf = mitad + 1; }
		else { sup = mitad - 1; }
	}
	while (a[mitad] != valor && inf <= sup);
    
	if (a[mitad] == valor) { return 1; }
	
    return 0;
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
