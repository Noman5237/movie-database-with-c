/**
 * @file: Console.h
 * @author: Anonyman637
 * @date: 4/4/2021; 2:38 AM
 */

#ifndef MOVIEDATABASEAPP_H
#define MOVIEDATABASEAPP_H

#include <input.h>
#include <Database/database.h>
#include <movie.h>

/* ============================== MAIN MENU ========================= */

int manageMovieDatabase();

int addMovie();

int showMovies();

int deleteMovie();

int searchMovie();


/* ============================== SUB MENU ========================= */

int createDatabase();

int loadDatabase();

int quickSearch();

int advancedSearch();

int unloadNExportOperatingDatabase();
#endif //MOVIEDATABASEAPP_H
