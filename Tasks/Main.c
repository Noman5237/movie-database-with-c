/**
 * @file: MovieDatabase.c
 * @author: Anonyman637
 * @date: 3/17/2021; 5:30 PM
 */

#include <Database/database.h>

int main() {
	DB *db = db_init("Harry Potter Franchise");
	db_add(db, movie_init("Philosopher's Stone", "2001",
	                      "Daniel Radcliffe", "Emma Watson",
	                      "Chris Columbus", "David Heyman",
	                      "Late one night, Albus Dumbledore and Minerva McGonagall, professors at Hogwarts School of "
	                      "Witchcraft and Wizardry, along with the school's groundskeeper Rubeus Hagrid, deliver a recently "
	                      "orphaned infant named Harry Potter to his only remaining relatives, the Dursleys."));
	
	db_add(db, movie_init("Harry Potter and the Philosopher's Stone", "2001",
	                      "Daniel Radcliffe", "Emma Watson",
	                      "Chris Columbus", "David Heyman",
	                      "Late one night, Albus Dumbledore and Minerva McGonagall, professors at Hogwarts School of "
	                      "Witchcraft and Wizardry, along with the school's groundskeeper Rubeus Hagrid, deliver a recently "
	                      "orphaned infant named Harry Potter to his only remaining relatives, the Dursleys."));
	
	db_add(db, movie_init("Harry and the Philosopher's Stone", "2001",
	                      "Daniel Radcliffe", "Emma Watson",
	                      "Chris Columbus", "David Heyman",
	                      "Late one night, Albus Dumbledore and Minerva McGonagall, professors at Hogwarts School of "
	                      "Witchcraft and Wizardry, along with the school's groundskeeper Rubeus Hagrid, deliver a recently "
	                      "orphaned infant named Harry Potter to his only remaining relatives, the Dursleys."));
	
	db_add(db, movie_init("Stone", "2003",
	                      "Daniel Radcliffe", "Emma Watson",
	                      "Chris Columbus", "David Heyman",
	                      "Late one night, Albus Dumbledore and Minerva McGonagall, professors at Hogwarts School of "
	                      "Witchcraft and Wizardry, along with the school's groundskeeper Rubeus Hagrid, deliver a recently "
	                      "orphaned infant named Harry Potter to his only remaining relatives, the Dursleys."));
	
	char *exportPath = "P:\\TEMP\\CoreProgramming\\CProjects\\Homework\\MovieDatabase\\resources\\database\\";
	
	DB *sampleQuery = db_query(db, "sampleQuery", "title : `Harry Potter and the Philosopher's Stone`");
//	DB *sampleQuery = db_query(db, "sampleQuery", "a : `b` & c : `d`");
	db_show(sampleQuery);
	db_export(sampleQuery, exportPath);
	db_destroy(sampleQuery);
	
	db_show(db);
	db_export(db, exportPath);
	
	db_destroy(db);
	
	return 0;
}
