//
//  main.c
//  t12c2e1
//
//  Created by Vicente Cubells Nonell on 25/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define MAXPOINTS 500

typedef struct {
    int x;
    int y;
} punto;

/* Definición de funciones */
void inicializaPuntos(punto postes[MAXPOINTS]);
int leerPuntos(punto postes[MAXPOINTS]);
float distancia(punto p1, punto p2);
float calcularArea(punto p1, punto p2, punto p3);
void obtenerAreaMayor(punto postes[MAXPOINTS], int cantidad);
void almacenaPuntos(punto p1, punto p2, punto p3);

int main(int argc, const char * argv[])
{
    punto postes[MAXPOINTS];
    int cantidad = 0;
    
    /* Inicializa puntos */
    inicializaPuntos(postes);
    
    /* Leer puntos del archivo chatri.in */
    cantidad = leerPuntos(postes);
    
    /* Obtener área mayor */
    obtenerAreaMayor(postes, cantidad);
    
    return 0;
}

/* Implementación de funciones */
void inicializaPuntos(punto postes[MAXPOINTS])
{
    int c;
    
    for (c = 0; c < MAXPOINTS; ++c) {
        postes[c].x = 0;
        postes[c].y = 0;
    }
}

int leerPuntos(punto postes[MAXPOINTS])
{
    FILE * fd;
    int x, y;
    int cantidad = 0;
    
    fd = fopen("/Users/vcubells/Downloads/chatri.in", "r");
    
    if (fd == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    x = 0;
    
    while (!feof(fd) && (x != -1) ) {
        fscanf(fd, "%d %d", &x, &y);
        postes[cantidad].x = x;
        postes[cantidad].y = y;
        ++cantidad;
    }
    
    fclose(fd);
    
    return (cantidad - 1);
}

float distancia(punto p1, punto p2)
{
    return sqrt( pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) );
}
            
float calcularArea(punto p1, punto p2, punto p3)
{
    float a, b, c;
    float p;
    
    a = distancia(p1, p2);
    b = distancia(p2, p3);
    c = distancia(p1, p3);
    
    p = (a + b + c) / 2;
    
    return sqrt( p * (p -a) * (p - b) * (p -c) );
    
}

void obtenerAreaMayor(punto postes[MAXPOINTS], int cantidad)
{
    int i, j, k;
    float area, areaMayor = 0;
    
    punto p1, p2, p3;
    punto f1, f2, f3;
    
    for (i = 0; i < cantidad; ++i) {
        p1 = postes[i];
        for (j = i + 1; j < cantidad; ++j) {
            p2 = postes[j];
            for (k = j + 1; k < cantidad; ++k) {
                p3 =postes[k];
                area = calcularArea(p1, p2, p3);
                
                if (area > areaMayor) {
                    areaMayor = area;
                    f1 = p1;
                    f2 = p2;
                    f3 = p3;
                }
            }
        }
    }
    
    printf("p1.x = %3d\tp1.y = %3d\n", f1.x, f1.y);
    printf("p2.x = %3d\tp2.y = %3d\n", f2.x, f2.y);
    printf("p3.x = %3d\tp3.y = %3d\n", f3.x, f3.y);
    
    /* Almacenar los puntos en un archivo */
    almacenaPuntos(f1, f2, f3);
    
}

void almacenaPuntos(punto p1, punto p2, punto p3)
{
    FILE * fd;
    
    fd = fopen("/Users/vcubells/chatri.out", "w");
    
    if (fd == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    
    fprintf(fd, "%3d %3d\n", p1.x, p1.y);
    fprintf(fd, "%3d %3d\n", p2.x, p2.y);
    fprintf(fd, "%3d %3d\n", p3.x, p3.y);
    
    fclose(fd);
}
