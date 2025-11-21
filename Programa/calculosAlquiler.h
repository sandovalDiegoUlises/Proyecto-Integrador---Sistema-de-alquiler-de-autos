#include<stdio.h>
#include "definiciones.h"

typedef struct{
	float precioPorDia;
	float precioPorSemana;
	float precioPorMes;
	float promedio;
	float porcentaje;
}tDatosCalculos;


void inicializarCalculos(tDatosCalculos*);
void cargarAuto(tDatosCalculos*,float,float,float);
float estadisticaPorMes(tDatosCalculos*,int);

//CALCULA LOS PRECIOS PARCIALES DEL ALQUILER
float calcularDia(int, tDatosAutos);
float calcularSemana(int, tDatosAutos);
float calcularMes(int, tDatosAutos);

//CALCULA EL PRECIO FINAL DEL ALQUILER SI EL PAGO ES CON TARJETA
float calcularTotalTarjeta(float, int);

void inicializarCalculos(tDatosCalculos* pCalcu){
	
	pCalcu->precioPorDia = 0.0;
	pCalcu->precioPorSemana = 0.0;
	pCalcu->precioPorMes = 0.0;
	pCalcu->promedio = 0.0;
	pCalcu->porcentaje = 0.0;
				
}

void cargarAuto(tDatosCalculos* pCalc, float dia, float semana, float mes){
	pCalc ->precioPorDia = dia;
	pCalc ->precioPorSemana = semana;
	pCalc ->precioPorMes = mes;
	
}

float calcularDia(int pCantDias, tDatosAutos pAuxAlquilado){
	float precioFinal = pCantDias * pAuxAlquilado.importeDia ;
	return precioFinal; 
}

float calcularSemana(int pCantSemana, tDatosAutos pAuxAlquilado){
	float precioFinal = pCantSemana * pAuxAlquilado.importeSemana;
	return precioFinal; 
}

float calcularMes(int pCantMeses, tDatosAutos pAuxAlquilado){
	float precioFinal = pCantMeses * pAuxAlquilado.importeMes ;
	return precioFinal; 
}

float calcularTotalTarjeta(float pImporteAlquiler, int pOpcionCuotas){
	float factor;
	
    switch(pOpcionCuotas) {
        case 1: 
			factor = 1.10;  
			break; // 3 cuotas +10%
        case 2: 
			factor = 1.20;  
			break; // 6 cuotas +20%
        case 3: 
			factor = 1.28;  
			break; // 9 cuotas +28%
        case 4: 
			factor = 1.35;  
			break; // 12 cuotas +35%
        default:
            printf("\nOpcion invalida.\n");
            return -1;
    }

    return pImporteAlquiler * factor;
}

float estadisticaPorMes(tDatosCalculos* pCalc, int cant){

    float total = pCalc->precioPorDia + pCalc->precioPorSemana + pCalc->precioPorMes;

    pCalc->promedio = total / cant;
 
    pCalc->porcentaje = (pCalc->precioPorMes * 100) / total;

    return pCalc->promedio;
}
