//
//  main.c
//  t3c2e3
//
//  Created by Vicente Cubells Nonell on 23/08/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int menor(int, int);
int mayor(int, int);
int igual(int, int);

int main(int argc, const char * argv[])
{

    int n1, n2;
    
    printf("Entre los valores de a,b: ");
    scanf("%d,%d", &n1, &n2);
    
    printf("El menor de %d y %d es %d \n", n1, n2, menor(n1, n2));
    printf("El mayor de %d y %d es %d \n", n1, n2, mayor(n1, n2));
    
    igual(n1, n2) ? printf("Son iguales") : printf("NO son iguales");
    
    return 0;
}

int menor(int n1, int n2)
{
    if (n1 < n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int mayor(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int igual(int n1, int n2)
{
    return n1 == n2;
}

