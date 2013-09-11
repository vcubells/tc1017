//
//  main.c
//  aleatorio_actualiza
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
    
    int c = 0;
    
    /* Mostrar los libros */
    archivo = fopen("/Users/vcubells/Desktop/biblioteca.dat", "rb+");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        exit(1);
    }
    
    printf("Selecciona el número del libro a modificar:\n");
    
    fread(&registro, sizeof(libro), 1, archivo);
    
    while (!feof(archivo)) {
        printf("%d\t%s\t%s\n", ++c, registro.isbn, registro.titulo );
        
        fread(&registro, sizeof(libro), 1, archivo);
    }
    
    printf("?:");
    scanf("%d", &c);
    
    /* Desplazarnos al registro que se quiere modificar */
    fseek(archivo, sizeof(libro) * (c-1), SEEK_SET);
    
    /* Leer el registro a modificar */
    fread(&registro, sizeof(libro), 1, archivo);
    
    printf("Entre el nuevo ISBN (%s): ", registro.isbn);
    scanf("%s", registro.isbn);
    
    printf("Entre el nuevo título (%s): ", registro.titulo);
    scanf("%s", registro.titulo);
    
    printf("Entre el nuevo autor (%s): ", registro.autor);
    scanf("%s", registro.autor);
    
    printf("Entre el nuevo número de páginas (%d): ", registro.paginas);
    scanf("%d", &registro.paginas);
    
    /* Escribir el registro actualizado */
    
    fseek(archivo, sizeof(libro) * (c-1), SEEK_SET);
    
    fwrite(&registro, sizeof(libro), 1, archivo);
    
    /* Cerrar el archivo */
    fclose(archivo);
    
    return 0;
}

