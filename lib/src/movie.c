/**
 * @file: movie.c
 * @author: User
 * @date: 3/17/2021; 4:36 PM
 */

#include <movie.h>

Movie *movie_init(char *title, char *year, char *actor, char *actress, char *director, char *producer, char *plot) {
	Movie *movie = (Movie *) malloc(sizeof(Movie));
	if (!movie) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	movie->title = malloc(sizeof(char) * (strlen(title) + 1));
	if (!movie->title) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->title, title);
	
	movie->year = malloc(sizeof(char) * (strlen(year) + 1));
	if (!movie->year) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->year, year);
	
	movie->actor = malloc(sizeof(char) * (strlen(actor) + 1));
	if (!movie->actor) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->actor, actor);
	
	movie->actress = malloc(sizeof(char) * (strlen(actress) + 1));
	if (!movie->actress) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->actress, actress);
	
	movie->director = malloc(sizeof(char) * (strlen(director) + 1));
	if (!movie->director) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->director, director);
	
	movie->producer = malloc(sizeof(char) * (strlen(producer) + 1));
	if (!movie->producer) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->producer, producer);
	
	movie->plot = malloc(sizeof(char) * (strlen(plot) + 1));
	if (!movie->plot) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Movie *) NULL;
	}
	
	strcpy(movie->plot, plot);
	
	return movie;
}


char *ll_getValue(Movie *movie, char *key) {
	char *value = NULL;
	
	if (strcmp(key, "title")) {
		value = movie->title;
	} else if (strcmp(key, "year")) {
		value = movie->year;
	} else if (strcmp(key, "actor")) {
		value = movie->actor;
	} else if (strcmp(key, "actress")) {
		value = movie->actress;
	} else if (strcmp(key, "director")) {
		value = movie->director;
	} else if (strcmp(key, "producer")) {
		value = movie->producer;
	} else if (strcmp(key, "plot")) {
		value = movie->plot;
	}
	
	return value;
	
}

/* ============================== List Accessories ========================= */


int ll_freeData(Movie *movie) {
	free(movie->title);
	free(movie->year);
	free(movie->actor);
	free(movie->actress);
	free(movie->director);
	free(movie->producer);
	free(movie->plot);
	free(movie);
	return 0;
}

int ll_printer(Movie *data) {
	printf("Title: %s\n", data->title);
	printf("Year: %s\n", data->year);
	printf("Actor: %s\n", data->actor);
	printf("Actress: %s\n", data->actress);
	printf("Director: %s\n", data->director);
	printf("Producer: %s\n", data->producer);
	printf("Plot: %s\n", data->plot);
	return 0;
}

