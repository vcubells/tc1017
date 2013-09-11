//
//  main.c
//  t12c1e1
//
//  Created by Vicente Cubells Nonell on 08/11/12.
//  Copyright (c) 2012 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXROUTES 100

typedef struct  {
    char ip[15];
    char interface[10];
    int activa;
} route;

/* Prototipos de las funciones */
void adicionaRuta(route tabla[MAXROUTES]);
void eliminaRuta(route tabla[MAXROUTES]);
void actualizaRuta(route tabla[MAXROUTES]);
void mostrarRutas(route tabla[MAXROUTES]);
void generaPaquete(route tabla[MAXROUTES]);
void estadisticas(route tabla[MAXROUTES]);

/* Funciones utilitarias */
void inicializaTabla(route tabla[MAXROUTES]);
int buscarEntradaVacia(route tabla[MAXROUTES]);
int buscarRuta(route tabla[MAXROUTES], char ip[15]);

/* Funciones para trabajar con archivos */
void almacenaTablaRutas(route tabla[MAXROUTES]);
void leerTablaRutas(route tabla[MAXROUTES]);

#define ARCHIVO "/Users/vcubells/Desktop/rutas.dat"

#define INTERFACES 3

/* Contadores de paquetes enrutados */
int contadores[INTERFACES] = {0};
int errores = 0;

int main(int argc, const char * argv[])
{
    int opc;
    
    route tabla[MAXROUTES];
    
    /* Inicializar la tabla de rutas vacías */
    inicializaTabla(tabla);
    
    /* Leer rutas almacenadas */
    leerTablaRutas(tabla);
    
    /* Menú de opciones */
    do {
        printf("\n \
               Opciones\n \
               -----------\n \
               1- Adicionar ruta\n \
               2- Borrar una ruta\n \
               3- Actualizar una ruta\n \
               4- Mostrar tabla de enrutamiento\n \
               5- Generar un paquete\n \
               6- Estadísticas\n \
               0- Salir\n\n \
               Seleccione una opción?: ");
        scanf("%d", &opc);
        
        switch (opc) {
            case 0:
                break;
            case 1:
                adicionaRuta(tabla);
                break;
            case 2:
                eliminaRuta(tabla);
                break;
            case 3:
                actualizaRuta(tabla);
                break;
            case 4:
                mostrarRutas(tabla);
                break;
            case 5:
                generaPaquete(tabla);
                break;
            case 6:
                estadisticas(tabla);
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    }
    while (opc != 0);
    
    /* Almacenar tabla de rutas */
    almacenaTablaRutas(tabla);
    
    return 0;
}

void inicializaTabla(route tabla[MAXROUTES])
{
    int r;
    route entrada = {"", "", 0};
    
    for (r = 0; r < MAXROUTES; ++r) {
        tabla[r] = entrada;
    }
}

int buscarEntradaVacia(route tabla[MAXROUTES])
{
    int r = 0;
    
    while (r < MAXROUTES && tabla[r].activa == 1)
    {
        ++r;
    }
    
    if (r == MAXROUTES) {
        return -1;
    }
    else {
        return r;
    }
}

int buscarRuta(route tabla[MAXROUTES], char ip[15])
{
    int r = 0;
    int encontrada = 0;
    
    while (r < MAXROUTES && encontrada == 0)
    {
        if (strcmp(tabla[r].ip, ip) == 0) {
            encontrada = 1;
            break;
        }
        
        ++r;
    }
    
    if (encontrada == 0) {
        return -1;
    }
    else {
        return r;
    }
}


void adicionaRuta(route tabla[MAXROUTES])
{
    int vacia = buscarEntradaVacia(tabla);
    
    if (vacia == -1) {
        printf("Lo siento, la tabla de rutas está llena\n");
    }
    else {
        printf("Entra la dirección IP destino: ");
        scanf("%s", tabla[vacia].ip);
        
        printf("Entra la interface destino (Ethernet | ATM | FR): ");
        scanf("%s", tabla[vacia].interface);
        
        tabla[vacia].activa = 1;
        
        printf("Ruta adicionada: IP: %s, Interface: %s, Activa: %d\n",
               tabla[vacia].ip,
               tabla[vacia].interface,
               tabla[vacia].activa);
    }
}

void eliminaRuta(route tabla[MAXROUTES])
{
    char ip[15];
    int existe;
    
    printf("Entra la IP de la ruta a eliminar: ");
    scanf("%s", ip);
    
    existe = buscarRuta(tabla, ip);
    
    if (existe == -1) {
        printf("La ruta especificada no existe\n");
    }
    else {
        tabla[existe].activa = 0;
        printf("Ruta IP: %s, Interface: %s eliminada satisfactoriamente\n",
               tabla[existe].ip,
               tabla[existe].interface);
    }
    
}

void actualizaRuta(route tabla[MAXROUTES])
{
    char ip[15];
    int existe;
    route anterior;
    
    printf("Entra la IP de la ruta a actualizar: ");
    scanf("%s", ip);
    
    existe = buscarRuta(tabla, ip);
    
    if (existe == -1) {
        printf("La ruta especificada no existe\n");
    }
    else {
        anterior = tabla[existe];
        
        printf("Entra la nueva dirección IP destino: ");
        scanf("%s", tabla[existe].ip);
        
        printf("Entra la interface destino (Ethernet | ATM | FR): ");
        scanf("%s", tabla[existe].interface);
        
        printf("Ruta IP: %s, Interface: %s actualizada por : IP: %s, Interface: %s\n",
               anterior.ip,
               anterior.interface,
               tabla[existe].ip,
               tabla[existe].interface);
    }
}

void mostrarRutas(route tabla[MAXROUTES])
{
    int r;
    
    int activas = 0;
    
    printf("%15s\t%10s\n", "IP Destino", "Interface");
    
    for (r = 0; r < MAXROUTES; ++r) {
        if (tabla[r].activa == 1) {
            printf("%15s\t%10s\n", tabla[r].ip, tabla[r].interface);
            ++activas;
        }
    }
    
    printf("Total de rutas: %d\n\n", activas);
}

void generaPaquete(route tabla[MAXROUTES])
{
    char ip[15];
    int existe;
    
    printf("Entra la IP de destino: ");
    scanf("%s", ip);
    
    existe = buscarRuta(tabla, ip);
    
    if (existe == -1) {
        printf("No existe una ruta para el destino especificado\n");
        errores++;
    }
    else {
        printf("Se ha enrutado el paquete por la interfaz %s\n", tabla[existe].interface);
        
        if (strcmp(tabla[existe].interface, "Ethernet") == 0) {
            contadores[0]++;
        }
        else if (strcmp(tabla[existe].interface, "ATM") == 0) {
            contadores[1]++;
        }
        else if (strcmp(tabla[existe].interface, "FR") == 0) {
            contadores[2]++;
        }
    }
}

void estadisticas(route tabla[MAXROUTES])
{
    int i, h, suma = 0;
    
    printf("%10s\t%8s\tHistograma\n", "Interface", "Paquetes");
    printf("---------------------------------------------------");
    
    for (i = 0; i < INTERFACES; ++i) {
        
        suma += contadores[i];
        
        switch (i) {
            case 0:
                printf("%10s\t%8d\t", "Ethernet", contadores[i]);
                break;
            case 1:
                printf("%10s\t%8d\t", "ATM", contadores[i]);
                break;
            case 2:
                printf("%10s\t%8d\t", "FR", contadores[i]);
                break;
            default:
                break;
        }
        
        /* Imprimir histograma */
        for (h = 0; h < contadores[i]; ++h) {
            printf("*");
        }
        
        printf("\n");
        
    }
    
    /* Estadísticas generales */
    printf("Total de paquetes enrutados: %d\n", suma);
    printf("Total de errores: %d\n", errores);
    printf("Total de paquetes procesados: %d\n", suma + errores);
    
}

void almacenaTablaRutas(route tabla[MAXROUTES])
{
    FILE * fd;
    int registro;
    
    fd = fopen(ARCHIVO, "wb+");
    
    if (fd != NULL) {
        registro = 0;
        while(registro < MAXROUTES)
        {
            fwrite(&tabla[registro], sizeof(route), 1, fd);
            registro++;
        }
        
        fclose(fd);
    }
    else {
        printf("Archivo de rutas no se pudo abrir\n");
    }
    
}

void leerTablaRutas(route tabla[MAXROUTES])
{
    FILE * fd;
    int registro;
    
    fd = fopen(ARCHIVO, "rb+");
    
    if (fd != NULL)
    {
        registro = 0;
        while(!feof(fd) && registro < MAXROUTES)
        {
            fread(&tabla[registro], sizeof(route), 1, fd);
            registro++;
        }
        
        fclose(fd);
    }
    else {
        printf("Archivo de rutas no se pudo abrir\n");
    }
}