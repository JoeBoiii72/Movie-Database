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

int main()
{
    MovieDatabase* mdb = createMovieDatabase();

    testAdd(mdb, 10);

    sortMovieDatabase(mdb);

    printMovieDataBase(mdb);

    freeMovieDataBase(mdb);

    return 0;
}