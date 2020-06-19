/*  
=======================================
$File: main.c $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#include "Movie.h"
#include "MovieDatabase.h"

int only_film_noir(Movie* movie)
{
    return strstr(getGenre(movie), "Film-Noir");
}

int sortByDuration(Movie* movie1, Movie* movie2)
{
    return (getDuration(movie1) < getDuration(movie2));
}

int sortByTitleLength(Movie* movie1, Movie* movie2)
{
    return (strlen(getTitle(movie1)) > strlen(getTitle(movie2)));
}

/*
Sort the movies in chronological order and display on the console.
*/
void task1()
{
}

/*
Display the third longest Film-Noir
*/
void task2()
{
}

/*
Find the film with the shortest title.
*/
void task3()
{
}

/*
After deleting all R rated films from the database, display the number of
films left in the database
*/
void task4()
{
}

int main()
{
    MovieDatabase* mdb = createMovieDatabase();

    addMoviesFromFile(mdb, "films.txt");

    MovieDatabase* new_mdb = isolateMovieDatabase(mdb, only_film_noir);

    printMovieDatabase(new_mdb);

    sortMovieDatabase(new_mdb, NULL);

    printf("------------------\n");

    printMovieDatabase(new_mdb);

    freeMovieDatabase(mdb);

    freeMovieDatabase(new_mdb);

    return 0;
}