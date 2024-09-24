#pragma once
#include <iostream>
#include <string>

using namespace std;

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
        Movie(string imdb_id, string title, int year, string genre, float rating, string director);

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