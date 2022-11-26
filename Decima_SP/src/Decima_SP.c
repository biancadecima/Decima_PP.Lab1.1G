#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "movies.h"
#include "controller.h"

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaPeliculas = ll_newLinkedList();
	srand(time(NULL)); // la debo llamar para poder usar rand
	char salir = 'n';

	 do {
		switch (controller_menu()) {
		case 1://Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos del mismo.
			if(controller_cargarPeliculasArchivoTexto("movies.csv", listaPeliculas)){
				printf("\nSe cargo correctamente el archivo\n");
			}else{
				printf("\nNo se cargo el archivo\n");
			}
			break;
		case 2:// Imprimir lista: Se imprimirá por pantalla la tabla con los datos de las películas.
			if(ll_isEmpty(listaPeliculas) == 0){
				if(!controller_listarPeliculas(listaPeliculas)){
					printf("\nNo se pudo listar\n");
				}
			}else{
				printf("\nNecesita cargar el archivo\n");
			}
			break;
		case 3://Asignar rating: asignará a la película un valor de rating flotante entre 1 y 10 con 1 decimal calculado de manera aleatoria se mostrará por pantalla el mismo.
			if(ll_isEmpty(listaPeliculas) == 0){
				ll_map(listaPeliculas, asignarRating);
				controller_listarPeliculas(listaPeliculas);
			}else{
				printf("\nNecesita cargar el archivo\n");
			}
			break;
		case 4://Asignar género: asignará a la película un género de acuerdo a un número aleatorio entre 1 y 4.
			if(ll_isEmpty(listaPeliculas) == 0){
				ll_map(listaPeliculas, asignarGenero);
				controller_listarPeliculas(listaPeliculas);
			}else{
				printf("\nNecesita cargar el archivo\n");
			}
			break;
		case 5:// Filtrar por género: Se deberá generar un archivo igual al original, pero donde solo aparezcan películas del género seleccionado.
			if (ll_isEmpty(listaPeliculas) == 0) {
				if (controller_filtarPorGenero(listaPeliculas)) {
					printf("\nSe filtro correctamente el archivo\n");
				} else {
					printf("\nNo se filtro el archivo\n");
				}
			}else{
				printf("\nNecesita cargar el archivo\n");
			}
			break;
		case 6: // Ordenar películas: Se deberá mostrar por pantalla un listado de las películas ordenadas por género y dentro de las del mismo género que aparezcan ordenadas por rating descendente.
			if (ll_isEmpty(listaPeliculas) == 0) {
				if (!controller_ordenarPorGeneroYRating(listaPeliculas)) {
					printf("\nNo se ordeno el archivo\n");
				}
			}else{
				printf("\nNecesita cargar el archivo\n");
			}
			break;
		case 7:// Guardar películas: Se deberá guardar el listado del punto anterior en un archivo de texto
			if (ll_isEmpty(listaPeliculas) == 0) {
				if (controller_guardarPeliculasArchivoTexto("moviesNuevo.csv",listaPeliculas)) {
					printf("\nSe guardo correctamente el archivo\n");
				} else {
					printf("\nNo se guardo el archivo\n");
				}
			}else{
				printf("\nNecesita cargar el archivo\n");
			}
			break;
		case 8:// Salir.
			salir = controller_confirmarSalida();
			break;
		}
	} while (salir == 'n');

	return EXIT_SUCCESS;
}
