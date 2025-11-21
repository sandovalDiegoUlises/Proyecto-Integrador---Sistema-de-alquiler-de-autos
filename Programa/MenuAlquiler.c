#include <stdio.h>
#include <ctype.h>
#include <windows.h>

//TADS
#include "calculosAlquiler.h"
#include "busqueda.h"
#include "definiciones.h"

// PROTOTIPOS
void alquilarVehiculo();
void mostarRegistros();
void busquedaAutos();
void tiposDeCamioneta();
void fechasAlquilada();
void mostrarMetodoDePago();
void autoAlquilado();
void alquilarPorModelo();
void alquilarPorPatente();

//VARIABLES GLOBALES
tDatosAutos autoAlquilar;
int cantDias, cantSemana, cantMes;
float importDia, importSemana, importMes;
float importeAlquiler;

int main(){

    int opcion;

    do{
        printf("\n ========================================= \n");
        printf("          Alquiler de Autos ");
        printf("\n ========================================= \n");
        printf("\n 1- Alquilar vehiculo ");
        printf("\n 2- Buscar vehiculo");
        printf("\n 3- Registros");
        printf("\n 0- Salir");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                autoAlquilado();
                break;
            case 2:
            	busquedaAutos();
            	break;
            case 3:
               // mostarRegistros();
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Error, vuelva a ingresar otra opcion..\n");
        }

    }while(opcion != 0);

    return 0;
}

void alquilarVehiculo(){
    int opcion1;

    do{
        printf("\nQue desea alquilar: ");
        printf("\n 1- Auto");
        printf("\n 2- Camioneta");
        printf("\n 0- Salir");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion1);
		
        switch(opcion1){
            case 1:
                printf("\nAutos en stock...\n");
                //tiposDeAuto();
                break;

            case 2:
                printf("\nCamionetas en stock...\n");
            //    tiposDeCamioneta();
                break;

            case 0:
                printf("Volviendo al menu...\n");
                Sleep(1000);
                system("cls");
                break;

            default:
                printf("Error, vuelva a ingresar otra opcion..\n");
        }

    }while(opcion1 != 0);
}

void busquedaAutos(){
    int opcion2;

    do{
        printf("\n--- Busqueda: ---");
        printf("\n 1- Buscar por Marca");
        printf("\n 2- Buscar por Modelo");
        printf("\n 3- Buscar por Color");
        printf("\n 0- Volver atras");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion2);

        switch(opcion2){
            case 1:
                busquedaPorMarca();
                break;

            case 2:
                busquedaPorModelo();
                break;
                
            case 3:
                busquedaPorColor();
                break;
				
            case 0:
                printf("\nVolviendo...\n");
                break;

            default:
                printf("Error, vuelva a ingresar otra opcion..\n");
        }

    }while(opcion2 != 0);
}

void  fechasAlquilada(){
	int opcion3;
	
	cantDias = 0;
    cantSemana = 0;
    cantMes = 0;
	
	do{
		
		printf("\n ========================================= \n");
    	printf("          Fechas para Alquilar ");
    	printf("\n ========================================= \n");
    	printf("\n 1- Dia");
    	printf("\n 2- Semana");
	    printf("\n 3- Mes");
	    printf("\n 0- Volver atras");
	    printf("\n\t Elija una opcion: ");
	    scanf("%d",&opcion3);
    
    switch(opcion3){
    	case 1:{
    		
    		printf("\n Indique la cantidad de dias: ");
    		scanf("%d",&cantDias);
    		
    		importeAlquiler = calcularDia(cantDias, autoAlquilar);
    		printf("\nEl importe parcial es de $%.2f", importeAlquiler);
    		mostrarMetodoDePago();
    		opcion3 = 0;//SALIDA DE LA FUNCION fechaAlquilada luego de que el usuario ya haya elegido el metodo de pago
    		break;
    	}
    	case 2:{
    		printf("\n Indique la cantidad de Semanas: ");
    		scanf("%d",&cantSemana);
    		
			importeAlquiler = calcularSemana(cantSemana, autoAlquilar);
    		printf("\nEl importe parcial es de $%.2f", importeAlquiler);
    		mostrarMetodoDePago();
    		opcion3 = 0;//SALIDA DE LA FUNCION fechaAlquilada luego de que el usuario ya haya elegido el metodo de pago
    		break;
    	}
    	case 3:{
    		printf("\n Indique la cantidad de Mes: ");
    		scanf("%d",&cantMes);
    		
    		importeAlquiler = calcularMes(cantMes, autoAlquilar);
    		printf("\nEl importe parcial es de $%.2f", importeAlquiler);
    		mostrarMetodoDePago();
    		opcion3 = 0; //SALIDA DE LA FUNCION fechaAlquilada luego de que el usuario ya haya elegido el metodo de pago
    		break;
    	}
    	case 0:{
    		printf("\n Saliendo...");
    		Sleep(1000);
            system("cls");
    		break;
    	}
    }
    
	}while(opcion3 != 0);
}

void mostrarMetodoDePago(){
	int opcion4;
	float totalFinal;
	
	do{
		
		printf("\n ========================================= \n");
		printf("          Metodos De Pago ");
		printf("\n ========================================= \n");
		printf("\n 1-Efectivo ( 10%% de descuento sobre el precio final)");
		printf("\n 2-Transferecia ( 5%% de descuento sobre el precio final)");
		printf("\n 3-Tarjeta (con interes segun cuotas)");
		printf("\n\t Elija una opcion: ");
		scanf("%d",&opcion4);
    
    	switch(opcion4){
    		
	    	case 1:{
	    		totalFinal = importeAlquiler * 0.90;
	    		printf("\n Tiene que abonar: $%.2f", totalFinal);
	    		opcion4 = 0; //SALIDA DEL BUCLE
	    		break;
	    	}
	    	
	    	case 2:{
	    		totalFinal = importeAlquiler * 0.95;
	    		printf("\n Tiene que abonar: $%.2f", totalFinal);
	    		opcion4 = 0;//SALIDA DEL BUCLE
	    		break;
	    	}
	    	
	    	case 3:{
	    		int opcionCuotas;
	    		printf("\n Elija cantidad de cuotas:");
                printf("\n 1 - 3 cuotas   (10%% de interes)");
                printf("\n 2 - 6 cuotas   (20%% de interes)");
                printf("\n 3 - 9 cuotas   (28%% de interes)");
                printf("\n 4 - 12 cuotas  (35%% de interes)");
                printf("\n\n Opcion: ");
                scanf("%d", &opcionCuotas);

                totalFinal= calcularTotalTarjeta(importeAlquiler, opcionCuotas);
	
                if (totalFinal != -1) {
                    printf("\nTotal a pagar: $%.2f", totalFinal);
                    printf("\nCuota mensual: $%.2f\n", totalFinal / (opcionCuotas == 1 ? 3 :
                                                        opcionCuotas == 2 ? 6 :
                                                        opcionCuotas == 3 ? 9 : 12));
                }
                opcion4 = 0; //SALIDA DEL BUCLE
                break;
	    	}
	    	
	    	case 0: 
	    		printf("\nSaliendo del menu..\n");
	    		break;
	    	default:
	    		printf("\nMetodo de pago invalido. Intente otra vez");
	    		break;
	    }
    
 	 }while(opcion4 != 0);
  
}

void autoAlquilado(){
	int opcion5;
	do{
	
		printf("\n ========================================= \n");
        printf("      Alquilar un auto     ");
        printf("\n ========================================= \n");
        printf("\n 1- Alquilar ingresando el modelo del auto ");
        printf("\n 2- Alquilar ingresando la patente del auto ");
        printf("\n 0- Volver atras");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion5);
        
        switch(opcion5){
        	case 1:
        		alquilarPorModelo();
				break;
			case 2:
				alquilarPorPatente();
				break;
        	case 0:
        		printf("\nVolviendo al menu...");
        		Sleep(1000);
        		system("cls");
        		break;
        	default:
        		printf("\nIngrese una opcion valida");
        		break;
        }
	}while(opcion5 != 0);
}

void alquilarPorModelo(){
	tString modeloAlqui;
	tDatosAutos aux;
	bool encontrado = false;
		
	FILE * archivo = fopen("archivoAutos.dat", "rb+");

	if(archivo == NULL){
		printf("\nNo se pudo abrir el archivo\n");
	}
	
	printf("\n Que modelo de auto desea alquilar: ");
	scanf("%s", modeloAlqui);
	
    while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1 && encontrado == false){
    	
        if(strcmp(aux.modelo,modeloAlqui) == 0){
        	encontrado = true;
        	
        	if(aux.alquilado == true){
        		printf("\nError: el auto se encuentra actualmente alquilado\n");
			}else{
				printf("\nSe encontro el auto y esta disponible para alquilarse\n");
				
				// MODIFICACIÓN DEL REGISTRO
                aux.alquilado = true;
				autoAlquilar = aux;
                // Retroceder 1 registro para sobrescribir
                fseek(archivo, -(long)sizeof(tDatosAutos), SEEK_CUR);

                // Guardar el registro modificado
                fwrite(&aux, sizeof(tDatosAutos), 1, archivo);

                printf("\nEl auto ha sido alquilado correctamente.\n");
			}
        }
    }
    
    if(!encontrado){
    	printf("\nNo se encontro ese modelo de auto ' %s ' ", modeloAlqui);
	}
	if(autoAlquilar.alquilado == true){
		fechasAlquilada();
	}
    
    fclose(archivo);
}

void alquilarPorPatente() {
	
    char patenteBuscada[20];
    tDatosAutos aux;
    bool encontrado = false;
    int i;

    FILE *archivo = fopen("archivoAuto.dat", "rb+");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo.");
        return;
    }

    printf("\nIngresar la Patente del auto: ");
    scanf(" %s", patenteBuscada);

    // Pasar patente ingresada a mayúsculas
    for (i = 0; i < strlen(patenteBuscada); i++) {
        patenteBuscada[i] = toupper(patenteBuscada[i]);
    }
    
    while (fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1 && !encontrado) {

        // Patente del archivo convertida a mayúsculas
        char patenteArchivo[20];
        strcpy(patenteArchivo, aux.patente);

        for (i = 0; i < strlen(patenteArchivo); i++) {
            patenteArchivo[i] = toupper(patenteArchivo[i]);
        }

        if (strcmp(patenteArchivo, patenteBuscada) == 0) {

            encontrado = true;

            if (aux.alquilado) {
                printf("\nEl auto ya está alquilado.");
            } else {

                printf("\nAuto encontrado y disponible para alquilar.\n");

                // Marcar como alquilado
                aux.alquilado = true;

                // Actualizar copia global luego de modificar
                autoAlquilar = aux;

                // Retroceder un registro
                fseek(archivo, -(long)sizeof(tDatosAutos), SEEK_CUR);

                // Guardar modificación
                fwrite(&aux, sizeof(tDatosAutos), 1, archivo);

                printf("\nAuto marcado como ALQUILADO correctamente.\n");
            }
        }
    }

    if (!encontrado) {
        printf("\nNo se encontró un auto con esa patente.\n");
    }

    // Si el auto quedó alquilado, llamar a función de fechas
    if (autoAlquilar.alquilado == true) {
        fechasAlquilada();
    }

    fclose(archivo);
}


