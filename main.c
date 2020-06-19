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

int if_film_noir(Movie* movie)
{
    return strstr(getGenre(movie), "Film-Noir");
}

int if_R_rated(Movie* movie)
{    
    return !(strcmp(getCertificate(movie), "R"));
}

int sortByDuration(void* p1, void* p2)
{
    Movie* m1 = (Movie*)p1;
    Movie* m2 = (Movie*)p2;
    return (getDuration(m1) < getDuration(m2));
}

int sortByTitleLength(void* p1, void* p2)
{
    Movie* m1 = (Movie*)p1;
    Movie* m2 = (Movie*)p2;
    return (strlen(getTitle(m1)) > strlen(getTitle(m2)));
}

/*
Sort the movies in chronological order and display on the console.
*/
void task1(MovieDatabase* mdb)
{
    sortMovieDatabase(mdb, NULL);
    printMovieDatabase(mdb);
    printf("\n");
}

/*
Display the third longest Film-Noir
*/
void task2(MovieDatabase* mdb)
{
    MovieDatabase* new_mdb = isolateMovieDatabase(mdb, if_film_noir);
    sortMovieDatabase(new_mdb, sortByDuration);
    printMovie(getMovieByIndex(new_mdb, 2));
    printf("\n");
}

/*
Find the film with the shortest title.
*/
void task3(MovieDatabase* mdb)
{
    sortMovieDatabase(mdb, sortByTitleLength);
    printMovie(getMovieByIndex(mdb, 0));
    printf("\n");
}

/*
After deleting all R rated films from the database, display the number of
films left in the database
*/
void task4(MovieDatabase* mdb)
{
    printf("Movies left BEFORE deletion -> %d\n", mdb->size);
    removeMovies(mdb, if_R_rated);
    printf("Movies left AFTER deletion -> %d\n", mdb->size);
    printf("\n");
}

int main()
{    
    MovieDatabase* mdb = createMovieDatabase();

    addMoviesFromFile(mdb, "films.txt");

    task1(mdb);
    task2(mdb);
    task3(mdb);
    task4(mdb);

    freeMovieDatabase(mdb);

    return 0;
}