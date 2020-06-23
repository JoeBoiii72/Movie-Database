/*  
=======================================
$File: MovieDatabase.c $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#define PRINTLINE() printf("file: %s, line: %d\n",__FILE__, __LINE__ )

#include "MovieDatabase.h"
#include "Movie.h"
#include <stdio.h>
#include <string.h>

#define TRUE  !0
#define FALSE !TRUE

// constructor
MovieDatabase
create_movie_database()
{
    MovieDatabase mdb;
    mdb.size = 0;
    mdb.list = create_list();

    mdb.add           = &mdb_add;
    mdb.copy          = &mdb_copy;
    mdb.addFromFile   = &mdb_addFromFile;
    mdb.get           = &mdb_get;
    mdb.remove        = &mdb_remove;
    mdb.free          = &mdb_free;
    mdb.sort          = &mdb_sort;
    mdb.print         = &mdb_print;
    mdb.getSize       = &mdb_getSize;
    return mdb;
}

// copy constructor
MovieDatabase
mdb_copy(MovieDatabase* mdb)
{
    MovieDatabase copy_mdb = create_movie_database();
    node_t* cur_node = mdb->list.getHead(&(mdb->list));

    while(cur_node)
    {
        copy_mdb.add(&copy_mdb, createMovieCopy((Movie*)cur_node->data));
        cur_node = cur_node->next;
    }
    return copy_mdb;
}

void
mdb_add(MovieDatabase* mdb, Movie* movie)
{    
    mdb->list.push(&(mdb->list), (void*)movie);
    mdb->size++;
}

void
mdb_free(MovieDatabase* mdb)
{
    mdb->list.free(&(mdb->list));
}

void
mdb_addFromFile(MovieDatabase* mdb, const char* fileName)
{
	FILE* f;
    
    f = fopen(fileName, "r");

    if (f == NULL)
        exit(1);

    // buffer to store each line
	char* line = malloc(sizeof(char) * 120);

	// intialbuffer size
    size_t ibSize;

    // size of line read
    size_t length;

	while ((length = getline(&line, &ibSize, f)) != -1)
    {           
        char* token = strtok(line, "\"");
        char* title = token;

        token = strtok(NULL, ",");
        int year = atoi(token);

        token = strtok(NULL, ",");
        char* cert = token;

        token = strtok(NULL, ",");
        char* genre = token;

        token = strtok(NULL, ",");
        int duration = atoi(token);

        token = strtok(NULL, ",");
        float rating = atoi(token);
        
        // add movie
        mdb->add(mdb, createMovie(title, year, genre, rating, duration, cert));
	}

    free(line);
	fclose(f);
}

void mdb_print(MovieDatabase* mdb)
{
    mdb->list.print(&(mdb->list), printMovie);
}

static int
defaultCompare(void* p1, void* p2)
{
    Movie* m1 = (Movie*)p1;
    Movie* m2 = (Movie*)p2;
    return (getYear(p1) > getYear(p2));
}

void
mdb_sort(MovieDatabase* mdb, int(*comp)(void*, void*))
{
    if(!comp)
        mdb->list.sort(&(mdb->list), defaultCompare);
    else
        mdb->list.sort(&(mdb->list), comp);
}

Movie* mdb_get(MovieDatabase *mdb, int index)
{
    void* m = mdb->list.get(&(mdb->list), index);
    return (Movie*)m;
}

void mdb_remove(MovieDatabase *mdb, int(*comp)(void*))
{
    node_t* prev = NULL;
    node_t* curr = mdb->list.getHead(&(mdb->list));
    while (curr)
    {
        node_t* next = curr->next;
        if(comp(curr->data) == TRUE)
        {
            if(!prev)
                mdb->list.head = next;
            else
                prev->next = next;

            free(curr->data);
            free(curr);

            mdb->size--;
        }
        else
            prev = curr;
        curr = curr->next;
    }
}

size_t mdb_getSize(MovieDatabase* mdb)
{
    return mdb->size;
}