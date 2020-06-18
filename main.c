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

int only_2010_or_larger(Movie* movie)
{
    return (getYear(movie) >= 2010);
}

int main()
{

    MovieDatabase* mdb = createMovieDatabase();

    addMoviesFromFile(mdb, "films.txt");

    sortMovieDatabase(mdb);

    MovieDatabase* new_mdb = isolateMovieDatabase(mdb, only_2010_or_larger);

    freeMovieDataBase(mdb);

    printMovieDataBase(new_mdb);

    freeMovieDataBase(new_mdb);

    return 0;
}