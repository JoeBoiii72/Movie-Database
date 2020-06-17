#include "Movie.h"


Movie createMovie(String title, int year, String genre, float rating)
{
    Movie movie;
    movie.title = title;
    movie.year = year;
    movie.genre = genre;
    movie.rating = rating;
    return movie;
}

String getTitle(Movie* movie)
{
    return movie->title;
}

int getYear(Movie* movie)
{
    return movie->genre;
}

String getGenre(Movie* movie)
{
    return movie->genre;
}

float getRating(Movie* movie)
{
    return movie->rating;
}

void printMovie(Movie* movie)
{
    printf("%s,"  , movie->title);
    printf("%d,"  , movie->year);
    printf("%s,"  , movie->genre);
    printf("%f\n" , movie->rating);
}