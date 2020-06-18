#include "Movie.h"
#include "MovieDatabase.h"

void testAdd(MovieDatabase* mdb)
{
    Movie* m1 = createMovie("hello", 1999, "PORN", 5.0);
    Movie* m2 = createMovie("rwerg", 2001, "STUF", 1.0);
    Movie* m3 = createMovie("heerg", 1111, "ANOT", 5.0);
    Movie* m4 = createMovie("poopo", 4000, "EJEE", 6.0);

    addMovie(mdb, m1); 
    addMovie(mdb, m2);
    addMovie(mdb, m3);
    addMovie(mdb, m4);
}

int main()
{
    MovieDatabase* mdb = createMovieDatabase();

    testAdd(mdb);

    printMovieDataBase(mdb);

    Movie* m = getMovie(mdb, 3);

    printMovie(m);

    freeMovieDataBase(mdb);

    return 0;
}