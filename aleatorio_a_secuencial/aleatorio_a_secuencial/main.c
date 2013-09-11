//
//  main.c
//  aleatorio_a_secuencial
//
//  Created by Vicente Cubells Nonell on 22/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

typedef struct {
    char isbn[10];
    char titulo[50];
    char autor[30];
    int paginas;
} libro;


int main(int argc, const char * argv[])
{
    FILE * aleatorio;
    FILE * secuencial;
    
    libro registro;
    
    aleatorio = fopen("/Users/vcubells/Desktop/biblioteca.dat", "rb");
    
    if (aleatorio == NULL) {
        printf("Error al abrir el archivo");
        exit(1);
    }
    
    secuencial = fopen("/Users/vcubells/Desktop/reporte.txt", "w");
    
    if (secuencial == NULL) {
        printf("Error al abrir el archivo");
        exit(1);
    }
    
    fread(&registro, sizeof(libro), 1, aleatorio);
    
    while (!feof(aleatorio)) {
        fprintf(secuencial, "%-10s\t%-50s\t%-30s\t%5d\n",
                registro.isbn,
                registro.titulo,
                registro.autor,
                registro.paginas);
        
        fread(&registro, sizeof(libro), 1, aleatorio);
    }
    
    fclose(aleatorio);
    fclose(secuencial);
    
    return 0;
}

