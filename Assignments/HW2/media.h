#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace media
{
    class Media
    {
    private:
        string _mediaId;
        string _mediaTitle;
        int _mediaYear;
        string _mediaGenre;
        // float _rating;
        // string _director;

    public:
        Media(string mediaId, string mediaTitle, int mediaYear);

    
        string getId();
        void setId(string);

        string getTitle();
        void setTitle(string);

        int getYear();
        void setYear(int);

        // string getGenre();
        // void setGenre(string);

        virtual string printInfo();

        // float getRating();
        // void setRating(float);

        // string getDirector();
        // void setDirector(string);

//         virtual string media::Media::printinfo()
// {
//             cout << "ID: " << mediaId << ", Title: " << mediaTitle << "Year: " << mediaYear << " Genre : ";
//     }
    };
}