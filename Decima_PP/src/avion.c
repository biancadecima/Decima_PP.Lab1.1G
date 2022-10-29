#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avion.h"

void limpiarPantalla(){
	for(int i = 0; i<40; i++){
		printf("\n");
	}
}

int menu()
{
    int opcion;
    printf("    *** ABM AVION *** \n\n");
    printf("1- Alta avion\n");
    printf("2- Modificar avion\n");
    printf("3- Baja avion\n");
    printf("4- Listar aviones\n");
    printf("5- Listar aerolineas\n");
    printf("6- Listar tipos\n");
    printf("7- Listar destinos\n");
    printf("8- Alta vuelo\n");
    printf("9- Listar vuelos\n");
    printf("10- Informes\n");
    printf("11- salir\n");
    printf("\nIngrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

char confirmarSalida() {
	char salir;

	printf("Desea salir del programa?\n Presione 's' para confirmar, 'n' para cancelar: ");
	fflush(stdin);
	scanf("%c", &salir);
	while (salir != 'n' && salir != 's') {
		printf("\nOpción invalida. Reingrese: ");
		fflush(stdin);
		scanf("%c", &salir);
	}

	return salir;
}

int estadoArrayAviones(eAvion aviones[], int tam) {
	int rtn = 0;
	int contador = 0;

	for (int i = 0; i < tam; i++) {
		if (aviones[i].isEmpty == 0) {
			contador++;
			rtn = 1;
		}
	}
	if (contador == tam) {
		rtn = -1;
	}

	return rtn;
}

int inicializarAviones(eAvion aviones[], int tam)
{
    int todoOk = 0;

    if(aviones != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
        	aviones[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreAvion(eAvion aviones[], int tam)
{
    int indice = -1;
    for (int i = 0 ; i < tam; i++)
    {
        if(aviones[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAvion(eAvion aviones[], int tam, int* pId, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp)
{
    int todoOk = 0;
    int indice;
    eAvion aux;

    if(aviones != NULL && tam > 0)
    {
        indice = buscarLibreAvion(aviones, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            printf("\n***** ALTA AVION ******\n");

            aux.id = *pId;
            (*pId)++;

            mostrarAerolineas(aerolineas, tam_ae);
            printf("\nIngrese ID de la aerolinea: \n");
            scanf("%d", &aux.idAerolinea);
            while(!validarIdAerolinea(aux.idAerolinea, aerolineas, tam_ae)){
            	printf("\n Id aerolinea invalido. Reingrese ID de aerolinea: \n");
            	scanf("%d", &aux.idAerolinea);
            }

            mostrarTipos(tipos, tam_tp);
            printf("Ingrese ID del tipo: \n");
            scanf("%d", &aux.idTipo);
            while(!validarIdTipo(aux.idTipo, tipos, tam_tp)){
            	printf("\n Id tipo invalido. Reingrese ID del tipo: \n");
            	scanf("%d", &aux.idTipo);
            }

			printf("Ingrese capacidad del vuelo: \n");
			scanf("%d", &aux.capacidad);
			while (!validarCapacidad(aux.capacidad)) {
				printf("\nCapacidad inválida. Reingrese capacidad del vuelo: \n");
				scanf("%d", &aux.capacidad);
			}

            aux.isEmpty = 0;
            aviones[indice] = aux;
            todoOk = 1;
        }
    }

    return todoOk;
}

void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp)
{
   char descripcionAerolinea[20];
   char descripcionTipo[20];

   cargarAerolineaDescripcion(aerolineas, tam_ae, aviones.idAerolinea, descripcionAerolinea);
   cargarTiposDescripcion(tipos, tam_tp, aviones.idTipo, descripcionTipo);

	printf("| %6d| %12s|  %9s|  %6d|\n", aviones.id, descripcionAerolinea, descripcionTipo, aviones.capacidad);
}

int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp) {
	int todoOk = 0;
	if (aviones != NULL && tam > 0) {
		printf("***** LISTA DE AVIONES *****\n");
		printf("****************************\n");
		printf("================================================\n");
		printf("||  ID  ||  AEROLINEA ||   TIPO   || CAPACIDAD ||\n");
		printf("================================================\n");
		for (int i = 0; i < tam; i++) {
			if (aviones[i].isEmpty == 0) {
				mostrarAvion(aviones[i], aerolineas, tam_ae, tipos, tam_tp);
			}
		}
		printf("================================================\n");
		todoOk = 1;
	}

	return todoOk;

}

int buscarAvionId(eAvion aviones[], int tam, int id) {
	int indice = -1;
	for (int i = 0; i < tam; i++) {
		if (!aviones[i].isEmpty && aviones[i].id == id) {
			indice = i;
			break;
		}
	}

	return indice;
}


int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp) {
	int indice;
	int todoOk = 0;
	int id;
	char confirma;

	if (aviones != NULL && tam > 0) {
		printf("*** BAJA AVION *** \n\n");
		mostrarAviones(aviones, tam, aerolineas, tam_ae, tipos, tam_tp);
		printf("\nIngrese id del avion que desea eliminar: \n");
		scanf("%d", &id);
		indice = (buscarAvionId(aviones, tam, id));
		if (indice == -1) {
			printf("El id %d no esta registrado", id);
		} else {
			mostrarAvion(aviones[indice], aerolineas, tam_ae, tipos, tam_tp);
			printf("\nConfirma baja?");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				aviones[indice].isEmpty = 1;
				todoOk = 1;

			} else {
				printf("Baja cancelada");
			}
		}
	}

	return todoOk;
}

int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp){
	int todoOk = 0;
	int id;
	int indice;
	int opcion;
	char confirma;
	int aux;

	if (aviones != NULL && tam > 0) {
		printf("* MODIFICAR PERSONA * \n\n");

		mostrarAviones(aviones, tam, aerolineas, tam_ae, tipos, tam_tp);
		printf("\nIngrese id del avion que desea modificar: \n");
		scanf("%d", &id);
		indice = (buscarAvionId(aviones, tam, id));
		if (indice == -1) {
			printf("\n No se encontro el id \n");
		} else {
			mostrarAvion(aviones[indice], aerolineas, tam_ae, tipos, tam_tp);
			printf("\nConfirma modificacion?\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				printf("* MODIFICAR AVION * \n\n");
				printf("1- Tipo\n2- Capacidad\nIngrese opcion:\n");
				scanf("%d", &opcion);
				switch (opcion) {
				case 1:
					mostrarTipos(tipos, tam_tp);
					printf("Ingrese nuevo id tipo: \n");
					scanf("%d", &aux);
					while (!validarIdTipo(aux, tipos, tam_tp)) {
						printf("\n Id tipo invalido. Reingrese ID del tipo: \n");
						scanf("%d", &aux);
					}
					aviones[indice].idTipo = aux;
					break;
				case 2:
					 printf("Ingrese nueva capacidad: \n");
					 scanf("%d", &aux);
					 aviones[indice].capacidad = aux;
					 break;
				}
			} else {
				printf("\nModificacion cancelada\n");
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

int cargarAvionCapacidad(eAvion aviones[], int tam, int idAvion, int* capacidad) {
	int todoOk = 0;

	if (aviones != NULL && tam > 0 && capacidad != NULL) {
		for (int i = 0; i < tam; i++) {
			if (aviones[i].id == idAvion) {
				*capacidad = aviones[i].capacidad;
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;
}

int ordenarAvionesDobleCriterio(eAvion aviones[], int tam){
	int todoOk = 0;
	eAvion aux;

	if(aviones != NULL && tam > 0){
		for(int i =0; i<tam-1; i++){
			for(int j =i+1; j<tam; j++){
				if((aviones[i].idAerolinea > aviones[j].idAerolinea) || (aviones[i].idAerolinea == aviones[j].idAerolinea && aviones[i].capacidad > aviones[j].capacidad)){
					aux = aviones[i];
					aviones[i] = aviones[j];
					aviones[j] = aux;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

