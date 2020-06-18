/*  
=======================================
$File: Movie.c $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#include "Movie.h"

// constructor
Movie* 
createMovie(char* title, int year, char* genre, float rating)
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

// copy constructor
Movie* 
createMovieCopy(Movie* srcMovie)
{
    Movie* movie = malloc(sizeof(movie));

    movie->title = malloc(sizeof(char) * (strlen(srcMovie->title)+1));
    movie->genre = malloc(sizeof(char) * (strlen(srcMovie->genre)+1));

    strcpy(movie->title, srcMovie->title);
    strcpy(movie->genre, srcMovie->genre);

    movie->year = srcMovie->year;
    movie->rating = srcMovie->rating;
    return movie;
}

// getters, for abstraction
char* getTitle (Movie* movie){return movie->title; }
int   getYear  (Movie* movie){return movie->year;  }
char* getGenre (Movie* movie){return movie->genre; }
float getRating(Movie* movie){return movie->rating;}

// free the memory we allocated for the movie
void freeMovie(Movie* movie)
{
    free(movie->title);
    free(movie->genre);
    free(movie);
}

// print like we see in films.txt
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