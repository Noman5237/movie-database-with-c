/**
 * @file: MovieDatabase.c
 * @date: 3/17/2021; 5:30 PM
 */

#include <Database/database.h>
#include "Console.cpp"

#define DATABASE_DIR "C:\\Users\\DOLPHIN\\Desktop\\Coding\\MovieDatabase\\resources\\database\\"

int main() {
	DB *db = db_init("Movie Database");
	/*db_add(db, movie_init("Philosopher's Stone", "2001",
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
	                      "Radcliffe", "Emma Watson",
	                      "Chris Columbus", "David Heyman",
	                      "Late one night, Albus Dumbledore and Minerva McGonagall, professors at Hogwarts School of "
	                      "Witchcraft and Wizardry, along with the school's groundskeeper Rubeus Hagrid, deliver a recently "
	                      "orphaned infant named Harry Potter to his only remaining relatives, the Dursleys."));
	
	db_add(db, movie_init("Stone", "2003",
	                      "Radcliffe", "Emma Watson",
	                      "Chris Columbus", "David Heyman",
	                      "Late one night,Albus Dumbledore and Minerva McGonagall, professors at Hogwarts School of "
	                      "Witchcraft and Wizardry, along with the school's groundskeeper Rubeus Hagrid, deliver a recently "
	                      "orphaned infant named Harry Potter to his only remaining relatives, the Dursleys."));
	*/




	DB *sampleQuery = db_query(db, "sampleQuery", "title : `Harry Potter and the Philosopher's Stone` | year : `2003`");
	db_print(sampleQuery);
	db_export(sampleQuery, DATABASE_DIR);
	db_destroy(sampleQuery);

//	DB *onlyRadCliffe = db_query(db, "onlyRadCliffe", "actor : `Radcliffe`");
	DB *onlyRadCliffe = db_import(DATABASE_DIR "onlyRadCliffe.db");
	db_print(onlyRadCliffe);
	
	db_print(db);
	db_export(db, DATABASE_DIR);
	db_destroy(db);


	
	return 0;
}
