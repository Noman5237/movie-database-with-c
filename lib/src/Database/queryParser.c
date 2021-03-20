/**
 * @file: queryParser.c
 * @author: Anonyman637
 * @date: 3/18/2021; 6:57 PM
 */

#include <Database/queryParser.h>

Condition *condition__init(char *key, char *value, int mode) {
	
	Condition *condition = (Condition *) malloc(sizeof(Condition));
	if (!condition) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Condition *) NULL;
	}
	
	condition->key = malloc(sizeof(char) * (strlen(key) + 1));
	if (!condition->key) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Condition *) NULL;
	}
	
	strcpy(condition->key, key);
	
	
	condition->value = malloc(sizeof(char) * (strlen(value) + 1));
	if (!condition->value) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (Condition *) NULL;
	}
	
	strcpy(condition->value, value);
	
	condition->mode = mode;
	
	return condition;
}

int condition__check(Condition *condition, node_t data) {
	char *value = node_get(data, condition->key);
	return !strcmp(condition->value, value);
}

Query *query_init(char *expression) {
	int noOfConditions = 1;
	int queryLen = (int) strlen(expression);
	for (int i = 0; i < queryLen; i++) {
		char c = expression[i];
		c == '&' || c == '|' ? noOfConditions++ : 0;
	}
	
	Query *query = (Query *) malloc(sizeof(Query));
	query->noOfConditions = noOfConditions;
	
	Condition **conditions = malloc(sizeof(Condition *) * noOfConditions);
	for (int i = 0; i < noOfConditions; i++) {
		conditions[i] = (Condition *) malloc(sizeof(Condition));
	}
	
	conditions[0]->mode = AND;
	int nr = 0;
	char key[MOVIE_KEY_CHARS_MAX], value[MOVIE_VAL_CHARS_MAX];
	for (int nc = 0; nc < noOfConditions; nc++) {
		int nArg = 0, cnr = 0;
		nArg = sscanf(expression + nr,
		              "%"STR(MOVIE_KEY_CHARS_MAX)"s : `%"STR(MOVIE_VAL_CHARS_MAX)"[^`\n]`%n",
		              key, value, &cnr);
		
		int keyLen = (int) strlen(key);
		int valueLen = (int) strlen(value);
		
		if (nArg != 2) {
			return EXCEPTION_NEW(SYNTAX_ERROR), (Query *) NULL;
		}
		
		conditions[nc]->key = malloc(sizeof(char) * (keyLen + 1));
		strcpy(conditions[nc]->key, key);
		conditions[nc]->value = malloc(sizeof(char) * (valueLen + 1));
		strcpy(conditions[nc]->value, value);
		
		nr += cnr;
		while (expression[nr] == ' ') nr++;
		char nextMode = expression[nr];
		if (nextMode == '&' || nextMode == '|') {
			conditions[nc + 1]->mode = nextMode == '&' ? AND : OR;
			nr++;
		}
	}
	
	query->conditions = conditions;
	
	return query;
}

int query_evaluate(Query *query, node_t data) {
	int result = 1;
	for (int i = 0; i < query->noOfConditions; i++) {
		Condition *condition = query->conditions[i];
		int conditionCheck = condition__check(condition, data);
		if (condition->mode == OR) {
			result = result || conditionCheck;
		} else if (condition->mode == AND) {
			result = result && conditionCheck;
		}
	}
	
	return result;
}









