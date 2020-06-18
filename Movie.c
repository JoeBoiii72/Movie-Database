#include "Movie.h"


Movie* createMovie(char* title, int year, char* genre, float rating)
{
    Movie* movie = malloc(sizeof(movie)); 
    movie->year = year;
    movie->title = (char*)malloc((strlen(title)*sizeof(char))+1);
    movie->genre = (char*)malloc((strlen(title)*sizeof(char))+1);
    strcpy(movie->title, title);
    strcpy(movie->genre, genre);
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