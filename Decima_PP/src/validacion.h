#ifndef VALIDACION_H_
#define VALIDACION_H_

#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"

/**
* \brief valida la existencia de un id de aerolinea ingresado
* \param id id de aerolinea ingresado
* \param aerolineas array de aerolinea
* \param tam tamaño del array de aerolinea
* \return 1 si es valido, 0 si no
*/
int validarIdAerolinea(int id, eAerolinea aerolineas[], int tam);

/**
* \brief valida la existencia de un id de tipos ingresado
* \param id id de tipos ingresado
* \param tipos array de tipos
* \param tam tamaño del array de tipos
* \return 1 si es valido, 0 si no
*/
int validarIdTipo(int id, eTipo tipos[], int tam);

/**
* \brief valida la existencia de un id de destinos ingresado
* \param id id de destinos ingresado
* \param destinos array de destinos
* \param tam tamaño del array de destinos
* \return 1 si es valido, 0 si no
*/
int validarIdDestino(int id, eDestino destinos[], int tam);

/**
* \brief valida el valor de la capacidad ingresado
* \param  capacidad valor de la capacidad ingresado
* \return 1 si es valido, 0 si no
*/
int validarCapacidad(int capacidad);

/**
* \brief valida el valor del dia ingresado
* \param  dia valor del dia ingresado
* \return 1 si es valido, 0 si no
*/
int validarDia(int dia);

/**
* \brief valida el valor del mes ingresado
* \param  mes valor del mes ingresado
* \return 1 si es valido, 0 si no
*/
int validarMes(int mes);

/**
* \brief valida el valor del año ingresado
* \param  anio valor del año ingresado
* \return 1 si es valido, 0 si no
*/
int validarAnio(int anio);

#endif /* VALIDACION_H_ */
