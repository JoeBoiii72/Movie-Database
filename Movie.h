#ifndef __MOVIE_H__
#define __MOVIE_H__

typedef const char* String;
typedef struct Movie Movie;

struct Movie
{
    String title;
    int year;
    String genre;
    float rating;
};

Movie createMovie(String title, int year, String genre, float rating);
String getTitle(Movie* movie);
int getYear(Movie* movie);
String getGenre(Movie* movie);
float getRating(Movie* movie);
void printMovie(Movie* movie);

#endif