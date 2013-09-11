//
//  main.c
//  AlumnosMaterias
//
//  Created by Vicente Cubells Nonell on 08/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define E 10
#define M 6

void imprimeMatriz(float m[E][M]);
void promedioPorEstudiante(float m[E][M]);
void promedioGeneral(float m[E][M]);
void calificacionMasAlta(float m[E][M]);
void calificacionMasBaja(float m[E][M]);

int main(int argc, const char * argv[])
{
    int e, m;
    
    float calificaciones[E][M] = {0};
    
    /* Cambiar la semilla del generador de números aleatorios */
    srand(time(NULL));
    
    /* Inicializar la matriz */
    for (e = 0; e < E; ++e) {
        for (m = 0; m < M; ++m) {
            calificaciones[e][m] = (rand() % 100) * 1.0;
        }
    }

    imprimeMatriz(calificaciones);
    promedioPorEstudiante(calificaciones);
    promedioGeneral(calificaciones);
    calificacionMasAlta(calificaciones);
    calificacionMasBaja(calificaciones);
    
    return 0;
}

void imprimeMatriz(float matriz[E][M])
{
    int e,m;
    
    for (e = 0; e < E; ++e) {
        for (m = 0; m < M; ++m) {
            printf("%7.2f", matriz[e][m]);
        }
        
        printf("\n");
    }
}

void promedioPorEstudiante(float matriz[E][M])
{
    int e,m;
    float suma;
    
    for (e = 0; e < E; ++e) {
        
        suma = 0; /* Inicializar suma cada vez que se cambia de estudiante */
        
        /* Sumar las calificaciones de un estudiante */
        for (m = 0; m < M; ++m) {
            suma += matriz[e][m];
        }
        
        /* Calcular e imprimir el promedio de un estudiante */
        printf("E%d = %7.2f\n", e, suma / M);
        
    }
}

void promedioGeneral(float matriz[E][M])
{
    int e,m;
    float suma;
    
    suma = 0; /* Inicializar suma una sola vez */
    
    /* Sumar las calificaciones de todos estudiante */
    for (e = 0; e < E; ++e) {
        for (m = 0; m < M; ++m) {
            suma += matriz[e][m];
        }  
    }
    
    /* Calcular e imprimir el promedio general */
    printf("Promedio general = %7.2f\n",  suma / (M * E));
}

void calificacionMasAlta(float matriz[E][M])
{
    float masAlta = 0.0;
    
    int estudiante, materia;
    
    int e, m;
    
    for (e = 0; e < E; ++e) {
        for (m = 0; m < M; ++m) {
            if (matriz[e][m] > masAlta)
            {
                masAlta = matriz[e][m];
                estudiante = e;
                materia = m;
            }
        }
    }
    
    printf("Calificación más alta es %5.2f obtenida por estudiante %d en la materia %d \n", masAlta, estudiante, materia);
}


void calificacionMasBaja(float matriz[E][M])
{
    float masBaja = 200.0;
    
    int estudiante, materia;
    
    int e, m;
    
    for (e = 0; e < E; ++e) {
        for (m = 0; m < M; ++m) {
            if (matriz[e][m] < masBaja)
            {
                masBaja = matriz[e][m];
                estudiante = e;
                materia = m;
            }
        }
    }
    
    printf("Calificación más baja es %5.2f obtenida por estudiante %d en la materia %d \n", masBaja, estudiante, materia);
}

