/**
 * @file: Console.c
 * @author: Anonyman637
 * @date: 4/3/2021; 8:07 PM
 */

// FIXME: Fix all the memory leaks after extensive debugging

#include "MovieDatabaseApp.h"

DB *operatingDatabase;

extern int defaultExceptionHandlerFatality;

int main() {
	defaultExceptionHandlerFatality = VERBOSE;
	input_menu(5,
	           input_menuOption_init("Manage databases", "Create and Load Database", manageMovieDatabase),
	           input_menuOption_init("Add a new movie", "Adds a new movie to operating database", addMovie),
	           input_menuOption_init("Show all movies", "Prints all movies in current database in table",
	                                 showMovies),
	           input_menuOption_init("Delete a movie", "Deletes a existing movie from operating database",
	                                 deleteMovie),
	           input_menuOption_init("Search a movie", "Searches a movie in operating database", searchMovie));
	
	unloadNExportOperatingDatabase();
	return 0;
}

/* ============================== MAIN MENU ========================= */

int manageMovieDatabase() {
	input_menu(2,
	           input_menuOption_init("Create a new database", "Creates a new database", createDatabase),
	           input_menuOption_init("Load a database", "Loads a existing database", loadDatabase));
	return 0;
}

int addMovie() {
	if (!operatingDatabase) {
//		TODO: define empty operating database error return in exception library
		printf("Create a new database or load an existing database first!\n");
		return 1;
	}
	
	char *title = input("Title of the movie", "", "Movie Title e.g.Pirates of the Caribbean", validator_null);
	if (input_empty(title)) {
		return 0;
	}
	
	char *year = input("Release year of the movie", "", "The year in which movie is released e.g.2012",
	                   validator_null);
	if (input_empty(year)) {
		return 0;
	}
	
	char *actor = input("Lead Actor of the movie", "", "Lead actor case of the movie.g.Daniel Radcliffe",
	                    validator_null);
	if (input_empty(actor)) {
		return 0;
	}
	
	char *actress = input("Lead Actress of the movie", "", "Lead actor case of the movie e.g.Jennifer Lawrence",
	                      validator_null);
	if (input_empty(actress)) {
		return 0;
	}
	
	char *director = input("Director of the movie", "", "Director of the movie e.g.Christopher Nolan", validator_null);
	if (input_empty(director)) {
		return 0;
	}
	
	char *producer = input("Producer of the movie", "", "Producer of the movie e.g.Steven Spielberg", validator_null);
	if (input_empty(producer)) {
		return 0;
	}
	
	char *plot = input("Plot of the movie", "", "Plot summary of the movie", validator_null);
	if (input_empty(plot)) {
		return 0;
	}
	
	if (db_add(operatingDatabase, movie_init(title, year, actor, actress, director, producer, plot))) {
		printf("New movie added successfully.\n");
	}
	
	free(title);
	free(year);
	free(actor);
	free(actress);
	free(director);
	free(producer);
	free(plot);
	
	return 0;
}

int showMovies() {
	if (!operatingDatabase) {
//		TODO: define empty operating database error return in exception library
		printf("Create a new database or load an existing database first!\n");
		return 1;
	}
	return db_print(operatingDatabase);
}

int deleteMovie() {
	if (!operatingDatabase) {
//		TODO: define empty operating database error return in exception library
		printf("Create a new database or load an existing database first!\n");
		return 1;
	}
	
	char *indexStr = input("Index of the movie to delete", "Invalid Movie Index",
	                       "Index of the movie is the first column of every row in database", validator_null);
	
	int index = atoi(indexStr);
	
	db_erase(operatingDatabase, index);
	free(indexStr);
	
	return 0;
}

int searchMovie() {
	if (!operatingDatabase) {
//		TODO: define empty operating database error return in exception library
		printf("Create a new database or load an existing database first!\n");
		return 1;
	}
	
	input_menu(2,
	           input_menuOption_init("Quick Search", "Quickly searches operating database using column header",
	                                 quickSearch),
	           input_menuOption_init("Advanced Search",
	                                 "Creates a advanced search using custom query expression", advancedSearch));
	return 0;
}

/* ============================== SUB MENU ========================= */

int createDatabase() {
//	FIXME: Validate with unique database name
	char *newDatabaseName = input("Unique name of the new database", "Database name not unique",
	                              "Name of the database must be unique or there is a chance of data loss",
	                              validator_null);
	if (input_empty(newDatabaseName)) {
		return 0;
	}
	
	DB *newDatabase = db_init(newDatabaseName);
	if (newDatabase) {
		unloadNExportOperatingDatabase();
		printf("New database %s created.\n", newDatabaseName);
		operatingDatabase = newDatabase;
	} else {
		printf("Error creating new database\n");
	}
	
	free(newDatabaseName);
	
	return 0;
}

int loadDatabase() {
	char *databaseName = input("Name of the database to load", "", "Proper name of the existing database",
	                           validator_null);
	
	if (input_empty(databaseName)) {
		return 0;
	}
	
	char *databasePath = (char *) malloc(sizeof(char) * MOVIE_VAL_CHARS_MAX);
	sprintf(databasePath, DATABASE_DIR "%s.db", databaseName);
	
	DB *loadedDatabase = db_import(databasePath);
	
	if (loadedDatabase) {
		unloadNExportOperatingDatabase();
		printf("Database %s loaded.\n", databaseName);
		operatingDatabase = loadedDatabase;
	} else {
		printf("Error loading asked database\n");
	}
	
	free(databaseName);
	return 0;
}

int quickSearch() {
	char *columnName = input("Column name", "", "Name of column to search data for, e.g. year, title etc.",
	                         validator_null);
	if (input_empty(columnName)) {
		return 0;
	}
	char *expectedData = input("Expected Value", "", "Expected data to search for, e.g. 2003, Aliens etc.",
	                           validator_null);
	if (input_empty(expectedData)) {
		return 0;
	}
	
	char *searchExpression = malloc(sizeof(char) * MOVIE_VAL_CHARS_MAX);
	if (!searchExpression) {
		return EXCEPTION_NEW(OUT_OF_MEMORY);
	}
	
	sprintf(searchExpression, "%s : `%s`", columnName, expectedData);
	DB *quickSearch = db_query(operatingDatabase, "Quick Search Result", searchExpression);
	db_print(quickSearch);
	db_destroy(quickSearch);
	
	return 0;
}

int advancedSearch() {
	
	char *queryName = input("Name of the query", "", "A database will be created and exported from query name",
	                        validator_null);
	if (input_empty(queryName)) {
		return 0;
	}
	char *searchExpression = input("Expression", "",
	                               "Key Value Pair with conditionals e.g. 'title : `Harry Potter` | year : `2003`'",
	                               validator_null);
	if (input_empty(searchExpression)) {
		return 0;
	}
	
	db_export(db_query(operatingDatabase, queryName, searchExpression), DATABASE_DIR);
	
	free(queryName);
	free(searchExpression);
	
	return 0;
}

int unloadNExportOperatingDatabase() {
	if (operatingDatabase) {
		db_export(operatingDatabase, DATABASE_DIR);
		db_destroy(operatingDatabase);
	}
	return 0;
}
