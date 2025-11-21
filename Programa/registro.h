#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>
#include "definiciones.h"

FILE* archivo ;
tDatosAutos dato,datoAnte;

void menuRegistro();
void iniciarProceso();
void procesoCorte();
void finProceso();

//void  procesoPorMarca();


void principioCorte();
void unaMarca();
void finCorte();

int totalAlquilado;
int totalEnStock ;
int subTotalMayor ;
tString marcaMayorAlquiler ; 

int subTotalAlquilados ;
int cantPorMarca ;


tString marca ;

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
 	
 	printf("\n***Lista de Autos ***\n");
 	
 	printf("Marca\t|Modelo\t |Patente\t |Alquilado\t\n");
 	printf("\n----------------------------------------------------------------\n");
 }
void procesoCorte(){
	while(!feof(archivo)){
		 printf("%s\n",datoAnte.marca);
		principioCorte();
	
while(!feof(archivo) && datoAnte.codigoVehiculo == dato.codigoVehiculo){
 unaMarca();
 	
fread(&dato,sizeof(tDatosAutos),1,archivo);
			
}
 finCorte();
	}
	
	
}

void principioCorte(){
		
	subTotalAlquilados = 0 ;
    cantPorMarca  = 0;
	
}

void unaMarca(){
	 printf(" \n\t%-15s %-15s %-10s", dato.modelo,dato.patente,dato.alquilado ? "SI" : "NO");
            
if(dato.alquilado == 1){

	subTotalAlquilados++ ;}
   cantPorMarca++ ;
}
void finCorte(){
	printf("\nAutos Alquilado %d",subTotalAlquilados);
	printf( "\nTotal de autos de %s : %d ",datoAnte.marca,cantPorMarca);
	printf("\n-----------------------------------------------------------------------\n");
	if(  subTotalAlquilados > subTotalMayor){
		subTotalMayor = subTotalAlquilados;
		strcpy(marcaMayorAlquiler,datoAnte.marca);
	}else{
		totalEnStock++ ;
	}
	totalAlquilado += subTotalAlquilados ;
	datoAnte = dato ;
	
}
void finProceso(){
	printf("\n\nAutos Alquilado :%d",totalAlquilado);
	printf("\nAutos en Stock : %d",totalEnStock);
	printf("\nLa marca con mayor alquileres %s:%d",marcaMayorAlquiler,subTotalMayor);
	fclose(archivo);
}
 

