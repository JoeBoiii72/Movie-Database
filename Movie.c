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
#define PRINTLINE() printf("file: %s, line: %d\n",__FILE__, __LINE__ )


// constructor
Movie* 
createMovie(char* title, int year, char* genre, int rating, int duration, char* certi)
{    
    Movie* movie;
    movie = (Movie*)malloc(sizeof(Movie));

    strcpy(movie->title, title);
    strcpy(movie->genre, genre);
    strcpy(movie->certi, certi);

    movie->year = year;
    movie->duration = duration;
    movie->rating = rating;
    return movie;
}

// copy constructor
Movie* 
createMovieCopy(Movie* srcMovie)
{
    Movie* movie;
    movie = (Movie*)malloc(sizeof(Movie));

    strcpy(movie->title, srcMovie->title);
    strcpy(movie->genre, srcMovie->genre);
    strcpy(movie->certi, srcMovie->certi);

    movie->year = srcMovie->year;
    movie->duration = srcMovie->duration;
    movie->rating = srcMovie->rating;
    return movie;
}

// getters, for abstraction
char* getTitle       (Movie* movie){return movie->title;   }
int   getYear        (Movie* movie){return movie->year;    }
char* getGenre       (Movie* movie){return movie->genre;   }
float getRating      (Movie* movie){return movie->rating;  }
char* getCertificate (Movie* movie){return movie->certi;   }
int   getDuration    (Movie* movie){return movie->duration;}

// free the memory we allocated for the movie
void freeMovie(Movie* movie)
{
    free(movie);
}

// print like we see in films.txt
void printMovie(Movie* movie)
{
    if(movie)
    {
        printf("\"%s\","     , movie->title);
        printf("%d,"    , movie->year);
        printf("%s,"    , movie->certi);
        printf("%s,"    , movie->genre);
        printf("%d,"    , movie->duration);
        printf("%d\n"   , movie->rating);
    }
}