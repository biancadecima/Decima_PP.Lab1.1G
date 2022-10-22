#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aerolinea.h"
#include "avion.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"

#define TAM_AV 300
#define TAM_TP 4
#define TAM_AE 5
#define TAM_DS 4
#define TAM_VL 4

int main()
{
	setbuf(stdout,NULL);

    char salir = 'n';
    int nextId = 1;
    eAvion aviones[TAM_AV];
    eTipo tipos[TAM_TP];
    eAerolinea aerolineas[TAM_AE];
    eDestino destinos[TAM_DS];
    eVuelo vuelos[TAM_VL];

    hardcodeTipo( tipos);
    hardcodeAerolineas( aerolineas);
    hardcodeDestino( destinos);
    hardcodeVuelo( vuelos);

    if(!inicializarAviones(aviones, TAM_AV))
    {
        printf("Problemas al inicializar");
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
			if (!modificarAvion(aviones, TAM_AV,  aerolineas, TAM_AE, tipos, TAM_TP)) {
				printf("No se pudo realizar la modificacion\n");
			}else {
				printf("\n Modificacion exitosa \n");
			}
			break;

		case 3:
			 if(!bajaAvion( aviones, TAM_AV,  aerolineas, TAM_AE, tipos, TAM_TP)){
				 printf("No se pudo realizar la baja\n");
			 }else {
					printf("\n Baja exitosa \n");
				}
			break;

		case 4:
			if (!ordenarAvionesDobleCriterio(aviones, TAM_AV)) {
				printf("No se pudo realizar el listado\n");
			} else {
				mostrarAviones(aviones, TAM_AV,  aerolineas, TAM_AE, tipos, TAM_TP);
			}
			break;

		case 5:
			mostrarAerolineas(aerolineas, TAM_AE);
			break;
		case 6:
			mostrarTipos( tipos, TAM_TP);
			break;

		case 7:
			mostrarDestinos( destinos, TAM_DS);
			break;

		case 8:
			mostrarVuelos( vuelos, TAM_VL, destinos, TAM_DS);
			break;

		case 9:
			salir = confirmarSalida();
			break;

		default:
			printf("Opcion invalida\n");
		}
		system("pause");

	} while (salir == 'n');

	return 0;
}
