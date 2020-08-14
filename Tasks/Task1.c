
/* Created By: Anonyman637
 * Created On: 8/12/2020; 5:54 AM
 */


#include <DataStruct/stack.h>

int main() {
	
	// Initializing a new stack; allocated on heap
	Stack *stack = init();
	
	// Pushing Data into stack
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	
	// Getting stack size
	printf("Stack Size: %d\n", size(stack));
	
	// Traversing stack
	traverse(stack);
	printf("\n");
	
	// Popping and getting top of stack
	printf("Top: %d\n",top(stack));
	pop(stack);
	printf("Top: %d\n",top(stack));
	pop(stack);
	printf("Top: %d\n",top(stack));
	pop(stack);
	
	// Stack is now empty
	printf("Stack %s empty.\n", empty(stack) ? "is": "is not");
	
	// Popping from an empty stack
	pop(stack);
	
	// Freeing the memory allocated on heap by new
	destroy(stack);
	
	return 0;
}

