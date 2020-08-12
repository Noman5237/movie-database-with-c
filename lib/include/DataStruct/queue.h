
/* Created By: Anonyman637
 * Created On: 8/11/2020; 2:14 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <DataStruct/node.h>

typedef LinkedList Queue;

/* ============================== ACCESSOR ========================= */

INT front(Queue *queue);

INT back(Queue *queue);

/* ============================== MODIFIERS ========================= */

int enqueue(Queue *queue, INT data);

int dequeue(Queue *queue);

#endif //QUEUE_H
