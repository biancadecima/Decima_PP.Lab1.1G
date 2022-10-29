#ifndef AVION_H_
#define AVION_H_

#include "aerolinea.h"
#include "tipo.h"
#include "validacion.h"

typedef struct
{
	int id;// autoincremental
	int idAerolinea;//validar
	int idTipo;//validar
	int capacidad; // (cantidad pasajeros entre 10 y 300)
	int isEmpty; // 1 vacio, 0 lleno
} eAvion;

/*
brief Imprime \n para limpiar la consola
 */
void limpiarPantalla();

/*
brief Muestra el menu principal y pide que el usuerio ingrese una opcion
@return int opcion ingresado por el usuario
 */
int menu();

/*
brief le pregunta al usuario si desea salir del programa
@return retorna la respuesta del usuario, s para confirmar, n para cancelar
 */
char confirmarSalida();

/*
brief Verifica el estado del array de aviones
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return 0 vacio, 1 hay al menos un avion, -1 lleno;
 */
int estadoArrayAviones(eAvion aviones[], int tam);

/*
brief Inicializa el campo isEmpty array en uno
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return 1 si funciono, 0 si no
 */
int inicializarAviones(eAvion aviones[], int tam);

/*
brief busca espacio libre en el array de aviones
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return el indice del array libre si funciono, -1 si no
 */
int buscarLibreAvion(eAvion aviones[], int tam);

/*
brief
@param aviones[] recibe array de aviones
@param tam recibe tamaño del array de aviones
@param id asigna un id autoincremental
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tamaño del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tamaño del array de tipos
@return 1 si funciono, 0 si no
 */
int altaAvion(eAvion aviones[], int tam, int* pId, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief muestra un avion
@param aviones[] recibe array de aviones
@param tam recibe tamaño del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tamaño del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tamaño del array de tipos
 */
void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief muestra todos los aviones ingresados
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return 1 si funciono, 0 si no
 */
int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief Recorre el array de aviones buscando una coincidencia de id
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return indice del avion si funciono, 0 si no
 */
int buscarAvionId(eAvion aviones[], int tam, int id);

/*
brief realiza una baja logica del avion mediante su id
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return 1 si funciono, 0 si no
 */
int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief modifica algun campo del avion mediante su id
@param aviones[] recibe array de aviones
@param tam recibe tamaño del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tamaño del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tamaño del array de tipos
@return 1 si funciono, 0 si no
 */
int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief mediante el id del avion, carga su capacidad
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@param idAvion carga el id del avion
@param capacidad recibe la capacidad del avion
@return 1 si funciono, 0 si no
 */
int cargarAvionCapacidad(eAvion aviones[], int tam, int idAvion, int* capacidad);

/*
brief ordena el array de aviones ordenados por aerolínea y capacidad.
@param aviones[] recibe array de aviones
@param tam recibe tamalo del array de aviones
@return 1 si funciono, 0 si no
 */
int ordenarAvionesDobleCriterio(eAvion aviones[], int tam);

#endif /* AVION_H_ */
