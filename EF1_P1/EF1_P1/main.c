//
//  main.c
//  EF1_P1
//
//  Created by Vicente Cubells Nonell on 15/05/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

#define FICHAS 100

typedef struct {
    int i, d;
} ficha;


int menu();
int adicionarFicha(ficha torre[], int c);
void fichaEnNivel(ficha torre[], int c);
int eliminarFicha(ficha torre[], int c);
int buscarFicha(ficha torre[], int c, ficha busca);
void imprimeTorre(ficha torre[], int c);
void hacerRefrexion(ficha torre[], int c);

int main(int argc, const char * argv[])
{
    ficha torre[FICHAS];
    int fichas_actuales = 0;
    int opc = 1;
    
    while (opc) {
        opc = menu();
        switch (opc) {
                
            case 0:
                printf("Gracias por utilizar la aplicación. Hasta pronto!!!\n");
                break;
                
            case 1:
                fichas_actuales = adicionarFicha(torre, fichas_actuales);
                break;
            
            case 2:
                fichaEnNivel(torre, fichas_actuales);
                break;
                
            case 3:
                fichas_actuales = eliminarFicha(torre, fichas_actuales);
                break;
                
            case 4:
                hacerRefrexion(torre, fichas_actuales);
                break;
                
            case 5:
                imprimeTorre(torre, fichas_actuales);
                break;
            
            default:
                printf("Opción no válida\n");
                break;
        }
    }
    return 0;
}

int menu()
{
    int opc;
    
    printf("\
           Opciones: \n\
           ____________\n\
           1. Adicionar ficha\n\
           2. Buscar ficha\n\
           3. Eliminar ficha\n\
           4. Hacer reflexión de la torre\n\
           5. Mostrar torre\n\
           0. Terminar\n\
           \n\
           Seleccione su opción: ");
    scanf("%d", &opc);
    
    return opc;
}

int adicionarFicha(ficha torre[], int c)
{
    ficha temp;
    int existe;
    
    printf("Entre la ficha a adicionar (Ej: 1,2): " );
    scanf("%d,%d", &temp.i, &temp.d);
    
    existe = buscarFicha(torre, c, temp);
    
    if (existe > -1)
    {
        printf("La ficha %d|%d ya existe en la posición %d\n", temp.i, temp.d, existe);
    }
    else {
        torre[c++] = temp;
    }    
    
    return c;
}

void fichaEnNivel(ficha torre[], int c)
{
    int nivel;
    
    printf("Entre el nivel (Ej: 1): " );
    scanf("%d", &nivel);
    
    --nivel;
    
    if (nivel < c)
    {
        printf("La ficha %d|%d está en el nivel %d\n", torre[nivel].i, torre[nivel].d, nivel+1);
    }
    else {
        printf("El nivel %d está por encima de los niveles actuales (%d) de la torre\n", nivel+1, c);
    }
    
}

int eliminarFicha(ficha torre[], int c)
{
    int existe;
    int i;
    ficha temp;
    
    printf("Entre la ficha a eliminar (Ej: 1,2): " );
    scanf("%d,%d", &temp.i, &temp.d);
    
    existe = buscarFicha(torre, c, temp);
    
    if (existe == -1)
    {
        printf("La ficha %d|%d no existe en la torre \n", temp.i, temp.d);
    }
    else {
        --c;
        for (i = existe; i < c; ++i)
            torre[i] = torre[i+1];
        
        printf("La ficha %d|%d ha sido eliminada y ocupaba la posición %d\n", temp.i, temp.d, existe);
        
    }
    
    return c;
    
}

int buscarFicha(ficha torre[], int c, ficha busca)
{
    int existe = -1;
    int i = 0;
    
    while (i < c && existe == -1) {
        if (torre[i].i == busca.i && torre[i].d == busca.d )
            existe = i;
        ++i;
    }
    
    return existe;
}

void imprimeTorre(ficha torre[], int c)
{
    int i = 0;
    
    while (i < c)
    {
        printf("%d|%d\n", torre[i].i, torre[i].d);
        ++i;
    }
}

void invertir(ficha torre[], int inicio, int fin)
{
    int i;
    ficha temp;
    
    for (i = inicio; inicio < fin; ++inicio, --fin) {
        temp = torre[inicio];
        torre[inicio] = torre[fin];
        torre[fin] = temp;
    }
}

void hacerRefrexion(ficha torre[], int c)
{
    int mitad;
    
    mitad = c / 2;
    
    invertir(torre, 0, mitad-1);
    invertir(torre, mitad, c-1);
    
}