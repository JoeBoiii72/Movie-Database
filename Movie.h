/*  
=======================================
$File: Movie.h $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#ifndef __MOVIE_H__
#define __MOVIE_H__

typedef struct Movie Movie;

struct Movie
{
    int   year;
    float rating; 
    int   duration;
    char  genre[120];
    char  title[120];
    char  certi[120];
};

Movie* createMovie(char* title, int year, char* genre, float rating, int duration, char* certi);
Movie* createMovieCopy(Movie* srcMovie);
void   freeMovie(Movie* movie);
char*  getTitle(Movie* movie);
int    getYear(Movie* movie);
char*  getGenre(Movie* movie);
char*  getCertificate(Movie* movie);
int    getDuration(Movie* movie);
float  getRating(Movie* movie);
void   printMovie(Movie* movie);

#endif