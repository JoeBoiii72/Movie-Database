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

MovieDatabase*
createMovieDatabase()
{
    MovieDatabase* mdb = malloc(sizeof(MovieDatabase));
    mdb->head = create_list();
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

        Movie* movie = createMovie(title, year, genre, rating, duration, cert);
        addMovie(mdb, movie);
	}

    free(line);
	fclose(f);
}


void
freeMovieDatabase(MovieDatabase* mdb)
{
    free_list(&(mdb->head));
}

static void
printNode(node_t* node)
{
    printMovie((Movie*)node->data);
}

void
printMovieDatabase(MovieDatabase* mdb)
{
    for_each(&(mdb->head), printNode);
}

void
addMovie(MovieDatabase* mdb, Movie* movie)
{    
    mdb->size++;
    add_data(&(mdb->head), (void*)movie);
}

MovieDatabase*
isolateMovieDatabase(MovieDatabase *mdb, int(*comp)(Movie*))
{
    MovieDatabase* new_mdb = createMovieDatabase();
    node_t* cur_node = mdb->head;

    while(cur_node)
    {
        Movie* cur_movie = (Movie*)(cur_node)->data;
        if(comp(cur_movie) != 0)
        {
            // so new_mdb doesnt rely on old one
            Movie* new_movie = createMovieCopy(cur_movie);
            addMovie(new_mdb, new_movie);
        }
        cur_node = cur_node->next;
    }
    return new_mdb;
}


static int
defaultCompare(void* p1, void* p2)
{
    Movie* m1 = (Movie*)p1;
    Movie* m2 = (Movie*)p2;
    return (getYear(p1) > getYear(p2));
}

void
sortMovieDatabase(MovieDatabase *mdb, int(*comp)(void*, void*))
{ 
    if(!comp)
        comp = defaultCompare;

    sort_list(&(mdb->head), comp);
}

Movie* getMovieByIndex(MovieDatabase *mdb, int index)
{
    node_t* cur_node = mdb->head;
    int cur_index = 0;

    while(cur_node && cur_index++ != index)
        cur_node = cur_node->next;

    return (Movie*)(cur_node)->data;
}

void removeMovies(MovieDatabase *mdb, int(*comp)(Movie*))
{
    node_t* curr_node  = mdb->head;
    node_t* prev_node  = 0;
    while(curr_node)
    {
        Movie* cur_movie = (Movie*)(curr_node)->data;
        node_t* next_node = curr_node->next;
        if(comp(cur_movie) != 0)
        {
            free(curr_node->data);
            free(curr_node);
            if(prev_node)
                prev_node->next = next_node;
            else
                mdb->head = next_node;
            mdb->size--;
        }
        else
            prev_node = curr_node;
        curr_node = next_node;
    }
}
