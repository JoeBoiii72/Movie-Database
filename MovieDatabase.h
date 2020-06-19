/*  
=======================================
$File: MovieDatabase.h $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#ifndef __MOVIEDATABASE_H__
#define __MOVIEDATABASE_H__

#include "Movie.h"
#include "LinkedList.h"
#include <stdio.h>

struct MovieDatabase
{
    LinkedList list;
};

typedef struct MovieDatabase MovieDatabase;

MovieDatabase* createMovieDatabase();
void           addMoviesFromFile(MovieDatabase* mdb, const char* fileName);
void           freeMovieDatabase(MovieDatabase* mdb);
void           printMovieDatabase(MovieDatabase* mdb);
void           sortMovieDatabase(MovieDatabase *mdb, int(*comp)(Movie*, Movie*));
MovieDatabase* isolateMovieDatabase(MovieDatabase *mdb, int(*comp)(Movie*));
void           addMovie(MovieDatabase* mdb, Movie* movie);
Movie*         getMovie(MovieDatabase* mdb, int index);

#endif
