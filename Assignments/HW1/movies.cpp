#include "movies.h"
// assume that movies have variables imdb id, title , year, genre, rating, director
//use getters and setters with the actual variables being private
// assume that all variables will have one value (one director, one genre, etc)
using namespace std;

//getters
 string movies::Movie::getImdbId() //future implementation: imdb ids always seem to have nine characters: two letters and seven numbers. validate for this?
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

   //setters
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
    if (year >= 1800 && year <= 2050) //validation: a year for a movie must be between 1800 and 2050. The first film was made in the 1880s.
    {
      _year = year;
    }
    else 
    std::cerr << "Invalid Year: " << year << std::endl;
 }

void movies::Movie::setGenre(string genre)
{
   _genre = genre;
}

void movies::Movie::setRating(float rating)
 {
    if (rating >= 0.0f && rating <= 10.0f) //validation: A rating on 10.0 scale cannot be above or below 0-10
    {
      _rating = rating;
    }
    else 
    std::cerr << "Invalid Rating: " << rating << std::endl;
 }

void movies::Movie::setDirector(string Director)
{
   _director = Director;
}
