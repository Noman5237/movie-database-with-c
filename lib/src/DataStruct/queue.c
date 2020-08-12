
/* Created By: Anonyman637
 * Created On: 8/11/2020; 2:14 AM
 */

#include <DataStruct/queue.h>

/* ============================== ACCESSOR ========================= */

INT front(Queue *queue) {
	return get(queue, 0);
}

INT back(Queue *queue) {
	return get(queue, -1);
}

/* ============================== MODIFIERS ========================= */

int enqueue(Queue *queue, INT data) {
	return append(queue, data);
}

int dequeue(Queue *queue) {
	return erase(queue, 0);
}
