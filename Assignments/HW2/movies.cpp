#include "movies.h"
using namespace std;

movies::Movie::Movie(string mediaId, string mediaTitle, int mediaYear, string movGenre, float movRating, string movDirector)
                  : media::Media(mediaId, mediaTitle, mediaYear)
{
   _movGenre = movGenre;
   _movRating = movRating;
   _movDirector = movDirector;
}


string movies::Movie::getGenre()
{
   return _movGenre;
}
float movies::Movie::getRating()
{
   return _movRating;
}
string movies::Movie::getDirector()
{
   return _movDirector;
}


void movies::Movie::setGenre(string movGenre)
{
   _movGenre = movGenre;
}

void movies::Movie::setRating(float movRating)
{
      _movRating = movRating;
}

void movies::Movie::setDirector(string movDirector)
{
   _movDirector = movDirector;
}
