#ifndef INFORMES_H_
#define INFORMES_H_

#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"

/*
brief Muestra el menu de informes y pide que el usuerio ingrese una opcion
@return int opcion ingresado por el usuario
 */
int menuInformes();

/*
brief Muestra aviones de la aerol�nea seleccionada por el usuario.
@param aviones[] recibe array de aviones
@param tam recibe tama�o del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tama�o del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tama�o del array de tipos
@return 1 si funciono, 0 si no
 */
int mostrarAvionesAerolinea(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief Muestra aviones de un tipo seleccionado.
@param aviones[] recibe array de aviones
@param tam recibe tama�o del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tama�o del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tama�o del array de tipos
@return 1 si funciono, 0 si no
 */
int mostrarAvionesTipo(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief calcula e informa PORCENTAJE de aviones jet sobre el total de aviones de una aerol�nea solicitada
@param aviones[] recibe array de aviones
@param tam recibe tama�o del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tama�o del array de aerolineas
@return 1 si funciono, 0 si no
 */
int porcentajeJetAerolinea(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae);

/*
brief muestra un listado de los aviones separados por aerol�nea
@param aviones[] recibe array de aviones
@param tam recibe tama�o del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tama�o del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tama�o del array de tipos
@return 1 si funciono, 0 si no
 */
int mostrarAvionesPorAerolineas(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae, eTipo tipos[], int tam_tp);

/*
brief calcula e informa la o las aerol�neas que pueden transportar mas pasajeros
@param aviones[] recibe array de aviones
@param tam recibe tama�o del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tama�o del array de aerolineas
@return 1 si funciono, 0 si no
 */
int mayorCapacidadAerolineas(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae);

/*
brief calcula y muestra la aerol�nea con menor cantidad de aviones
@param aviones[] recibe array de aviones
@param tam recibe tama�o del array de aviones
@param aerolineas[] recibe array de aerolineas
@param tam_ae recibe tama�o del array de aerolineas
@param tipos[] recibe array de tipos
@param tam_tp recibe tama�o del array de tipos
@return 1 si funciono, 0 si no
 */
int menorAvionesAerolinea(eAvion aviones[], int tam_av, eAerolinea aerolineas[], int tam_ae);

#endif /* INFORMES_H_ */
