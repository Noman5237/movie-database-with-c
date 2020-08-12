
/* Created By: Anonyman637
 * Created On: 8/11/2020; 2:14 AM
 */

#ifndef STACK_H
#define STACK_H

#include <DataStruct/node.h>

typedef LinkedList Stack;

/* ============================== ACCESSOR ========================= */

INT top(Stack *stack);

/* ============================== MODIFIERS ========================= */

int push(Stack *stack, INT data);

int pop(Stack *stack);

#endif //STACK_H
