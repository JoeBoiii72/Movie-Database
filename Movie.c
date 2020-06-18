#include "Movie.h"


Movie* createMovie(char* title, int year, char* genre, float rating)
{
    Movie* movie = malloc(sizeof(movie));

    movie->title = malloc(sizeof(char) * (strlen(title)+1));
    movie->genre = malloc(sizeof(char) * (strlen(genre)+1));

    strcpy(movie->title, title);
    strcpy(movie->genre, genre);

    movie->year = year;
    movie->rating = rating;
    return movie;
}

char* getTitle(Movie* movie)
{
    return movie->title;
}

int getYear(Movie* movie)
{
    return movie->genre;
}

char* getGenre(Movie* movie)
{
    return movie->genre;
}

float getRating(Movie* movie)
{
    return movie->rating;
}

void freeMovie(Movie* movie)
{
    free(movie->title);
    free(movie->genre);
    free(movie);
}

void printMovie(Movie* movie)
{
    if(movie)
    {
        printf("%s,"  , movie->title);
        printf("%d,"  , movie->year);
        printf("%s,"  , movie->genre);
        printf("%f\n" , movie->rating);
    }
}