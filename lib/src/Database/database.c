/**
 * @file: database.c
 * @author: Anonyman637
 * @date: 3/17/2021; 11:07 PM
 */

#include <utility.h>
#include "Database/database.h"

DB *db_init(char *dbName) {
	DB *db = (DB *) malloc(sizeof(DB));
	if (!db) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (DB *) NULL;
	}
	
	db->list = ll_init();
	if (!db->list) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (DB *) NULL;
	}
	
	
	db->dbName = malloc(sizeof(char) * (strlen(dbName) + 1));
	if (!db->dbName) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (DB *) NULL;
	}
	
	strcpy(db->dbName, dbName);
	
	return db;
}

int db_add(DB *db, node_t data) {
	if (!db) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	return ll_append(db->list, data);
}

int db_erase(DB *db, int index) {
	if (!db) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	return ll_erase(db->list, index);
}


DB *db_query(DB *db, char *queryName, char *expression) {
	if (!db) {
		return EXCEPTION_NEW(INVALID_POINTER), (DB *) NULL;
	}
	DB *queryDatabase = db_init(queryName);
	int dbSize = ll_size(db->list);
	Query *query = query_init(expression);
	if (!query) {
		return EXCEPTION_NEW(INVALID_POINTER), (DB *) NULL;
	}
	for (int i = 0; i < dbSize; i++) {
		node_t data = ll_get(db->list, i);
		if (query_evaluate(query, data)) {
			db_add(queryDatabase, node_clone(data));
		}
	}
	return queryDatabase;
}

int db_destroy(DB *db) {
	if (!db) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	ll_destroy(db->list);
	free(db->dbName);
	free(db);
	return 0;
}

int db_export(DB *db, char *pathToOutputDir) {
	if (!db) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	FILE *fp;
	char outputPath[PATH_MAX];
	strcpy(outputPath, pathToOutputDir);
	strcat(outputPath, db->dbName);
	strcat(outputPath, ".db");
	if (!(fp = fopen(outputPath, "wb"))) {
		return EXCEPTION_NEW(FILE_NOT_FOUND);
	}
	
	fprintf(fp, "%s\n", db->dbName);
	int dbSize = ll_size(db->list);
	for (int i = 0; i < dbSize; i++) {
		node_fileWrite(ll_get(db->list, i), fp);
	}
	
	fclose(fp);
	return 0;
}

DB *db_import(char *filePath) {
	FILE *fp = NULL;
	if (!(fp = fopen(filePath, "rb"))) {
		return EXCEPTION_NEW(FILE_NOT_FOUND), (DB *) NULL;
	}
	
	char bytes[MOVIE_VAL_CHARS_MAX];
	fscanf(fp, "%"STR(MOVIE_VAL_CHARS_MAX)"[^\n]\n", bytes);
	DB *db = db_init(bytes);
	
	while (!feof(fp)) {
		db_add(db, node_fileRead(fp));
	}
	
	fclose(fp);
	
	return db;
}

int db_print(DB *db) {
	if (!db) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	/* ------------------ Name ------------------ */
	
	// Top Bar
	printf("+");
	for (int i = 0; i < NODE_COLS * (NODE_COL_CHARS_MAX + 1) - 1; i++) {
		printf("-");
	}
	printf("+\n");
	
	// Centered DB Name
	printf("|");
	centerText(db->dbName, NODE_COLS * (NODE_COL_CHARS_MAX + 1) - 1);
	printf("|\n");
	
	/* ------------------ Header ------------------ */
	
	drawGrid(NODE_COLS, NODE_COL_CHARS_MAX);
	printf("|");
	centerText("id", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("title", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("year", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("actor", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("actress", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("director", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("producer", NODE_COL_CHARS_MAX);
	printf("|");
	centerText("plot", NODE_COL_CHARS_MAX);
	printf("|\n");
	drawGrid(NODE_COLS, NODE_COL_CHARS_MAX);
	
	// print the records
	int dbSize = ll_size(db->list);
	char indexStr[8];
	for (int i = 0; i < dbSize; i++) {
		printf("|");
//		itoa(i, indexStr, 10);
		i = atoi(indexStr);
		printMin(indexStr, NODE_COL_CHARS_MAX);
		node_print(ll_get(db->list, i));
		printf("\n");
	}
	
	drawGrid(NODE_COLS, NODE_COL_CHARS_MAX);
	
	return 0;
}

