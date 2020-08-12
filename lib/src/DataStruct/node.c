
/* Created By: Anonyman637
 * Created On: 8/11/2020 1:05 AM
 */

#include <DataStruct/node.h>
#include <exception.h>

/* ============================== CONSTRUCTOR ========================= */

LinkedList *new() {
	LinkedList *ll = (LinkedList *) malloc(sizeof(LinkedList));
	ll->_size = 0;
	ll->_head = NULL;
	
	return ll;
}

/* ============================== ACCESSOR ========================= */

INT get(LinkedList *ll, int index) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		--index;
	}
	
	if (index >= ll->_size) {
		return exception_new(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *node = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, node = node->next);     // Empty Body
	} else {
		for (int i = 0; i <= index; ++i, node = node->prev);    // Empty Body
	}
	
	return node->data;
}

int foreach(LinkedList *ll, int (*callback)(int)) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	Node *node = ll->_head;
	for (int i = 0; i < ll->_size; ++i, node = node->next) {
		if (callback(node->data)) {
			return exception_new(CALLBACK_ERROR);
		}
	}
	
	return 0;
}

int traverse(LinkedList *ll) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}

	foreach(ll, printer);
	
	return 0;
}

/* ============================== CAPACITY ========================= */

int size(LinkedList *ll) {
	if (!ll) {
		return exception_new(INVALID_POINTER), -1;
	}
	
	return ll->_size;
}

int empty(LinkedList *ll) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	return ll->_size == 0;
}
/* ============================== MODIFIERS ========================= */

int append(LinkedList *ll, INT data) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	
	if (!ll->_head) {
		node->prev = node;
		node->next = node;
		ll->_head = node;
	}
	
	Node *head = ll->_head;
	Node *last = head->prev;
	
	head->prev = node;
	node->next = head;
	
	last->next = node;
	node->prev = last;
	
	++ll->_size;
	
	return 0;
}

int insert(LinkedList *ll, int index, INT data) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		--index;
	}
	
	if (index >= ll->_size) {
		return exception_new(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *curr = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, curr = curr->next);     // Empty Body
	} else {
		for (int i = 0; i <= index; ++i, curr = curr->prev);    // Empty Body
	}
	
	Node *prev = curr->prev;
	
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	
	prev->next = node;
	node->prev = prev;
	
	curr->prev = node;
	node->next = curr;
	
	if (index == 0) {
		ll->_head = node;
	}
	
	++ll->_size;
	
	return 0;
}

int erase(LinkedList *ll, int index) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		--index;
	}
	
	if (index >= ll->_size) {
		return exception_new(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *curr = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, curr = curr->next);     // Empty Body
	} else {
		for (int i = 0; i <= index; ++i, curr = curr->prev);    // Empty Body
	}
	
	Node *prev = curr->prev;
	Node *next = curr->next;
	
	prev->next = next;
	next->prev = prev;
	
	if (index == 0) {
		ll->_head = next;
	}
	
	free(curr);
	--ll->_size;
	
	return 0;
}

int set(LinkedList *ll, int index, INT newData) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		--index;
	}
	
	if (index >= ll->_size) {
		return exception_new(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *node = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, node = node->next);     // Empty Body
	} else {
		for (int i = 0; i <= index; ++i, node = node->prev);    // Empty Body
	}
	
	node->data = newData;
	
	return 0;
}

/* ============================== DESTRUCTOR ========================= */

int delete(LinkedList *ll) {
	if (!ll) {
		return exception_new(INVALID_POINTER);
	}
	
	Node *node = ll->_head;
	Node *next = node->next;
	for (int i = 0; i < ll->_size; ++i, node = next, next = next->next) {
		free(node);
	}
	
	free(ll);
	return 0;
}

/* ============================== UTILITY ========================= */

int printer(INT data) {
	printf("%d ", data);
	return 0;
}
