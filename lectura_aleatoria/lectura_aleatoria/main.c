//
//  main.c
//  lectura_aleatoria
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
    FILE * archivo;
    
    libro registro;
    
    archivo = fopen("/Users/vcubells/Desktop/biblioteca.dat", "rb");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        exit(0);
    }
    
    fread(&registro, sizeof(libro), 1, archivo);
    
    /* Leer los registros */
    while (!feof(archivo)) {
        
        printf("%s\t%s\t%s\t%d\n",
               registro.isbn,
               registro.titulo,
               registro.autor,
               registro.paginas);
        
        fread(&registro, sizeof(libro), 1, archivo);
    }
    
    fclose(archivo);
    
    
    return 0;
}

