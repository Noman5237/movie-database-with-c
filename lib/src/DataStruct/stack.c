
/* Created By: Anonyman637
 * Created On: 8/11/2020; 2:14 AM
 */

#include "DataStruct/stack.h"


/* ============================== ACCESSOR ========================= */

INT top(Stack *stack) {
	return get(stack, 0);
}

/* ============================== MODIFIERS ========================= */

int push(Stack *stack, INT data) {
	if (size(stack)) {
		return insert(stack, 0, data);
	} else {
		return append(stack, data);
	}
}

int pop(Stack *stack) {
	return erase(stack, 0);
}
