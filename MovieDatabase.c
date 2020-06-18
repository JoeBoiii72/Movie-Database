#include "MovieDatabase.h"
#include "Movie.h"

MovieDatabase* createMovieDatabase()
{
    MovieDatabase* mdb = (MovieDatabase*)malloc(sizeof(MovieDatabase));
    mdb->head = (MovieNode*)malloc(sizeof(MovieNode));
    mdb->size = 0;
    return mdb;
}

static void freeNode(MovieNode* n)
{
    freeMovie(n->movie);
    free(n);
}

void freeMovieDataBase(MovieDatabase* mdb)
{
    MovieNode* p = mdb->head;

    while(p->next)
    {
        MovieNode* next = p->next;
        freeNode(p);
        p = next;
    }

    printf("Movie Database deleted\n", mdb->size);
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

    printf("--------\n");
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


static int compareFunction(MovieNode* p1, MovieNode* p2)
{
    if(p1->movie->year > p2->movie->year)
        return 1;
    return 0;
}

static void swapNodes(MovieNode* p1, MovieNode* p2) 
{ 
    Movie* movie = p1->movie;
    p1->movie = p2->movie; 
    p2->movie = movie;
} 

void sortMovieDatabase(MovieDatabase *mdb)
{ 
    MovieNode* curr = mdb->head;
    MovieNode* next;

    while(curr->next)
    {
        MovieNode* next = curr->next;

        while(next->next)
        {
            if (compareFunction(curr, next) > 0)
            {
                swapNodes(next, curr);
            }
            next = next->next;
        }
        curr = curr->next;
    }
}
