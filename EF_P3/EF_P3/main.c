//
//  main.c
//  EF_P3
//
//  Created by Vicente Cubells Nonell on 21/11/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

typedef struct {
	int placa;
	int modelo;
} coche;

void creaRegistro(coche registro[N]);
void buscarModelo(coche registro[N], int modelo);

int main(int argc, const char * argv[])
{
    coche registro[N];
    int modelo;
    
    srand(time(NULL));
    
    /* Crear el registro de autos */
    creaRegistro(registro);
    
    /* Buscar los autos de un modelo dado */
    printf("Entre el modelo del auto a buscar (1950 a 2012): ");
    scanf("%d", &modelo);
    
    buscarModelo(registro, modelo);
    
    return 0;
}

void creaRegistro(coche registro[N])
{
    int i;
    
    for (i = 0; i < N; ++i) {
        registro[i].placa = rand() % 1000000 + 100000;
        registro[i].modelo = rand() % 63 + 1950;
    }
}

void buscarModelo(coche registro[N], int modelo)
{
    int i;
    
    printf("Listado de autos modelo %d\n", modelo);
    printf("--------------------------\n");
    
    for (i = 0; i < N; ++i) {
        if (registro[i].modelo == modelo)
            printf("%6d\n", registro[i].placa);
    }
}

