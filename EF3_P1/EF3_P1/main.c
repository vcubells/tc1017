//
//  main.c
//  EF3_P1
//
//  Created by Vicente Cubells Nonell on 15/05/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define RANGO 101

int menu();
void generaNumeros(int numeros[], int frecuencia[]);
void numerosOrdenados(int numeros[]);
void ordenaNumeros(int numeros[]);
void mediana(int numeros[]);
void numeroMasRepite(int frecuencia[]);
void menores30(int numeros[]);
void mayores70(int numeros[]);
void numeros30y70(int numeros[]);
void generaArchivo(int frecuencia[], FILE *);
void imprimeNumeros(int numeros[]);

int main(int argc, const char * argv[])
{
    int numeros[N];
    int frecuencia[RANGO] = {0};
    int opc = 1;
    
    srand(time(NULL));
    
    generaNumeros(numeros, frecuencia);
    
    while (opc) {
        opc = menu();
        switch (opc) {
                
            case 0:
                printf("Gracias por utilizar la aplicación. Hasta pronto!!!\n");
                break;
                
            case 1:
                numerosOrdenados(numeros);
                break;
                
            case 2:
                mediana(numeros);
                break;
                
            case 3:
                numeroMasRepite(frecuencia);
                break;
                
            case 4:
                menores30(numeros);
                break;
            
            case 5:
                mayores70(numeros);
                break;
                
            case 6:
                numeros30y70(numeros);
                break;
                
            case 7:
                generaArchivo(frecuencia, NULL);
                break;
                
            case 8:
                imprimeNumeros(numeros);
                break;
                
            case 9:
                generaArchivo(frecuencia, stdout);
                break;
                
            default:
                printf("Opción no válida\n");
                break;
        }
    }
    
    return 0;
}

int menu()
{
    int opc;
    
    printf("\
           Opciones: \n\
           ____________\n\
           1. Números ordenados ascendentemente\n\
           2. La mediana\n\
           3. Número que más se repite\n\
           4. Los menores que 30\n\
           5. Los mayores que 70\n\
           6. Entre 30 y 70\n\
           7. Generar archivo con histograma\n\
           8. Mostrar números\n\
           9. Mostrar histograma\n\
           0. Terminar\n\
           \n\
           Seleccione su opción: ");
    scanf("%d", &opc);
    
    return opc;
}

void generaNumeros(int numeros[], int frecuencia[])
{
    int i, n;
    
    for (i = 0; i < N; ++i) {
        n = rand() % (RANGO - 1) + 1;
        numeros[i] = n;
        frecuencia[n]++;
    }
    
    printf("\n\n");
}

void numerosOrdenados(int numeros[])
{
    printf("--- Números ordenados ascendentemente ---\n\n");
    
    ordenaNumeros(numeros);
    imprimeNumeros(numeros);
}

void ordenaNumeros(int numeros[])
{
    int i, j, temp;
    
    for (i = 0; i < N; ++i) {
        for (j = N - 1; j > i; --j) {
            if (numeros[j-1] > numeros[j])
            {
                temp = numeros[j-1];
                numeros[j-1] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

void mediana(int numeros[])
{
    ordenaNumeros(numeros);
    printf("La mediana es: %d\n\n", numeros[N/2]);
}

void numeroMasRepite(int frecuencia[])
{
    int i, n;
    int mayor = 0;
    
    for (i = 1; i < RANGO; ++i) {
        if (frecuencia[i] > mayor) {
            n = i;
            mayor = frecuencia[i];
        }
    }
    
    printf("El número que más se repite es el %d con %d veces", n, mayor);
    
    printf("\n\n");
}

void menores30(int numeros[])
{
    int i;
    
    printf("--- Números menores que 30 ---\n\n");
    
    for (i = 0; i < N; ++i) {
        if (numeros[i] < 30) {
            printf("%5d", numeros[i]);
        }
    }
    
    printf("\n\n");
}

void mayores70(int numeros[])
{
    int i;

    printf("--- Números mayores que 70 ---\n\n");
    
    for (i = 0; i < N; ++i) {
        if (numeros[i] > 70) {
            printf("%5d", numeros[i]);
        }
    }
    
    printf("\n\n");

}

void numeros30y70(int numeros[])
{
    int i;
    
    printf("--- Números entre 30 y 70 ---\n\n");
    
    for (i = 0; i < N; ++i) {
        if (numeros[i] > 30 && numeros[i] < 70) {
            printf("%5d", numeros[i]);
        }
    }
    
    printf("\n\n");
}

void generaArchivo(int frecuencia[], FILE * out)
{
    FILE * fd;
    int i, j;
    
    if (out == NULL)
    {
        fd = fopen("/Users/vcubells/Desktop/numeros.txt", "w");
    }
    else {
        fd = out;
    }
    
    if ( fd == NULL) {
        printf("Error al generar la salida");
    }
    else {
        fprintf(fd, "%5s\t%5s\n\n", "Num.", "Frec.");
        
        for (i = 1; i < RANGO; ++i) {
            fprintf(fd, "%5d\t%5d\t", i, frecuencia[i]);
            
            for (j = 1; j <= frecuencia[i]; ++j) {
                fprintf(fd, "-");
            }
            
            fprintf(fd, "\n");
        }
    }
    
    if (out == NULL)
        fclose(fd);
}

void imprimeNumeros(int numeros[])
{
    int i;
    
    for (i = 0; i < N; ++i) {
        printf("%5d", numeros[i]);
    }
    
    printf("\n\n");
}