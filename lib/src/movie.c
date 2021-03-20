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


/* ============================== COMPLEMENTARY ========================= */

char *node_get(Movie *movie, char *key) {
	if (!movie) {
		return EXCEPTION_NEW(INVALID_POINTER), (char *) NULL;
	}
	
	char *value = NULL;
	
	if (!strcmp(key, "title")) {
		value = movie->title;
	} else if (!strcmp(key, "year")) {
		value = movie->year;
	} else if (!strcmp(key, "actor")) {
		value = movie->actor;
	} else if (!strcmp(key, "actress")) {
		value = movie->actress;
	} else if (!strcmp(key, "director")) {
		value = movie->director;
	} else if (!strcmp(key, "producer")) {
		value = movie->producer;
	} else if (!strcmp(key, "plot")) {
		value = movie->plot;
	}
	
	return value;
	
}

Movie *node_clone(Movie *movie) {
	
	if (!movie) {
		return EXCEPTION_NEW(INVALID_POINTER), (Movie *) NULL;
	}
	
	Movie *clone = movie_init(movie->title, movie->year,
	                          movie->actor, movie->actress,
	                          movie->director, movie->producer, movie->plot);
	
	return clone;
}

int node_destroy(Movie *movie) {
	if (!movie) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
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

int node_print(Movie *movie) {
	if (!movie) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	printf("Title: %s\n", movie->title);
	printf("Year: %s\n", movie->year);
	printf("Actor: %s\n", movie->actor);
	printf("Actress: %s\n", movie->actress);
	printf("Director: %s\n", movie->director);
	printf("Producer: %s\n", movie->producer);
	printf("Plot: %s\n", movie->plot);
	return 0;
}

int node_fileWrite(Movie *movie, FILE *fp) {
	if (!movie || !fp) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	fprintf(fp, "%s\n", movie->title);
	fprintf(fp, "%s\n", movie->year);
	fprintf(fp, "%s\n", movie->actor);
	fprintf(fp, "%s\n", movie->actress);
	fprintf(fp, "%s\n", movie->director);
	fprintf(fp, "%s\n", movie->producer);
	fprintf(fp, "%s\n", movie->plot);
	
	return 0;
}


Movie *node_fileRead(FILE *fp) {
	if (!fp) {
		return EXCEPTION_NEW(INVALID_POINTER), (Movie *) NULL;
	}
	
	char title[MOVIE_VAL_CHARS_MAX];
	char year[MOVIE_VAL_CHARS_MAX];
	char actor[MOVIE_VAL_CHARS_MAX];
	char actress[MOVIE_VAL_CHARS_MAX];
	char director[MOVIE_VAL_CHARS_MAX];
	char producer[MOVIE_VAL_CHARS_MAX];
	char plot[MOVIE_VAL_CHARS_MAX];
	
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", title) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", year) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", actor) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", actress) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", director) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", producer) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	if (fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", plot) != 1)
		return EXCEPTION_NEW(FILE_READ_ERROR_EOF), (Movie *) NULL;
	
	return movie_init(title, year, actor, actress, director, producer, plot);
	
}
