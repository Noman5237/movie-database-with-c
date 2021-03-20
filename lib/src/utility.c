/**
 * @file: utility.c
 * @author: Anonyman637
 * @date: 3/20/2021; 8:48 AM
 */

#include <stdio.h>
#include <utility.h>
#include <string.h>

/* ============================== DRAWING ========================= */

int drawGrid(int noOfColumns, int colWidth) {
	for (int i = 0; i < noOfColumns; i++) {
		printf("+");
		for (int j = 0; j < colWidth; j++) {
			printf("-");
		}
	}
	printf("+\n");
	
	return 0;
}

int centerText(char *text, int fieldWidth) {
	int strLen = (int) strlen(text);
	int padLen = (fieldWidth - strLen) / 2;
	printf("%*s%s%*s", padLen, "", text, fieldWidth - strLen - padLen, "");
	
	return 0;
}

int printMin(char *text, int minWidth) {
	
	int strLen = (int) strlen(text);
	
	if (strLen <= minWidth) {
		printf("%s", text);
		for (int i = 0; i < minWidth - strLen; i++) {
			printf(" ");
		}
	} else {
		for (int i = 0; i < minWidth - 3; i++) {
			printf("%c", text[i]);
		}
		printf("...");
	}
	
	return 0;
}
