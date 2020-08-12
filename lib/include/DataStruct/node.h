
/* Created By: Anonyman637
 * Created On: 8/11/2020; 1:05 AM
 */

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <exception.h>

#define INT int

typedef struct Node {
	INT data;
	
	struct Node *prev;
	struct Node *next;
	
} Node;

typedef struct LinkedList {
	int _size;
	Node *_head;
	
} LinkedList, LList, LL;

/* ============================== CONSTRUCTOR ========================= */

LinkedList *new();

/* ============================== ACCESSOR ========================= */

INT get(LinkedList *ll, int index);

int foreach(LinkedList *ll, int (*callback)(int));

int traverse(LinkedList *ll);

/* ============================== CAPACITY ========================= */

int size(LinkedList *ll);

int empty(LinkedList *ll);

/* ============================== MODIFIERS ========================= */

int append(LinkedList *ll, INT data);

int insert(LinkedList *ll, int index, INT data);

int erase(LinkedList *ll, int index);

int set(LinkedList *ll, int index, INT newData);

/* ============================== DESTRUCTOR ========================= */

int delete(LinkedList *ll);

/* ============================== UTILITY ========================= */

int printer(INT data);

#endif //LINKEDLIST_NODE_H
