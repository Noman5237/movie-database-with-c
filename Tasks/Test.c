/**
 * @file: ImportData.c
 * @author: Anonyman637
 * @date: 3/18/2021; 2:51 AM
 */

#include <input.h>

int validator_name(char *name) {
	int len = strlen(name);
	if (len < 5) {
		return 0;
	}
	return 1;
}

int hi() {
	printf("Hi\n");
	return 0;
}

int about() {
	printf("about\n");
	return 0;
}

int main() {
	input_menu(2, input_menuOption_init("Hi", "This is a simple hi", hi),
	           input_menuOption_init("About", "This is the content creator", about));
	return 0;
}

