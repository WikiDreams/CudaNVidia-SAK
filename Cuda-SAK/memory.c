/**
 * @file memory.c
 * @brief Macros for memory managing
 *
 * Macros que ser�o usadas nos programas que requerem o uso das 
 * fun��es malloc e free
 * @version 1
 */
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

/**
 * Esta fun��o deve ser utilizada para auxiliar a aloca��o de mem�ria.
 * Esta fun��o <b>n�o deve</b> ser chamada directamente, mas sim atrav�s
 * da macro MALLOC().
 * @param size tamanho do bloco a alocar
 * @param file nome do ficheiro
 * 	       (atrav�s da macro MALLOC)
 * @param line linha onde a fun��o foi chamada
 * 	       (atrav�s da macro MALLOC)
 * @return O bloco de mem�ria alocado
 * @see MALLOC
 */
void * eipa_malloc(size_t size, const int line, const char * file) {

	void * ptr = malloc(size);

	if( ptr == NULL ) {
		fprintf(stderr, "[%d@%s][ERROR] can't malloc %lu bytes\n", line, file, size);
		exit(EXIT_FAILURE);
	}

	return ptr;
}

/**
 * Esta fun��o deve ser utilizada para auxiliar a realoca��o de mem�ria.
 * Esta fun��o <b>n�o deve</b> ser chamada directamente, mas sim atrav�s
 * da macro REALLOC().
 * @param ptr ponteiro para o endere�o de mem�ria previamente alocado
 * @param size tamanho do bloco a realocar
 * @param file nome do ficheiro
 * 	       (atrav�s da macro REALLOC)
 * @param line linha onde a fun��o foi chamada
 * 	       (atrav�s da macro REALLOC)
 * @return O bloco de mem�ria alocado
 * @see REALLOC
 */
void * eipa_realloc(void ** ptr, size_t size, const int line, const char * file) {

	void * newPtr = realloc(* ptr, size);

	if (newPtr == NULL) {
		fprintf(stderr, "[%d@%s][ERROR] can't realloc %lu bytes\n", line, file, size);
		exit(EXIT_FAILURE);
	}

	return newPtr;
}

/**
 * Esta fun��o deve ser utilizada para auxiliar a liberta��o de mem�ria.
 * Esta fun��o <b>n�o deve</b> ser chamada directamente, mas sim atrav�s
 * da macro FREE().
 * @param ptr endere�o do ponteiro a libertar
 * @param file nome do ficheiro
 * 	       (atrav�s da macro FREE)
 * @param line linha onde a fun��o foi chamada
 * 	       (atrav�s da macro FREE)
 * @return A fun��o n�o retorna nada
 * @see FREE
 */
void eipa_free(void ** ptr, const int line, const char * file) {

	(void) line;
	(void) file;	
	free(* ptr);
	* ptr = NULL;

}
