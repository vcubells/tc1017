//
//  main.c
//  EF_P1
//
//  Created by Vicente Cubells Nonell on 21/11/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define MAXPOINTS 500

typedef struct {
    int x;
    int y;
    
} punto;


void inicializaPuntos(punto puntos[MAXPOINTS]);
int leerPuntos(punto puntos[MAXPOINTS]);
float distancia(punto p1, punto p2);
float obtieneArea(punto p1, punto p2, punto p3);
void obtieneMayorArea(punto puntos[MAXPOINTS], int num);
void almacenaPuntos(punto p1, punto p2, punto p3);

int main(int argc, const char * argv[])
{
    punto puntos[MAXPOINTS];
    int num;
    
    /* Inicializa arreglo */
    inicializaPuntos(puntos);
    
    /* Leer puntos */
    num = leerPuntos(puntos);
    
    /* Obtener mayor área */
    obtieneMayorArea(puntos, num);
    
    return 0;
}

void inicializaPuntos(punto puntos[MAXPOINTS])
{
    int i;
    
    for (i = 0; i < MAXPOINTS; ++i)
    {
        puntos[i].x = -1;
        puntos[i].y = -1;
    }
}

int leerPuntos(punto puntos[MAXPOINTS])
{
    FILE * file;
    
    punto actual;
    int i = 0;
    
    actual.x = actual.y = 0;
    
    if ((file = fopen("/Users/vcubells/chatri.in", "r")) == NULL) {
        printf("Error al abrir el archivo de puntos\n");
    }
    else {
        while (!feof(file) && (actual.x != -1)) {
            fscanf(file, "%d %d", &actual.x, &actual.y);
            puntos[i++] = actual;
        }
        
        fclose(file);
    }
    
    return (i-1);
}

float distancia(punto p1, punto p2)
{
    return sqrt( pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) );
}

float obtieneArea(punto p1, punto p2, punto p3)
{
    float a, b, c, p;

    a = distancia(p1, p2);
    b = distancia(p2, p3);
    c = distancia(p1, p3);
    
    p = (a + b + c) / 2;
    
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void obtieneMayorArea(punto puntos[MAXPOINTS], int num)
{
    int i, j, k;
        
    float mayor = 0, area;
    
    punto p1, p2, p3;
    punto f1, f2, f3;
    
    p1 = puntos[0];
    
    for (i = 0; i < num; ++i) {
        
        p1 = puntos[i];
        
        for (j = i + 1; j < num; ++j) {
            
            p2 = puntos[j];
            
            for (k = j + 1; k < num; ++k) {
                
                p3 = puntos[k];
                
                area = obtieneArea(p1, p2, p3);
                
                if (area > mayor)
                {
                    mayor = area;
                    f1 = p1;
                    f2 = p2;
                    f3 = p3;
                }
                
            }
        }
    }
    
    almacenaPuntos(f1, f2, f3);
    
}

void almacenaPuntos(punto p1, punto p2, punto p3)
{
    FILE * file;
    
    if ((file = fopen("/Users/vcubells/chatri.out", "w")) == NULL) {
        printf("Error al abrir el archivo de puntos\n");
    }
    else {
        
        fprintf(file, "%d %d\n", p1.x, p1.y);
        fprintf(file, "%d %d\n", p2.x, p2.y);
        fprintf(file, "%d %d", p3.x, p3.y);
        
        fclose(file);
    }
}
