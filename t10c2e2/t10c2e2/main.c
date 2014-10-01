//
//  main.c
//  t10c2e2
//
//  Created by Vicente Cubells Nonell on 25/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOTELES 10
#define CIUDADES 5

typedef struct {
    char nombre[30];
    float precio;
    int capacidad;
} hotel;

void llenaMatriz(hotel registro[CIUDADES][HOTELES]);
void imprimeMatriz(hotel registro[CIUDADES][HOTELES]);
void obtieneIngresosPorCiudad(hotel registro[CIUDADES][HOTELES]);
void obtieneIngresoPromedio (hotel registro[CIUDADES][HOTELES]);
void obtieneHotelMenosIngresos(hotel registro[CIUDADES][HOTELES]);
void obtieneIngresoPromedioPorCiudad (hotel registro[CIUDADES][HOTELES]);

int main(int argc, const char * argv[])
{
    hotel registro[CIUDADES][HOTELES];
    
    srand((int) time(NULL));
    
    llenaMatriz(registro);
    imprimeMatriz(registro);
    obtieneIngresosPorCiudad(registro);
    obtieneIngresoPromedio (registro);
    obtieneHotelMenosIngresos(registro);
    obtieneIngresoPromedioPorCiudad(registro);
    
    return 0;
}

void llenaMatriz(hotel registro[CIUDADES][HOTELES])
{
    int c, h;
    
    for (c = 0; c < CIUDADES; ++c) {
        for (h = 0; h < HOTELES; ++h) {
            registro[c][h].capacidad = rand() % 150 + 50;
            registro[c][h].precio = rand() % 1500 + 250;
            sprintf(registro[c][h].nombre, "Hotel %d%d", c, h);
        }
    }
}

void imprimeMatriz(hotel registro[CIUDADES][HOTELES])
{
    int c, h;
    
    for (c = 0; c < CIUDADES; ++c) {
        
        printf("Ciudad %d:\n", c);
        printf("%30s\t%9s\t%10s\n", "Nombre del hotel", "Precio", "Capacidad");
        
        for (h = 0; h < HOTELES; ++h) {
            printf("%30s\t%9.2f\t%7d\n", registro[c][h].nombre, registro[c][h].precio, registro[c][h].capacidad);
        }
    }
}

void obtieneIngresosPorCiudad(hotel registro[CIUDADES][HOTELES])
{
    int c, h;
    float ingresos;
    
    printf("\nIngresos por ciudad\n");
    printf("-------------------\n");
    
    for (c = 0; c < CIUDADES; ++c) {
        
        ingresos = 0;
        
        for (h = 0; h < HOTELES; ++h) {
            ingresos += registro[c][h].capacidad * registro[c][h].precio;
        }
        
        printf("Ciudad %d ingresó %12.2f\n", c, ingresos);
    }
}


void obtieneIngresoPromedio(hotel registro[CIUDADES][HOTELES])
{
    int c, h;
    float ingresos;
    
    printf("\nIngresos promedio por hotel en el país:\n");
    printf("-----------------------------------------\n");
    
    ingresos = 0;
    
    for (c = 0; c < CIUDADES; ++c) {

        for (h = 0; h < HOTELES; ++h) {
            ingresos += registro[c][h].capacidad * registro[c][h].precio;
        }
    }
    
    printf("%12.2f\n", ingresos / (HOTELES * CIUDADES));
}

void obtieneHotelMenosIngresos(hotel registro[CIUDADES][HOTELES])
{
    int c, h;
    float menorIngreso, ingresos;
    int hotel, ciudad;
    
    printf("\nHotel con menos ingresos:\n");
    printf("---------------------------\n");
    
    hotel = 0;
    ciudad = 0;
    menorIngreso = registro[0][0].capacidad * registro[0][0].precio;
    
    for (c = 0; c < CIUDADES; ++c) {
        
        for (h = 0; h < HOTELES; ++h) {
            ingresos = registro[c][h].capacidad * registro[c][h].precio;
            
            if(ingresos < menorIngreso)
            {
                menorIngreso = ingresos;
                hotel = h;
                ciudad = c;
            }
        }
    }
    
    printf("%-30s\t%12.2f\n", registro[ciudad][hotel].nombre, menorIngreso);
}

void obtieneIngresoPromedioPorCiudad(hotel registro[CIUDADES][HOTELES])
{
    int c, h;
    float ingresos;
    
    printf("\nIngresos promedio por hotel en cada ciudad\n");
    printf("--------------------------------------------\n");
    
    for (c = 0; c < CIUDADES; ++c) {
        
        ingresos = 0;
        
        for (h = 0; h < HOTELES; ++h) {
            ingresos += registro[c][h].capacidad * registro[c][h].precio;
        }
        
        printf("Ciudad %d ingresó como promedio por hotel %12.2f\n", c, ingresos / HOTELES);
    }
}
