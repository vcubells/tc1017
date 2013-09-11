//
//  main.c
//  t10c2e1
//
//  Created by Vicente Cubells Nonell on 22/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define UNIVERSIDADES 5
#define PROFESORES 10

typedef struct {
    char nombre[30];
    int horas;
    
} profesor;

void llenaMatriz(profesor horas[UNIVERSIDADES][PROFESORES]);
void imprimeMatriz(profesor horas[UNIVERSIDADES][PROFESORES]);
void clasificaProfesores(profesor horas[UNIVERSIDADES][PROFESORES]);
void clasificaUniversidad(profesor horas[UNIVERSIDADES][PROFESORES]);
void universidades50Productivos(profesor horas[UNIVERSIDADES][PROFESORES]);
void quintoProfesorEvaluado(profesor horas[UNIVERSIDADES][PROFESORES]);

int main(int argc, const char * argv[])
{

    profesor horas[UNIVERSIDADES][PROFESORES];
    
    srand(time(NULL));
    
    llenaMatriz(horas);
    imprimeMatriz(horas);
    clasificaProfesores(horas);
    clasificaUniversidad(horas);
    universidades50Productivos(horas);
    quintoProfesorEvaluado(horas);
    
    return 0;
}

/* Genera los valores iniciales d ela matriz */
void llenaMatriz(profesor horas[UNIVERSIDADES][PROFESORES])
{
    profesor temp;
    
    for (int i = 0; i < UNIVERSIDADES; ++i) {
        for (int j = 0; j < PROFESORES; ++j) {
            temp.horas = rand() % 80;
            sprintf(temp.nombre, "Profesor %2d-%2d", i, j );
            horas[i][j] = temp;
        }
    }
}

void imprimeMatriz(profesor horas[UNIVERSIDADES][PROFESORES])
{
    int filas, columnas;
    
    printf("\nMatriz de horas trabajadas\n");
    printf("-----------------------------\n");
    
    /* Imprimir fila de encabezamiento */
    printf("%10s", "Universidad");
    for (columnas = 0; columnas < PROFESORES; ++columnas) {
        printf("\t% 12s P%2d", "", columnas);
    }
    printf("\n");
    
    /* Imprime el resto de las filas */
    for (filas = 0; filas < UNIVERSIDADES; ++filas) {
        printf("%10d", filas);
        for (columnas = 0; columnas < PROFESORES; ++columnas) {
            printf("\t%10s (%2d)", horas[filas][columnas].nombre, horas[filas][columnas].horas);
        }
        /* Cambiar de línea */
        printf("\n");
    }
}

void clasificaProfesores(profesor horas[UNIVERSIDADES][PROFESORES])
{
    int filas, columnas;
    char condicion[30];
    
    printf("\nClasificación de profesores\n");
    printf("-----------------------------\n");
    
    
    
    /* Imprime el resto de las filas */
    for (filas = 0; filas < UNIVERSIDADES; ++filas) {
        printf("Universidad %3d:\n", filas);
        
        for (columnas = 0; columnas < PROFESORES; ++columnas) {
            if (horas[filas][columnas].horas > 55)
                strcpy(condicion, "Muy productivo");
            else if (horas[filas][columnas].horas < 33)
                strcpy(condicion, "Remunerado en exceso");
            else
                strcpy(condicion, "Satisfactorio");
            
            printf("\t- %30s\t(%2d)\t--- %s\n", horas[filas][columnas].nombre, horas[filas][columnas].horas, condicion);
        }
        /* Cambiar de línea */
        printf("\n\n");
    }
}

void clasificaUniversidad(profesor horas[UNIVERSIDADES][PROFESORES])
{
    int filas, columnas;
    int suma, indice;
    
    printf("\nClasificación de universidades\n");
    printf("--------------------------------\n");
    
    
    for (filas = 0; filas < UNIVERSIDADES; ++filas) {

        suma = 0;
        for (columnas = 0; columnas < PROFESORES; ++columnas) {
            
            suma += horas[filas][columnas].horas;
        }
        
        /* Determinar índice de la universidad i */
        indice = suma / PROFESORES;
        
        if (indice > 18)
            printf("Universidad %3d (%3d) --- %c\n", filas, indice, 'A');
        else
            printf("Universidad %3d (%3d) --- %c\n", filas, indice, 'B');
        
        /* Cambiar de línea */
        printf("\n\n");
    }
}

void universidades50Productivos (profesor horas[UNIVERSIDADES][PROFESORES])
{
    int filas, columnas;
    int suma;
    float universidades = 0.0;
    
    printf("\nUniversidades con mas del 50%% de profesores muy productivos\n");
    printf("--------------------------------------------------------------\n");

    for (filas = 0; filas < UNIVERSIDADES; ++filas) {
        suma = 0;
        for (columnas = 0; columnas < PROFESORES; ++columnas) {
            if (horas[filas][columnas].horas > 55)
                ++suma;
                        
        }
        
        if (suma > (PROFESORES / 2) ) {
            printf("Universidad %3d (%3d profesores) \n", filas, suma);
            ++universidades;
        }
        
    }
    
    printf("Porcentaje de universidades = %5.2f", universidades / UNIVERSIDADES * 100);
    
    printf("\n\n");
}


void quintoProfesorEvaluado(profesor horas[UNIVERSIDADES][PROFESORES])
{
    int filas;
    int suma = 0;
    float universidades = 0.0;
    
    printf("\n5to profesor evaluado\n");
    printf("-----------------------\n");
    
    for (filas = 0; filas < UNIVERSIDADES; ++filas) {
        if (horas[filas][5].horas < 33)
                ++suma;
            
    }
        
    if (suma >= (UNIVERSIDADES / 2) )
        printf("Más de la mitad de los 5to profesores evaluados de cada universidad fue Remunerado en exceso \n");
    else
        printf("Menos de la mitad de los 5to profesores evaluados de cada universidad fue Remunerado en exceso \n");
    
    printf("\n\n");
}


