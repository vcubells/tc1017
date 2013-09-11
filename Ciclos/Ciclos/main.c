//
//  main.c
//  Ciclos
//
//  Created by Vicente Cubells Nonell on 27/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int factorial, numero, contador;
    
    printf("Entre el número al cual desea calcularle el factorial: ");
    scanf("%d", &numero);
    
    factorial = 1;
    contador = 2;
    
        // Escrito con un while
    while (contador <= numero) {
        factorial = factorial * contador;
        
        contador = contador + 1;
    }
    
    printf("El factorial (while) de %d = %d \n", numero, factorial);
    
        // Escrito con un for
    for (factorial = 1, contador = 2; contador <= numero; contador++) {
        factorial *= contador;
    }
    
    printf("El factorial (for) de %d = %d \n", numero, factorial);
    
    return 0;
}

