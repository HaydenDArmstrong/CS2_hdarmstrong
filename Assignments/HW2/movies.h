#pragma once
#include <iostream>
#include <string>
#include "media.h"

namespace movies
{
    class Movie : public media::Media
    {
    private:
        // std::string _imdbId;
        // std::string _title;
        // int _year;
        std::string _movGenre;
        float _movRating;
        std::string _movDirector;

    public:
        Movie(std::string mediaID, std::string mediaTitle, int mediaYear, std::string movGenre, float movRating, std::string movDirector);

        std::string displayInfo() const override {
        return "Movie Info: Title, Genre, Year";
    }
    
        std::string getGenre();
        void setGenre(std::string);

        float getRating();
        void setRating(float);

        std::string getDirector();
        void setDirector(std::string);
    };
}