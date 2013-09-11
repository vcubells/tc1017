//
//  main.c
//  t11c1e3
//
//  Created by Vicente Cubells Nonell on 29/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

void leerArchivo();
void escribeArchivo();

int main(int argc, const char * argv[])
{
    int opc = 0;
    
    do {
        printf("1-Escribir en archivo\n2-Leer archivo\n0-Salir\nEntre su opción: ");
        scanf("%d", &opc);
        
        switch (opc) {
            case 0: break;
                
            case 1:
                escribeArchivo();
                break;
                
            case 2:
                leerArchivo();
                break;
                
            default:
                printf("Opción no válida");
                break;
        }
    }
    while (opc != 0);
    
    return 0;
}

void escribeArchivo()
{
    int cuenta;        /* número de cuenta */
    char nombre[ 30 ]; /* nombre de cuenta */
    double saldo;      /* saldo de la cuenta */
    
    FILE *ptrCf;     /* ptrCf = apuntador al archivo clientes.dat */
    
    /* fopen abre el archivo. Si no es capaz de crear el archivo, sale del programa  */
    if ( ( ptrCf = fopen( "/Users/vcubells/Desktop/clientes.dat", "a" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse\n" );
    } /* fin de if */
    else {
        printf( "Introduzca la cuenta, el nombre, y el saldo.\n" );
        printf( "Introduzca EOF al final de la entrada.\n" );
        printf( "? " );
        scanf( "%d %s %lf", &cuenta, nombre, &saldo );
        
        /* escribe la cuenta, el nombre y el saldo dentro del archivo con fprintf */
        while ( !feof( stdin ) ) {
            fprintf( ptrCf, "%d %s %.2f\n", cuenta, nombre, saldo );
            printf( "? " );
            scanf( "%d %s %lf", &cuenta, nombre, &saldo );
        } /* fin de while */
        
        fclose( ptrCf ); /* fclose cierra el archivo */
    } /* fin de else */
    
}

void leerArchivo()
{
    int cuenta;        /* número de cuenta */
    char nombre[ 30 ]; /* nombre de cuenta */
    double saldo;      /* saldo de la cuenta */
    
    FILE *ptrCf;     /* ptrCf = apuntador al archivo clientes.dat */
    
    /* fopen abre el archivo; si no se puede abrir el archivo, abandona el programa */
    if ( ( ptrCf = fopen( "/Users/vcubells/Desktop/clientes.dat", "r" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse\n" );
    } /* fin de if */
    else { /* lee la cuenta, el nombre y el saldo del archivo */
        printf( "%-10s%-13s%s\n", "Cuenta", "Nombre", "Saldo" );
        fscanf( ptrCf, "%d %s %lf", &cuenta, nombre, &saldo );
        
        /* mientras no sea fin de archivo */
        while ( !feof( ptrCf ) ) {
            printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
            fscanf( ptrCf, "%d %s %lf", &cuenta, nombre, &saldo );
        } /* fin de while */
        
        fclose( ptrCf ); /* fclose cierra el archivo */
    } /* fin de else */
    
}

