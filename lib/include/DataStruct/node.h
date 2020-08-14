/**
 * @file node.h
 * @author Anonyman637
 * @date 8/11/2020; 1:05 AM
 */


#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <exception.h>


/**
 * Linked List Nodes contains data which are of by default integer types.
 *
 * <p>
 * Based on the need of the user, node_t can be defined as
 * other types of integers i.e. long, short, long long
 * or oven other types of numbers such as float or double.
 *
 * @note
 * Creating a separate node type was initiated keeping in mind of extending
 * it to generic type in future.
 */
typedef int node_t;


/**
 * Node is a core data structure which holds data and pointers to its neighboring nodes.
 *
 * <p>
 * Conventionally this Node is more commonly known as **Doubly** since it contains
 * pointer references to both its previous and next neighboring node.
 *
 * @attention
 * Do not modify the Node data or pointer references to neighboring nodes
 * unless you know what you doing and are solely responsible for unwanted
 * and weird behaviour of your programs.
 *
 * @see LinkedList
 */
typedef struct Node {
	node_t data;
	
	struct Node *prev;
	struct Node *next;
	
} Node;


/**
 * Linked List is a collection of nodes accessed by a single **Head Node** pointer.
 *
 * <p>
 * Conventionally this Linked List is more commonly known as **Circular Doubly Linked List**
 * since it is made up of **Doubly** nodes and by design the modifier functions facilitate
 * **Circular** list.
 *
 * ### Design Preview
 * ~~~.c
 * +-------------------------------------------------------+
 * |                                                       |
 * | +-----------------+                                   |
 * | |size       | 4   |    Doubly Circular Linked List    |
 * | +-----------------+                                   |
 * | +---------------------------------------------------+ |
 * | |                                                   | |
 * | | +----------------------------------------------+  | |
 * | | |  head[0]         [1]         [2]        [3]  |  | |
 * | | |  +-----+     +-----+     +-----+    +-----+  |  | |
 * | | |  |5    |     |2    |     |3    |    |7    |  |  | |
 * | | +--+prev <-----+prev <-----+prev <----+prev <--+  | |
 * | | +-->next +----->next +----->next +---->next +--+  | |
 * | | |  +-----+     +-----+     +-----+    +-----+  |  | |
 * | | |                                              |  | |
 * | | +----------------------------------------------+  | |
 * | |                                                   | |
 * | +---------------------------------------------------+ |
 * |                                                       |
 * +-------------------------------------------------------+
 * ~~~
 *
 * @note
 * Instead of declaring pointer to pointer to Node Head as Linked List,
 * Linked List is a specially designed object with size and node head pointer
 * because of extensibility, flexibility and its similarity to unanimous one dimensional
 * dynamic storage data structures.
 * The structure contains size variable for optimization purposes.
 *
 * @attention
 * Do not modify the size of head of the Linked List unless you know what you doing and
 * are solely responsible for unwanted and weird behaviour of your programs.
 *
 * @warning
 * Any type of **modification** of Linked List without the supplied modifier functions
 * is not intended and the supplied software is not responsible for any
 * fatal or non crashes and unwanted and weird behaviour of the user programs.
 *
 * @see Node init() append()
 */
typedef struct LinkedList {
	int _size;
	Node *_head;
	
} LinkedList, LList, LL;


/* ============================== CONSTRUCTOR ========================= */


/**
 * Creates a new empty **Doubly Circular Linked List**
 * on heap and returns a pointer to the instantiated object.
 *
 * @throws OUT_OF_MEMORY if allocation is not possible for new list.
 *
 * @return
 * Pointer to new empty **Doubly Circular Linked List** if successful,
 * otherwise returns NULL if exception handler is not brutal.
 *
 * <p>
 * **Complexity** O(1)
 *
 * @note
 * Initially this function was named new.
 * But it interfered with Tests run in C++ using GoogleTest
 *
 * @attention
 * It is recommended to use init() function to create a new linked list
 * and use destroy() function to delete/free the allocated linked list
 * unless you know what you are doing and also fully responsible for your actions.
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 52 37
 *
 * ~~~
 *
 * @see append() destroy()
 */
LinkedList *init();


/* ============================== ACCESSOR ========================= */


/**
 * Get the data of element of provided index of the provided list
 *
 * <p>
 * Indexing starts from 0.
 * **get** also supports reverse order indexes.
 * <br>
 * So -1 as index value will return the data of the last element of the list,
 * and so will -2 return the data of the second last element of the list.
 *
 * @param ll Pointer to the linked list instantiated by init()
 * @param index Index of the desired data to look up
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **index** is invalid in the perspective of **ll**.
 *
 * @return
 * Data of desired element, given the list and index.
 *
 * <p>
 * **Complexity** O(**index**)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	append(ll, 637);
 * 	// Printing the data of 2nd element
 * 	printf("2nd element: %d\n", get(ll, 1));
 * 	// Printing the data of the last element
 * 	printf("Last element: %d\n", get(ll, -1));
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 2nd element: 37
 * Last element: 637
 *
 * ~~~
 *
 * @see set() init() append() destroy() printer()
 */
node_t get(LinkedList *ll, int index);


/**
 * Given the linked list pointer and callback function,
 * forEach function calls the callback function passing
 * each element of the list sequentially.
 *
 * @param ll Pointer to the linked list instantiated by init()
 * @param callback Callback function that takes the supplied data
 * and returns Zero(0) on successful execution
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 * @throws CALLBACK_ERROR if **callback** responded with value other than Zero(0).
 *
 * @return
 * Zero(0) if every callback function executes successfully.
 *
 * <p>
 * **Complexity** O(*size*)
 *
 * @note
 * Initially this function was named foreach.
 * But both Doxygen identifies foreach as keyword
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * // Regular linked list and its squared values
 * LinkedList *ll, *sq;
 *
 * int square(int a) {
 * 	append(sq, a * a);
 * 	return 0;
 * }
 *
 * int main() {
 *
 * 	// Initializing ll and sq
 * 	ll = init();
 * 	sq = init();
 * 	// Appending data to ll
 * 	append(ll, 5);
 * 	append(ll, 2);
 * 	append(ll, 3);
 * 	append(ll, 7);
 * 	// forEach demo
 * 	forEach(ll, square);
 * 	// Traversing ll and sq
 * 	traverse(ll);
 * 	traverse(sq);
 * 	// Destroying ll and sq
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 5 2 3 7
 * 25 4 9 49
 *
 * ~~~
 *
 * @see append() destroy() traverse()
 */
int forEach(LinkedList *ll, int (*callback)(int));


/* ============================== CAPACITY ========================= */


/**
 * Returns the size of provided list.
 *
 * @param ll Pointer to the linked list instantiated by init()
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 *
 * @return
 * Size of the provided list if successful,
 * otherwise -1 if exception handler is not brutal.
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	append(ll, 637);
 * 	// Printing the size of ll
 * 	printf("Size of ll: %d\n", size(ll));
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 3
 *
 * ~~~
 *
 * @see empty() init() append()
 */
int size(LinkedList *ll);


/**
 * Checks whether the provided list is empty.
 *
 * @param ll Pointer to the list instantiated by init()
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 *
 * @return
 * True(1) if size of provided list is Zero(0),
 * otherwise returns False(0).
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	append(ll, 637);
 * 	// Check whether ll is empty which is certainly not
 * 	printf("ll %s empty.\n", empty(ll) ? "is", "is not");
 * 	// Erasing elements from ll
 * 	erase(ll, -1);
 * 	erase(ll, -1);
 * 	erase(ll, -1);
 * 	// Check whether ll is empty which is certainly not
 * 	printf("ll %s empty.\n", empty(ll) ? "is", "is not");
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * ll is not empty.
 * ll is empty.
 *
 * ~~~
 *
 * @see LinkedList size() append() erase()
 */
int empty(LinkedList *ll);


/* ============================== MODIFIERS ========================= */


/**
 * Adds new data to the end of the provided list.
 *
 * @param ll Pointer to the linked list instantiated by init()
 * @param newData New data to be appended at the end of the list
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
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
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 52 37
 *
 * ~~~
 *
 * @see init() destroy()
 */
int append(LinkedList *ll, node_t newData);


/**
 * Inserts new data at specified index given the index already exists in provided list
 *
 * <p>
 * Indexing starts from 0.
 * **insert** also supports reverse order indexes.
 * <br>
 * So -1 as index value will insert the new data in the last position of the list,
 * and so will -2 return insert the new data in the second last position of the list.
 *
 * @param ll Pointer to the linked list instantiated by init()
 * @param index Existing index for the new data to insert at
 * @param newData Data to be inserted at desired index of the list
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **index** is invalid in the perspective of **ll**.
 * @throws OUT_OF_MEMORY if allocation is not possible for new data.
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(|*index*|)
 *
 * @attention
 * insert cannot create position that doesn't exist!!!
 * <br>
 * For example you cannot insert new data at the beginning of the list
 * when the size of the list is 0. For that you must use append().
 * <br>
 * And also if the size of a list is 3, you cannot insert at -4 to change the head,
 * because -4 doesn't exist yet. In this case you can insert at 0, which will help you achieve
 * your desired result.
 * <br>
 * *Just remember, insert cannot be used into non-existing index and
 * the newly inserted data will always hold the given index in the modified list.*
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 2);
 * 	append(ll, 7);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Inserting new data at the head
 * 	insert(ll, 0, 5);
 * 	// Inserting new data at index -2
 * 	insert(ll, -2, 3);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 2 7
 * 5 2 3 7
 *
 * ~~~
 *
 * @see erase() append()
 */
int insert(LinkedList *ll, int index, node_t newData);


/**
 * Erases the element of the list specified by index.
 *
 * <p>
 * Indexing starts from 0.
 * **erase** also supports reverse order indexes.
 * <br>
 * So -1 as index value will erase the last element of the list,
 * and so will -2 erase the second last element of the list.
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **index** is invalid in the perspective of **ll**.
 *
 * @param ll Pointer to the linked list instantiated by init()
 * @param index Index of the element to erase
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(**index**)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 5);
 * 	append(ll, 2);
 * 	append(ll, 3);
 * 	append(ll, 7);
 * 	insert(ll, -3, 6);
 * 	append(ll, 8);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Erasing some elements
 * 	erase(ll, 0);
 * 	erase(ll, 1);
 * 	erase(ll, -1);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 5 2 6 3 7 8
 * 6 3 7
 *
 * ~~~
 *
 * @see insert() append()
 */
int erase(LinkedList *ll, int index);


/**
 * Set the data of element of provided index of the provided list
 *
 * <p>
 * Indexing starts from 0.
 * Get function also supports reverse order indexes.
 * <br>
 * So -1 as index value will set the data of the last element of the list,
 * and so will -2 set the data of the second last element of the list.
 *
 * @param ll Pointer to the linked list instantiated by init()
 * @param index Index of the desired data to modify
 * @param newData Value of the new data for desired indexed element in list
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **index** is invalid in the perspective of **ll**.
 *
 * @return
 * Zero(0) if *data* of the element of the desired index was replaced with **newData**
 *
 * <p>
 * **Complexity** O(**index**)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 * 	LinkedList *ll = init();
 * 	append(ll, 52);
 * 	append(ll, 37);
 *
 * 	printf("Previous data last element: %d\n", get(ll, -1));
 * 	set(ll, 1, 637);
 * 	printf("Modified data last element: %d\n", get(ll, 1));
 *
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * Previous data last element: 37
 * Modified data last element: 637
 *
 * ~~~
 *
 * @see get() init() append() destroy()
 */
int set(LinkedList *ll, int index, node_t newData);


/* ============================== DESTRUCTOR ========================= */


/**
 * Free the memory occupied by the provided list that was allocated on heap by init().
 *
 * @param ll Pointer to the linked list instantiated by init()
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 *
 * @return
 * Zero(0) if linked list **ll** was successfully freed
 * along with its rest of its elements.
 *
 * <p>
 * **Complexity** O(*size*)
 *
 * @note
 * Initially this function was named delete.
 * But it interfered with Tests run in C++ using GoogleTest
 *
 * @attention
 * It is recommended to use init() function to create a new linked list
 * and use destroy() function to delete/free the allocated linked list
 * unless you know what you are doing and also fully responsible for your actions.
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 52 37
 *
 * ~~~
 *
 * @see init() append()
 */
int destroy(LinkedList *ll);


/* ============================== UTILITY ========================= */


/**
 * Prints all the elements of the provided linked list separated by space which ends with newline.
 *
 * <p>
 * traverse is a minimal utility function to print the elements of the list.
 * It is implemented using forEach() and another utility function printer().
 * It is recommended that users should make their own traverse function
 * for customization and flexibility.
 *
 * @param ll Pointer to the linked list instantiated by init()
 *
 * @throws INVALID_POINTER if **ll** is either NULL, uninitialized or unaddressable.
 *
 * @return
 * Zero(0) if linked list **ll** was successfully traversed.
 *
 * <p>
 * **Complexity** O(*size*)
 *
 * @note
 * There was no intention of creating traverse.
 * But its useful in some way for someone.
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/node.h>
 *
 * int main() {
 *
 * 	// Initializing an empty doubly circular linked list
 * 	LinkedList *ll = init();
 * 	// Appending data to ll
 * 	append(ll, 52);
 * 	append(ll, 37);
 * 	// Printing all the elements of ll
 * 	traverse(ll);
 * 	// Destroying ll
 * 	destroy(ll);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 52 37
 *
 * ~~~
 *
 * @see printer() forEach()
 */
int traverse(LinkedList *ll);


/**
 * Prints out the data supplied to the default output stream with a trailing whitespace.
 *
 * <p>
 * printer is a minimal callback function for traverse function.
 *
 * @param data Data to be printed to the default output stream
 * It is recommended that users should make their own printer function
 * for customization and flexibility.
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(1)
 *
 * @see traverse()
 */
int printer(node_t data);


#endif //LINKEDLIST_NODE_H
