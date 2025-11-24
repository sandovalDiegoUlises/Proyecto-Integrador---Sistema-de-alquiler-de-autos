#include <stdio.h>
#include "definiciones.h"

//CALCULA LOS PRECIOS PARCIALES DEL ALQUILER
float calcularDia(int, tDatosAutos);
float calcularSemana(int, tDatosAutos);
float calcularMes(int, tDatosAutos);

//CALCULA EL PRECIO FINAL DEL ALQUILER SI EL PAGO ES EN EFECTIVO O TARJETA
float calcularDescuento( int, float );

//CALCULA EL PRECIO FINAL DEL ALQUILER SI EL PAGO ES CON TARJETA
float calcularTotalTarjeta(float, int);

float calcularDia(int pCantDias, tDatosAutos pAuxAlquilado){
	float precioFinal = pCantDias * pAuxAlquilado.importeDia;
	return precioFinal; 
}

float calcularSemana(int pCantSemana, tDatosAutos pAuxAlquilado){
	float precioFinal = pCantSemana * pAuxAlquilado.importeSemana;
	return precioFinal; 
}

float calcularMes(int pCantMeses, tDatosAutos pAuxAlquilado){
	float precioFinal = pCantMeses * pAuxAlquilado.importeMes;
	return precioFinal; 
}

float calcularDescuento( int pOpcion4, float pImporteAlquiler ){

	if( pOpcion4 == 1){
		return pImporteAlquiler * 0.90; // 10% DE DESCUENTO SI EL PAGO ES EN EFECTIVO (1)
	}
	
	if( pOpcion4 == 2){
		return pImporteAlquiler * 0.95; //  5% DE DESCUENTO SI EL PAGO ES POR TRANSFERENCIA (2)
	}
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
