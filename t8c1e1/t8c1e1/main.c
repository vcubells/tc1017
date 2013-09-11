//
//  main.c
//  t8c1e1
//
//  Created by Vicente Cubells Nonell on 04/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int id, opc;
    char nombre[30];
    float saldo;
    
    //Abrir un archivo
    FILE * fd;
    fd = fopen("/Users/vcubells/cuentas.csv", "w");
    
    do {
        printf("Entre el id de la cuenta: ");
        scanf("%d", &id);
        
        printf("Entre el nombre de la persona: ");
        scanf("%s", nombre);
        
        printf("Entre el saldo de la cuenta: ");
        scanf("%f", &saldo);
        
        // Escribir en el archivo
        fprintf(fd,"%d,%s,%.2f\n", id, nombre, saldo);
        
        printf("¿Quieres entrar otra cuenta? (1-Si / 0-No): ");
        scanf("%d", &opc);
    }
    while (opc != 0);
    
    //Cerrar el archivo
    fclose(fd);
    
    return 0;
}

