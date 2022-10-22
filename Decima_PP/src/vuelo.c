#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vuelo.h"
//#include "destino.h"

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

void mostrarVuelo(eVuelo vuelo, eDestino destinos[], int tam_ds){
	char descripcionDestino[30];

	cargarDestinosDescripcion(destinos, tam_ds, vuelo.idDestino, descripcionDestino);

	printf("|| %d | %10d |  %10s  | %d/%d/%d ||\n", vuelo.id, vuelo.idAvion, descripcionDestino, vuelo.fecha.dia, vuelo.fecha.mes, vuelo.fecha.anio);
}

int mostrarVuelos(eVuelo vuelos[], int tam, eDestino destinos[], int tam_ds){
	int todoOk = 0;

		if (vuelos != NULL && tam > 0) {
			printf("|| ID | AVION | DESTINO | FECHA ||\n");
			for (int i = 0; i < tam; i++) {
				mostrarVuelo(vuelos[i], destinos, tam_ds);
			}
			todoOk = 1;
		}
		return todoOk;
}
