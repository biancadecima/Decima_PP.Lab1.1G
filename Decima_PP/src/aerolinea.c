#include "aerolinea.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"

void hardcodeAerolineas(eAerolinea aerolineas[]){
	eAerolinea hardcode[5] = {
				{1000,"Lan"},
				{1001,"Iberia"},
				{1002,"Norwegian"},
				{1003,"American"},
				{1004,"Austral"},
		};

		for(int i = 0; i<5; i++){
			aerolineas[i] = hardcode[i];
		}
}

void mostrarAerolinea(eAerolinea aerolinea){
	printf("|| %d | %10s  ||\n", aerolinea.id, aerolinea.descripcion);
}

int mostrarAerolineas(eAerolinea aerolineas[], int tam){
	int todoOk = 0;

		if (aerolineas != NULL && tam > 0) {
			printf("\n========================\n");
			printf("||  ID  | DESCRIPCION ||\n");
			printf("========================\n");
			for (int i = 0; i < tam; i++) {
				mostrarAerolinea(aerolineas[i]);
			}
			printf("========================\n");
			todoOk = 1;
		}
		return todoOk;
}

int cargarAerolineaDescripcion(eAerolinea aerolineas[], int tam, int idAerolinea, char descripcion[]) {
	int todoOk = 0;

	if (aerolineas != NULL && tam > 0 && descripcion != NULL) {
		for (int i = 0; i < tam; i++) {
			if (aerolineas[i].id == idAerolinea) {
				strcpy(descripcion, aerolineas[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

