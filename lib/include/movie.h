/**
 * @file: movie.h
 * @author: Anonyman637
 * @date: 3/17/2021; 4:36 PM
 */

#ifndef ASSIGNMENT_MOVIE_H
#define ASSIGNMENT_MOVIE_H

#include <stdio.h>
#include <stdlib.h>
#include <exception.h>
#include <string.h>

typedef struct Movie {
	char *title;
	char *year;
	char *actor;
	char *actress;
	char *director;
	char *producer;
	char *plot;
	
} Movie;


Movie *movie_init(char *title, char *year, char *actor, char *actress, char *director, char *producer, char *plot);

#endif //ASSIGNMENT_MOVIE_H
