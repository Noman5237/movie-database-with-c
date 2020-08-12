
/* Created By: Anonyman637
 * Created On: 8/12/2020; 12:48 AM
 */

#include <exception.h>

int exception__new(int errorCode, char *file, int line) {
	
	if (!STRICT) {
		return errorCode;
	}
	
	exception_printMessage(errorCode);
//	printf("Trace => %s: %d\n", file, line);
	exit(errorCode);
	
}

void exception_printMessage(int errorCode) {
	
	switch (errorCode) {
		case INVALID_POINTER:
			printf("Pointer reference is either NULL, uninitialized or unaddressable.");
			break;
		case CALLBACK_ERROR:
			printf("Callback function execution is not successful.");
			break;
		case INDEX_OUT_OF_BOUNDS:
			printf("Index is out of bounds i.e. trying to access an element that doesn't exist.");
			break;
		default:
			printf("Error is not a fault of our knowledge,"
			       " but a mistake of our judgment giving assent to that which is not true.");
			break;
	}
	
	printf("\n");
	
}

void exception_setStrict(int strictness) {
	STRICT = strictness;
	
}
