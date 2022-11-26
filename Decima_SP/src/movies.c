#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movies.h"

eMovie* pelicula_new(){
	eMovie* nuevaPelicula = NULL;

	nuevaPelicula = (eMovie*)malloc(sizeof(eMovie));

	if(nuevaPelicula != NULL){
		nuevaPelicula -> id = 0;
		strcpy(nuevaPelicula -> titulo, " ");
		strcpy(nuevaPelicula -> genero, " ");
		nuevaPelicula -> rating = 0;
	}

	return nuevaPelicula;
}

eMovie* pelicula_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr){
	eMovie* nuevaPelicula = pelicula_new();

	if(nuevaPelicula != NULL && idStr != NULL && tituloStr != NULL && generoStr != NULL && ratingStr != NULL){
		if(!(pelicula_setId(nuevaPelicula, atoi(idStr)) &&
			pelicula_setTitulo(nuevaPelicula, tituloStr) &&
			pelicula_setGenero(nuevaPelicula, generoStr) &&
			pelicula_setRating(nuevaPelicula, atoi(ratingStr))))
		{
			free(nuevaPelicula);
			nuevaPelicula = NULL;
		}
	}

	return nuevaPelicula;
}

void pelicula_MostrarPelicula(eMovie* this){
	int id;
	char titulo[100];
	char genero[100];
	int rating;


	if(this != NULL){
		if(pelicula_getId(this, &id)
			&& pelicula_getTitulo(this, titulo)
			&& pelicula_getGenero(this, genero)
			&& pelicula_getRating(this, &rating)){
			printf("| %3d | %-24s | %-20s | %3d |\n", id, titulo, genero, rating);
		}
	}
}

int pelicula_setId(eMovie* this,int id){
	int retorno = 0;

	if(this != NULL){
		this -> id = id;
		retorno = 1;
	}

	return retorno;
}


int pelicula_getId(eMovie* this,int* id){
	int retorno = 0;

	if(this != NULL){
		*id = this -> id;
		retorno = 1;
	}

	return retorno;
}

int pelicula_setTitulo(eMovie *this, char *titulo) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(this->titulo, titulo);
		retorno = 1;
	}

	return retorno;
}

int pelicula_getTitulo(eMovie *this, char *titulo) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(titulo, this->titulo);
		retorno = 1;
	}

	return retorno;
}

int pelicula_setGenero(eMovie *this, char *genero) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(this->genero, genero);
		retorno = 1;
	}

	return retorno;
}

int pelicula_getGenero(eMovie *this, char *genero) {
	int retorno = 0;

	if (this != NULL) {
		strcpy(genero, this->genero);
		retorno = 1;
	}

	return retorno;
}

int pelicula_setRating(eMovie* this,int rating){
	int retorno = 0;

	if(this != NULL){
		this -> rating = rating;
		retorno = 1;
	}

	return retorno;
}

int pelicula_getRating(eMovie* this,int* rating){
	int retorno = 0;

	if(this != NULL){
		*rating = this -> rating;
		retorno = 1;
	}

	return retorno;
}
