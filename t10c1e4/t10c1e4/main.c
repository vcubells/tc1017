//
//  main.c
//  t10c1e4
//
//  Created by Vicente Cubells Nonell on 18/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define E 8
#define M 6

void obtienePromedioIndividual(int calif[E][M]);
void obtienePromedioGeneral(int calif[E][M]);
void obtieneCalificacionAlta(int calif[E][M]);
void obtieneCalificacionBaja(int calif[E][M]);
void imprimeMatriz(int calif[E][M]);

int main(int argc, const char * argv[])
{
    int filas, columnas;
    int registro[E][M];
    
    srand(time(NULL));
    
    /* Inicializar la matriz */
    for (filas = 0; filas < E; ++filas) {
        for (columnas = 0; columnas < M; ++columnas) {
            registro[filas][columnas] = rand() % 40 + 60;
        }
    }
    
    /* Visualizar la matriz */
    imprimeMatriz(registro);
    
    /* Promedio de cada estudiante */
    obtienePromedioIndividual(registro);
    
    /* Promedio total */
    obtienePromedioGeneral(registro);
    
    /* Estudiante con la calificación mas alta */
    obtieneCalificacionAlta(registro);
    
    /* Estudiante con la calificación mas baja */
    obtieneCalificacionBaja(registro);

    return 0;
}

void obtienePromedioIndividual(int calif[E][M])
{
    int filas, columnas;
    float suma;
    
    printf("\nPromedio individual de los estudiantes\n");
    printf("--------------------------------------\n");
    
    for (filas = 0; filas < E; ++filas) {
        suma = 0;
        for (columnas = 0; columnas < M; ++columnas) {
            suma += calif[filas][columnas];
        }
        
        printf("El promedio del estudiante %2d = %5.2f \n", filas, suma/M);
    }
}

void obtienePromedioGeneral(int calif[E][M])
{
    int filas, columnas;
    float suma;
    float suma_promedios = 0;
    
    printf("\nPromedio general del grupo\n");
    printf("--------------------------\n");
    
    for (filas = 0; filas < E; ++filas) {
        suma = 0;
        for (columnas = 0; columnas < M; ++columnas) {
            suma += calif[filas][columnas];
        }
        
        suma_promedios += (suma / M);
    }
    
    printf("El promedio general del grupo = %5.2f \n", suma_promedios/E);
}

void obtieneCalificacionAlta(int calif[E][M])
{
    int filas, columnas;
    int estudiante, calificacion, materia;
    
    printf("\nEstudiante con calificación mas alta\n");
    printf("--------------------------------------\n");
    
    /* Asumir que la calificación mas alta es la primera */
    estudiante = 0;
    calificacion = calif[0][0];
    materia = 0;
    
    for (filas = 0; filas < E; ++filas) {
        for (columnas = 0; columnas < M; ++columnas) {
            if (calif[filas][columnas] > calificacion)
            {
                calificacion = calif[filas][columnas];
                estudiante = filas;
                materia = columnas;
            }
        }
    }
    
    printf("Estudiante %2d ( %3d en materia %2d ) \n", estudiante, calificacion, materia);
}

void obtieneCalificacionBaja(int calif[E][M])
{
    int filas, columnas;
    int estudiante, calificacion;
    
    printf("\nEstudiante con calificación mas baja\n");
    printf("--------------------------------------\n");
    
    /* Asumir que la calificación mas baja es la primera */
    estudiante = 0;
    calificacion = calif[0][0];
    for (filas = 0; filas < E; ++filas) {
        for (columnas = 0; columnas < M; ++columnas) {
            if (calif[filas][columnas] < calificacion)
            {
                calificacion = calif[filas][columnas];
                estudiante = filas;
            }
        }
    }
    
    printf("Estudiante %2d ( %3d ) \n", estudiante, calificacion);
}

void imprimeMatriz(int calif[E][M])
{
    int filas, columnas;
    
    printf("\nMatriz de calificaciones\n");
    printf("--------------------------\n");
    
    /* Imprimir fila de encabezamiento */
    printf("%10s", "Estudiante");
    for (columnas = 0; columnas < M; ++columnas) {
        printf("\tM%d", columnas);
    }
    printf("\n");
    
    /* Imprime el resto de las filas */
    for (filas = 0; filas < E; ++filas) {
        printf("%10d", filas);
        for (columnas = 0; columnas < M; ++columnas) {
            printf("\t%2d", calif[filas][columnas]);
        }
        /* Cambiar de línea */
        printf("\n");
    }
}
