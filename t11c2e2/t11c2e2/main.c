//
//  main.c
//  t11c2e2
//
//  Created by Vicente Cubells Nonell on 05/11/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

/* Figura 11.12: fig11_12.c
 Escritura en un archivo de acceso aleatorio */
#include <stdio.h>

/* definiciÛn de la estructura datosCliente */
struct datosCliente {
    int numCta;          /* n˙mero de cuenta */
    char apellido[ 15 ]; /* apellido de la cuenta */
    char nombre[ 10 ];   /* nombre de la cuenta */
    double saldo;        /* saldo de la cuenta */
}; /* fin de la estructura datosCliente  */

int main()
{
    FILE *ptrCf; /* apuntador al archivo credito.dat */
    
    /* crea datosCliente con informaciÛn predeterminada */
    struct datosCliente cliente = { 0, "", "", 0.0 };
    
    /* fopen abre el archivo; si no lo puede abrir, sale del archivo */
    if ( ( ptrCf = fopen( "/Users/vcubells/Desktop/credito.dat", "rb+" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse.\n" );
    } /* fin de if */
    else {
        
        /* se requiere que el usuario especifique el n˙mero de cuenta */
        printf( "Introduzca el numero de cuenta"
               " ( 1 a 100, 0 para terminar la entrada )\n? " );
        scanf( "%d", &cliente.numCta );
        
        /* el usuario introduce la informaciÛn, la cual se copia dentro del archivo */
        while ( cliente.numCta != 0 ) {
            
            /* el usuario introduce el apellido, el nombre y el saldo */
            printf( "Introduzca el apellido, el nombre, el saldo\n? " );
            
            /* establece los valores para apellido, nombre, y saldo del registro */
            fscanf( stdin, "%s %s %lf", cliente.apellido,
                   cliente.nombre, &cliente.saldo );
            
            /* localiza la posiciÛn de un registro especÌfico en el archivo */
            fseek( ptrCf, ( cliente.numCta - 1 ) *
                  sizeof( struct datosCliente ), SEEK_SET );
            
            /* escribe en el archivo la informaciÛn especificada por el usuario */
            fwrite( &cliente, sizeof( struct datosCliente ), 1, ptrCf );
            
            /* permite al usuario introducir otro n˙mero de cuenta */
            printf( "Introduce el numero de cuenta\n? " );
            scanf( "%d", &cliente.numCta );
        } /* fin de while */
        
        fclose( ptrCf ); /* fclose cierra el archivo */
    } /* fin de else */
    
    return 0; /* indica terminaciÛn exitosa */
    
} /* fin de main */


/**************************************************************************
 * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/



