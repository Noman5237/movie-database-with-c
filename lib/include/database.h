/**
 * @file: database.h
 * @author: Anonyman637
 * @date: 3/17/2021; 11:08 PM
 */

#ifndef ASSIGNMENT_DATABASE_H
#define ASSIGNMENT_DATABASE_H

#include <DataStruct/node.h>

typedef struct Database {
	char *dbName;
	LinkedList *list;
} Database, DB;

DB *db_init(char *dbName);

int db_add(DB *db, node_t node);

int db_erase(DB *db, int index);

DB *db_query(DB *db, char *queryName, char *expression);

int db_destroy(DB *db);

int db_show(DB *db);

int db_export(DB *db, char *pathToOutputDir);

DB *db_import(char *filePath);

#endif //ASSIGNMENT_DATABASE_H
