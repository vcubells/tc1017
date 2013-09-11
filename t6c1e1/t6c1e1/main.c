//
//  main.c
//  t6c1e1
//
//  Created by Vicente Cubells Nonell on 20/09/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int fib(int);

int main(int argc, const char * argv[])
{
    int i, n, f;
    char * nombre = (char *) malloc(255);
    
    printf("Entra el valor de n: ");
    scanf("%d", &n);
    
    printf("%4s \t %10s %-20s\n", "n", "f(n)", "nomb");
    
    for (i=0; i <= n; ++i) {
        f = fib(i);
        f = (f % 2 == 0) ? f : -f;
        printf("Entre el nombre: ");
        scanf("%s", nombre);
        
        printf("%4d \t %10.3f %-20s\n", i, (float)f, nombre);
    }
    
    return 0;
}

int fib(int n)
{
    int x, y, i, temp;
    
    x = y = 1;
    
    for(i=2; i <= n; ++i)
    {
        temp = y;
        y = x;
        x += temp;
    }
    
    return x;
}
