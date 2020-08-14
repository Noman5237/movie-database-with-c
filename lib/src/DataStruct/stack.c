/**
 * @file stack.h
 * @author: Anonyman637
 * @date: 8/11/2020; 2:14 AM
 */


#include "DataStruct/stack.h"


/* ============================== ACCESSOR ========================= */


node_t top(Stack *stack) {
	return get(stack, 0);
}


/* ============================== MODIFIERS ========================= */


int push(Stack *stack, node_t data) {
	if (size(stack)) {
		return insert(stack, 0, data);
	} else {
		// Remember! insert cannot create new position
		return append(stack, data);
	}
}


int pop(Stack *stack) {
	return erase(stack, 0);
}

