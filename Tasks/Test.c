/**
 * @file: ImportData.c
 * @author: Anonyman637
 * @date: 3/18/2021; 2:51 AM
 */

#include <Database/database.h>

int main() {
	DB *db = db_import(
			"P:\\TEMP\\CoreProgramming\\CProjects\\Homework\\MovieDatabase\\resources\\database\\HarryPotterFranchise");
	db_show(db);
	db_destroy(db);
}