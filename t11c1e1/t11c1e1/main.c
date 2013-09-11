//
//  main.c
//  t11c1e1
//
//  Created by Vicente Cubells Nonell on 29/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

/* Figura 11.3: fig11_03.c
 Crea un archivo secuencial */

#include <stdio.h>

int main()
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
    
    return 0; /* indica terminaciÛn exitosa */
    
} /* fin de main */

