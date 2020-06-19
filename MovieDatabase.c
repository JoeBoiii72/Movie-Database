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
    mdb->list = create_list();
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
        int rating = atoi(token);

        Movie* movie = createMovie(title, year, genre, rating, duration, cert);
        addMovie(mdb, movie);
	}

	free(line);
	fclose(f);
}


void
freeMovieDatabase(MovieDatabase* mdb)
{
    free_list(mdb->list);
    free(mdb);
}

void
printMovieDatabase(MovieDatabase* mdb)
{
    LinkedList* list = mdb->list;
    Node* cur_node = *list;
    while(cur_node)
    {
        Movie* cur_movie = (Movie*)(cur_node)->data;
        printMovie(cur_movie);
        cur_node = cur_node->next;
    }
}

void
addMovie(MovieDatabase* mdb, Movie* movie)
{    
    add_data(mdb->list, (void*)movie);
}

//Movie*
//getMovie(MovieNode* mdb, int index)
//{
//}

MovieDatabase*
isolateMovieDatabase(MovieDatabase *mdb, int(*comp)(Movie*))
{
    MovieDatabase* new_mdb = createMovieDatabase();

    LinkedList* list = mdb->list;
    Node* cur_node = *list;

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
defaultCompare(Movie* p1, Movie* p2)
{
    return (p1->year > p2->year);
}

static void
swapNodes(Node* p1, Node* p2)
{ 
    Movie* movie = (Movie*)p1->data;
    p1->data = (Movie*)p2->data; 
    p2->data = movie;
}

void
sortMovieDatabase(MovieDatabase *mdb, int(*comp)(Movie*, Movie*))
{ 
    if(!comp)
        comp = defaultCompare;

    LinkedList* list = mdb->list;
    Node* curr = *list;

    while(curr->next)
    {
        Node* next = curr->next;

        while(next)
        {
            if (comp((Movie*)curr->data, (Movie*)next->data)!=0)
            {
                swapNodes(next, curr);
            }
            next = next->next;
        }
        curr = curr->next;
    }
}
