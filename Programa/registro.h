#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// TAD 
#include "definiciones.h"

// PROTOTIPOS
void menuRegistro();
void iniciarProceso();
void procesoCorte();
void finProceso();
void unaMarca();


// VARIABLES GLOBALES

// enteros
int totalAlquilado, totalEnStock, subTotalMayor, subTotalAlquilados;
int cantPorMarca, tipoActual;

int totalAutosAlquilados = 0; 
int totalCamionetasAlquiladas = 0;
int totalAutosEnStock = 0; 
int totalCamionetasEnStock = 0;

// cadenas
tString marcaMayorAlquiler;
tString marca;

// otros
FILE* archivo ;
tDatosAutos dato, datoAnte;

void menuRegistro(){
	
	iniciarProceso();
	procesoCorte();
	finProceso();

}

void iniciarProceso(){
 	archivo = fopen("archivoAutos.dat","rb");
  
  	if (archivo == NULL) {
    	printf("\nERROR: No se pudo abrir el archivo 'archivoAuto.dat'.\n");
    	exit(EXIT_FAILURE);
	}
 	
	fread(&dato,sizeof(tDatosAutos),1,archivo);
 	datoAnte = dato ;
 	
 	totalAlquilado = 0;
    totalEnStock  = 0;
	subTotalMayor = 0 ;
 	
 	printf("\n***Lista de Autos Y camioneta ***\n");
 	

 	printf("\n----------------------------------------------------------------\n");
 }
 
void procesoCorte(){

    while(!feof(archivo)){

        tipoActual = dato.codigoVehiculo;

        if(tipoActual == 1){
        	printf("\n\n*** AUTOS ***\n");
		}else{
			printf("\n\n*** CAMIONETAS ***\n");
		}
            
        printf("Marca       Modelo      Patente     Alquilado\n");
        printf("------------------------------------------------------\n");

        while(!feof(archivo) && dato.codigoVehiculo == tipoActual){
            unaMarca();
            fread(&dato, sizeof(tDatosAutos), 1, archivo);
        }
      
        printf("------------------------------------------------------\n");
    }
}

void unaMarca() {

    printf("%-10s %-10s %-12s %s\n",
           dato.marca,
           dato.modelo,
           dato.patente,
           dato.alquilado ? "SI" : "NO");

    if (dato.alquilado) {

        if (tipoActual == 1) {
            totalAutosAlquilados++;
        } else {
            totalCamionetasAlquiladas++;
        }

    } else {

        if (tipoActual == 1) {
            totalAutosEnStock++;
        } else {
            totalCamionetasEnStock++;
        }
    }
}

void finProceso(){
    printf("\n========== RESUMEN FINAL ==========\n");
    printf("Autos alquilados      : %d\n", totalAutosAlquilados);
    printf("Autos en stock        : %d\n", totalAutosEnStock);
    printf("Camionetas alquiladas : %d\n", totalCamionetasAlquiladas);
    printf("Camionetas en stock   : %d\n", totalCamionetasEnStock);
    printf("===================================\n");

    fclose(archivo);
}
