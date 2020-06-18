#ifndef __MOVIE_H__
#define __MOVIE_H__

typedef struct Movie Movie;

struct Movie
{
    char* title;  
    int year;
    char* genre;
    float rating;
};

Movie* createMovie(char* title, int year, char* genre, float rating);
void   freeMovie(Movie* movie);
char*  getTitle(Movie* movie);
int    getYear(Movie* movie);
char*  getGenre(Movie* movie);
float  getRating(Movie* movie);
void   printMovie(Movie* movie);

#endif