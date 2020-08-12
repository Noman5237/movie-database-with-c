
/* Created By: Anonyman637
 * Created On: 8/11/2020; 11:51 PM
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdio.h>
#include <stdlib.h>

enum errorCode {
	INVALID_POINTER = 101,
	CALLBACK_ERROR,
	INDEX_OUT_OF_BOUNDS,
};

static int STRICT = 1;

#define exception_new(errorCode) exception__new(errorCode, __FILE__, __LINE__)

int exception__new(int errorCode, char *file, int line);

void exception_printMessage(int errorCode);

void exception_setStrict(int strictness);

#endif //EXCEPTION_H
