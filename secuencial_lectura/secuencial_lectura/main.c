//
//  main.c
//  secuencial_lectura
//
//  Created by Vicente Cubells Nonell on 15/04/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    FILE * fd;
    
    char isbn[10];
    char titulo[50];
    char autor[30];
    int paginas;
    
    fd  = fopen("/Users/vcubells/Desktop/libros.dat", "r");
    
    while (!feof(fd)) {
        fscanf(fd, "%s %s %s %d\n", isbn, titulo, autor, &paginas);
        
        printf("ISBN: %s, Titulo: %s, Autor: %s, Páginas: %d \n", isbn, titulo, autor, paginas);
    }
    
    fclose(fd);
    
    return 0;
}

