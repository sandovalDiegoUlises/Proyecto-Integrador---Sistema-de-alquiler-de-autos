#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//PROTOTIPOS DE LAS FUNCIONES
void busquedaPorMarca();
void busquedaPorModelo();
void busquedaPorColor();

//DEFINICION DE LAS FUNCIONES
void busquedaPorMarca(){
	
	tString marca;
	tDatosAutos aux;
	int encontrados = 0;
	
	FILE *archivo = fopen("archivoAutos.dat", "rb");
	
	if(archivo == NULL){
		printf("\nERROR: No se pudo acceder al archivo\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\nIngrese la marca a buscar: ");
	scanf(" %s", marca);
	
	
	while(fread(&aux, sizeof(tDatosAutos), 1, archivo)== 1){
		
		if(strcmp(aux.marca, marca) == 0){
			printf("\n%s -%5s- %5s", 
			aux.marca, aux.modelo, aux.alquilado == true? "Alquilado" : "Disponible")
			encontrados++;
		}		
	}
	if(encontrados == 0){
		printf("\nNo se encontraron autos de esa marca\n");
	}
	fclose(archivo);
}

void busquedaPorModelo(){
		
	tString modelo;
	tDatosAutos aux;
	bool encontrado = false;
	
	FILE *archivo = fopen("archivoAutos.dat", "rb");
	
	if(archivo == NULL){
		printf("\nERROR: No se pudo acceder al archivo\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\nIngrese el modelo a buscar: ");
	scanf(" %s", modelo);
	
	while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1){
		
		if(strcmp(aux.modelo, modelo) == 0){
			printf("\n%s -%5s- %5s", 
			aux.marca, aux.modelo, aux.alquilado == true? "Alquilado" : "Disponible");
			encontrado = true;
		}		
	}
	
	if(encontrado == false){
		printf("\nNo se encontro el modelo de auto\n");
	}
	
	fclose(archivo);
}

void busquedaPorColor(){
	
	tString color;
	tDatosAutos aux;
	FILE *archivo = fopen("archivoAutos.dat", "rb");
	
	printf("\nIngrese el color del auto ");
	printf("(Los colores disponibles son Negro, Blanco, Rojo, Azul, Gris y Naranja): ");
	scanf(" %s", color);
	
	while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1){
		if(strcmp(aux.color, color) == 0){
			printf("\n%s -%5s- %5s", 
			aux.marca, aux.modelo, aux.alquilado == true? "Alquilado" : "Disponible");
		}
	}
	fclose(archivo);
}
#endif

