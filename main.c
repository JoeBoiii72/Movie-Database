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

int if_not_film_noir(void* p)
{
    Movie* m = (Movie*)p;
    return !strstr(m->genre, "Film-Noir");
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
    mdb->sort(mdb, NULL);
    mdb->print(mdb);
    printf("\n");
}

/*
Display the third longest Film-Noir
*/
void task2(MovieDatabase* mdb)
{
    
    MovieDatabase new_mdb = mdb->copy(mdb);
    new_mdb.remove(&new_mdb, if_not_film_noir);
    new_mdb.sort(&new_mdb, sortByDuration);
    printMovie(new_mdb.get(&new_mdb, 2));
    new_mdb.free(&new_mdb);
    printf("\n");
}

/*
Find the film with the shortest title.
*/
void task3(MovieDatabase* mdb)
{
    mdb->sort(mdb, sortByTitleLength);
    printMovie(mdb->get(mdb, 0));
    printf("\n");
}

/*
After deleting all R rated films from the database, display the number of
films left in the database
*/
void task4(MovieDatabase* mdb)
{
    printf("Movies left BEFORE deletion -> %d\n", mdb->size);
    mdb->remove(mdb, if_R_rated);
    printf("Movies left AFTER deletion -> %d\n", mdb->size);
    printf("\n");
}

int main()
{    
    MovieDatabase mdb = create_movie_database();

    mdb.add_from_file(&mdb, "films.txt");

    task1(&mdb);
    task2(&mdb);
    task3(&mdb);
    task4(&mdb);

    mdb.free(&mdb);

    return 0;
}