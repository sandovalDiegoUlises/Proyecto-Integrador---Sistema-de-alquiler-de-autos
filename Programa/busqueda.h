#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>  

#include "definiciones.h"

//================ PROTOTIPOS ================
void mostrarTitulo();
void busquedaPorMarca();
void busquedaPorModelo();
void busquedaPorColor();
void filtrarTipoDeVehiculo(int);

//============= MOSTRAR TITULO ====================
void mostrarTitulo() {
    printf("\n%-10s | %-10s | %-10s | %-10s | %13s | %17s | %14s | %-10s\n",
           "Marca", "Modelo", "Color", "Patente", "Import. Dia", "Import. Semana", "Import. Mes", "Estado");
    printf("--------------------------------------------------------------------------------------------------------------\n");
}


//=============== BUSCAR POR MARCA ==================
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
    
    int i;
    
    marca[0] = toupper(marca[0]);
    int valor = strlen(marca);
    for(i = 1; i < valor; i++){
    	marca[i] = tolower(marca[i]);
    }
	
	mostrarTitulo();
	
	while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1){
        if(strcmp(aux.marca, marca) == 0){
        
        	printf("%-10s | %-10s | %-10s | %-10s | $%11.2f | $%15.2f | $%12.2f | %-10s\n",
	       aux.marca,
	       aux.modelo,
	       aux.color,
	       aux.patente,
	       aux.importeDia,
	       aux.importeSemana,
	       aux.importeMes,
	       aux.alquilado ? "Alquilado" : "Disponible");
	       
            encontrados++;
        }
    }

    if(encontrados == 0){
        printf("\nNo se encontraron autos de esa marca.\n");
    }

    fclose(archivo);
}

//=============== BUSCAR POR MODELO ==================
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
    
    int i;
    modelo[0] = toupper(modelo[0]);
    int valor = strlen(modelo);
    for(i=1; i<valor; i++){
    	modelo[i] = tolower(modelo[i]);
    }
	
	mostrarTitulo();
	
    while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1 && encontrado == false){
        if(strcmp(aux.modelo, modelo) == 0){
            printf("%-10s | %-10s | %-10s | %-10s | $%11.2f | $%15.2f | $%12.2f | %-10s\n",
	       aux.marca,
	       aux.modelo,
	       aux.color,
	       aux.patente,
	       aux.importeDia,
	       aux.importeSemana,
	       aux.importeMes,
	       aux.alquilado ? "Alquilado" : "Disponible");
	       
            encontrado = true;
        }
    }

    if(!encontrado){
        printf("\nNo se encontro ese modelo.\n");
    }

    fclose(archivo);
}

//=============== BUSCAR POR COLOR ==================
void busquedaPorColor(){

    tString color;
    tDatosAutos aux;
    int encontrados = 0;

    FILE *archivo = fopen("archivoAutos.dat", "rb");

    if(archivo == NULL){
        printf("\nERROR: No se pudo acceder al archivo\n");
        exit(EXIT_FAILURE);
    }

    printf("\nIngrese el color del auto (Blanco, Negro, Azul, Rojo, Gris, Naranja o Verde): ");
	scanf(" %s", color);

    int i;
    color[0] = toupper(color[0]);
    int valor = strlen(color);
    for(i=1; i<valor; i++){
    	color[i] = tolower(color[i]);
    }
	
	mostrarTitulo();
	
    while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1){
        if(strcmp(aux.color, color) == 0){
            printf("%-10s | %-10s | %-10s | %-10s | $%11.2f | $%15.2f | $%12.2f | %-10s\n",
	       aux.marca,
	       aux.modelo,
	       aux.color,
	       aux.patente,
	       aux.importeDia,
	       aux.importeSemana,
	       aux.importeMes,
	       aux.alquilado ? "Alquilado" : "Disponible");
            encontrados++;
        }
    }

    if(encontrados == 0){
        printf("\nNo se encontraron autos de ese color.\n");
    }

    fclose(archivo);
}

//==================== FILTRAR POR TIPO DE VEHICULO ( 1 = AUTO , 2 = CAMIONETA ) ==========================

void filtrarTipoDeVehiculo(int pCodigoVehiculo){
	
    tDatosAutos aux;
    
    FILE *archivo = fopen("archivoAutos.dat", "rb");

    if(archivo == NULL){
        printf("\nERROR: No se pudo acceder al archivo\n");
        exit(EXIT_FAILURE);
    }

    printf("\n---- Mostrando %s ----\n", pCodigoVehiculo == 1 ? "todos los autos" : "todas las camionetas");
    
	mostrarTitulo();
	
    while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1){
        if( aux.codigoVehiculo == pCodigoVehiculo ){
        	printf("%-10s | %-10s | %-10s | %-10s | $%11.2f | $%15.2f | $%12.2f | %-10s\n",
	       	aux.marca,
	       	aux.modelo,
	       	aux.color,
	       	aux.patente,
	       	aux.importeDia,
	       	aux.importeSemana,
	       	aux.importeMes,
	       	aux.alquilado ? "Alquilado" : "Disponible");
        }
    }

    fclose(archivo);
}
