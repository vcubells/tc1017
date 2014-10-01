//
//  main.c
//  matrices_hotelEJ2
//
//  Created by michelle kalach on 6/30/14.
//  Copyright (c) 2014 Michelle Kalach. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define HOTELES 2
#define CIUDADES 4

struct ingreso
{
    char hotel[30];
    char ciudad[30];
    float precio;
    int capacidad;
};

void llenarMatriz(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES]);
void imprimeMatriz(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES]);
void ingresosPorCiudad(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES]);
void ingresosPromedioPorHotel(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES]);
void hotelMenosIngreso(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES]);

int main(int argc, const char * argv[])
{
    
    //declarar variables de matriz ( ingreso por ciudad)
    struct ingreso ingresoOlimpiada [CIUDADES][HOTELES];
    
    //CANTIDAD DIARIO DE INGRESOS
    llenarMatriz(ingresoOlimpiada);
    
    //imprimir matriz
    imprimeMatriz(ingresoOlimpiada);
    
    //Obtener ingresos por ciudad
    ingresosPorCiudad(ingresoOlimpiada);
    
    //Obtener ingresos promedio por hotel
    ingresosPromedioPorHotel(ingresoOlimpiada);
    
    //Obtener el hotel con menor ingreso
    hotelMenosIngreso(ingresoOlimpiada);
    
    return 0;
}


void llenarMatriz(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES])
{
    char ciudad[30];
    
    // Recorre todas las ciudades
    for (int c = 0; c < CIUDADES; c++)
    {
        printf("Entre el nombre de la ciudad: \n");
        scanf("%s", ciudad);
        
        // Recorre todos los hoteles de una ciudad
        for (int h = 0; h < HOTELES; h++)
        {
            strcpy(ingresoOlimpiada[c][h].ciudad, ciudad);
            
            printf("Entre el nombre del hotel:\n ");
            scanf("%s", ingresoOlimpiada[c][h].hotel);
            
            printf("Entre el precio del hotel:\n");
            scanf("%f", &ingresoOlimpiada[c][h].precio);
            
            printf("Entre la capacidad del hotel:\n");
            scanf("%d", &ingresoOlimpiada[c][h].capacidad);
            
        }
    }
    
    printf("\n");
}

void imprimeMatriz(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES])
{
    
    printf("\n------- Información de los hoteles --------- \n\n");
    
    // Visualizar encabezamiento de las columnas
    for (int h = 0; h < HOTELES; ++h) {
        printf("%-30s(%-7s, %-4s)\t", "Hotel", "Precio", "Cap.");
    }
    
    printf("\n");
    
    for (int c = 0; c < CIUDADES; ++c) {
        
        // Imprimir el nombre de la ciudad
        printf("--- Ciudad: %s\n", ingresoOlimpiada[c][0].ciudad);
        
        for (int h = 0; h < HOTELES; ++h) {
            //Mostrar cada celda de la matriz
            printf("%-30s(%7.2f, %4d)\t",
                   ingresoOlimpiada[c][h].hotel,
                   ingresoOlimpiada[c][h].precio,
                   ingresoOlimpiada[c][h].capacidad);
            
        }
        
        printf("\n");
    }
}

void ingresosPorCiudad(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES])
{
    float suma;
    
    printf("\n------- Ingresos por ciudad --------- \n\n");
    
    printf("%-30s\t%-10s\n", "Ciudad", "Ingreso");

    for (int c = 0; c < CIUDADES; ++c) {
        
        suma = 0;
        
        for (int h = 0; h < HOTELES; ++h) {
            suma += ingresoOlimpiada[c][h].capacidad * ingresoOlimpiada[c][h].precio;
        }
        
        printf("%-30s\t%10.2f\n", ingresoOlimpiada[c][0].ciudad, suma);
    }
}

void ingresosPromedioPorHotel(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES])
{
    float suma = 0;
    
    printf("\n------- Ingresos promedio por hotel  --------- \n\n");
    
    for (int c = 0; c < CIUDADES; ++c) {
        
        for (int h = 0; h < HOTELES; ++h) {
            suma += ingresoOlimpiada[c][h].capacidad * ingresoOlimpiada[c][h].precio;
        }
    }
    
    float promedio = suma / (HOTELES * CIUDADES);
    
    printf("El ingreso promedio por hotel en el país fue de %.2f\n", promedio);
}

void hotelMenosIngreso(struct ingreso ingresoOlimpiada [CIUDADES][HOTELES])
{
    int ciudadMenor = 0;
    int hotelMenor = 0;
    
    float ingresoAux;
    
    float menorIngreso = 1000000000;
    
    printf("\n------- Hotel con menor ingreso  --------- \n\n");

    for (int c = 0; c < CIUDADES; ++c) {
        for (int h = 0; h < HOTELES; ++h) {
            
            ingresoAux = ingresoOlimpiada[c][h].precio * ingresoOlimpiada[c][h].capacidad;
            
            if ( ingresoAux < menorIngreso ) {
                ciudadMenor = c;
                hotelMenor = h;
                menorIngreso = ingresoAux;
            }
        }
    }
    
    printf("El hotel %s ubicado en la ciudad %s obtuvo los menores ingresos equivalentes a %.2f\n",
           ingresoOlimpiada[ciudadMenor][hotelMenor].hotel,
           ingresoOlimpiada[ciudadMenor][hotelMenor].ciudad,
           menorIngreso);
}

