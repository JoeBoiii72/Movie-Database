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

typedef struct MovieDatabase MovieDatabase;

struct MovieDatabase
{
    size_t size;
    List   list;
    void          (*add )(MovieDatabase*, Movie*);
    void          (*add_from_file)(MovieDatabase*, const char*);
    Movie*        (*get)(MovieDatabase*, int);
    MovieDatabase (*copy)(MovieDatabase*);
    void          (*free)(MovieDatabase*);
    void          (*sort)(MovieDatabase*, int(*comp)(void*, void*));
    void          (*print)(MovieDatabase*);
    void          (*remove)(MovieDatabase*, int(*comp)(void*));
};



/*

*/
MovieDatabase create_movie_database();

/*

*/
void mdb_add_from_file(MovieDatabase* mdb, const char* fileName);

/*
*/
MovieDatabase mdb_copy(MovieDatabase* mdb);

/*

*/
void mdb_free(MovieDatabase* mdb);

/*

*/
void mdb_print(MovieDatabase* mdb);

/*

*/
void mdb_sort(MovieDatabase *mdb, int(*comp)(void*, void*));

/*

*/
void mdb_add(MovieDatabase* mdb, Movie* movie);

/*

*/
Movie* mdb_get(MovieDatabase* mdb, int index);

/*

*/
void mdb_remove(MovieDatabase* mdb, int(*comp)(void*));

#endif
