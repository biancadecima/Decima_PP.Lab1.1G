#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct
{
	int id; //comienza en 20000
	char descripcion[25];
	float precio;
} eDestino;

void hardcodeDestino(eDestino destinos[]);

void mostrarDestino(eDestino destino);

int mostrarDestinos(eDestino destinos[], int tam);

int cargarDestinosDescripcion(eDestino destinos[], int tam, int idDestino, char descripcion[]);

#endif /* DESTINO_H_ */
