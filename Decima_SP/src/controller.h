#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "movies.h"
#include "parser.h"
#include "informes.h"

/** \brief Muestra el menu principal y le pide al usuario que seleccione una opcion
 * \return int opcion
 */
int controller_menu();

/** \brief Le pide al usuario una confirmacion antes de salir
 * \return char salir. s si quiere salir, n si no
 */
char controller_confirmarSalida();

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 * \param path char* path del archivo
 * \param pListaPeliculas LinkedList* lista de peliculas
 * \return int retorno. 0 error, 1 exitoso.
 */
int controller_cargarPeliculasArchivoTexto(char *path, LinkedList *pListaPeliculas);

/** \brief Lista las peliculas cargadas
 *
 * \param pListaPeliculas LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_listarPeliculas(LinkedList *pListaPeliculas);

/** \brief filtra la lista por el genero seleccionado y crea un archivo de texto con la misma
 *
 * \param pListaPeliculas LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_filtarPorGenero(LinkedList *pListaPeliculas);

/** \brief ordena la lista por genero y por rating descendente
 *
 * \param pListaPeliculas LinkedList*
* \return int retorno. 0 error, 1 exitoso.
 *
 */
int controller_ordenarPorGeneroYRating(LinkedList *pListaPeliculas);

/** \brief Guarda la lista en el archivo
 * \param path char* path del archivo
 * \param pListaPeliculas LinkedList* lista de peliculas
 * \return int retorno. 0 error, 1 exitoso.
 */
int controller_guardarPeliculasArchivoTexto(char *path, LinkedList *pListaPeliculas);

#endif /* CONTROLLER_H_ */
