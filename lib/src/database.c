/**
 * @file: database.c
 * @author: Anonyman637
 * @date: 3/17/2021; 11:07 PM
 */

#include "database.h"

DB *db_init(char *dbName) {
	DB *db = (DB *) malloc(sizeof(DB));
	if (!db) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (DB *) NULL;
	}
	
	db->list = ll_init();
	
	db->dbName = malloc(sizeof(char) * (strlen(dbName) + 1));
	if (!db->dbName) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (DB *) NULL;
	}
	
	strcpy(db->dbName, dbName);
	
	return db;
}

int db_add(DB *db, node_t data) {
	return ll_append(db->list, data);
}

int db_erase(DB *db, int index) {
	return ll_erase(db->list, index);
}

DB *db_query(DB *db, char *queryName, char *expression) {
	DB *queryDatabase = db_init(queryName);
	int size = ll_size(db->list);
	for (int i = 0; i < size; i++) {
		node_t data = ll_get(db->list, i);
	}
	return NULL;
}

int db_destroy(DB *db) {
	ll_destroy(db->list);
	free(db->dbName);
	free(db);
	return 0;
}

int db_export(DB *db, char *pathToOutputDir) {
	FILE *fp;
	char outputPath[PATH_MAX];
	strcpy(outputPath, pathToOutputDir);
	strcat(outputPath, db->dbName);
	printf("%s\n", outputPath);
	if (!(fp = fopen(outputPath, "wb"))) {
		return EXCEPTION_NEW(FILE_READ_ERROR);
	}

//	todo export the data
	
	return 0;
}

int db_show(DB *db) {
//	TODO show a fancy grid
	printf("%s\n", db->dbName);
	return ll_traverse(db->list);
}

DB *db_import(char *filePath) {
	FILE *fp = NULL;
	if (!(fp = fopen(filePath, "rb"))) {
		return EXCEPTION_NEW(FILE_READ_ERROR), (DB *) NULL;
	}
	
	DB *db = db_init("");

//	todo import the data
	fclose(fp);
	
	return db;
}
