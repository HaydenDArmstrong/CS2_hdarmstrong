#include "movies.h"
using namespace std;

movies::Movie::Movie(string imdb_id, string title, int year, string genre, float rating, string director)
{
   _imdbId = imdb_id;
   _title = title;
   _year = year;
   _genre = genre;
   _rating = rating;
   _director = director;
}

// getters
string movies::Movie::getImdbId()
{
   return _imdbId;
}

string movies::Movie::getTitle()
{
   return _title;
}
int movies::Movie::getYear()
{
   return _year;
}
string movies::Movie::getGenre()
{
   return _genre;
}
float movies::Movie::getRating()
{
   return _rating;
}
string movies::Movie::getDirector()
{
   return _director;
}

// setters
void movies::Movie::setImdbId(string imdbId)
{
   _imdbId = imdbId;
}

void movies::Movie::setTitle(string title)
{
   _title = title;
}
void movies::Movie::setYear(int year)
{
   _year = year;
}

void movies::Movie::setGenre(string genre)
{
   _genre = genre;
}

void movies::Movie::setRating(float rating)
{
      _rating = rating;
}

void movies::Movie::setDirector(string Director)
{
   _director = Director;
}
