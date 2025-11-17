//Lista.c
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "listaAuto.h"

void crearLista(tLista **pLista){
	*pLista = NULL;
}

void inicializarArchivo(FILE *pArchivo, char modo){
	pArchivo = fopen("lista_autos.txt", modo);
	
	if(!pArchivo){
		printf("\nERROR: No se pudo crear el archivo lista_autos.txt\n");
		exit(EXIT_FAILURE);
	}
}

bool listaVacia(tLista* pLista){
	return pLista == NULL;
}

void cargarLista(tLista **pLista, FILE *pArchivo){
	
	tLista *aux = *pLista;
	
	pArchivo = inicializarArchivo(*pArchivo, r);

	if( feof(pArchivo)){
		printf("\nEl archivo esta vacio\n");
		exit(EXIT_FAILURE);
	}
	
	while( !feof(pArchivo) ){
		fread(&aux, sizeof(tLista), 1, pArchivo);
		aux = aux->siguiente;
	}
	*pLista = aux;
	*pLista->siguiente = NULL;
	
	printf("\nDatos cargados correctamente\n");
}

void agregarAuto(tLista	**pLista, FILE *pArchivo){
	tString marca;
	printf("\nIndique la marca del auto que desea agregar");
	
	return;
}
