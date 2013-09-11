//
//  main.c
//  2EP_2
//
//  Created by Vicente Cubells Nonell on 11/03/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void histograma(int frecuencia);

int main(int argc, const char * argv[])
{
    int salida1, salida2, salida3, salida4, salida5;
    int entrada1, entrada2, entrada3;
    int salida1T, salida2T, salida3T, salida4T, salida5T;
    int entrada1T, entrada2T, entrada3T;
    
    int carril;
    int cochesPorDia;
    int i;
    int dia;
    
    int totalSalida, totalEntrada;
    
    srand(time(NULL));
    
    salida1T = salida2T = salida3T = salida4T = salida5T = 0;
    entrada1T = entrada2T = entrada3T = 0;
    

    printf("%6s\t%6s\t%6s\t%6s\t%6s\t%6s\t%6s\t%6s\t%6s\n", "Día",
           "S1", "S2", "S3", "S4", "S5",
           "E1", "E2", "E3");
    
    for (dia = 23; dia <= 30; ++dia) {
        
        salida1 = salida2 = salida3 = salida4 = salida5 = 0;
        entrada1 = entrada2 = entrada3 = 0;
        
        cochesPorDia = rand() % 100;
        
        for (i = 0; i < cochesPorDia; ++i) {
            
            carril = rand() % 8 + 1;
            
            switch (carril) {
                case 1:
                    salida1++;
                    break;
                case 2:
                    salida2++;
                    break;
                case 3:
                    salida3++;
                    break;
                case 4:
                    salida4++;
                    break;
                case 5:
                    salida5++;
                    break;
                    
                    /* Para las entrada */
                case 6:
                    entrada1++;
                    break;
                case 7:
                    entrada2++;
                    break;
                case 8:
                    entrada3++;
                    break;
            }
        }
        
        /* Acumular valores diarios */
        salida1T += salida1;
        salida2T += salida2;
        salida3T += salida3;
        salida4T += salida4;
        salida5T += salida5;
        
        entrada1T += entrada1;
        entrada2T += entrada2;
        entrada3T += entrada3;
        
        /* Imprimir reporte del día */
        
        printf("%6d\t%6d\t%6d\t%6d\t%6d\t%6d\t%6d\t%6d\t%6d\n", dia,
               salida1, salida2, salida3, salida4, salida5,
               entrada1, entrada2, entrada3);
        
    }
    
    /* Generar reporte de totales */
    totalSalida = salida1T + salida2T + salida3T + salida4T + salida5T;
    printf("\nTotal de vehículos que salieron: %6d\n", totalSalida);
    
    totalEntrada = entrada1T + entrada2T + entrada3T;
    printf("Total de vehículos que entraron: %6d\n", totalEntrada);
    
    /* Porcentaje de IAVE */
    printf("\nPorcentaje de vehículos de salida que utilizaron IAVE: %6d%%\n",
           (salida4T + salida5T) * 100 / totalSalida);

    printf("Porcentaje de vehículo de entrada que utilizaron IAVE: %6d%%\n",
           entrada3T * 100 / totalEntrada);
    
    /* Histograma */
    printf("\n%3s\t%7s\n", "E/S", "Promedio");
    
    printf("%3s\t%7d", "S1", salida1T / 8);
    histograma(salida1T);
    
    printf("%3s\t%7d", "S2", salida2T / 8);
    histograma(salida2T);
    
    printf("%3s\t%7d", "S3", salida3T / 8);
    histograma(salida3T);
    
    printf("%3s\t%7d", "S4", salida4T / 8);
    histograma(salida4T);
    
    printf("%3s\t%7d", "S5", salida5T / 8);
    histograma(salida5T);
    
    printf("%3s\t%7d", "E1", entrada1T / 8);
    histograma(entrada1T);
    
    printf("%3s\t%7d", "E2", entrada2T / 8);
    histograma(entrada2T);
    
    printf("%3s\t%7d", "E3", entrada3T / 8);
    histograma(entrada3T);
    
    return 0;
}


void histograma(int frecuencia)
{
    int i;
    
    frecuencia /= 8;
    for (i = 0; i < frecuencia; ++i) {
        printf("-");
    }
    
    printf("\n");
}
