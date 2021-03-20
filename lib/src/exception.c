/**
 * @file exception.c
 * @author: Anonyman637
 * @date: 8/11/2020; 11:51 PM
 */


#include <exception.h>


int exception_new(int errorCode, const char *file, int line, int (*handler)(int)) {
	int responseCode = handler(errorCode);
	
	if (responseCode & VERBOSE) {
		// With VERBOSE we provide as much as information as we can
		printf("Trace => %s: %d\n", file, line);
	}
	
	if (responseCode & FATAL) {
		// With FATAL we exit immediately.
		exit(errorCode);
	}
	
	return errorCode;
}


/* ============================== UTILITY ========================= */

/**
 * Fatality Behaviour for defaultExceptionHandler()
 */
int defaultExceptionHandlerFatality = FATAL | VERBOSE;


int defaultExceptionHandler(int errorCode) {
	if (defaultExceptionHandlerFatality & VERBOSE) {
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
			case OUT_OF_MEMORY:
				printf("Probably primary memory allocated for this program is full.");
				break;
			case FILE_NOT_FOUND:
				printf("Provided file cannot be read maybe because the path doesn't exist.");
				break;
			case SYNTAX_ERROR:
				printf("Syntax error in query expression.");
				break;
			default:
				printf("Error is not a fault of our knowledge,"
				       " but a mistake of our judgment giving assent to that which is not true.");
				break;
			
		}
		
		printf("\n");
	}
	
	return defaultExceptionHandlerFatality;
}


void setDefaultExceptionHandlerFatality(int fatality) {
	defaultExceptionHandlerFatality = fatality;
}

