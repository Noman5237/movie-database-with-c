/**
 * @file: movie.h
 * @author: Anonyman637
 * @date: 3/17/2021; 4:36 PM
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <stdio.h>
#include <stdlib.h>
#include <exception.h>
#include <string.h>

#define MOVIE_KEY_CHARS_MAX 16
#define MOVIE_VAL_CHARS_MAX 2048

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

typedef struct Movie {
	char *title;
	char *year;
	char *actor;
	char *actress;
	char *director;
	char *producer;
	char *plot;
	
} Movie;

typedef Movie *node_t;


Movie *movie_init(char *title, char *year, char *actor, char *actress, char *director, char *producer, char *plot);

#endif //MOVIE_H
