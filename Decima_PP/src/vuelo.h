#ifndef VUELO_H_
#define VUELO_H_
#include "fecha.h"
#include "destino.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"

typedef struct
{
	int id; //autoincremental
	int idAvion;//validar
	int idDestino;//validar
	eFecha fecha; // validar dia, mes y año
	int isEmpty;
} eVuelo;

/*
brief carga datos de vuelos de manera forzada
@param vuelos[] recibe array de tipos
 */
void hardcodeVuelo(eVuelo vuelos[]);

/*
brief Verifica el estado del array de vuelos
@param vuelos[] recibe array de vuelos
@param tam_vl recibe tamalo del array de vuelos
@return 0 vacio, 1 hay al menos un avion, -1 lleno;
 */
int estadoArrayVuelos(eVuelo vuelos[], int tam_vl);

/*
brief Inicializa el campo isEmpty array en uno
@param vuelos[] recibe array de vuelos
@param tam_vl recibe tamalo del array de vuelos
@return 1 si funciono, 0 si no
 */
int inicializaVuelos(eVuelo vuelos[], int tam_vl);

/*
brief busca espacio libre en el array de vuelos
@param vuelos[] recibe array de vuelos
@param tam_vl recibe tamalo del array de vuelos
@return el indice del array libre si funciono, -1 si no
 */
int buscarLibreVuelo(eVuelo vuelos[], int tam_vl);

/*
brief carga los datos de un vuelo
@param vuelos[] recibe array de vuelos
@param tam_vl recibe tamaño del array de vuelos
@param aviones[] recibe array de aviones
@param tam_av recibe tamaño del array de aviones
@param destinos[] recibe array de destinos
@param tam_ds recibe tamaño del array de destinos
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tamaño del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tamaño del array de tipos
@param pIdVuelo asigna un id autoincremental
@return 1 si funciono, 0 si no
 */
int altaVuelo(eVuelo vuelos[], int tam_vl, eDestino destinos[], int tam_ds, eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp, int *pIdVuelo);

/*
brief muestra un vuelo
@param vuelos[] recibe array de vuelos
@param tam_vl recibe tamaño del array de vuelos
@param aviones[] recibe array de aviones
@param tam_av recibe tamaño del array de aviones
@param destinos[] recibe array de destinos
@param tam_ds recibe tamaño del array de destinos
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tamaño del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tamaño del array de tipos
 */
void mostrarVuelo(eVuelo vuelo, eAvion aviones[], int tam_av,eDestino destinos[], int tam_ds, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief muestra todos los vuelos
@param vuelos[] recibe array de vuelos
@param tam_vl recibe tamaño del array de vuelos
@param aviones[] recibe array de aviones
@param tam_av recibe tamaño del array de aviones
@param destinos[] recibe array de destinos
@param tam_ds recibe tamaño del array de destinos
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tamaño del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tamaño del array de tipos
@return 1 si funciono, 0 si no
 */
int mostrarVuelos(eVuelo vuelos[], int tam_vl, eAvion aviones[], int tam_av,eDestino destinos[], int tam_ds, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

#endif /* VUELO_H_ */
