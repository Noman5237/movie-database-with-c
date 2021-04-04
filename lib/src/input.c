/**
 * @file: input.c
 * @author: Anonyman637
 * @date: 4/3/2021; 9:32 PM
 */

#include <input.h>

char *input(char *prompt, char *errorMessage, char *helpMessage, int (validator)(char *)) {
	char *choice = malloc(sizeof(char) * INPUT_LEN_MAX);
	if (!choice) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (char *) NULL;
	}
	
	do {
		printf("%s: ", prompt);
		fflush(stdin);
		scanf("%[^\n]", choice);
		if (!strcmp(choice, "help")) {
			printf("%s\n", helpMessage);
			continue;
		} else if (!strcmp(choice, "quit")) {
			return "";
		}
		
		if (validator(choice)) {
			break;
		} else {
			printf("%s\n", errorMessage);
		}
		
	} while (true);
	
	return choice;
}

int validator_null(char *str) {
	return true;
}

int input_empty(char *str) {
	return str[0] == '\0';
}

InputMenuOption *input_menuOption_init(char *prompt, char *helpMessage, int (*executor)()) {
	InputMenuOption *menuOption = (InputMenuOption *) malloc(sizeof(InputMenuOption));
	if (!menuOption) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (InputMenuOption *) NULL;
	}
	
	menuOption->menuPrompt = malloc(sizeof(char) * (strlen(prompt) + 1));
	if (!menuOption->menuPrompt) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (InputMenuOption *) NULL;
	}
	
	strcpy(menuOption->menuPrompt, prompt);
	
	menuOption->helpMessage = malloc(sizeof(char) * (strlen(helpMessage) + 1));
	if (!menuOption->helpMessage) {
		return EXCEPTION_NEW(OUT_OF_MEMORY), (InputMenuOption *) NULL;
	}
	
	strcpy(menuOption->helpMessage, helpMessage);
	
	menuOption->executor = executor;
	
	return menuOption;
}

int input_menu(int totalNumberOfOptions, ...) {
	va_list optionsArgs;
	va_start(optionsArgs, totalNumberOfOptions);
	InputMenuOption *options[totalNumberOfOptions];
	
	for (int i = 0; i < totalNumberOfOptions; i++) {
		options[i] = va_arg(optionsArgs, InputMenuOption *);
	}
	
	char *choice = malloc(sizeof(char) * INPUT_LEN_MAX);
	if (!choice) {
		return EXCEPTION_NEW(OUT_OF_MEMORY);
	}
	
	int optionNo;
	do {
		for (int i = 0; i < totalNumberOfOptions; i++) {
			printf("%d. %s \n", i + 1, options[i]->menuPrompt);
		}
		printf("Choice: ");
		fflush(stdin);
		scanf("%s", choice);
		if (!strcmp(choice, "help")) {
			for (int i = 0; i < totalNumberOfOptions; i++) {
				printf("%s: %s\n", options[i]->menuPrompt, options[i]->helpMessage);
			}
			printf("help: Shows help in current context\n");
			printf("quit: Quits from current context\n");
			continue;
		} else if (!strcmp(choice, "quit")) {
			return 0;
		}
		
		optionNo = atoi(choice);
		if (optionNo < 1 || optionNo > totalNumberOfOptions) {
			printf("Invalid Choice!\n");
			continue;
		}
		
		options[optionNo - 1]->executor();
		
	} while (true);
}

