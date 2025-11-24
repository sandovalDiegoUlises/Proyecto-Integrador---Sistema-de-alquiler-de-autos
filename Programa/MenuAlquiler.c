#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

//TADS
#include "calculosAlquiler.h"
#include "busqueda.h"
#include "definiciones.h"
#include "registro.h"

// PROTOTIPOS
void inicializarDatos();
void menuPrincipal();
void alquilarVehiculo();
void mostarRegistros();
void busquedaAutos();
void fechasAlquilada();
void mostrarMetodoDePago();
void autoAlquilado();
void alquilarPorModelo();
void alquilarPorPatente();
void mostrarTicket( int );

//VARIABLES GLOBALES
tDatosAutos autoAlquilar;
int cantDias, cantSemana, cantMes, opcionCuotas;
float importDia, importSemana, importMes;
float importeAlquiler;
float totalFinal;

int main(){
	
	inicializarDatos();
 	menuPrincipal();

    return 0;
}

void inicializarDatos(){
	// INICIALIZACION DE LA VARIABLE AUTOALQUILAR 
	autoAlquilar.alquilado = false;
	strcpy(autoAlquilar.color, "");
	autoAlquilar.importeDia = 0.0;
	autoAlquilar.importeMes = 0.0;
	autoAlquilar.importeSemana = 0.0;
	strcpy(autoAlquilar.marca , "");
	strcpy(autoAlquilar.modelo , "");
	strcpy(autoAlquilar.patente , "");
	
	// INICIALIZACION DE OTRAS VARIABLES
	importeAlquiler = 0.0;
	totalFinal = 0.0;
	
}

void menuPrincipal(){
	
	int opcion;
	  
	do{
        printf("\n ========================================= \n");
        printf("     RoSa Mobility - Alquiler de Autos ");
        printf("\n ========================================= \n");
        printf("\n 1)- Alquilar vehiculo ");
        printf("\n 2)- Buscar vehiculo");
        printf("\n 3)- Registros");
        printf("\n 0)- Salir");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                alquilarVehiculo(); /*MENU DONDE EL USUARIO ELIGE SI QUIERE ALQUILAR AUTO O CAMIONETA*/
                break;
            case 2:
            	busquedaAutos(); /* MENU DESDE EL CUAL EL USUARIO PUEDE BUSCAR VEHICULOS POR MARCA MODELO O PATENTE*/
            	break;
            case 3:
                menuRegistro(); /*REGISTRO DONDE SE VEN TODOS LOS AUTOS Y CAMIONETAS. 
				SE REALIZA UN CORTE DE CONTROL INFORMANDO LA CANTIDAD QUE ESTUVIERAN ALQUILADOS*/
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("\nError, vuelva a ingresar otra opcion..\n");
                break;
        }

    }while(opcion != 0);
}

void alquilarVehiculo(){
	
	
	int opcion1;
    do{
    	printf("\n ========================================= \n");
        printf("           Que desea alquilar: ");
        printf("\n ========================================= \n");
        printf("\n 1)- Auto"); 
        printf("\n 2)- Camioneta");
        printf("\n 0)- Salir");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion1);
		
        switch(opcion1){
            case 1:
                printf("\nAutos en stock...\n");
                filtrarTipoDeVehiculo(1);// ESTA FUNCION RECIBE 1 SI SE DESEA VER TODOS LOS AUTOS 
                autoAlquilado();
                opcion1 = SALIR_ALQUILER; // UNA MACRO DEFINIDA EN definiciones.h QUE SIRVE PARA SALIR DE LA FUNCION alquilarVehiculo
                break;

            case 2:
                printf("\nCamionetas en stock...\n");
            	filtrarTipoDeVehiculo(2); // REUTILIZAMOS LA FUNCION filtrarTipoDeVehiculo PASANDO 2 PARA MOSTRAR SOLO LAS CAMIONETAS
            	autoAlquilado();
            	opcion1 = SALIR_ALQUILER; // UNA MACRO DEFINIDA EN definiciones.h QUE SIRVE PARA SALIR DE LA FUNCION alquilarVehiculo
                break;

            case SALIR_ALQUILER:
                printf("Volviendo al menu...\n");
                Sleep(1000);
                system("cls");
                break;

            default:
                printf("Error, vuelva a ingresar otra opcion..\n");
                break;
        }

    }while(opcion1 != SALIR_ALQUILER);
}

void busquedaAutos(){
    int opcion2;

    do{
    	printf("\n ========================================= \n");
        printf("              Busqueda por.. ");
        printf("\n ========================================= \n");
        printf("\n 1)- Busqueda por Marca");
        printf("\n 2)- Busqueda por Modelo");
        printf("\n 3)- Busqueda por Color");
        printf("\n 0)- Volver atras");
        printf("\n\t Ingrese una opcion: ");
        scanf("%d",&opcion2);

        switch(opcion2){
            case 1:
                busquedaPorMarca(); /* EL USUARIO INGRESA POR TECLADO LA MARCA DEL VEHICULO QUE DESEA BUSCAR */
                break;

            case 2:
                busquedaPorModelo(); /* EL USUARIO INGRESA POR TECLADO EL MODELO DEL VEHICULO QUE DESEA BUSCAR */
                break;
                
            case 3:
                busquedaPorColor(); /* EL USUARIO INGRESA POR TECLADO EL COLOR DEL VEHICULO QUE DESEA BUSCAR */
                break;
				
            case 0:
                printf("\nVolviendo...\n");
                break;

            default:
                printf("Error, vuelva a ingresar otra opcion..\n");
                break;
        }

    }while(opcion2 != 0);
}

void fechasAlquilada(){
	int opcion3;
	
	cantDias = 0;
    cantSemana = 0;
    cantMes = 0;
	
	do{
		
		printf("\n ========================================= \n");
    	printf("            Fechas para Alquilar ");
    	printf("\n ========================================= \n");
    	printf("\n 1)- Dia");
    	printf("\n 2)- Semana");
	    printf("\n 3)- Mes");
	    printf("\n\t Elija una opcion: ");
	    scanf("%d",&opcion3);
    
	    switch(opcion3){
	    	case 1:{
	    		
	    		printf("\n Indique la cantidad de dias: ");
	    		scanf("%d",&cantDias);
	    		
	    		importeAlquiler = calcularDia(cantDias, autoAlquilar);/*SE CALCULA EL IMPORTE PARCIAL DEPENDIENDO DEL importeDia DEL VEHICULO Y LA CANTIDAD DE DIAS*/
	    		printf("\nEl importe parcial es de $%.2f", importeAlquiler);
	    		mostrarMetodoDePago();
	    		opcion3 = SALIR_FUNCION; //SALIDA DE LA FUNCION fechaAlquilada luego de que el usuario ya haya elegido el metodo de pago
	    		break;
	    	}
	    	case 2:{
	    		printf("\n Indique la cantidad de Semanas: ");
	    		scanf("%d",&cantSemana);
	    		
				importeAlquiler = calcularSemana(cantSemana, autoAlquilar);/*SE CALCULA EL IMPORTE PARCIAL DEPENDIENDO DEL importeSemana DEL VEHICULO Y LA CANTIDAD DE SEMANAS*/
	    		printf("\nEl importe parcial es de $%.2f", importeAlquiler);
	    		mostrarMetodoDePago();
	    		opcion3 = SALIR_FUNCION; //SALIDA DE LA FUNCION fechaAlquilada luego de que el usuario ya haya elegido el metodo de pago
	    		break;
	    	}
	    	case 3:{
	    		printf("\n Indique la cantidad de Mes: ");
	    		scanf("%d",&cantMes);
	    		
	    		importeAlquiler = calcularMes(cantMes, autoAlquilar);/*SE CALCULA EL IMPORTE PARCIAL DEPENDIENDO DEL importeMes DEL VEHICULO Y LA CANTIDAD DE MESES*/
	    		printf("\nEl importe parcial es de $%.2f", importeAlquiler);
	    		mostrarMetodoDePago();
	    		opcion3 = SALIR_FUNCION; //SALIDA DE LA FUNCION fechaAlquilada luego de que el usuario ya haya elegido el metodo de pago
	    		break;
	    	}
	    	default:
	    		printf("\nIngrese una opcion valida,\n");
	    		break;
    	}
	}while(opcion3 != SALIR_FUNCION);
}

void mostrarMetodoDePago(){
	int opcion4;
	do{
		
		printf("\n ========================================= \n");
		printf("            Metodos De Pago ");
		printf("\n ========================================= \n");
		printf("\n 1)- Efectivo ( 10%% de descuento sobre el precio final)");
		printf("\n 2)- Transferecia ( 5%% de descuento sobre el precio final)");
		printf("\n 3)- Tarjeta (con interes segun cuotas)");
		printf("\n\t Elija una opcion: ");
		scanf("%d",&opcion4);
    
    	switch(opcion4){
    		
	    	case 1:{
	    		totalFinal = calcularDescuento( opcion4, importeAlquiler );
	    		printf("\n Tiene que abonar: $%.2f", totalFinal);
	
	    		mostrarTicket( opcion4 );
				opcion4 = SALIR_FUNCION; // UNA MACRO DEFINIDA EN definiciones.h QUE SIRVE PARA SALIR YA SEA DE LA FUNCION mostrarMetodoDePago O fechaAlquilada
	    		break;
	    	}
	    	
	    	case 2:{
	    		totalFinal = calcularDescuento( opcion4, importeAlquiler );
	    		printf("\n Tiene que abonar: $%.2f\n", totalFinal);
	
	    		mostrarTicket( opcion4 );
	    		opcion4 = SALIR_FUNCION;
	    		break;
	    	}
	    	
	    	case 3:{
	    	
	    	    printf("\n ========================================= \n");
	    		printf("       Elija cantidad de cuotas:");
	    		printf("\n ========================================= \n");
                printf("\n 1)- 3 cuotas   (10%% de interes)");
                printf("\n 2)- 6 cuotas   (20%% de interes)");
                printf("\n 3)- 9 cuotas   (28%% de interes)");
                printf("\n 4) - 12 cuotas  (35%% de interes)");
                printf("\n\n Opcion: ");
                scanf("%d", &opcionCuotas);

                totalFinal = calcularTotalTarjeta(importeAlquiler, opcionCuotas); /* ESTA FUNCION CALCULA EL IMPORTE TOTAL SI EL PAGO ES CON TARJETA.
				RECIBE DE PARAMETRO EL IMPORTE PARCIAL Y LA CANTIDAD DE CUOTAS ELEGIDA POR EL USUARIO */
	
                mostrarTicket( opcion4 ); 
                opcion4 = SALIR_FUNCION;
                break;
	    	}

	    	default:
	    		printf("\nMetodo de pago invalido. Intente otra vez");
	    		break;
	    }
    
 	 }while(opcion4 != SALIR_FUNCION);
  
}

void autoAlquilado(){
	
	
	
	int opcion5;
	
	do{
	
		printf("\n ========================================= \n");
        printf("            Alquilar un auto     ");
        printf("\n ========================================= \n");
        printf("\n 1)- Alquilar ingresando el modelo del auto ");
        printf("\n 2)- Alquilar ingresando la patente del auto ");
        printf("\n 0)- Volver atras");
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
        		printf("\nVolviendo atras...");
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
	
	int i;
    modeloAlqui[0] = toupper(modeloAlqui[0]);
    int valor = strlen(modeloAlqui);
    for(i=1; i<valor; i++){
    	modeloAlqui[i] = tolower(modeloAlqui[i]);
    }
	
    while(fread(&aux, sizeof(tDatosAutos), 1, archivo) == 1 && encontrado == false){
    	
        if(strcmp(aux.modelo,modeloAlqui) == 0){
        	encontrado = true;
        	
        	if(aux.alquilado == true){
        		printf("\nError: el auto se encuentra actualmente alquilado\n");
			}else{
				printf("\nSe encontro el auto modelo %s y ha sido alquilado correctamente\n", modeloAlqui);
				// MODIFICACIÓN DEL REGISTRO
                aux.alquilado = true;
				autoAlquilar = aux;
                // Retroceder 1 registro para sobrescribir
                fseek(archivo, -(long)sizeof(tDatosAutos), SEEK_CUR);

                // Guardar el registro modificado
                fwrite(&aux, sizeof(tDatosAutos), 1, archivo);
                
				printf("\nMarca : %s",aux.marca);
                printf("\nModelo: %s",aux.modelo);
                printf("\nColor : %s",aux.color);
                printf("\nPatente: %s",aux.patente);
                
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
	
	tString patenteBuscada;
    tDatosAutos aux;
    bool encontrado = false;
    int i;

    FILE *archivo = fopen("archivoAutos.dat", "rb+");
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
    	
        if (strcmp(aux.patente, patenteBuscada) == 0) {

            encontrado = true;

            if (aux.alquilado) {
                printf("\nEl vehiculo ya está alquilado.");
            } else {

                printf("\nVehiculo encontrado y disponible para alquilar.\n");

                // Marcar como alquilado
                aux.alquilado = true;

                // Actualizar copia global luego de modificar
                autoAlquilar = aux;

                // Retroceder un registro
                fseek(archivo, -(long)sizeof(tDatosAutos), SEEK_CUR);

                // Guardar modificación
                fwrite(&aux, sizeof(tDatosAutos), 1, archivo);
                printf("\nMarca : %s",aux.marca);
                printf("\nModelo: %s",aux.modelo);
                printf("\nColor : %s",aux.color);
                printf("\nPatente: %s",aux.patente);

                printf("\nVehiculo marcado como ALQUILADO correctamente.\n");
            }
        }
    }

    if (!encontrado) {
        printf("\nNo se encontró un vehiculo con esa patente.\n");
    }

    // Si el auto quedó alquilado, llamar a función de fechas
    if (autoAlquilar.alquilado == true) {
        fechasAlquilada();
    }

    fclose(archivo);
}

void mostrarTicket(int pOpcion4){

    system("cls"); // LIMPIA PANTALLA

    printf("\n====================================\n");
    printf("         TICKET ALQUILER        ");
    printf("\n====================================");

    printf("\n\tAUTO ALQUILADO");
    printf("\nMarca: %s", autoAlquilar.marca);
    printf("\nModelo: %s", autoAlquilar.modelo);
    printf("\nPatente: %s", autoAlquilar.patente);
    printf("\nColor: %s ", autoAlquilar.color);

    printf("\n====================================");
    
    printf("\n\tDETALLES DEL ALQUILER");
    printf("\nDias: %d  ", cantDias);
    printf("\nSemanas: %d", cantSemana);
	printf("\nMeses: %d", cantMes );
	
	if ( pOpcion4 == 3) { /* VERIFICA SI EL USUARIO ELIGIO PAGO CON TARJETA  */
	    printf("\nTotal a pagar: $%.2f", totalFinal);
	    printf("\nCuota mensual: %d cuotas de $%.2f\n", (opcionCuotas == 1 ? 3 :
	                                      			    opcionCuotas == 2 ? 6 :
	                                       			   opcionCuotas == 3 ? 9 : 12 ),totalFinal / (opcionCuotas == 1 ? 3 :
	                                        										opcionCuotas == 2 ? 6 :
	                                      		  								 	opcionCuotas == 3 ? 9 : 12));
														/* INTENTA BUSCAR LA CANTIDAD DE CUOTAS ELEGIDA POR EL USUARIO */
	}	

    printf("\n====================================");
    printf("\nTOTAL PAGADO: $%.2f", totalFinal);
    printf("\n====================================");
    printf("\n      Gracias por su alquiler!     ");
    printf("\n====================================\n\n");
    
    
    /* VOLVEMOS A INICIALIZAR LAS VARIABLES GLOBALES POR SI EL USUARIO DESEA ALQUILAR OTRO VEHICULO */
	inicializarDatos();
	
    Sleep(2000);
    
    char opcion6;	
    
    printf("\n\nDesea continuar? (S / N): ");
    fflush(stdin);
    scanf("%c",&opcion6);
    
	opcion6 = toupper(opcion6);
	
	if(opcion6 == 'N'){
		exit(1);
	}
	// SI OPCION6 == 'S' SIMPLEMENTE SE VUELVE A LA FUNCION DE ORIGEN
}
