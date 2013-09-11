//
//  main.c
//  3EP
//
//  Created by Vicente Cubells Nonell on 05/11/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINIMO 50000
#define CARRERAS 10
#define ASIG 6
#define PAGOPORUNIDAD 1500

typedef struct {
    char nombre[30];
    int inscritos;
    int codigo;
    int unidades;
    
} asignatura;

void generarRegistro(asignatura registro[CARRERAS][ASIG]);
void imprimirRegistro(asignatura registro[CARRERAS][ASIG]);
void asignaturaMayorMonto(asignatura registro[CARRERAS][ASIG]);
void porcentajeAsignaturasSinMinimo(asignatura registro[CARRERAS][ASIG]);

int main(int argc, const char * argv[])
{
    asignatura registro[CARRERAS][ASIG];
    
    srand(time(NULL));
    
    generarRegistro(registro);
    imprimirRegistro(registro);
    asignaturaMayorMonto(registro);
    porcentajeAsignaturasSinMinimo(registro);
    
    return 0;
}


void generarRegistro(asignatura registro[CARRERAS][ASIG])
{
    int c, a;
    for (c = 0; c < CARRERAS; ++c) {
        for (a = 0; a < ASIG; ++a) {
            registro[c][a].codigo = a + c;
            registro[c][a].inscritos = rand() % 31;
            sprintf(registro[c][a].nombre, "Asignatura %d-%d", c, a);
            registro[c][a].unidades = rand() % 12 + 1;
        }
    }
}

void imprimirRegistro(asignatura registro[CARRERAS][ASIG])
{
    int c, a;
    int diferencia = 0;
    int monto;
    printf("%30s\t%8s\t%8s\t%8s\t%8s\n", "Asignatura", "Código", "Unidades", "Inscritos", "Diferencia");
    for (c = 0; c < CARRERAS; ++c) {
        printf("Carrera %d\n", c);
        for (a = 0; a < ASIG; ++a) {
            monto = registro[c][a].inscritos * registro[c][a].unidades * PAGOPORUNIDAD;
            diferencia = 0;
            if (monto < MINIMO)
            {
                if (registro[c][a].inscritos == 0)
                    diferencia = MINIMO - monto;
                else
                    diferencia = (MINIMO - monto) / registro[c][a].inscritos;
            }
            
            printf("%30s\t%8d\t%8d\t%8d\t%8d\n",
                   registro[c][a].nombre,
                   registro[c][a].codigo,
                   registro[c][a].unidades,
                   registro[c][a].inscritos,
                   diferencia);             
        }
    }
}

void asignaturaMayorMonto(asignatura registro[CARRERAS][ASIG])
{
    int c, a;
    int mayor = 0;
    int monto = 0;
    int temp;
    
    for (c = 0; c < CARRERAS; ++c) {
        temp = registro[c][0].inscritos * registro[c][0].unidades * PAGOPORUNIDAD;
        mayor = 0;
        for (a = 1; a < ASIG; ++a) {
            monto = registro[c][a].inscritos * registro[c][a].unidades * PAGOPORUNIDAD;
            
            if (monto > temp)
            {
                temp = monto;
                mayor = a;
            }
        }
        
        printf("Carrera %d: Materia con mayor monto es %s con %d\n",
               c,
               registro[c][mayor].nombre,
               temp);
    }
}

void porcentajeAsignaturasSinMinimo(asignatura registro[CARRERAS][ASIG])
{
    int c, a;
    int sinminimo = 0;
    int monto;
    
    for (c = 0; c < CARRERAS; ++c) {
        for (a = 0; a < ASIG; ++a) {
            monto = registro[c][a].inscritos * registro[c][a].unidades * PAGOPORUNIDAD;
            if (monto < MINIMO)
            {
                sinminimo++;
            }
        }
    }
    
    /* Porcentaje */
    printf("Porcentaje de materias que no cubren el mínimo = %5.2f\n",
           ((float)sinminimo / (CARRERAS * ASIG)) * 100 );
}
