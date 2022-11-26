#ifndef INFORMES_H_
#define INFORMES_H_

#include "movies.h"

/** \brief asigna valores de ratings del 1 al 10 aleatoriamente
 * \param void* this elemento de la lista
 */
void asignarRating(void* this);

/** \brief asigna valores de genero del 1 al 4 aleatoriamente
 * \param void* this elemento de la lista
 */
void asignarGenero(void* this);

/** \brief Verifica si el elemento es de genero drama
 * \param void *this elemento de la lista
 * \return  int retorno 0 si no es de genero drama, 1 si lo es
 */
int filtrarPeliculaGeneroDrama(void *this);

/** \brief Verifica si el elemento es de genero comedia
 * \param void *this elemento de la lista
 * \return  int retorno 0 si no es de genero comedia, 1 si lo es
 */
int filtrarPeliculaGeneroComedia(void *this);

/** \brief Verifica si el elemento es de genero accion
 * \param void *this elemento de la lista
 * \return  int retorno 0 si no es de genero accion, 1 si lo es
 */
int filtrarPeliculaGeneroAccion(void *this);

/** \brief Verifica si el elemento es de genero terror
 * \param void *this elemento de la lista
 * \return  int retorno 0 si no es de genero terror, 1 si lo es
 */
int filtrarPeliculaGeneroTerror(void *this);

/** \brief Compara dos valores de rating entre dos elemntos
 * \param void *p1 primer elemento
 * \param void *p2 segundo elemento
 * \return  int retorno 0 si no funciono, 1 si el primero es mayor al segundo, -1 si no lo es
 */
int compararPorRating (void *p1, void *p2);

/** \brief Compara dos generos entre dos elemntos
 * \param void *p1 primer elemento
 * \param void *p2 segundo elemento
 * \return  int retorno 0 si no funciono, 1 si el primero es mayor al segundo, -1 si no lo es
 */
int compararPorGenero (void *p1, void *p2);

#endif /* INFORMES_H_ */
