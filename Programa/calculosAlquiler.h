#include<stdio.h>

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

float estadisticaPorMes(tDatosCalculos* pCalc, int cant){

    float total = pCalc->precioPorDia + pCalc->precioPorSemana + pCalc->precioPorMes;

    pCalc->promedio = total / cant;
 
    pCalc->porcentaje = (pCalc->precioPorMes * 100) / total;

    return pCalc->promedio;
}
