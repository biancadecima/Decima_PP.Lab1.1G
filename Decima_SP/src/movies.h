#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct{
	int id;
	char titulo[100];
	char genero[100];
	int rating;
}eMovie;

/** \brief Pide memoria dinamica e inicializa los datos
 * \return eMovie*
 */
eMovie* pelicula_new();

/** \brief pide memoria dinamica y carga a una pelicula con datos
 *
 * \param idStr char*
 * \param tituloStr char*
 * \param generoStr char*
 * \param ratingStr char*
 * \return eMovie*
 */
eMovie* pelicula_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr);

/** \brief muestra una pelicula
 *
 * \param eMovie* this
 */
void pelicula_MostrarPelicula(eMovie* this);

/** \brief carga el id a una pelicula
 *
 * \param eMovie* this
 * \param int id
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_setId(eMovie* this,int id);

/** \brief consigue el id de una pelicula
 *
 * \param eMovie* this
 * \param int* id
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_getId(eMovie* this,int* id);

/** \brief carga el titulo a una pelicula
 *
 * \param eMovie* this
 * \param char *titulo
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_setTitulo(eMovie *this, char *titulo);

/** \brief consigue el titulo de una pelicula
 *
 * \param eMovie* this
 * \param char *titulo
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_getTitulo(eMovie *this, char *titulo);

/** \brief carga el genero a una pelicula
 *
 * \param eMovie* this
 * \param char *genero
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_setGenero(eMovie *this, char *genero);

/** \brief consigue el genero de una pelicula
 *
 * \param eMovie* this
 * \param char *genero
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_getGenero(eMovie *this, char *genero);

/** \brief carga el rating a una pelicula
 *
 * \param eMovie* this
 * \param int rating
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_setRating(eMovie* this,int rating);

/** \brief consigue el rating de una pelicula
 *
 * \param eMovie* this
 * \param int* rating
 * \return  int retorno. 0 error, 1 exitoso.
 */
int pelicula_getRating(eMovie* this,int* rating);

#endif /* MOVIES_H_ */
