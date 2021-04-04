/**
 * @file: database.h
 * @author: Anonyman637
 * @date: 3/17/2021; 11:08 PM
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <Database/queryParser.h>

#define PATH_MAX 260

typedef struct Database {
	char *dbName;
	LinkedList *list;
} Database, DB;

DB *db_init(char *dbName);

int db_add(DB *db, node_t node);

int db_erase(DB *db, int index);

/**
 * Syntax of query<br>
 * Condition: "key<Space>:<Space>`value`"<br>
 * Multiple conditions can be merged together using &(AND) or |(OR) <br>
 * expression syntax: "Condition1 | Condition2 & Condition3 | ... ConditionN"
 *
 * @param db
 * @param queryName
 * @param expression For simplicity expression has only one function i.e. comparing equality
 * @return
 */
 
DB *db_query(DB *db, char *queryName, char *expression);

int db_destroy(DB *db);

int db_print(DB *db);

int db_export(DB *db, char *pathToOutputDir);

DB *db_import(char *filePath);

#endif //DATABASE_H
