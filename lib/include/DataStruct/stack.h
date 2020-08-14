/**
 * @file stack.h
 * @author: Anonyman637
 * @date: 8/11/2020; 2:14 AM
 */
 

#ifndef STACK_H
#define STACK_H


#include <DataStruct/node.h>


/**
 * Stack is nothing special than a one dimensional list
 * which is modified and accessed in unique fashion.
 *
 * The type Stack is just a syntactic sugar
 * which makes code more meaningful and understandable in contexts of Stack.
 *
 * ### Design Preview
 * ~~~.c
 * +-------------------+
 * |                   |
 * |      Stack        |
 * |                   |
 * |  +--------+----+  |
 * |  | size   | 4  |  |
 * |  +--------+----+  |
 * |                   |
 * |  +-----+ +-----+  |
 * |  |     | |     |  |
 * |  |   +-+-v-+   |  |
 * |  | h |     | t |  |
 * |  | e |prev | o |  |
 * |  | a |5    | p |  |
 * |  | d |next |   |  |
 * |  |   |     |   |  |
 * |  |   +-^-+-+   |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |   +-+-v-+   |  |
 * |  |   |     |   |  |
 * |  |   |prev |   |  |
 * |  |   |2    |   |  |
 * |  |   |next |   |  |
 * |  |   |     |   |  |
 * |  |   +-^-+-+   |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |   +-+-v-+   |  |
 * |  |   |     |   |  |
 * |  |   |prev |   |  |
 * |  |   |3    |   |  |
 * |  |   |next |   |  |
 * |  |   |     |   |  |
 * |  |   +-^-+-+   |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |     | |     |  |
 * |  |   +-+-v-+   |  |
 * |  |   |     |   |  |
 * |  |   |prev |   |  |
 * |  |   |7    |   |  |
 * |  |   |next |   |  |
 * |  |   |     |   |  |
 * |  |   +-^-+-+   |  |
 * |  |     | |     |  |
 * |  +-----+ +-----+  |
 * |                   |
 * +-------------------+
 * ~~~
 *
 * @note
 * As Linked List and Stack shares many functions,
 * so this design pattern was adopted to give users a taste of inheritance like features
 * although it was not the intention at first.
 *
 * @attention
 * Do not modify the size of head of the Stack unless you know what you doing and
 * are solely responsible for unwanted and weird behaviour of your programs.
 * <br>
 * As Stack is a syntactic sugar, so it recommended to use the following functions
 * in order to avoid confusions in contexts of Stack:
 * <br>
 * init()
 * top() forEach() traverse()
 * size() empty()
 * push() pop()
 * destroy()
 *
 * @warning
 * Any type of **modification** of Stack without the supplied modifier functions
 * is not intended and the supplied software is not responsible for any
 * fatal or non crashes and unwanted and weird behaviour of the user programs.
 *
 * @see LinkedList init() push()
 */
typedef LinkedList Stack;


/* ============================== ACCESSOR ========================= */


/**
 * Get the latest available pushed data in the provided stack.
 *
 * @param stack Pointer to the stack instantiated by init()
 *
 * @throws INVALID_POINTER if **stack** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **stack** is empty.
 *
 * @return
 * Latest available pushed data in the provided stack.
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/stack.h>
 *
 * int main() {
 *
 * 	// Initializing an empty stack
 * 	Queue *stack = init();
 * 	// Pushing data into the stack
 * 	push(stack, 37);
 * 	push(stack, 52);
 * 	// Getting the top data in the stack
 * 	printf("%d\n", top(stack));
 * 	// Destroying stack
 * 	destroy(stack);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 52
 *
 * ~~~
 *
 * @see init() push()
 */
node_t top(Stack *stack);


/* ============================== MODIFIERS ========================= */


/**
 * Adds a new data to the provided stack.
 *
 * @param stack Pointer to the stack instantiated by init()
 * @param data Data to be pushed in the provided stack
 *
 * @throws INVALID_POINTER if **stack** is either NULL, uninitialized or unaddressable.
 * @throws OUT_OF_MEMORY if allocation is not possible for new data.
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/stack.h>
 *
 * int main() {
 *
 * 	// Initializing an empty stack
 * 	Queue *stack = init();
 * 	// Pushing data into the stack
 * 	push(stack, 7);
 * 	push(stack, 3);
 * 	push(stack, 2);
 * 	push(stack, 5);
 * 	// Traversing the stack
 * 	traverse(stack);
 * 	// Destroying stack
 * 	destroy(stack);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 5 2 3 7
 *
 * ~~~
 *
 * @see init() pop() traverse()
 */
int push(Stack *stack, node_t data);


/**
 * Erases the latest data pushed into the provided stack.
 *
 * @param stack Pointer to the stack instantiated by init()
 *
 * @throws INVALID_POINTER if **stack** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **stack** is empty.
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/stack.h>
 *
 * int main() {
 *
 * 	// Initializing an empty stack
 * 	Queue *stack = init();
 * 	// Pushing data into the stack
 * 	push(stack, 7);
 * 	push(stack, 3);
 * 	push(stack, 2);
 * 	push(stack, 5);
 * 	// Traversing the stack
 * 	traverse(stack);
 * 	// Popping some data from stack
 * 	pop(stack);
 * 	pop(stack);
 * 	// Traversing the stack
 * 	traverse(stack);
 * 	// Destroying stack
 * 	destroy(stack);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 5 2 3 7
 * 3 7
 * ~~~
 *
 * @see push() traverse() destroy()
 */
int pop(Stack *stack);


#endif //STACK_H
