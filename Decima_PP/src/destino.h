#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct
{
	int id; //comienza en 20000
	char descripcion[25];
	float precio;
} eDestino;

/*
brief carga datos de destinos de manera forzada
@param destinos[] recibe array de destinos
 */
void hardcodeDestino(eDestino destinos[]);

/*
brief muestra un destino
@param destino recibe destino
 */
void mostrarDestino(eDestino destino);

/*
brief muestra todos los destinos cargados
@param destinos[] recibe array de destinos
@param tam recibe tamaño del array de destinos
@return 1 si funciono, 0 si no.
 */
int mostrarDestinos(eDestino destinos[], int tam);

/*
brief mediante el id de la aerolinea, carga su descripcion
@param aerolineas[] recibe array de aerolineas
@param tam recibe tamalo del array de aerolineas
@param idAerolinea carga el id de la aerolinea
@param descripcion recibe la descripcion de la aerolinea
@return 1 si funciono, 0 si no
 */
int cargarDestinosDescripcion(eDestino destinos[], int tam, int idDestino, char descripcion[]);

/*
brief mediante el id del destino , carga su precio
@param destinos[] recibe array de destinos
@param tam recibe tamalo del array de destinos
@param idDestino carga el id del destino
@param precio recibe precio del destino
@return 1 si funciono, 0 si no
 */
int cargarDestinosPrecio(eDestino destinos[], int tam, int idDestino, float* precio);

#endif /* DESTINO_H_ */
