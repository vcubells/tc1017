//
//  main.c
//  Condicional Switch
//
//  Created by Vicente Cubells Nonell on 20/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    char caracter;
    
    printf("Entra una letra: ");
    scanf("%c", &caracter);
    
    switch (caracter) {
        case 'A':
        case 'a':
            printf("Oprimió una a ");
            break;
        case 'b':
            printf("Oprimió la b ");
            break;
            
        default:
            printf("Oprimió otra letra = %c", caracter);
            break;
    }
    
    printf("\n");
    
    if (caracter == 'a' || caracter == 'A')
    {
        printf("Oprimió una a");
    }
    else if (caracter == 'b')
    {
        printf("Oprimió la b");
    }
    else {
        printf("Oprimió otra letra = %c", caracter);
    }
    
    return 0;
}

