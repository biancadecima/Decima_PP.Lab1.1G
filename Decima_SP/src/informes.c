#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"

void asignarRating(void* this)
{
	eMovie* pPelicula = NULL;
    int rating;
    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;
    	if(pPelicula != NULL){
			pelicula_getRating(pPelicula, &rating);
			if (rating == 0) {
				rating = rand()%10 + 1;
				pelicula_setRating(pPelicula, rating);
			}
    	}
    }
}

void asignarGenero(void* this)
{
	eMovie* pPelicula = NULL;
	int randGenero;
    char genero[50];
    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;
    	if(pPelicula != NULL){
    		pelicula_getGenero(pPelicula, genero);
			if (strcmp(genero, "sin genero") == 0) {
				randGenero = rand()% 4 + 1;
				switch(randGenero){
				case 1:
					strcpy(genero, "drama");
					pelicula_setGenero(pPelicula, genero);
					break;
				case 2:
					strcpy(genero, "comedia");
					pelicula_setGenero(pPelicula, genero);
					break;
				case 3:
					strcpy(genero, "accion");
					pelicula_setGenero(pPelicula, genero);
					break;
				case 4:
					strcpy(genero, "terror");
					pelicula_setGenero(pPelicula, genero);
					break;
				}
			}
    	}
    }
}

int filtrarPeliculaGeneroDrama(void *this)
{
	eMovie* pPelicula = NULL;
	char auxGenero[100];
    int retorno = 0;

    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;
		if (pPelicula != NULL) {
			pelicula_getGenero(pPelicula, auxGenero);
			if (strcmp(auxGenero, "drama") == 0) {
				retorno = 1;
			}
		}
    }

    return retorno;
}

int filtrarPeliculaGeneroComedia(void *this)
{
	eMovie* pPelicula = NULL;
	char auxGenero[100];
    int retorno = 0;

    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;
		if (pPelicula != NULL) {
			pelicula_getGenero(pPelicula, auxGenero);
			if (strcmp(auxGenero, "comedia") == 0) {
				retorno = 1;
			}
		}

    }
    return retorno;
}

int filtrarPeliculaGeneroAccion(void *this)
{
	eMovie* pPelicula = NULL;
	char auxGenero[100];
    int retorno = 0;

    if(this != NULL)
    {
		pPelicula = (eMovie*) this;
		if (pPelicula != NULL) {
			pelicula_getGenero(pPelicula, auxGenero);
			if (strcmp(auxGenero, "accion") == 0) {
				retorno = 1;
			}
		}

    }
    return retorno;
}

int filtrarPeliculaGeneroTerror(void *this)
{
	eMovie* pPelicula = NULL;
	char auxGenero[100];
    int retorno = 0;

    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;
		if (pPelicula != NULL) {
			pelicula_getGenero(pPelicula, auxGenero);
			if (strcmp(auxGenero, "terror") == 0) {
				retorno = 1;
			}
		}

    }
    return retorno;
}

int compararPorRating (void *p1, void *p2) {
	int compara = 0;
	eMovie* pPeliculaUno = NULL;
	eMovie* pPeliculaDos = NULL;
	int rating1;
	int rating2;

	if (p1 != NULL && p2 != NULL) {
		pPeliculaUno = (eMovie*) p1;
		pPeliculaDos = (eMovie*) p2;
		if (pPeliculaUno != NULL && pPeliculaDos != NULL) {
			pelicula_getRating(pPeliculaUno, &rating1);
			pelicula_getRating(pPeliculaDos, &rating2);
			if(rating1 > rating2){
				compara = 1;
			}else{
				compara = -1;
			}
		}
	}

	return compara;
}

int compararPorGenero (void *p1, void *p2) {
	int compara = 0;
	eMovie* pPeliculaUno = NULL;
	eMovie* pPeliculaDos = NULL;
	char genero1[100];
	char genero2[100];

	if (p1 != NULL && p2 != NULL) {
		pPeliculaUno = (eMovie*) p1;
		pPeliculaDos = (eMovie*) p2;
		if (pPeliculaUno != NULL && pPeliculaDos != NULL) {
			pelicula_getGenero(pPeliculaUno, genero1);
			pelicula_getGenero(pPeliculaDos, genero2);
			compara = strcmp(genero1, genero2);
		}
	}

	return compara;
}
