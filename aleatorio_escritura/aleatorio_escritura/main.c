//
//  main.c
//  secuencial_escritura
//
//  Created by Vicente Cubells Nonell on 15/04/13.
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
    FILE * fd;
  
    libro registro;
    
    int centinela = 1;
    
    fd = fopen("/Users/vcubells/Desktop/biblioteca.dat", "wb");
    
    while (centinela == 1) {
        printf("Entra el ISBN: ");
        scanf("%s", registro.isbn);
        printf("Entra el título: ");
        scanf("%s", registro.titulo);
        printf("Entra el autor: ");
        scanf("%s", registro.autor);
        printf("Entra el número de páginas: ");
        scanf("%d", &registro.paginas);
        
        fwrite(&registro, sizeof(libro), 1, fd);

        
        printf("Quieres entrar otro libro? 1-Si / 0-No: ");
        scanf("%d", &centinela);
    }
    
    fclose(fd);
    
    return 0;
}


