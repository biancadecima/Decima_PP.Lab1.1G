#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"

void hardcodeTipo(eTipo tipos[]){
	eTipo hardcode[4] = {
				{5000,"Jet"},
				{5001,"Helice"},
				{5002,"Planeador"},
				{5003,"Carga"},
		};

		for(int i = 0; i<4; i++){
			tipos[i] = hardcode[i];
		}
}

void mostrarTipo(eTipo tipo){
	printf("|| %d | %10s  ||\n", tipo.id, tipo.descripcion);
}

int mostrarTipos(eTipo tipos[], int tam){
	int todoOk = 0;

		if (tipos != NULL && tam > 0) {
			printf("\n========================\n");
			printf("||  ID  | DESCRIPCION ||\n");
			printf("========================\n");
			for (int i = 0; i < tam; i++) {
				mostrarTipo(tipos[i]);
			}
			printf("========================\n");
			todoOk = 1;
		}
		return todoOk;
}

int cargarTiposDescripcion(eTipo tipos[], int tam, int idTipo, char descripcion[]) { ///Carga la descrpcion a la que pertenece el id en un string idConfederacion
	int todoOk = 0;

	if (tipos != NULL && tam > 0 && descripcion != NULL) {
		for (int i = 0; i < tam; i++) {
			if (tipos[i].id == idTipo) {
				strcpy(descripcion, tipos[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

