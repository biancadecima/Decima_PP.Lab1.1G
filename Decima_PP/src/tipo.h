#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int id; //comienza en 5mil
	char descripcion[20];
} eTipo;

void hardcodeTipo(eTipo tipos[]);

void mostrarTipo(eTipo tipo);

int mostrarTipos(eTipo tipos[], int tam);

int cargarTiposDescripcion(eTipo tipos[], int tam, int idTipo, char descripcion[]);

int validarIdTipo(int id, eTipo tipos[], int tam);

#endif /* TIPO_H_ */
