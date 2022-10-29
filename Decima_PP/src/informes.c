#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"

int menuInformes()
{
    int opcion;
    printf("    *** MENU Informes *** \n\n");
    printf("1- Mostrar aviones de la aerolínea seleccionada por el usuario.\n");
    printf("2- Mostrar aviones de un tipo seleccionado.\n");
    printf("3- Informar Promedio de aviones jet sobre el total de aviones de una aerolínea\n");
    printf("4- Mostrar un listado de los aviones separados por aerolínea.\n");
    printf("5- Informar la o las aerolíneas que pueden transportar mas pasajeros\n");
    printf("6- Mostrar la aerolínea con menor cantidad de aviones\n");
    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

//- Mostrar aviones de la aerolínea seleccionada por el usuario.

int mostrarAvionesAerolinea(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp){
	int todoOk = 0;
	int idAerolinea;
	char descripcionAerolinea[50];

	if (aviones != NULL && tam_av > 0 && aerolineas != NULL && tam_ae > 0 && tipos != NULL && tam_tp > 0) {
		printf("\n*****  MOSTRAR AVIONES DE UNA AEROLINEA  *****\n\n");

		mostrarAerolineas(aerolineas, tam_ae);
		printf("Ingrese ID de la aerolinea: \n");
		scanf("%d", &idAerolinea);
		while (!validarIdAerolinea(idAerolinea, aerolineas, tam_ae)) {
			printf("\n Id aerolinea invalido. Reingrese ID de aerolinea: \n");
			scanf("%d", &idAerolinea);
		}

		cargarAerolineaDescripcion(aerolineas, tam_ae, idAerolinea, descripcionAerolinea);
		printf("\n AVIONES DE LA AEROLINEA %s :\n", descripcionAerolinea);
		printf("=================================================\n");
		printf("||  ID  ||   AEROLINEA  ||  TIPO  || CAPACIDAD ||\n");
		printf("=================================================\n");
		for (int i = 0; i < tam_av; i++) {
			if (aviones[i].idAerolinea == idAerolinea) {
				mostrarAvion(aviones[i], aerolineas, tam_ae, tipos, tam_tp);
			}
		}
		printf("=================================================\n");
	}

	return todoOk;
}

// Mostrar aviones de un tipo seleccionado.

int mostrarAvionesTipo(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp){
	int todoOk = 0;
	int idTipo;
	char descripcionTipo[50];

	if (aviones != NULL && tam_av > 0 && aerolineas != NULL && tam_ae > 0 && tipos != NULL && tam_tp > 0) {
		printf("\n*****  MOSTRAR AVIONES DE UN TIPO  *****\n\n");

		mostrarTipos(tipos, tam_tp);
		printf("Ingrese ID del tipo: \n");
		scanf("%d", &idTipo);
		while (!validarIdTipo(idTipo, tipos, tam_tp)) {
			printf("\n Id tipo invalido. Reingrese ID de tipo: \n");
			scanf("%d", &idTipo);
		}

		cargarTiposDescripcion(tipos, tam_tp, idTipo, descripcionTipo);
		printf("\n AVIONES DEL TIPO %s :\n", descripcionTipo);
		printf("=================================================\n");
		printf("||  ID  ||   AEROLINEA  ||  TIPO  || CAPACIDAD ||\n");
		printf("=================================================\n");
		for (int i = 0; i < tam_av; i++) {
			if (aviones[i].idTipo == idTipo) {
				mostrarAvion(aviones[i], aerolineas, tam_ae, tipos, tam_tp);
			}
		}
		printf("=================================================\n");
	}

	return todoOk;
}

// Informar PORCENTAJE de aviones jet sobre el total de aviones de una aerolínea (la aerolinea se la pido al usuario)

int porcentajeJetAerolinea(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae){
	int todoOk = 0;
	int idAerolinea;
	int contadorAviones = 0;
	int contadorJet = 0;
	float porcentaje;

	if (aviones != NULL && tam_av > 0 && aerolineas != NULL && tam_ae > 0) {
		printf("\n***** PORCENTAJE DE AVIONES JET POR TOTAL AVIONES AEROLINEA  *****\n");
		mostrarAerolineas(aerolineas, tam_ae);
		printf("Ingrese ID de la aerolinea: \n");
		scanf("%d", &idAerolinea);
		while (!validarIdAerolinea(idAerolinea, aerolineas, tam_ae)) {
			printf("\n Id aerolinea invalido. Reingrese ID de aerolinea: \n");
			scanf("%d", &idAerolinea);
		}

		for(int i = 0; i < tam_av; i++){//recorro aviones
			if(aviones[i].idAerolinea == idAerolinea){
				contadorAviones++;
				if( aviones[i].isEmpty == 0 && aviones[i].idTipo == 5000){
					contadorJet++;
				}
			}
		}

		if (contadorAviones == 0) {
			printf("\nNo se encontraron aviones en la aerolinea\n");
		} else {
			porcentaje = (contadorJet * 100) / contadorAviones;
			printf("\nPorcentaje de aviones tipo Jet: %.2f\n", porcentaje);
		}
		todoOk = 1;
	}

	return todoOk;
}

//Mostrar un listado de los aviones separados por aerolínea.
int mostrarAvionesPorAerolineas(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp){
	int todoOk = 0;
	int idAerolinea = 999;
	char descripcionAerolinea[50];
	int flag = 1;

	if (aviones != NULL && tam_av > 0 && aerolineas != NULL && tam_ae > 0 && tipos != NULL && tam_tp > 0) {
		for (int j = 0; j < tam_ae; j++) {
			idAerolinea++;
			cargarAerolineaDescripcion(aerolineas, tam_ae, idAerolinea, descripcionAerolinea);
			printf("\nAVIONES DE LA AEROLINEA %s\n", descripcionAerolinea);
			printf("================================================\n");
			printf("||  ID  ||  AEROLINEA ||   TIPO   || CAPACIDAD ||\n");
			printf("================================================\n");
			for (int i = 0; i < tam_av; i++) {
				if ( aviones[i].isEmpty == 0 && idAerolinea == aviones[i].idAerolinea) {
					 mostrarAvion(aviones[i], aerolineas, tam_ae, tipos, tam_tp);
					 flag = 0;
				}
			}
			if(flag == 1){
				printf("No se encontraron aviones en la aerolinea");
			}
			printf("================================================\n");
		}
	}

	return todoOk;
}



// Informar la o las aerolíneas que pueden transportar mas pasajeros (mayor acumulador de capacidades de sus aviones)

int mayorCapacidadAerolineas(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae) {
	int todoOk = 0;
	int acumuladorCapacidad[] = {0, 0, 0, 0, 0};
	int mayorCapacidadAerolinea;

	if (aviones != NULL && tam_av > 0 && aerolineas != NULL && tam_ae > 0) {
		printf("\n*****  MOSTRAR AEROLINEA CON MAYOR CAPACIDAD  *****\n\n");
		for (int i = 0; i < tam_ae; i++) {
			for (int j = 0; j < tam_av; j++) {
				if (aviones[i].isEmpty == 0 && aviones[j].idAerolinea == aerolineas[i].id) {
					acumuladorCapacidad[i] += aviones[j].capacidad;
				}
			}
		}

		for (int i = 0; i < tam_ae; i++) {
			if (i == 0 || acumuladorCapacidad[i] > mayorCapacidadAerolinea) {
				mayorCapacidadAerolinea = acumuladorCapacidad[i];
			}
		}

		for (int i = 0; i < tam_ae; i++) {
			if (mayorCapacidadAerolinea == acumuladorCapacidad[i]) {
				printf("%s, con capacidad total de %d\n\n", aerolineas[i].descripcion, mayorCapacidadAerolinea);
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

// Mostrar la aerolínea con menor cantidad de aviones

int menorAvionesAerolinea(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae){
	int todoOk = 0;
	int contadorAvion[5];
	int menorCantidadAvion;


	if(aviones != NULL && tam_av > 0 && aerolineas != NULL && tam_ae > 0){
		printf("\n*****  MOSTRAR AEROLINEA CON MENOS AVIONES  *****\n\n");
		for(int i = 0; i<tam_ae; i++) {
			contadorAvion[i] = 0;
			for(int j = 0; j<tam_av; j++) {
				if(aviones[i].isEmpty == 0 && aviones[j].idAerolinea == aerolineas[i].id) {
					contadorAvion[i]++;
				}
			}
		}

		for(int i = 0; i<tam_ae; i++) {
			if(i == 0 || contadorAvion[i] < menorCantidadAvion) {
				menorCantidadAvion = contadorAvion[i];
			}
		}

		for(int i = 0; i<tam_ae; i++) {
			if(menorCantidadAvion == contadorAvion[i]) {
				printf("%s posee %d aviones\n\n", aerolineas[i].descripcion, menorCantidadAvion);
			}
		}
		todoOk = 1;
	}

	return todoOk;
}
