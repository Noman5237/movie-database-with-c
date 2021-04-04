/**
 * @file: input.h
 * @author: Anonyman637
 * @date: 4/3/2021; 9:32 PM
 */

#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <exception.h>
#include <stdarg.h>
#include <stdbool.h>

#define INPUT_LEN_MAX 101

char *input(char *prompt, char *errorMessage, char *helpMessage, int (validator)(char *));

int validator_null(char *);

int input_empty(char *str);

typedef struct InputMenuOption {
	char *menuPrompt;
	char *helpMessage;
	
	int (*executor)();
} InputMenuOption;

InputMenuOption *input_menuOption_init(char *prompt, char *helpMessage, int (*executor)());

int input_menu(int totalNumberOfOptions, ...);

#endif //INPUT_H
