/**
 * @file: queryParser.h
 * @author: Anonyman637
 * @date: 3/18/2021; 6:58 PM
 */

#ifndef ASSIGNMENT_QUERYPARSER_H
#define ASSIGNMENT_QUERYPARSER_H

#include <DataStruct/node.h>

#define KEY_LEN_MAX 128
#define VAL_LEN_MAX 2048

enum conditionMode {
	AND,
	OR,
};

typedef struct Condition {
	char *key;
	char *value;
	int mode;
} Condition;

typedef struct Query {
	int noOfConditions;
	Condition **conditions;
} Query;

Condition *condition__init(char *key, char *value, int mode);

int condition__check(Condition *condition, node_t data);

Query *query_init(char *expression);

int query_evaluate(Query *query, node_t data);

#endif //ASSIGNMENT_QUERYPARSER_H
