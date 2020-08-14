/**
 * @file queue.c
 * @author: Anonyman637
 * @date: 8/11/2020; 2:14 AM
 */

#include <DataStruct/queue.h>

/* ============================== ACCESSOR ========================= */

node_t front(Queue *queue) {
	return get(queue, 0);
}

node_t back(Queue *queue) {
	return get(queue, -1);
}

/* ============================== MODIFIERS ========================= */

int enqueue(Queue *queue, node_t data) {
	return append(queue, data);
}

int dequeue(Queue *queue) {
	return erase(queue, 0);
}
