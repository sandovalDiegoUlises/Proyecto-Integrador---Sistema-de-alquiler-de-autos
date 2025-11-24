#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <stdbool.h>
#include <stdio.h>

#define MAX 20
#define SALIR_FUNCION -1 
#define SALIR_ALQUILER 0

typedef char tString[MAX];

typedef struct{
	int codigoVehiculo; /* 1 SI ES AUTO, 2 SI ES CAMIONETA*/
    tString marca;
    tString modelo;
    tString color;
    float importeDia;
    float importeSemana;
    float importeMes;
    tString patente;
    bool alquilado; /* SI ES true SIGNIFICA QUE EL VEHICULO ESTA ALQUILADO, CASO CONTRARIO EL VEHICULO ESTA DISPONIBLE*/
}tDatosAutos;

#endif
