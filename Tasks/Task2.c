
/* Created By: Anonyman637
 * Created On: 8/12/2020; 5:55 AM
 */

#include <DataStruct/queue.h>

int main() {
	
	// TODO front and back
	
	// Initializing a new queue; allocated on heap
	Queue *queue = init();
	
	// Enqueuing data into queue
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	
	// Getting queue size
	printf("Queue Size: %d\n", size(queue));
	
	// Getting the earliest enqueued data
	printf("Front of Queue: %d\n", front(queue));
	
	// Getting the latest enqueued data
	printf("Back of Queue: %d\n", back(queue));
	
	// Traversing queue
	traverse(queue);
	
	// De-queuing data from queue
	dequeue(queue);
	traverse(queue);
	
	dequeue(queue);
	traverse(queue);
	
	dequeue(queue);
	
	// Queue is now empty
	printf("Queue %s empty.\n", empty(queue) ? "is": "is not");
	
	// De-queuing an empty queue exits with error in strict mode
	// dequeue(queue);
	
	// Freeing the memory allocated on heap by new
	destroy(queue);
	
	return 0;
}


