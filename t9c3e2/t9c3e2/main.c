//
//  main.c
//  t9c3e2
//
//  Created by Vicente Cubells Nonell on 15/10/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int i;
    char cadena[250];
    
    printf("Entre una cadena: ");
    scanf("%s", cadena);
    
    for (i = 0; cadena[i] != '\0'; ++i);
    
    printf(" strlen(%s) = %d caracteres \n", cadena, i);
    
    return 0;
}

