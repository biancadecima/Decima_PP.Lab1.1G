#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int id; //comienza en 5mil
	char descripcion[20];
} eTipo;

/*
brief carga datos de tipos de manera forzada
@param tipos[] recibe array de tipos
 */
void hardcodeTipo(eTipo tipos[]);

/*
brief muestra un tipo
@param tipos recibe tipo
 */
void mostrarTipo(eTipo tipo);

/*
brief muestra todos los tipos cargados
@param tipos[] recibe array de tipos
@param tam recibe tamaño del array de tipos
@return 1 si funciono, 0 si no.
 */
int mostrarTipos(eTipo tipos[], int tam);

/*
brief mediante el id del tipo, carga su descripcion
@param tipos[] recibe array de tipos
@param tam recibe tamaño del array de tipos
@param idTipo carga el id de la tipo
@param descripcion recibe la descripcion del tipo
@return 1 si funciono, 0 si no
 */
int cargarTiposDescripcion(eTipo tipos[], int tam, int idTipo, char descripcion[]);

#endif /* TIPO_H_ */
