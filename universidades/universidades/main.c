//
//  main.c
//  universidades
//
//  Created by Vicente Cubells Nonell on 11/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define UNIV 10
#define PROF 20

typedef struct {
    char nombre[25];
    int horas;
} profesor;

void generaDatos(profesor m[UNIV][PROF]);
void imprimeDatos(profesor m[UNIV][PROF]);
void clasificacionProfesores(profesor m[UNIV][PROF]);
void clasificacionUniversidad(profesor m[UNIV][PROF]);
void porcentajeUniversidadesProductivas(profesor m[UNIV][PROF]);


int main(int argc, const char * argv[])
{
    profesor bd[UNIV][PROF];
    
    srand(time(NULL));
    
    generaDatos(bd);
    imprimeDatos(bd);
    clasificacionProfesores(bd);
    clasificacionUniversidad(bd);
    porcentajeUniversidadesProductivas(bd);
    
    return 0;
}

void generaDatos(profesor m[UNIV][PROF])
{
    int u, p;
    
    for (u = 0; u < UNIV; ++u) {
        for (p = 0; p < PROF; ++p) {
            sprintf(m[u][p].nombre, "Profesor %d-%d", u, p);
            m[u][p].horas = rand() % 81;
        }
    }
}

void imprimeDatos(profesor m[UNIV][PROF])
{
    int u, p;
    
    for (u = 0; u < UNIV; ++u) {
        printf("\n\n------ Universidad %d ------ \n\n", u);
        for (p = 0; p < PROF; ++p) {
            printf("%-25s\t%3d\n", m[u][p].nombre, m[u][p].horas);
        }
    }
}

void clasificacionProfesores(profesor m[UNIV][PROF])
{
    int u, p;
    char clasificacion[25];
    
    for (u = 0; u < UNIV; ++u) {
        printf("\n\n------ Universidad %d ------ \n\n", u);
        for (p = 0; p < PROF; ++p) {
            
            if (m[u][p].horas > 55)
            {
                strcpy(clasificacion, "Muy productivo");
            }
            else if (m[u][p].horas < 33)
            {
                strcpy(clasificacion, "Remunerado en exceso");
            }
            else
            {
                strcpy(clasificacion, "Satisfactorio");
            }
            
            printf("%-25s\t%-25s\n", m[u][p].nombre, clasificacion);
        }
    }
}

void clasificacionUniversidad(profesor m[UNIV][PROF])
{
    int u, p;
    int suma;
    
    for (u = 0; u < UNIV; ++u) {
        suma = 0;
        for (p = 0; p < PROF; ++p) {
            suma += m[u][p].horas;
        }
        
        if (suma / PROF > 40)
        {
            printf("Universidad %d \t Tipo A\n", u);
        }
        else
        {
            printf("Universidad %d \t Tipo B\n", u);
        }
    }
}

void porcentajeUniversidadesProductivas(profesor m[UNIV][PROF])
{
    int u, p;
    int profesoresProductivos;
    float universidadesProductivas = 0.0;
    
    for (u = 0; u < UNIV; ++u) {
        profesoresProductivos = 0;
        for (p = 0; p < PROF; ++p) {
            
            if (m[u][p].horas > 55)
            {
                profesoresProductivos ++;
            }
        }
        
        if (profesoresProductivos > (PROF / 2))
        {
            universidadesProductivas ++;
        }
    }
    
    printf("Porcentaje de universidades con mas del 50%% de profesores productivos = %5.2f \n ", ((universidadesProductivas / UNIV) * 100));
}