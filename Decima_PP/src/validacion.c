#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"

int validarIdAerolinea(int id, eAerolinea aerolineas[], int tam) {
	int valido = 0;

	if (aerolineas != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (aerolineas[i].id == id) {
				valido = 1;
				break;
			}
		}
	}

	return valido;
}

int validarIdTipo(int id, eTipo tipos[], int tam) {
	int valido = 0;

	if (tipos != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (tipos[i].id == id) {
				valido = 1;
				break;
			}
		}
	}

	return valido;
}

int validarIdDestino(int id, eDestino destinos[], int tam) {
	int valido = 0;

	if (destinos != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (destinos[i].id == id) {
				valido = 1;
				break;
			}
		}
	}

	return valido;
}

int validarCapacidad(int capacidad) {
	int valido = 0;

	if (capacidad >= 10 && capacidad <= 300) {
		valido = 1;
	}
	return valido;
}

int validarDia(int dia) {
	int valido = 0;

	if (dia > 0 && dia <= 31) {
		valido = 1;
	}
	return valido;
}

int validarMes(int mes) {
	int valido = 0;

	if (mes > 0 && mes <= 12) {
		valido = 1;
	}
	return valido;
}

int validarAnio(int anio) {
	int valido = 0;

	if (anio > 1990 && anio <= 2022) {
		valido = 1;
	}
	return valido;
}
