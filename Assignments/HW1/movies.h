#pragma once
#include <iostream>
#include <string>
// assume that movies have variables imdb id, title , year, genre, rating, director
//use getters and setters with the actual variables being private
// assume that all variables will have one value (one director, one genre, etc)
namespace movies
{
    class Movie
    {
        private:
         string _imdbId;
         string _title;
         int _year;
         string _genre;
         float _rating;
         string _director;

        public:
            string getImdbId();
            void setImdbId(string);

            string getTitle();
            void setTitle(string);

            int getYear();
            void setYear(int);

            string getGenre();
            void setGenre(string);

            float getRating();
            void setRating(float);

            string getDirector();
            void setDirector(string);
    };
}