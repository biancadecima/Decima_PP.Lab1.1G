#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "controller.h"

int controller_menu()
{
    int opcion;
    printf("\n\n    *** PELICULAS *** \n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir peliculas\n");
    printf("3- Asignar rating\n");
    printf("4- Asignar género\n");
    printf("5- Filtrar por género\n");
    printf("6- Ordenar películas por genero y rating descendente\n");
    printf("7- Guardar archivo de películas\n");
    printf("8- Salir\n");
    printf("\nIngrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

char controller_confirmarSalida() {
	char salir;

	printf("\n\nDesea salir del programa?\n Presione 's' para confirmar, 'n' para cancelar: ");
	fflush(stdin);
	scanf("%c", &salir);
	while (salir != 'n' && salir != 's') {
		printf("\nOpción invalida. Reingrese: ");
		fflush(stdin);
		scanf("%c", &salir);
	}

	return salir;
}

int controller_cargarPeliculasArchivoTexto(char *path, LinkedList *pListaPeliculas) {
	int retorno;
	FILE *pArchivo;
	int rtnParserPeli;

	if (path != NULL && pListaPeliculas != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL) {
			rtnParserPeli = parser_PeliculasArchivoTexto(pArchivo, pListaPeliculas);
			if (rtnParserPeli == 1) {
				retorno = 1;
			} else {
				retorno = 0;
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}

int controller_listarPeliculas(LinkedList *pListaPeliculas) {
	int retorno = 0;
	int largoList;
	eMovie *pPelicula = NULL;

	if (pListaPeliculas != NULL) {

		largoList = ll_len(pListaPeliculas);

		printf("\n*** LISTA DE PELICULAS ***\n");
		printf("================================================================\n");
		printf("|  ID  |          TITULO          |       GENERO      | RATING |\n");
		printf("================================================================\n");
		for (int i = 0; i < largoList; i++) {
			pPelicula = (eMovie*) ll_get(pListaPeliculas, i);
			if (pPelicula != NULL && ll_isEmpty(pListaPeliculas) == 0) {
				pelicula_MostrarPelicula(pPelicula);
				retorno = 1;
			}
			printf("================================================================\n");
		}
	}
	return retorno;
}

int controller_filtarPorGenero(LinkedList *pListaPeliculas){
	int retorno = 0;
	LinkedList*  listaFiltradaPorGenero = ll_newLinkedList();

	if(pListaPeliculas != NULL){
		int opcion;
	    printf("\n\n    *** FILTRAR POR GENERO *** \n\n");
	    printf("1- Genero drama\n");
	    printf("2- Genero comedia\n");
	    printf("3- Genero accion\n");
	    printf("4- Genero terror\n");
	    printf("\nIngrese opcion: \n");
	    scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			listaFiltradaPorGenero = ll_filter(pListaPeliculas,filtrarPeliculaGeneroDrama);
			if (listaFiltradaPorGenero != NULL) {
				controller_listarPeliculas(listaFiltradaPorGenero);
				if (controller_guardarPeliculasArchivoTexto("drama.csv",listaFiltradaPorGenero)) {
					printf("\nSe cargo correctamente el archivo\n");
					retorno = 1;
				}
			} else {
				printf("\nNo se encontraron peliculas del genero\n");
			}
			break;
		case 2:
			listaFiltradaPorGenero = ll_filter(pListaPeliculas,filtrarPeliculaGeneroComedia);
			if (listaFiltradaPorGenero != NULL) {
				if (controller_guardarPeliculasArchivoTexto("comedia.csv",listaFiltradaPorGenero)) {
					printf("\nSe cargo correctamente el archivo\n");
					retorno = 1;
				}
			} else {
				printf("\nNo se encontraron peliculas del genero\n");
			}
			break;
		case 3:
			listaFiltradaPorGenero = ll_filter(pListaPeliculas,filtrarPeliculaGeneroAccion);
			if (listaFiltradaPorGenero != NULL) {
				if (controller_guardarPeliculasArchivoTexto("accion.csv",listaFiltradaPorGenero)) {
					printf("\nSe cargo correctamente el archivo\n");
					retorno = 1;
				}
			} else {
				printf("\nNo se encontraron peliculas del genero\n");
			}
			break;
		case 4:
			listaFiltradaPorGenero = ll_filter(pListaPeliculas,filtrarPeliculaGeneroTerror);
			if (listaFiltradaPorGenero != NULL) {
				if (controller_guardarPeliculasArchivoTexto("terror.csv",listaFiltradaPorGenero)) {
					printf("\nSe cargo correctamente el archivo\n");
					retorno = 1;
				}
			} else {
				printf("\nNo se encontraron peliculas del genero\n");
			}
			break;
		}
	 ll_deleteLinkedList(listaFiltradaPorGenero);
	}

	return retorno;
}

int controller_ordenarPorGeneroYRating(LinkedList *pListaPeliculas){
	int retorno = 0;
	LinkedList* listaOrdenada = ll_newLinkedList();

	if (listaOrdenada != NULL) {
		listaOrdenada = ll_clone(pListaPeliculas);
		if (ll_sort(listaOrdenada, compararPorRating, 0) == 0) { // primero ordeno por rating
			if(ll_sort(listaOrdenada, compararPorGenero, 1) == 0){// luego por genero
				controller_listarPeliculas(listaOrdenada);
				retorno = 1;
			}
		}
	}

	 ll_deleteLinkedList(listaOrdenada);

	return retorno;
}

int controller_guardarPeliculasArchivoTexto(char *path, LinkedList *pListaPeliculas) {
	int retorno = 0;
	FILE *pArchivo;
	eMovie* pPelicula = NULL;
	int largoPeliculas;
	int id;
	char titulo[100];
	char genero[100];
	int rating;

	if (path != NULL && pListaPeliculas != NULL) {
		largoPeliculas = ll_len(pListaPeliculas);
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL && largoPeliculas > 0) {
			fprintf(pArchivo, "id,titulo,genero,rating\n");
			for (int i = 0; i < largoPeliculas; i++) {
				pPelicula = (eMovie*) ll_get(pListaPeliculas, i);
				if (pPelicula != NULL) {
					if (pelicula_getId(pPelicula, &id)
							&& pelicula_getTitulo(pPelicula, titulo)
							&& pelicula_getGenero(pPelicula, genero)
							&& pelicula_getRating(pPelicula, &rating)) {
						fprintf(pArchivo, "%d,%s,%s,%d\n", id, titulo, genero, rating);
						retorno = 1;

					}
				}
			}
			fclose(pArchivo);
		}

	}

	return retorno;
}
