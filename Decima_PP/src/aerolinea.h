#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct
{
	int id; //comienza en mil
	char descripcion[20];
} eAerolinea;

/*
brief carga datos de aerolineas de manera forzada
@param aerolineas[] recibe array de aerolineas
 */
void hardcodeAerolineas(eAerolinea aerolineas[]);

/*
brief muestra una aerolinea
@param aerolinea recibe aerolinea
 */
void mostrarAerolinea(eAerolinea aerolinea);

/*
brief muestra todas las aerolineas cargadas
@param aerolineas[] recibe array de aerolineas
@param tam recibe tamaño del array de aerolineas
@return 1 si funciono, 0 si no.
 */
int mostrarAerolineas(eAerolinea aerolineas[], int tam);

/*
brief mediante el id de la aerolinea, carga su descripcion
@param aerolineas[] recibe array de aerolineas
@param tam recibe tamalo del array de aerolineas
@param idAerolinea carga el id de la aerolinea
@param descripcion recibe la descripcion de la aerolinea
@return 1 si funciono, 0 si no
 */
int cargarAerolineaDescripcion(eAerolinea aerolineas[], int tam, int idAerolinea, char descripcion[]);

#endif /* AEROLINEA_H_ */
