//
//  main.c
//  t3c2e5
//
//  Created by Vicente Cubells Nonell on 31/01/13.
//  Copyright (c) 2013 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>

int Mayor(int n1, int n2);
int Menor(int n1, int n2);
int Igual(int n1, int n2);

int main(int argc, const char * argv[])
{
    int a, b;
    
    printf("Entre el primer número: ");
    scanf("%d", &a);
    
    printf("Entre el segundo número: ");
    scanf("%d", &b);
    
    printf("El mayor es = %d \n", Mayor(a, b));
    printf("El menor es = %d \n", Menor(a, b));
   
    if (Igual(a, b))
    {
        printf("Son iguales");
    }
    else {
        printf("Son diferentes");
    }
    return 0;
}

int Mayor(int n1, int n2)
{
    if (n1 > n2)
        return n1;
    else
        return n2;
}


int Menor(int n1, int n2)
{
    if (n1 < n2)
        return n1;
    else
        return n2;
}

int Igual(int n1, int n2)
{
    return (n1 == n2);
}
