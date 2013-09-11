//
//  main.c
//  t8c1e2
//
//  Created by Vicente Cubells Nonell on 14/03/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

void escribir(int c1, int c2, int c3, int c4, int c5, int c6 );
void xml(int c1, int c2, int c3, int c4, int c5, int c6 );

int main(int argc, const char * argv[])
{

    int lanzamiento;
    int cara;
    int cara1, cara2, cara3, cara4, cara5, cara6;
    
    cara1 = cara2 = cara3 = cara4 = cara5 = cara6 = 0;
    
    srand(time(NULL));
    
    for (lanzamiento = 0; lanzamiento < 100000; ++lanzamiento) {
        cara = rand() % 6 + 1;
        
        switch (cara) {
            case 1:
                ++cara1;
                break;
                
            case 2:
                ++cara2;
                break;
                
            case 3:
                ++cara3;
                break;
                
            case 4:
                ++cara4;
                break;
                
            case 5:
                ++cara5;
                break;
                
            case 6:
                ++cara6;
                break;
        }
    }
    
    /* Generar reporte tabular */
    printf("%4s\t%7s\n", "Cara", "Veces");
    
    printf("%4d\t%7d\n", 1, cara1);
    printf("%4d\t%7d\n", 2, cara2);
    printf("%4d\t%7d\n", 3, cara3);
    printf("%4d\t%7d\n", 4, cara4);
    printf("%4d\t%7d\n", 5, cara5);
    printf("%4d\t%7d\n", 6, cara6);
    
    /* Generar archivo CSV */
    escribir(cara1, cara2, cara3, cara4, cara5, cara6);
    
    /* Generar archivo XML */
    xml(cara1, cara2, cara3, cara4, cara5, cara6);
    
    return 0;
}

void escribir(int c1, int c2, int c3, int c4, int c5, int c6 )
{
    FILE * fd;
    
    /* Abrir el archivo */
    fd = fopen("/Users/vcubells/Desktop/reporte.csv", "w");
    
    /* Escribir en el archivo */
    fprintf(fd, "%4s,%7s\n", "Cara", "Veces");
    fprintf(fd, "%4d,%7d\n", 1, c1);
    fprintf(fd, "%4d,%7d\n", 2, c2);
    fprintf(fd, "%4d,%7d\n", 3, c3);
    fprintf(fd, "%4d,%7d\n", 4, c4);
    fprintf(fd, "%4d,%7d\n", 5, c5);
    fprintf(fd, "%4d,%7d\n", 6, c6);
    
    /* Cerrar el archivo */
    fclose(fd);
}


void xml(int c1, int c2, int c3, int c4, int c5, int c6 )
{
    FILE * fd;
    
    /* Abrir el archivo */
    fd = fopen("/Users/vcubells/Desktop/reporte.xml", "w");
    
    /* Escribir en el archivo XML */
    fprintf(fd, "<?xml version='1.0' standalone='yes' ?>");
    fprintf(fd, "<dados>");
    
    fprintf(fd, "<cara>");
    fprintf(fd, "<numero>%d</numero>", 1);
    fprintf(fd, "<veces>%d</veces>", c1);
    fprintf(fd, "</cara>");
    
    fprintf(fd, "<cara>");
    fprintf(fd, "<numero>%d</numero>", 2);
    fprintf(fd, "<veces>%d</veces>", c2);
    fprintf(fd, "</cara>");
    
    fprintf(fd, "<cara>");
    fprintf(fd, "<numero>%d</numero>", 3);
    fprintf(fd, "<veces>%d</veces>", c3);
    fprintf(fd, "</cara>");
    
    fprintf(fd, "<cara>");
    fprintf(fd, "<numero>%d</numero>", 4);
    fprintf(fd, "<veces>%d</veces>", c4);
    fprintf(fd, "</cara>");
    
    fprintf(fd, "<cara>");
    fprintf(fd, "<numero>%d</numero>", 5);
    fprintf(fd, "<veces>%d</veces>", c5);
    fprintf(fd, "</cara>");
    
    fprintf(fd, "<cara>");
    fprintf(fd, "<numero>%d</numero>", 6);
    fprintf(fd, "<veces>%d</veces>", c6);
    fprintf(fd, "</cara>");
    
    fprintf(fd, "</dados>");
     
    /* Cerrar el archivo */
    fclose(fd);
}

