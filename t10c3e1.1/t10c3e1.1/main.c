//
//  main.c
//  t10c3e1.1
//
//  Created by Vicente Cubells Nonell on 30/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define UNIVERSIDADES 2
#define PROFESORES 5

struct profesor {
    char nombre[30];
    int horas;
};

void llenarMatriz(struct profesor matriz[UNIVERSIDADES][PROFESORES]);
void clasificaProfesor(struct profesor matriz[UNIVERSIDADES][PROFESORES]);
void clasificaUniversidad(struct profesor matriz[UNIVERSIDADES][PROFESORES]);
void universidades50Productivos(struct profesor matriz[UNIVERSIDADES][PROFESORES]);
void quintoProfesor(struct profesor matriz[UNIVERSIDADES][PROFESORES]);

int main(int argc, const char * argv[])
{
    // Declarara la matriz de horas trabajadas
    struct profesor horasTrabajadas[UNIVERSIDADES][PROFESORES];
    
    // Pedir información y llenar la matriz
    llenarMatriz(horasTrabajadas);
    
    // Mostrar nombre y clasificación de los profesores
    clasificaProfesor(horasTrabajadas);
    
    // Mostrar clasificación de las universidades
    clasificaUniversidad(horasTrabajadas);
    
    // Universidades con más del 50% de profesores muy productivos
    universidades50Productivos(horasTrabajadas);
    
    // Identificar si el 5to profesor de cada universidad es remunerado en exceso
    quintoProfesor(horasTrabajadas);
    
    return 0;
}

void llenarMatriz(struct profesor matriz[UNIVERSIDADES][PROFESORES])
{
    for (int u = 0; u < UNIVERSIDADES; ++u) {
        
        printf("Universidad %d\n", u);
        printf("-----------------\n");
        
        for (int p = 0; p < PROFESORES; ++p) {
            
            printf("Entre el nombre del profesor %d-%d: ", u, p);
            scanf("%s", matriz[u][p].nombre);
            
            printf("Entre las horas trabajadas del profesor %d-%d: ", u, p);
            scanf("%d", &matriz[u][p].horas);
            
        }
        
        printf("\n");
    }
}

void clasificaProfesor(struct profesor matriz[UNIVERSIDADES][PROFESORES]){
    
    printf("--- Clasificación de profesores ---\n\n");
    
    for (int u = 0; u < UNIVERSIDADES; ++u) {
        
        printf("Universidad %d\n", u);
        printf("-----------------\n");
        
        for (int p = 0; p < PROFESORES; ++p) {
            if (matriz[u][p].horas > 55) { // Muy productivo
                printf("%-30s\t%5d\t%-25s\n", matriz[u][p].nombre, matriz[u][p].horas, "Muy productivo");
            }
            else if ( matriz[u][p].horas >= 33 && matriz[u][p].horas <= 55) // Satisfactorio
            {
                printf("%-30s\t%5d\t%-25s\n", matriz[u][p].nombre, matriz[u][p].horas, "Satisfactorio");
            }
            else { // Remunerado en exceso
                printf("%-30s\t%5d\t%-25s\n", matriz[u][p].nombre, matriz[u][p].horas, "Remunerado en exceso");
            }
        }
        
        printf("\n");
    }
}

void clasificaUniversidad(struct profesor matriz[UNIVERSIDADES][PROFESORES])
{
    int suma;
    int indice = 0;
    
    printf("--- Clasificación de universidades ---\n\n");
    
    for (int u = 0; u < UNIVERSIDADES; ++u) {
        
        suma = 0;
        
        for (int p = 0; p < PROFESORES; ++p) {
            suma += matriz[u][p].horas;
        }
        
        indice = suma / PROFESORES;
        
        if (indice > 18) {
            printf("Universidad %d\tA\n", u);
        }
        else {
            printf("Universidad %d\tB\n", u);
        }
    }
    
    printf("\n");
}

void universidades50Productivos(struct profesor matriz[UNIVERSIDADES][PROFESORES])
{
    int numeroProfesoresProductivos;
    float porcentaje = 0;
    
    printf("--- Universidades con más del 50%% de profesores productivos ---\n\n");
    
    for (int u = 0; u < UNIVERSIDADES; ++u) {
        
        numeroProfesoresProductivos = 0;
        
        for (int p = 0; p < PROFESORES; ++p) {
            if (matriz[u][p].horas > 55)
            {
                ++numeroProfesoresProductivos;
            }
        }
        
        porcentaje = numeroProfesoresProductivos * 100.0 / PROFESORES;
        
        if (porcentaje > 50) {
            printf("Universidad %d\t%4d\t%5.2f%%\n", u, numeroProfesoresProductivos, porcentaje);
        }
    }
    
    printf("\n");
}

void quintoProfesor(struct profesor matriz[UNIVERSIDADES][PROFESORES])
{
    int profesoresRemuneradosEnExceso = 0;
    
    printf("--- Quinto profesor evaluado ---\n\n");
    
    for (int u = 0; u < UNIVERSIDADES; ++u) {
        if (matriz[u][4].horas < 33 ) {
            ++profesoresRemuneradosEnExceso;
        }
    }
    
    if (profesoresRemuneradosEnExceso >= (UNIVERSIDADES / 2)) {
        printf("Más de la mitad del 5to profesor evaluado está remunerado en exceso\n");
    }
    else {
        printf("Menos de la mitad del 5to profesor evaluado está remunerado en exceso\n");
    }
}

