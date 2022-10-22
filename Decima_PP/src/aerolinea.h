#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct
{
	int id; //comienza en mil
	char descripcion[20];
} eAerolinea;


void hardcodeAerolineas(eAerolinea aerolineas[]);

void mostrarAerolinea(eAerolinea aerolinea);

int mostrarAerolineas(eAerolinea aerolineas[], int tam);

int cargarAerolineaDescripcion(eAerolinea aerolineas[], int tam, int idAerolinea, char descripcion[]);

int validarIdAerolinea(int id, eAerolinea aerolineas[], int tam);

#endif /* AEROLINEA_H_ */
