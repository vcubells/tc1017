//
//  main.c
//  contenedores
//
//  Created by Vicente Cubells Nonell on 25/02/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MC 3

int darAlta(char categoria, int entran);
int darBaja(char categoria, int entran);

void total(int enA, int enB, int enC);
void entranSalen(int enA, int enB, int enC, int saA, int saB, int saC);

int main(int argc, const char * argv[])
{
    int entranA, entranB, entranC;
    int salenA, salenB, salenC;
    int opc;
    int categoria;
    
    entranA = entranB = entranC = 0;
    salenA = salenB = salenC = 0;
    
    /* Cambiar la semilla del generador de números aleatorios */
    srand(time(NULL));
    
    /* Menú de opciones */
    do {
        printf("1-Alta contenedor \n 2-Baja contenedor \n 3-Terminar \n");
        printf("Seleccione su opción: ");
        scanf("%d", &opc);
        
        switch (opc) {
            case 1:
                /* Dar de alta */
                
                /* Obtener categoría a partir de un número aleatorio */
                categoria = rand() % 3;
                
                switch (categoria) {
                    case 0:
                        /* Categoría A */
                        
                        entranA = darAlta('A', entranA, salenA);
                        
                        break;
                        
                    case 1:
                        /* Categoría B */
                        
                        entranB = darAlta('B', entranB, salenB);

                        break;
                        
                    case 2:
                        /* Categoría C */
                        
                        entranC = darAlta('C', entranC, salenC);

                        break;
                }
                
                break;
                
            case 2:
                /* Dar de baja */
                
                /* Obtener categoría a partir de un número aleatorio */
                categoria = rand() % 3;
                
                switch (categoria) {
                    case 0:
                        /* Categoría A */
                        
                        salenA = darBaja('A', entranA, salenA);
                        
                        break;
                        
                    case 1:
                        /* Categoría B */
                        
                        salenB = darBaja('B', entranB, salenB);
                        
                        break;
                        
                    case 2:
                        /* Categoría C */
                        
                        salenC = darBaja('C', entranC, salenC);
                        
                        break;
                }
                
                break;
            case 3:
                /* Salir */
                printf("Gracias por utilizar este programa \n");
                break;
            default:
                /* Opción no válida */
                printf("Seleccione una opción correcta \n");
                break;
        }
        
    }
    while (opc != 3);
    
    /* Imprimir los reportes */
    total(entranA, entranB, entranC);
    entranSalen(entranA, entranB, entranC, salenA, salenB, salenC);
    
    return 0;
}

int darAlta(char categoria, int entran, int salen)
{
    if ((entran - salen) < MC) {
        ++entran;
    }
    else
    {
        printf("La categoría %c ya está llena \n", categoria);
    }
    
    return entran;
}

int darBaja(char categoria, int entran, int salen)
{
    if ((entran - salen) > 0) {
        ++salen;
    }
    else
    {
        printf("La categoría %c está vacía\n", categoria);
    }
    
    return salen;
}

void total(int enA, int enB, int enC)
{
    printf("Total de contenedores de categoría A = %d \n", enA);
    printf("Total de contenedores de categoría B = %d \n", enB);
    printf("Total de contenedores de categoría C = %d \n", enB);
}

void entranSalen(int enA, int enB, int enC, int saA, int saB, int saC)
{
    printf("Entraron %d contenedores y salieron %d de categoría A = %d \n", enA, saA);
    printf("Entraron %d contenedores y salieron %d de categoría B = %d \n", enB, saB);
    printf("Entraron %d contenedores y salieron %d de categoría C = %d \n", enC, saC);
}



