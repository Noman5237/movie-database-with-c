/**
 * @file exception.h
 * @author: Anonyman637
 * @date: 8/11/2020; 11:51 PM
 */


#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <stdio.h>
#include <stdlib.h>


/**
 * Currently supported exception types by defaultExceptionHandler().
 */
enum errorCode {
	INVALID_POINTER = 101,
	CALLBACK_ERROR,
	INDEX_OUT_OF_BOUNDS,
	OUT_OF_MEMORY
};

/**
 * Currently supported respond codes by exception_new().
 */
enum exceptionResponder {
	SILENT = 0x0,
	FATAL,
	VERBOSE = 0x10,
};


/**
 * This macro eases process of throwing exceptions
 * that gets handled by defaultExceptionHandler() provided as utility.
 *
 * If you dont like default exception handler craft a macro like this
 * that uses your own exception handler.
 *
 * @see exception_new() defaultExceptionHandler()
 */
#define EXCEPTION_NEW(errorCode) exception_new(errorCode, __FILE__, __LINE__, defaultExceptionHandler)


/**
 * Initiates a pseudo exception handling process with the help of provided trace and handler.
 *
 * exception_new prints the trace of the caller function and
 * passes the errorCode to the errorCode to handler function.
 * <br>
 * Depending on the response sent by the handler, it will act accordingly.
 *
 * @param errorCode Error Code for new exception thrown
 * @param file File Location of caller function
 * @param line Line Location of caller function
 * @param handler Handler is a callback function for handling this exception
 * and it must return a response
 *
 * @return
 * **errorCode** if handler responds with anything other than FATAL.
 *
 * @see defaultExceptionHandler()
 */
int exception_new(int errorCode, const char* file, int line, int (*handler)(int));


/* ============================== UTILITY ========================= */


/**
 * Default exception handler for the library functions.
 *
 * By default it responds with VERBOSE and FATAL for all known error codes described.
 * It also prints some hints regarding the cause of exception.
 *
 * <p>
 * To change the default behaviour of the function
 * use setDefaultExceptionHandlerFatality to suit your need and style.
 *
 * @param errorCode Error Code to handle
 *
 * @return
 * value of defaultExceptionHandlerFatality
 *
 * @see exception_new()
 */
int defaultExceptionHandler(int errorCode);


/**
 * Set desired type of exception handling behaviour for defaultExceptionHandler().
 *
 * @param fatality Fatality code for default exception handler
 *
 * @see defaultExceptionHandler()
 */
void setDefaultExceptionHandlerFatality(int fatality);


#endif //EXCEPTION_H
