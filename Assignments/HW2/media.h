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

        virtual ~Media() {}

        string getId();
        void setId(string);

        string getTitle();
        void setTitle(string);

        int getYear();
        void setYear(int);
    };

}
