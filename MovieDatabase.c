/*  
=======================================
$File: MovieDatabase.c $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#include "MovieDatabase.h"
#include "Movie.h"
#include <stdio.h>
#include <string.h>

MovieDatabase*
createMovieDatabase()
{
    MovieDatabase* mdb = (MovieDatabase*)malloc(sizeof(MovieDatabase));
    mdb->head = (MovieNode*)malloc(sizeof(MovieNode));
    mdb->size = 0;
    return mdb;
}



void addMoviesFromFile(MovieDatabase* mdb, const char* fileName)
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

        addMovie(mdb, createMovie(title, year, genre, rating));
	}

	free(line);
	fclose(f);
}


static void
freeNode(MovieNode* n)
{
    freeMovie(n->movie);
    free(n);
}

void
freeMovieDataBase(MovieDatabase* mdb)
{
    MovieNode* p = mdb->head;

    while(p->next)
    {
        MovieNode* next = p->next;
        freeNode(p);
        p = next;
    }
    free(mdb);

    printf("Movie Database deleted\n", mdb->size);
}

void
printMovieDataBase(MovieDatabase* mdb)
{
    MovieNode* p = mdb->head;

    printf("--- Movie Database size: %d ---\n", mdb->size);

    while(p->next)
    {
        printMovie(p->movie);
        p = p->next;
    }

    printf("--------\n");
}

void
addMovie(MovieDatabase* mdb, Movie* movie)
{
    MovieNode* n = (MovieNode*)malloc(sizeof(MovieNode));
    n->next  = mdb->head;
    n->movie = movie;
    mdb->head = n;
    mdb->size++;
}

Movie*
getMovie(MovieDatabase* mdb, int index)
{
    if(index >= mdb->size)
        return 0;

    MovieNode* p = mdb->head;

    int cur_index = 0;
    while(p && cur_index != index)
    {
        cur_index++;
        p = p->next;
    }

    return p->movie;
}

MovieDatabase*
isolateMovieDatabase(MovieDatabase *mdb, int(*comp)(Movie*))
{
    MovieDatabase* new_mdb = createMovieDatabase();

    MovieNode* p = mdb->head;
    while(p->next)
    {
        if(comp(p->movie) != 0)
        {
            // so new_mdb doesnt rely on old one
            Movie* new_movie = createMovieCopy(p->movie);
            addMovie(new_mdb, new_movie);
        }
        p = p->next;
    }
    return new_mdb;
}


static int
compareFunction(MovieNode* p1, MovieNode* p2)
{
    return(p1->movie->year > p2->movie->year);
}

static void
swapNodes(MovieNode* p1, MovieNode* p2) 
{ 
    Movie* movie = p1->movie;
    p1->movie = p2->movie; 
    p2->movie = movie;
} 

void
sortMovieDatabase(MovieDatabase *mdb)
{ 
    MovieNode* curr = mdb->head;
    MovieNode* next;

    while(curr->next)
    {
        MovieNode* next = curr->next;

        while(next->next)
        {
            if (compareFunction(curr, next)!=0)
            {
                swapNodes(next, curr);
            }
            next = next->next;
        }
        curr = curr->next;
    }
}
