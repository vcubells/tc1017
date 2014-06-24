//
//  main.c
//  t6c2e3
//
//  Created by Vicente Cubells Nonell on 17/06/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double gradosAradianes( int angulo);

int main(int argc, const char * argv[])
{
    double radianes;
    double cot, tang;
    
    printf("%6s\t%5s\t%6s\t%8s\t%10s\n", "Angulo", "Seno", "Coseno", "Tangente", "Cotangente");

    for (int i = 5; i <= 100; i += 5) {
        radianes = gradosAradianes(i);
        
        tang = tan(radianes);
        cot = 1 / tang;
        
        printf("%6d\t%5.2lf\t%6.2lf\t%8.2lf\t%10.2lf\n", i, sin(radianes), cos(radianes), tang, cot);
    }
    
    return 0;
}

double gradosAradianes( int angulo)
{
    return (angulo * M_PI / 180);
}