#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int parser_PeliculasArchivoTexto(FILE* pFile , LinkedList* pListaPeliculas)
{
	int retorno;
	// lo que levanta el fscanf del archivo
 	char auxId[2000];
	char auxTitulo[2000];
	char auxGenero[2000];
	char auxRating[2000];
	// numero de lecturas que realizo fscanf
	int retornoFscanf;
	eMovie* pPelicula;

	if(pFile != NULL && pListaPeliculas != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTitulo, auxGenero, auxRating);// lectura fantasma
		do{
			retornoFscanf = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTitulo, auxGenero, auxRating);
			if(retornoFscanf == 4){
				pPelicula = pelicula_newParametros(auxId, auxTitulo, auxGenero, auxRating);
				if(pPelicula != NULL){
					ll_add(pListaPeliculas, pPelicula);
					retorno = 1;
				}
			}else{
				retorno = 0;
				break;
			}
		}while(!feof(pFile));
	}

    return retorno;
}


