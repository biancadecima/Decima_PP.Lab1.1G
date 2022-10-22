#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"

void hardcodeDestino(eDestino destinos[]){
	eDestino hardcode[4] = {
				{20000,"Calafate", 22250},
				{20001,"Miami", 103000},
				{20002,"Milan", 84400},
				{20003,"Amsterdam", 95600},
		};

		for(int i = 0; i<4; i++){
			destinos[i] = hardcode[i];
		}
}

void mostrarDestino(eDestino destino){
	printf("|| %d | %10s |  %.2f  ||\n", destino.id, destino.descripcion, destino.precio);
}

int mostrarDestinos(eDestino destinos[], int tam){
	int todoOk = 0;

		if (destinos != NULL && tam > 0) {
			printf("|| ID | DESCRIPCION | PRECIO ||\n");
			for (int i = 0; i < tam; i++) {
				mostrarDestino(destinos[i]);
			}
			todoOk = 1;
		}
		return todoOk;
}

int cargarDestinosDescripcion(eDestino destinos[], int tam, int idDestino, char descripcion[]) { ///Carga la descrpcion a la que pertenece el id en un string idConfederacion
	int todoOk = 0;

	if (destinos != NULL && tam > 0 && descripcion != NULL) {
		for (int i = 0; i < tam; i++) {
			if (destinos[i].id == idDestino) {
				strcpy(descripcion, destinos[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}
