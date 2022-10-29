#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vuelo.h"

void hardcodeVuelo(eVuelo vuelos[]){
	eVuelo hardcode[4] = {
				{300, 1, 20000, {2, 3, 2013}},
				{301, 2, 20001, {4, 3, 2012}},
				{302, 3, 20002, {6, 9, 2015}},
				{303, 4, 20003, {9, 5, 2010}},
		};

		for(int i = 0; i<4; i++){
			vuelos[i] = hardcode[i];
		}
}

int estadoArrayVuelos(eVuelo vuelos[], int tam_vl) {
	int rtn = 0; // 0 vacio, 1 hay al menos uno, -1 lleno;
	int contador = 0;

	for (int i = 0; i < tam_vl; i++) {
		if (vuelos[i].isEmpty == 0) {
			contador++;
			rtn = 1;
		}
	}
	if (contador == tam_vl) {
		rtn = -1;
	}

	return rtn;
}

int inicializaVuelos(eVuelo vuelos[], int tam_vl)
{
    int todoOk = 0;

    if(vuelos != NULL && tam_vl > 0)
    {
        for (int i = 0; i < tam_vl; i++)
        {
        	vuelos[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreVuelo(eVuelo vuelos[], int tam_vl)
{
    int indice = -1;
    for (int i = 0 ; i < tam_vl; i++)
    {
        if(vuelos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaVuelo(eVuelo vuelos[], int tam_vl, eDestino destinos[], int tam_ds, eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp, int *pIdVuelo) {
	int todoOk = 0;
    int indice;
    eVuelo aux;

    if(aviones != NULL && tam_av > 0 && destinos != NULL && tam_ds > 0 && vuelos != NULL && tam_vl > 0 && pIdVuelo != NULL)
    {
        indice = buscarLibreVuelo(vuelos, tam_vl);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            printf("***** ALTA VUELO ******\n");

            aux.id = *pIdVuelo;
            (*pIdVuelo)++;

            mostrarAviones(aviones, tam_av, aerolineas, tam_ae, tipos, tam_tp);
            printf("Ingrese ID del Avion: \n");
            scanf("%d", &aux.idAvion);
            while(buscarAvionId(aviones, tam_av, aux.idAvion) == -1){
            	printf("\n Id avion invalido. Reingrese ID de aerolinea: \n");
            	scanf("%d", &aux.idAvion);
            }

            mostrarDestinos(destinos, tam_ds);
            printf("Ingrese ID del destino: \n");
            scanf("%d", &aux.idDestino);
            while(!validarIdDestino(aux.idDestino, destinos, tam_ds)){
            	printf("\n Id destino invalido. Reingrese ID del destino: \n");
            	scanf("%d", &aux.idDestino);
            }

			printf("Ingrese fecha: \n");
			scanf("%d/%d/%d", &aux.fecha.dia, &aux.fecha.mes, &aux.fecha.anio);
			while (!validarDia(aux.fecha.dia) || !validarMes(aux.fecha.mes) || !validarAnio(aux.fecha.anio)) {
				printf("\nFecha invalida. Reingrese fecha: \n");
				scanf("%d/%d/%d", &aux.fecha.dia, &aux.fecha.mes, &aux.fecha.anio);
			}

            aux.isEmpty = 0;
            vuelos[indice] = aux;
            todoOk = 1;
        }
    }

	return todoOk;

}

void mostrarVuelo(eVuelo vuelo, eAvion aviones[], int tam_av,eDestino destinos[], int tam_ds, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp){
	char descripcionDestino[30];
	int capacidadAvion;
	float precioDestino;

	if(cargarAvionCapacidad(aviones, tam_av, vuelo.idAvion, &capacidadAvion) &&
	cargarDestinosDescripcion(destinos, tam_ds, vuelo.idDestino, descripcionDestino) &&
	cargarDestinosPrecio(destinos, tam_ds, vuelo.idDestino, &precioDestino)){
		printf("|| %d | %17d |%13s| %10.2f | %d/%d/%d ||\n", vuelo.id, capacidadAvion, descripcionDestino, precioDestino,  vuelo.fecha.dia, vuelo.fecha.mes, vuelo.fecha.anio);
	}

}

int mostrarVuelos(eVuelo vuelos[], int tam_vl, eAvion aviones[], int tam_av,eDestino destinos[], int tam_ds, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp){
	int todoOk = 0;

		if (vuelos != NULL && tam_vl > 0) {
			printf("\n==========================================================================\n");
			printf("||   ID   | CAPACIDAD AVION |    DESTINO    | PRECIO DESTINO |    FECHA    ||\n");
			printf("==========================================================================\n");
			for (int i = 0; i < tam_vl; i++) {
				mostrarVuelo(vuelos[i], aviones, tam_av , destinos, tam_ds, aerolineas, tam_ae, tipos, tam_tp);
			}
			printf("==========================================================================\n");
			todoOk = 1;
		}
		return todoOk;
}
