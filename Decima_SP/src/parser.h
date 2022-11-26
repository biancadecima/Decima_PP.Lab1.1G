#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "movies.h"

/** \brief abre un archivo y lee sus datos
 * \param FILE* pFile puntero al archivo que se va a leer
 * \param LinkedList* pListaPeliculas Puntero a la lista
 * \return int retorno 0 error, 1 si funciono
 */
int parser_PeliculasArchivoTexto(FILE* pFile , LinkedList* pListaPeliculas);

#endif /* PARSER_H_ */
