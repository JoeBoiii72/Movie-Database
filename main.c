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

int randInt(int lower, int upper) 
{ 
    return (rand() % (upper - lower + 1)) + lower;
} 

void testAdd(MovieDatabase* mdb, int movies)
{
    srand(time(0));
    for(int i = 0; i < movies; i++)
    {
        Movie* m1 = createMovie("hello", randInt(1990, 2020) , "PORN", 5.0);
        addMovie(mdb, m1); 
    }
}

int only_2000_or_larger(Movie* movie)
{
    return (getYear(movie) > 2000);
}

int main()
{
    MovieDatabase* mdb = createMovieDatabase();

    testAdd(mdb, 10);

    sortMovieDatabase(mdb);

    MovieDatabase* new_mdb = isolateMovieDatabase(mdb, only_2000_or_larger);

    freeMovieDataBase(mdb);

    printMovieDataBase(new_mdb);

    freeMovieDataBase(new_mdb);

    return 0;
}