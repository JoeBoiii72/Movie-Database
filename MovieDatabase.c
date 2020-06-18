#include "MovieDatabase.h"
#include "Movie.h"

MovieDatabase* createMovieDatabase()
{
    MovieDatabase* mdb = (MovieDatabase*)malloc(sizeof(MovieDatabase));
    mdb->head = (MovieNode*)malloc(sizeof(MovieNode));
    mdb->size = 0;
    return mdb;
}

void freeNode(MovieNode* n)
{
    if(n)
    {
        free(n->movie);
        free(n);
    }
}

void freeMovieDataBase(MovieDatabase* mdb)
{
    MovieNode* p = mdb->head;

    while(p->next)
    {
        MovieNode* n = p->next;

        freeNode(p);

        p = n;
    }
}

void printMovieDataBase(MovieDatabase* mdb)
{
    MovieNode* p = mdb->head;

    printf("--- Movie Database size: %d ---\n", mdb->size);

    while(p->next)
    {
        printMovie(p->movie);
        p = p->next;
    }

    printf("---  ---\n");
}

void addMovie(MovieDatabase* mdb, Movie* movie)
{
    MovieNode* n = (MovieNode*)malloc(sizeof(MovieNode));
    n->next  = mdb->head;
    n->movie = movie;
    mdb->head = n;
    mdb->size++;
}

Movie* getMovie(MovieDatabase* mdb, int index)
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