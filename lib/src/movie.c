/**
 * @file: movie.c
 * @author: User
 * @date: 3/17/2021; 4:36 PM
 */

#include <movie.h>

Movie *createMovie(char *title) {
	Movie *movie = (Movie *) malloc(sizeof(Movie));
	if (!movie) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	movie->title = malloc(sizeof(title));
	movie->title = title;
	
	return movie;
}

int printer(Movie *movie) {
	printf("Title: %s", movie->title);
	return 0;
}
