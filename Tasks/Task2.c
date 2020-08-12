
/* Created By: Anonyman637
 * Created On: 8/12/2020; 5:55 AM
 */

#include <DataStruct/queue.h>

int main() {
	
	// Initializing a new queue; allocated on heap
	Queue *queue = new();
	
	// Enqueuing data into queue
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	
	// Getting queue size
	printf("Queue Size: %d\n", size(queue));
	
	// Traversing queue
	traverse(queue);
	printf("\n");
	
	// De-queuing data from queue
	dequeue(queue);
	traverse(queue);
	printf("\n");
	
	dequeue(queue);
	traverse(queue);
	printf("\n");
	
	dequeue(queue);
	
	// Queue is now empty
	printf("Queue %s empty.\n", empty(queue) ? "is": "is not");
	
	// De-queuing an empty queue exits with error in strict mode
	dequeue(queue);
	
	// Freeing the memory allocated on heap by new
	delete(queue);
	
	return 0;
}


