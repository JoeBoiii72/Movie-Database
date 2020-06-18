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

typedef struct MovieNode MovieNode;
typedef struct MovieDatabase MovieDatabase;

struct MovieDatabase
{
    MovieNode* head;
    int        size;
};

struct MovieNode
{
    MovieNode* next;
    Movie*     movie;
};

MovieDatabase* createMovieDatabase();
void           freeMovieDataBase(MovieDatabase* mdb);
void           printMovieDataBase(MovieDatabase* mdb);
void           sortMovieDatabase(MovieDatabase *mdb);
void           addMovie(MovieDatabase* mdb, Movie* movie);
Movie*         getMovie(MovieDatabase* mdb, int index);

#endif
