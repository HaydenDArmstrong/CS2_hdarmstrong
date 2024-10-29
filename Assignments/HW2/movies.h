#pragma once
#include <iostream>
#include <string>
#include "media.h"

namespace movies
{
    class Movie : public media::Media
    {
    private:
        std::string _movGenre;
        float _movRating;
        std::string _movDirector;

    public:
        Movie(std::string mediaId, std::string mediaTitle, int mediaYear, std::string movGenre, float movRating, std::string movDirector);

        std::string getGenre();
        void setGenre(std::string);

        float getRating();
        void setRating(float);

        std::string getDirector();
        void setDirector(std::string);

        // string printDetails();
        // virtual void getDetails(Movie);

        void printDetails() const override
        {
            Media::printDetails();
            std::cout << ", Genre: " << _movGenre << ", Rating: " << _movRating
                      << ", Director: " << _movDirector << std::endl;
        }
        
    };
}