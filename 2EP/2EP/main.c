//
//  main.c
//  2EP
//
//  Created by Vicente Cubells Nonell on 01/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void grafica(int c, char * categ);

int main(int argc, const char * argv[])
{
    int es, operacion, precio;
    int i;
    int oferta_in, asequible_in, normal_in, caro_in;
    int oferta_out, asequible_out, normal_out, caro_out;
    int dia;
    int toferta_in, tasequible_in, tnormal_in, tcaro_in;
    int toferta_out, tasequible_out, tnormal_out, tcaro_out;
    
    toferta_in = tasequible_in = tnormal_in = tcaro_in = 0;
    toferta_out = tasequible_out = tnormal_out = tcaro_out = 0;
    
    srand(time(NULL));
    
    // Generalizar para el mes
    for (dia = 30; dia > 0; --dia) {
        
        oferta_in = asequible_in = normal_in = caro_in = 0;
        oferta_out = asequible_out = normal_out = caro_out = 0;
        
        // Generar cantidad de operaciones en el día
        es = rand() % 300;
        
        for (i = 0; i < es; ++i) {
            operacion = rand() % 2; // Generar entrada (1) o salida (0)
            
            precio = rand() % 800 - 200;
            
            switch (operacion) {
                case 1: // Entrada
                    if (precio < 0)
                        oferta_in++;
                    else if (precio > 0 && precio < 100)
                        asequible_in++;
                    else if (precio >= 100 && precio < 300)
                        normal_in++;
                    else
                        caro_in++;
                        break;
                    
                case 0: // Salida
                    if (precio < 0)
                        if ((toferta_in - toferta_out)  > 0) oferta_out++;
                        else if (precio> 0 && precio < 100)
                            if ((tasequible_in - tasequible_out) > 0) asequible_out++;
                            else if (precio >= 100 && precio < 300)
                                if ((tnormal_in - tnormal_out) > 0) normal_out++;
                                else
                                    if ((tcaro_in - tcaro_out) > 0) caro_out++;
                                        break;
            }
        }
        
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%4d In:%4d / Out: %4d \t In:%4d / Out: %4d \t In:%4d / Out: %4d \t In:%4d / Out: %4d\n", dia, oferta_in, oferta_out, asequible_in, asequible_out, normal_in, normal_out, caro_in, caro_out);
        
        // Acumular en los totales
        toferta_in += oferta_in;
        toferta_out += oferta_out;
        tasequible_in += asequible_in;
        tasequible_out += asequible_out;
        tnormal_in += normal_in;
        tnormal_out += normal_out;
        tcaro_in += caro_in;
        tcaro_out += caro_out;
        
    } // Aquí termina el mes
    
    // Fila de totales
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Total In:%4d / Out: %4d \t In:%4d / Out: %4d \t In:%4d / Out: %4d \t In:%4d / Out: %4d\n", toferta_in, toferta_out, tasequible_in, tasequible_out, tnormal_in, tnormal_out, tcaro_in, tcaro_out);
    
    //Fila de remanentes
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Total %10d \t %10d \t %10d \t %10d\n", toferta_in-toferta_out, tasequible_in-tasequible_out, tnormal_in-tnormal_out, tcaro_in-tcaro_out);
    
    // Generar la gráfica
    if (toferta_in - toferta_out > 0) grafica(toferta_in - toferta_out, "Oferta");
    if (tasequible_in-tasequible_out > 0) grafica(tasequible_in-tasequible_out, "Asequible");
    if (tnormal_in-tnormal_out > 0) grafica(tnormal_in-tnormal_out, "Normal");
    if (tcaro_in-tcaro_out > 0) grafica(tcaro_in-tcaro_out, "Caro");
    
    return 0;
}

void grafica(int c, char * categ)
{
    int i;
    int temp;
    
    temp = c;
    
    if (c > 100) {
        c *= .3;
    }
    
    printf("\n\n %-10s", categ);
    
    for (i = 0; i < c; ++i) {
        printf(" *");
    }
    
    printf(" (%d) \n", temp);
    
}

