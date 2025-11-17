//lista.h
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 20
#define MAX_MARCAS 7

typedef char tString[MAX];

typedef struct{
	tString marca;
	tString modelo;
	tString patente;
	bool alquilado;
}tDatosAuto;

typedef struct nodo{
	tDatosAuto autos;
	struct nodo* siguiente;
}tLista;

typedef tString tVectorMarcas[MAX_MARCAS];

tVectorMarcas marcas = {"Ford", "Renault", "Citroen", "Honda", "Audi", "Fiat", "Chevrolet"};

void crearLista(tLista**);
void inicializarArchivO(FILE*);
void cargarLista(tLista**, FILE*)
bool listaVacia(tLista*);
void agregarAuto(tLista**, FILE*);
void eliminarAuto(tLista**, FILE*);

#endif
