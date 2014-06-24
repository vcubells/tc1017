//
//  main.c
//  ejercicio10_estacionporura
//
//  Created by fernanda diez on 6/11/14.
//  Copyright (c) 2014 Fernanda Diez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
# define MAX 5

char contenedormasusado(int totalA,int totalB, int totalC);

int main(int argc, const char * argv[])
{
    
    int contenedor;
    int opcion;
    int movimiento;
    int entradaA,entradaB,entradaC,salidaA,salidaB,salidaC;
    int reloj;
    int actualA,actualB,actualC;
    int maximo;
    int totalA,totalB,totalC;
    
    int entradaAmensual,entradaBmensual,entradaCmensual;
    int salidaAmensual,salidaBmensual,salidaCmensual;
    
    reloj=1;
    
    movimiento=actualA=actualB=actualC=0;
    totalA=totalB=totalC=0;
    
    entradaAmensual = entradaBmensual = entradaCmensual = 0;
    salidaAmensual = salidaBmensual = salidaCmensual = 0;
    
    srand((int)time(NULL));
    printf("Entre el número máximo de contendores: \n");
    scanf("%d",&maximo);
    
    /* Mostrar el título de cada columna */
    printf("========================================================\n");
    
    printf("%3s\t|%3s\t|%3s\t|%3s\t|%3s\t|%3s\t|%3s\t|%c\n", "Día", "E-A", "S-A", "E-B", "S-B", "E-C", "S-C", '+');
    
    printf("========================================================\n");
    /* Ciclo de 31 dias */
    for (int i = 1; i <= 31; ++i) {

        /* Inicializar los contadores diarios */
        entradaA=entradaB=entradaC=salidaA=salidaB=salidaC=0;
    

        /* comienza cada día */
        do
        {
//            printf("Se ha acabado el día 0.-Si 1.-No \n");
//            scanf("%d",&opcion);
            
            opcion = rand() % 2;
            
            contenedor=rand()%3 + 1;
            switch(contenedor)//1.a 2.b 3.c
            {
                case 1://contenedor a
                    movimiento=rand()%2 + 1; //1. entra 2.sale
                    if (movimiento==1)
                    {
                        if(actualA==maximo){
                            
                            //printf(" No se puede ingresar en la categoría A porque ya alcanzó el máximo de contenedores \n");
                        }
                        else{
                            ++entradaA;
                            ++totalA;
                            ++actualA;
                        }
                        
                    }
                    else if (movimiento ==2)
                    {
                        if(actualA==0)
                        {
                            //printf("La pila de la categoría A está vacía \n");
                        }
                        else{
                            ++salidaA;
                            --actualA;
                            
                        }
                    }
                    
                    
                    
                    break;
                case 2: //contendor b
                    movimiento=rand()%2 + 1; //1. entra 2.sale
                    if (movimiento==1)
                    {
                        if(actualB==maximo)
                        {
                            //printf(" No se puede ingresar en la categoría B porque ya alcanzó el máximo de contenedores \n");
                        }
                        else{
                            ++entradaB;
                            ++totalB;
                            ++actualB;
                        }
                    }
                    else if (movimiento ==2)
                    {
                        if(actualB==0)
                        {
                            //printf("La pila de la categoría B está vacía \n");
                        }
                        else{
                            ++salidaB;
                            --actualB;
                            
                        }
                    }
                    
                    
                case 3:
                    movimiento=rand()%2 + 1; //1. entra 2.sale
                    if (movimiento==1)
                    {
                        if(actualC==maximo)
                        {
                            //printf(" No se puede ingresar en la categoría C porque ya alcanzó el máximo de contenedores \n");
                        }
                        else{
                            ++entradaC;
                            ++totalC;
                            ++actualC;
                        }
                    }
                    else if (movimiento ==2)
                    {
                        if(actualC==0)
                        {
                            //printf("La pila de la categoría A está vacía \n");
                        }
                        else{
                            ++salidaC;
                            --actualC;
                        }
                    }
                    
            }
        }
        
        while(opcion!=0);
        //print cosas
        
        char masUsado = contenedormasusado(totalA,totalB,totalC);
        
        printf("%3d\t|%3d\t|%3d\t|%3d\t|%3d\t|%3d\t|%3d\t|%c\n", i, entradaA, salidaA, entradaB, salidaB, entradaC, salidaC, masUsado);
      
        printf("________________________________________________________\n");
        
        
        /* Acumular contadores mensuales */
        entradaAmensual += entradaA;
        entradaBmensual += entradaB;
        entradaCmensual += entradaC;
        salidaAmensual += salidaA;
        salidaBmensual += salidaB;
        salidaCmensual += salidaC;
        
    } // Fin del for
    
    /* Mostrar resultados del mes */
    
    char masUsadoMes = contenedormasusado(entradaAmensual,entradaBmensual,entradaCmensual);
    
    printf("%3s\t|%3d\t|%3d\t|%3d\t|%3d\t|%3d\t|%3d\t|%c\n", "Mes", entradaAmensual, salidaAmensual, entradaBmensual, salidaBmensual, entradaCmensual, salidaCmensual, masUsadoMes);
    
    printf("========================================================\n");
    
    return 0;
}

char contenedormasusado(int totalA,int totalB, int totalC)
{
    if(totalA>=totalB && totalA>=totalC)
        return 'A';
    else if (totalB>=totalA && totalB>=totalC)
        return 'B';
    else
        return 'C';
    
}






