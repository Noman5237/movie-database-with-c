/**
 * @file: ImportData.c
 * @date: 3/18/2021; 2:51 AM
 */

#include <Database/database.h>

int main() {
	DB *db = db_import(
			"P:\\TEMP\\CoreProgramming\\CProjects\\Homework\\MovieDatabase\\resources\\database\\HarryPotterFranchise");
	db_print(db);
	db_destroy(db);
}
