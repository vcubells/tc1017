//
//  main.c
//  ejemplo
//
//  Created by Vicente Cubells Nonell on 02/07/14.
//  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXIMO 10

struct paciente {
    char nombre[30];
    int edad;
    char padecimiento[30];
    int urgencia; // 1- Baja, 2-Normal, 3-Urgente
};

void ingresarPaciente(struct paciente fila[MAXIMO]);
void retirarPaciente(struct paciente fila[MAXIMO]);
void buscarPaciente(struct paciente fila[MAXIMO]);
void ordenarPacientes(struct paciente fila[MAXIMO]);
void mostrarPacientes(struct paciente fila[MAXIMO]);
void promedioEdades(struct paciente fila[MAXIMO]);

int ultimo = 0;

int main(int argc, const char * argv[])
{
    int opcion;
    struct paciente pacientes[MAXIMO];
    
    do {
        printf("\n");
        printf("Menú de opciones:\n");
        printf("-----------------\n");
        printf("1- Ingresar un paciente\n");
        printf("2- Retirar un paciente\n");
        printf("3- Buscar pacientes con padicimiento\n");
        printf("4- Mostrar pacientes ordenados por urgencia\n");
        printf("5- Mostrar pacientes en espera\n");
        printf("6- Promedio de edades\n");
        
        printf("0- Terminar\n");
        
        printf("?: ");
        scanf("%d", &opcion);
        
        printf("\n");
        
        switch (opcion) {
            case 1:
                ingresarPaciente(pacientes);
                break;
            case 2:
                retirarPaciente(pacientes);
                break;
            case 3:
                buscarPaciente(pacientes);
                break;
            case 4:
                ordenarPacientes(pacientes);
                mostrarPacientes(pacientes);
                break;
            case 5:
                mostrarPacientes(pacientes);
                break;
            case 6:
                promedioEdades(pacientes);
                break;
        }
        
    } while (opcion != 0);
    
    return 0;
}

void ingresarPaciente(struct paciente fila[MAXIMO])
{
    printf("--- Ingresar un paciente a la fila\n\n");
    
    if (ultimo < MAXIMO) {
        printf("Entre el nombre del paciente: ");
        scanf("%s", fila[ultimo].nombre);
        
        printf("Entre la edad del paciente: ");
        scanf("%d", &fila[ultimo].edad);
        
        printf("Entre el padecimiento del paciente: ");
        scanf("%s", fila[ultimo].padecimiento);
        
        printf("¿Con qué urgencia debe ser atendido (1-Baja / 2-Normal / 3-Urgente): ");
        scanf("%d", &fila[ultimo].urgencia);
        
        ++ultimo;
    }
    else {
        printf("Ya no se atenderán más pacientes, regrese mañana por favor\n");
    }
}

void retirarPaciente(struct paciente fila[MAXIMO])
{
    int borrar;
    
    printf("--- Retirar un paciente de la fila\n\n");
    
    // Mostrar el listado de pacientes
    for (int p = 0; p < ultimo; ++p) {
        printf("%d - %s \n", p, fila[p].nombre);
    }
    
    printf("Indique el número del paciente a retirar de la fila: ");
    scanf("%d", &borrar);
    
    // Comprobar que el paciente existe
    if (borrar < ultimo && borrar >= 0) {
        for (int p = borrar; p < ultimo-1; ++p) {
            fila[p] = fila[p+1];
        }
        
        --ultimo;
    }
    else {
        printf("No existe el paciente con el número %d \n", borrar);
    }
    
}

void buscarPaciente(struct paciente fila[MAXIMO]){
    char padecimiento[30];
    
    // Pedir el padecimiento a buscar
    printf("Entre el padecimiento a buscar: ");
    scanf("%s", padecimiento);
    
    printf("--- Listado de pacientes con el padecimiento '%s'\n\n", padecimiento);
    
    // Buscar
    for (int p = 0; p < ultimo; ++p) {
        if (strcmp(padecimiento, fila[p].padecimiento) == 0) {
            printf("%s\n", fila[p].nombre);
        }
    }
}

void ordenarPacientes(struct paciente fila[MAXIMO])
{
    struct paciente aux;
    
    for (int i = 0; i < ultimo; ++i) {
        for (int j = ultimo-1; j > i; --j) {
            if (fila[j-1].urgencia < fila[j].urgencia) {
                // Intercambiar valores
                aux = fila[j-1];
                fila[j-1] = fila[j];
                fila[j] = aux;
            }
        }
    }
}

void mostrarPacientes(struct paciente fila[MAXIMO])
{
    printf("--- Listado de pacientes \n\n");
    
    // Mostrar pacientes ordenados
    printf("%-2s\t%-30s\t%-4s\n", "P", "Paciente", "Edad");
    printf("---------------------------------------\n");
    
    for (int p = 0; p < ultimo; ++p) {
        printf("%2d\t%-30s\t%4d\n",
               fila[p].urgencia,
               fila[p].nombre,
               fila[p].edad);
    }
}

void promedioEdades(struct paciente fila[MAXIMO])
{
    int suma = 0;
    
    printf("--- Mostrar promedio de edades\n\n");
    
    for (int p = 0; p < ultimo; ++p) {
        suma += fila[p].edad;
    }
    
    printf("El promedio de edad de pacientes en espera es %d\n", suma / ultimo);
}
