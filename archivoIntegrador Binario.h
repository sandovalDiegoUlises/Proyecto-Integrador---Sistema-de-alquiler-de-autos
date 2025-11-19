#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 20


typedef char tString[MAX];


typedef struct{
    tString marca;
	tString modelo;
	tString patente;
	bool alquilado;
    int precioPorDia ;
	int PrecioPorSemana;
	int precioPorMes;
	

}tDatosAutos;

FILE* archivo ;
tDatosAutos dato,datoAnte;


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





 void iniciarProceso(){
 	archivo = fopen("archivoAuto.dat","rb");
  
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
 	
 	printf("Marca\t|Modelo\t |Patente\t |Alquilado\t |Precio\n");
 	printf("\n----------------------------------------------------------------\n");
 }
void procesoCorte(){
	while(!feof(archivo)){
		principioCorte();
	
while(!feof(archivo) && strcmp(datoAnte.marca,dato.marca)== 0){
 unaMarca();
 	
fread(&dato,sizeof(tDatosAutos),1,archivo);
			
}
 finCorte();
	}
	
	
}

void principioCorte(){
		
	  printf("%s\n",datoAnte.marca);
	  
	subTotalAlquilados = 0 ;
    cantPorMarca  = 0;
	
}
void unaMarca(){
	 printf(" \t%-15s %-15s", dato.modelo,dato.patente);
            printf(" %-10s", dato.alquilado ? "SI" : "NO");
            printf(" \tDia:%d  Semana:%d  Mes:%d\n",
                    dato.precioPorDia,
                    dato.PrecioPorSemana,
                    dato.precioPorMes);
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
	printf("\nAutos Alquilado :%d",totalAlquilado);
	printf("\nAutos en Stock : %d",totalEnStock);
	printf("\nLa marca con mayor alquileres %s:%d",marcaMayorAlquiler,subTotalMayor);
	fclose(archivo);
}
 
  /*	void procesoPorMarca() {

    fclose(archivo);
    archivo = fopen("archivoAuto.dat","rb");

    printf("\nIngrese marca a buscar: ");
    scanf("%s", marca);

    printf("\nAutos de la marca %s:\n", marca);

    while(fread(&dato, sizeof(tDatosAutos), 1, archivo) == 1){

        if(strcmp(dato.marca, marca) == 0){

            printf("Modelo: %s\n", dato.modelo);
            printf("Patente: %s\n", dato.patente);
            printf("Alquilado: %s\n", dato.alquilado ? "SI":"NO");
            printf("Precios: Dia %.2f  Semana %.2f  Mes %.2f\n\n",
                    dato.precioPorDia, dato.PrecioPorSemana, dato.precioPorMes);
        }
    }
}
	

 	

  	
  	
  	

