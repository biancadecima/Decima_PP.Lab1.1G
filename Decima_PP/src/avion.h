#ifndef AVION_H_
#define AVION_H_

#include "aerolinea.h"
#include "tipo.h"

typedef struct
{
	int id;// autoincremental
	int idAerolinea;//validar
	int idTipo;//validar
	int capacidad; // (cantidad pasajeros entre 10 y 300)
	int isEmpty; // 1 vacio, 0 lleno
} eAvion;

void limpiarPantalla();

int menu();

char confirmarSalida();

int inicializarAviones(eAvion aviones[], int tam);

int buscarLibre(eAvion aviones[], int tam);

int altaAvion(eAvion aviones[], int tam, int* pId, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

int buscarAvionId(eAvion aviones[], int tam, int id);

int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

int ordenarAvionesDobleCriterio(eAvion aviones[], int tam);

#endif /* AVION_H_ */
