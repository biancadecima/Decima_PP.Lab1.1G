#ifndef VUELO_H_
#define VUELO_H_

#include "destino.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct
{
	int id; //autoincremental
	int idAvion;//validar
	int idDestino;//validar
	eFecha fecha; // validar dia, mes y año
} eVuelo;

void hardcodeVuelo(eVuelo vuelos[]);

void mostrarVuelo(eVuelo vuelo, eDestino destinos[], int tam_ds);

int mostrarVuelos(eVuelo vuelos[], int tam, eDestino destinos[], int tam_ds);

#endif /* VUELO_H_ */
