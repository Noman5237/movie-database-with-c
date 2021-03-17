/**
 * @file node.c
 * @author Anonyman637
 * @date 8/11/2020; 1:05 AM
 */


#include <DataStruct/node.h>
#include <exception.h>


/* ============================== CONSTRUCTOR ========================= */


LinkedList *ll_init() {
	LinkedList *ll = (LinkedList *) malloc(sizeof(LinkedList));
	if (!ll) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (LinkedList *) NULL;
	}
	
	ll->_size = 0;
	ll->_head = (Node *) NULL;
	
	return ll;
}


/* ============================== ACCESSOR ========================= */


node_t ll_get(LinkedList *ll, int index) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		
		// Although -size is a valid index,
		// it still needs to pass the INDEX_OUT_OF_BOUNDS test
		--index;
	}
	
	if (index >= ll->_size) {
		return EXCEPTION_NEW(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *node = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, node = node->next);     // Empty Body
	} else {
		// Remember! we cut off index by 1 when it is reverse
		for (int i = 0; i <= index; ++i, node = node->prev);    // Empty Body
	}
	
	return node->data;
}


int ll_forEach(LinkedList *ll, int (*callback)(node_t)) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	Node *node = ll->_head;
	for (int i = 0; i < ll->_size; ++i, node = node->next) {
		if (callback(node->data)) {
			return EXCEPTION_NEW(CALLBACK_ERROR);
		}
	}
	
	return 0;
}


/* ============================== CAPACITY ========================= */


int ll_size(LinkedList *ll) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER), -1;
	}
	
	return ll->_size;
}


int ll_empty(LinkedList *ll) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	return ll->_size == 0;
}


/* ============================== MODIFIERS ========================= */


int ll_append(LinkedList *ll, node_t newData) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	Node *node = (Node *) malloc(sizeof(Node));
	
	if (!node) {
		return EXCEPTION_NEW(OUT_OF_MEMORY);
	}
	
	node->data = newData;
	
	if (!ll->_size) {
		// When a node is alone it points to itself!
		node->prev = node;
		node->next = node;
		ll->_head = node;
		
		++ll->_size;
		
		return 0;
	}
	
	Node *head = ll->_head;
	Node *last = head->prev;
	
	// We are inserting the new node in the junction of head and last node
	head->prev = node;
	node->next = head;
	
	last->next = node;
	node->prev = last;
	
	++ll->_size;
	
	return 0;
}


int ll_insert(LinkedList *ll, int index, node_t newData) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		// Although -size is a valid index,
		// it still needs to pass the INDEX_OUT_OF_BOUNDS test
		--index;
	}
	
	if (index >= ll->_size) {
		return EXCEPTION_NEW(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *curr = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, curr = curr->next);     // Empty Body
	} else {
		// Remember! we cut off index by 1 when it is reverse
		// But when inserting in reverse, we can't let reverse index replace head
		// Because inserting -size is theoretically impossible
		// Because after inserting the index of new node will be -(size + 1) which destroys consistency
		for (int i = 0; i < index; ++i, curr = curr->prev);    // Empty Body
	}
	
	Node *node = (Node *) malloc(sizeof(Node));
	
	if (!node) {
		return EXCEPTION_NEW(OUT_OF_MEMORY);
	}
	
	node->data = newData;
	
	Node *prev = curr->prev;
	
	// We place node at the index of curr node
	prev->next = node;
	node->prev = prev;
	
	curr->prev = node;
	node->next = curr;
	
	// When inserting in reverse, we can't let reverse index replace head
	// Because inserting -size is theoretically impossible
	// Because after inserting the index of new node will be -(size + 1) which destroys consistency
	if (index == 0 && !reverse) {
		ll->_head = node;
	}
	
	++ll->_size;
	
	return 0;
}


int ll_erase(LinkedList *ll, int index) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		// Although -size is a valid index,
		// it still needs to pass the INDEX_OUT_OF_BOUNDS test
		--index;
	}
	
	if (index >= ll->_size) {
		return EXCEPTION_NEW(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *curr = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, curr = curr->next);     // Empty Body
	} else {
		// Remember! we cut off index by 1 when it is reverse
		for (int i = 0; i <= index; ++i, curr = curr->prev);    // Empty Body
	}
	
	Node *prev = curr->prev;
	Node *next = curr->next;
	
	// Replacing references of the neighboring nodes of curr node
	prev->next = next;
	next->prev = prev;
	
	if (index == 0) {
		ll->_head = next;
	}
	
	free(curr);
	--ll->_size;
	
	return 0;
}


int ll_set(LinkedList *ll, int index, node_t newData) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	int reverse = 0;
	
	if (index < 0) {
		reverse = 1;
		index *= -1;
		// Although -size is a valid index,
		// it still needs to pass the INDEX_OUT_OF_BOUNDS test
		--index;
	}
	
	if (index >= ll->_size) {
		return EXCEPTION_NEW(INDEX_OUT_OF_BOUNDS);
	}
	
	Node *node = ll->_head;
	
	if (!reverse) {
		for (int i = 0; i < index; ++i, node = node->next);     // Empty Body
	} else {
		// Remember! we cut off index by 1 when it is reverse
		for (int i = 0; i <= index; ++i, node = node->prev);    // Empty Body
	}
	
	node->data = newData;
	
	return 0;
}


/* ============================== DESTRUCTOR ========================= */


int ll_destroy(LinkedList *ll) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	Node *node = ll->_head;
	Node *next = node->next;
	
	// Although at the end of the loop next will point to freed address
	// Because the loop always terminates by following condition
	for (int i = 0; i < ll->_size; ++i, node = next, next = next->next) {
		free(node);
	}
	
	free(ll);
	return 0;
}


/* ============================== UTILITY ========================= */


int ll_traverse(LinkedList *ll) {
	if (!ll) {
		return EXCEPTION_NEW(INVALID_POINTER);
	}
	
	ll_forEach(ll, printer);
	printf("\n");
	
	return 0;
}
