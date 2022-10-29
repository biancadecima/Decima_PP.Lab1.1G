#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aerolinea.h"
#include "avion.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "validacion.h"
#include "informes.h"

#define TAM_AV 300
#define TAM_TP 4
#define TAM_AE 5
#define TAM_DS 4
#define TAM_VL 50

int main()
{
	setbuf(stdout,NULL);

    char salir = 'n';
    int nextId = 1;
    int nextIdVuelo = 50000;
    eAvion aviones[TAM_AV];
    eTipo tipos[TAM_TP];
    eAerolinea aerolineas[TAM_AE];
    eDestino destinos[TAM_DS];
    eVuelo vuelos[TAM_VL];

    hardcodeTipo( tipos);
    hardcodeAerolineas( aerolineas);
    hardcodeDestino( destinos);

	if (!inicializarAviones(aviones, TAM_AV)) {
		printf("\nProblemas al inicializar aviones\n");
	}
	if (!inicializaVuelos(vuelos, TAM_VL)) {
		printf("\nProblemas al inicializar vuelos\n");
	}

    do
    {
		switch (menu()) {
		case 1:
			if (!altaAvion(aviones, TAM_AV, &nextId, aerolineas, TAM_AE, tipos, TAM_TP)) {
				printf("No se pudo realizar el alta \n");
			} else {
				printf("\n Alta exitosa \n");
			}
			break;

		case 2:
			if (estadoArrayAviones(aviones, TAM_AV)) {
				if (!modificarAvion(aviones, TAM_AV, aerolineas, TAM_AE, tipos,
						TAM_TP)) {
					printf("No se pudo realizar la modificacion\n");
				} else {
					printf("\n Modificacion exitosa \n");
				}
			}else {
				printf("Se necesita cargar aviones\n");}
			break;

		case 3:
			if (estadoArrayAviones(aviones, TAM_AV)) {
				if (!bajaAvion(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_TP)) {
					printf("No se pudo realizar la baja\n");
				} else {
					printf("\n Baja exitosa \n");
				}
			} else {
				printf("Se necesita cargar aviones\n");
			}
			break;

		case 4:
			if (estadoArrayAviones(aviones, TAM_AV)) {
				if (!ordenarAvionesDobleCriterio(aviones, TAM_AV)) {
					printf("No se pudo realizar el listado\n");
				} else {
					mostrarAviones(aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_TP);
				}
			} else {
				printf("Se necesita cargar aviones\n");
			}
			break;

		case 5:
			limpiarPantalla();
			mostrarAerolineas(aerolineas, TAM_AE);
			break;

		case 6:
			limpiarPantalla();
			mostrarTipos( tipos, TAM_TP);
			break;

		case 7:
			limpiarPantalla();
			mostrarDestinos(destinos, TAM_DS);
			break;

		case 8:
			limpiarPantalla();
			if (estadoArrayAviones(aviones, TAM_AV)) {
				if (!altaVuelo(vuelos, TAM_VL, destinos, TAM_DS, aviones, TAM_AV, aerolineas, TAM_AE, tipos, TAM_TP, &nextIdVuelo)) {
					printf("No se pudo realizar el alta de vuelo\n");
				} else {
					printf("\n Alta de vuelo exitosa \n");
				}
			} else {
				printf("No puede dar de altas vuelos sin haber dado de alta aviones\n");
			}
			break;
		case 9:
			if(estadoArrayVuelos(vuelos, TAM_VL) == 0){
				printf("\n No se pueden mostrar los vuelos sin antes dar de alta \n");
			}else {
				limpiarPantalla();
				mostrarVuelos(vuelos, TAM_VL, aviones, TAM_AV, destinos, TAM_DS, aerolineas, TAM_AE, tipos, TAM_TP);
				printf("\n Alta de vuelo exitosa \n");
			}
			break;
		case 10:
			if (estadoArrayAviones(aviones, TAM_AV)) {
				switch(menuInformes()){
				case 1:
					mostrarAvionesAerolinea( aviones, TAM_AV,  aerolineas, TAM_AE, tipos, TAM_TP);
					break;
				case 2:
					mostrarAvionesTipo( aviones, TAM_AV, aerolineas, TAM_AE,  tipos,  TAM_TP);
					break;
				case 3:
					porcentajeJetAerolinea( aviones, TAM_AV, aerolineas, TAM_AE);
					break;
				case 4:
					mostrarAvionesPorAerolineas( aviones, TAM_AV, aerolineas, TAM_AE, tipos,  TAM_TP);
					break;
				case 5:
					mayorCapacidadAerolineas( aviones, TAM_AV, aerolineas, TAM_AE);
					break;
				case 6:
					menorAvionesAerolinea( aviones, TAM_AV, aerolineas, TAM_AE);
					break;
				}
			} else {
				printf("Se necesita cargar aviones\n");
			}
			break;
		case 11:
			salir = confirmarSalida();
			break;
		default:
			printf("Opcion invalida\n");
		}
		system("pause");

	} while (salir == 'n');

	return 0;
}
