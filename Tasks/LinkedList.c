#include <stdio.h>
#include <DataStruct/node.h>


int main() {
	
	LinkedList *ll = new();
	append(ll, 4);
	append(ll, 5);
	append(ll, 6);
	erase(ll, 0);
	traverse(ll);
	
	delete(ll);
	return 0;
}
