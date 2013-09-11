//
//  main.c
//  secuencial_escritura
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
    
    int centinela = 1;
    
    fd = fopen("/Users/vcubells/Desktop/libros.dat", "a");
    
    while (centinela == 1) {
        printf("Entra el ISBN: ");
        scanf("%s", isbn);
        printf("Entra el título: ");
        scanf("%s", titulo);
        printf("Entra el autor: ");
        scanf("%s", autor);
        printf("Entra el número de páginas: ");
        scanf("%d", &paginas);
        
        fprintf(fd, "%s %s %s %d\n", isbn, titulo, autor, paginas);
        
        printf("Quieres entrar otro libro? 1-Si / 0-No: ");
        scanf("%d", &centinela);
    }
    
    fclose(fd);
    
    return 0;
}

