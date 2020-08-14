/**
 * @file queue.h
 * @author: Anonyman637
 * @date: 8/11/2020; 2:14 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <DataStruct/node.h>

/**
 * Queue is nothing special than a one dimensional list
 * which is modified and accessed in unique fashion.
 *
 * The type Queue is just a syntactic sugar
 * which makes code more meaningful and understandable in contexts of Queue.
 *
 * ### Design Preview
 * ~~~.c
 * +-------------------------------------------------------+
 * |                                                       |
 * | +-----------+-----+                                   |
 * | |size       | 4   |               Queue               |
 * | +-----------------+                                   |
 * | +---------------------------------------------------+ |
 * | |                                                   | |
 * | | +----------------------------------------------+  | |
 * | | |  back                               front    |  | |
 * | | |  +-----+     +-----+     +-----+    +-----+  |  | |
 * | | |  |7    |     |3    |     |2    |    |5    |  |  | |
 * | | +--+prev <-----+prev <-----+prev <----+prev <--+  | |
 * | | +-->next +----->next +----->next +---->next +--+  | |
 * | | |  +-----+     +-----+     +-----+    +-----+  |  | |
 * | | |                                     (head)   |  | |
 * | | +----------------------------------------------+  | |
 * | |                                                   | |
 * | +---------------------------------------------------+ |
 * |                                                       |
 * +-------------------------------------------------------+
 * ~~~
 *
 * @note
 * As Linked List and Queue shares many functions,
 * so this design pattern was adopted to give users a taste of inheritance like features
 * although it was not the intention at first.
 *
 * @attention
 * Do not modify the size of head of the Queue unless you know what you doing and
 * are solely responsible for unwanted and weird behaviour of your programs.
 * <br>
 * As Queue is a syntactic sugar, so it recommended to use the following functions
 * in order to avoid confusions in contexts of Queue:
 * <br>
 * init()
 * front() back() forEach() traverse()
 * size() empty()
 * enqueue() dequeue()
 * destroy()
 *
 * @warning
 * Any type of **modification** of Queue without the supplied modifier functions
 * is not intended and the supplied software is not responsible for any
 * fatal or non crashes and unwanted and weird behaviour of the user programs.
 *
 * @see LinkedList init() enqueue()
 */
typedef LinkedList Queue;


/* ============================== ACCESSOR ========================= */


/**
 * Get the earliest available enqueued data of the provided queue.
 *
 * @param queue Pointer to the queue instantiated by init()
 *
 * @throws INVALID_POINTER if **queue** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **queue** is empty.
 *
 * @return
 * Earliest available enqueued data of the provided queue.
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/queue.h>
 *
 * int main() {
 *
 * 	// Initializing an empty queue
 * 	Queue *queue = init();
 * 	// Enqueuing data to queue
 * 	enqueue(queue, 6);
 * 	enqueue(queue, 2);
 * 	enqueue(queue, 3);
 * 	enqueue(queue, 7);
 * 	// Getting the earliest available enqueued data
 * 	printf("%d\n", front(queue));
 * 	// Jumbling queue
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	enqueue(queue, 37);
 * 	enqueue(queue, 5);
 * 	// Getting the earliest available enqueued data
 * 	printf("%d\n", front(queue));
 * 	// Destroying queue
 * 	destroy(queue);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 6
 * 37
 *
 * ~~~
 *
 * @see back() init() enqueue()
 */
node_t front(Queue *queue);


/**
 * Get the latest available enqueued data of the provided queue.
 *
 * @param queue Pointer to the queue instantiated by init()
 *
 * @throws INVALID_POINTER if **queue** is either NULL, uninitialized or unaddressable.
 * @throws INDEX_OUT_OF_BOUND if **queue** is empty.
 *
 * @return
 * Latest available enqueued data of the provided queue.
 *
 * <p>
 * **Complexity** O(1)
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/queue.h>
 *
 * int main() {
 *
 * 	// Initializing an empty queue
 * 	Queue *queue = init();
 * 	// Enqueuing data to queue
 * 	enqueue(queue, 7);
 * 	enqueue(queue, 3);
 * 	enqueue(queue, 2);
 * 	enqueue(queue, 6);
 * 	// Getting the latest available enqueued data
 * 	printf("%d\n", back(queue));
 * 	// Jumbling queue
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	enqueue(queue, 5);
 * 	enqueue(queue, 37);
 * 	// Getting the latest available enqueued data
 * 	printf("%d\n", back(queue));
 * 	// Destroying queue
 * 	destroy(queue);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 6
 * 37
 *
 * ~~~
 *
 * @see back() init() dequeue()
 */
node_t back(Queue *queue);


/* ============================== MODIFIERS ========================= */


/**
 * Adds a new data to the provided queue.
 *
 * @param queue Pointer to the queue instantiated by init()
 * @param data Data to be enqueued in the provided queue
 *
 * @throws INVALID_POINTER if **queue** is either NULL, uninitialized or unaddressable.
 * @throws OUT_OF_MEMORY if allocation is not possible for new data.
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(1)
 *
 * @note
 * Instead of naming this function push,
 * enqueue sounds more good in context of queue.
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/queue.h>
 *
 * int main() {
 *
 * 	// Initializing an empty queue
 * 	Queue *queue = init();
 * 	// Enqueuing data to queue
 * 	enqueue(queue, 5);
 * 	enqueue(queue, 2);
 * 	enqueue(queue, 3);
 * 	enqueue(queue, 7);
 * 	// Traversing Queue
 * 	traverse(queue);
 * 	// Jumbling queue
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	enqueue(queue, 6);
 * 	enqueue(queue, 37);
 * 	// Traversing Queue
 * 	traverse(queue);
 * 	// Destroying queue
 * 	destroy(queue);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 5 2 3 7
 * 6 37
 *
 * ~~~
 *
 * @see init() dequeue() traverse()
 */
int enqueue(Queue *queue, node_t data);


/**
 * Erases the earliest available enqueued data of the provided queue.
 *
 * @param queue Pointer to the queue instantiated by init()
 *
 * @throws INVALID_POINTER if **queue** is either NULL, uninitialized or unaddressable.
 *
 * @return
 * Zero(0) if successful.
 *
 * <p>
 * **Complexity** O(1)
 *
 * @note
 * Instead of naming this function push,
 * dequeue sounds more good in context of queue.
 *
 * #### Example
 * ~~~.c
 * #include<DataStruct/queue.h>
 *
 * int main() {
 *
 * 	// Initializing an empty queue
 * 	Queue *queue = init();
 * 	// Enqueuing data to queue
 * 	enqueue(queue, 6);
 * 	enqueue(queue, 37);
 * 	enqueue(queue, 5);
 * 	enqueue(queue, 2);
 * 	// Traversing Queue
 * 	traverse(queue);
 * 	// De-queuing some data
 * 	dequeue(queue);
 * 	dequeue(queue);
 * 	// Traversing Queue
 * 	traverse(queue);
 * 	// Destroying queue
 * 	destroy(queue);
 *
 * 	return 0;
 * }
 * ~~~
 *
 * #### Output
 * ~~~
 * 6 37 5 2
 * 6 37
 *
 * ~~~
 *
 * @see init() enqueue() traverse() destroy()
 */
int dequeue(Queue *queue);

#endif //QUEUE_H
