#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <stdbool.h>
#include <stdio.h>

#define MAX 20

typedef char tString[MAX];

typedef struct{
    tString marca;
    tString modelo;
    tString color;
    float importeDia;
    float importeSemana;
    float importeMes;
    tString patente;
    bool alquilado;
}tDatosAutos;


#endif
