//
//  main.c
//  EF1_P1
//
//  Created by Vicente Cubells Nonell on 15/05/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define LIBROS 100

typedef struct {
    char titulo[25];
    char autor[30];
    char isbn[10];
    int anio;
    int paginas;
} libro;


int menu();
int adicionarlibro(libro biblioteca[], int c);
int eliminarlibro(libro biblioteca[], int c);
int buscarlibro(libro biblioteca[], int c, libro busca);
void imprimebiblioteca(libro biblioteca[], int c);
void ordenalibro(libro biblioteca[], int c);
void buscalibroAutor(libro biblioteca[], int c);

int main(int argc, const char * argv[])
{
    libro biblioteca[LIBROS];
    int libros_actuales = 0;
    int opc = 1;
    
    while (opc) {
        opc = menu();
        switch (opc) {
                
            case 0:
                printf("Gracias por utilizar la aplicación. Hasta pronto!!!\n");
                break;
                
            case 1:
                libros_actuales = adicionarlibro(biblioteca, libros_actuales);
                break;
                
            case 2:
                libros_actuales = eliminarlibro(biblioteca, libros_actuales);
                break;
                
            case 3:
                ordenalibro(biblioteca, libros_actuales);
                break;
                
            case 4:
                buscalibroAutor(biblioteca, libros_actuales);
                break;
                
            case 5:
                imprimebiblioteca(biblioteca, libros_actuales);
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
           1. Adicionar libro\n\
           2. Eliminar libro\n\
           3. Libros ordenados por año\n\
           4. Libros de un autor\n\
           5. Mostrar biblioteca\n\
           0. Terminar\n\
           \n\
           Seleccione su opción: ");
    scanf("%d", &opc);
    
    return opc;
}

int adicionarlibro(libro biblioteca[], int c)
{
    libro temp;
    int existe;
    
    printf("Entre el títutlo del libro: " );
    scanf("%s", temp.titulo);
    
    printf("Entre el autor del libro: " );
    scanf("%s", temp.autor);
    
    printf("Entre el ISBN del libro: " );
    scanf("%s", temp.isbn);
    
    printf("Entre el año de publicación del libro: " );
    scanf("%d", &temp.anio);
    
    printf("Entre el número de páginas del libro: " );
    scanf("%d", &temp.paginas);
    
    existe = buscarlibro(biblioteca, c, temp);
    
    if (existe > -1)
    {
        printf("La libro con ISBN '%s' ya existe en la biblioteca \n", temp.isbn);
    }
    else {
        biblioteca[c++] = temp;
    }
    
    return c;
}

int eliminarlibro(libro biblioteca[], int c)
{
    int existe;
    int i;
    libro temp;
    
    printf("Entre el ISBN del libro a eliminar: " );
    scanf("%s", temp.isbn);
    
    existe = buscarlibro(biblioteca, c, temp);
    
    if (existe == -1)
    {
        printf("El libro con ISBN '%s' no existe en la biblioteca \n", temp.isbn);
    }
    else {
        --c;
        for (i = existe; i < c; ++i)
            biblioteca[i] = biblioteca[i+1];
        
        printf("El libro con ISBN '%s' ha sido eliminado de la biblioteca\n", temp.isbn);
        
    }
    
    return c;
    
}

int buscarlibro(libro biblioteca[], int c, libro busca)
{
    int existe = -1;
    int i = 0;
    
    while (i < c && existe == -1) {
        if (strcmp(biblioteca[i].isbn, busca.isbn) == 0 )
            existe = i;
        ++i;
    }
    
    return existe;
}

void imprimebiblioteca(libro biblioteca[], int c)
{
    int i = 0;
    
    printf("%-10s\t%-25s\t%-30s\t%5s\t%5s\n\n",
           "ISBN", "Título del libro", "Autor", "Año", "Págs.");
    
    while (i < c)
    {
        printf("%-10s\t%-25s\t%-30s\t%5d\t%5d\n\n",
               biblioteca[i].isbn,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio,
               biblioteca[i].paginas);
        ++i;
    }
}


void ordenalibro(libro biblioteca[], int c)
{
    int i, j;
    libro temp;
    
    for (i = 0; i < c; ++i) {
        for (j = c - 1; j > i; --j) {
            if (biblioteca[j-1].anio > biblioteca[j].anio)
            {
                temp = biblioteca[j-1];
                biblioteca[j-1] = biblioteca[j];
                biblioteca[j] = temp;
            }
        }
    }
}


void buscalibroAutor(libro biblioteca[], int c)
{
    int existe = -1;
    int i = 0;
    char autor[30];
    
    printf("Entre el autor a buscar: " );
    scanf("%s", autor);
    
    printf("Libros del autor %s\n\n", autor);
    
    printf("%-10s\t%-25s\t%5s\t%5s\n\n",
           "ISBN", "Título del libro", "Año", "Págs.");
    
    while (i < c) {
        if (strcmp(biblioteca[i].autor, autor) == 0 )
        {
            existe = i;
            printf("%-10s\t%-25s\t%5d\t%5d\n\n",
                   biblioteca[i].isbn,
                   biblioteca[i].titulo,
                   biblioteca[i].anio,
                   biblioteca[i].paginas);
        }
        ++i;
    }
    
    if (existe == -1) {
        printf("No se encontraron libros del autor en la biblioteca\n");
    }
}