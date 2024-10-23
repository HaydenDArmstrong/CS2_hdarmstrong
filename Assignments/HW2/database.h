#pragma once
#include "movies.h"  // Movie class
#include "music.h"   // Music class
#include "tvshows.h" // TVShows class

using namespace std;

/*
The database should have the following functionality:
Add or remove specified media given an ID. 
Display all media of a given type (using displayInfo),
 search for media given title, genre, etc and print out a nicely formatted table
For this assignment, your database can create an array of 100 movies (ie movies::Movies* movieList[100];), 100 tvshows and 100 music and assume that there will never be more than 100 of each of those tracked at one time.
*/

namespace db
{
    class Database
    {
    private:
        string _db_name;
        int _db_id;
        movies::Movie* _movieList[100];  
        music::Music* _musicList[100];  
        tvshow::Tvshow* _tvList[100];   
        int movieCount = 0;
        int musicCount = 0;
        int tvCount = 0;


    public:
        // constructor
        Database(string db_name, int db_id);

        // destructor
        ~Database();

        template<typename MediaType>
        void readMediaFromFile(std::string filename);

        template<typename MediaType>
        void writeMediaToFile(std::string filename, MediaType* mediaList[], int mediaCount, std::string (*getMediaInfoFunc)(MediaType*));
        // methods
        template<typename T1>
        void addMedia(T1* newMedia, T1* mediaList[], int& mediaCount);

        void addMovie(movies::Movie *newMovie);
        void addMusic(music::Music *newMusic);
        void addTvShow(tvshow::Tvshow *newTvShow);

    
        template<typename T1>
        void removeMedia(std::string& mediaId, T1* mediaList[], int& mediaCount); //applicable for all media types

        void removeMovie(string &mediaId);
        void removeMusic(string &mediaId);
        void removeTvshow(string &mediaId);

        void displayMovie();
        void displayMusic();
        void displayTvShow();

    

        template<typename T1>
        void searchMediaTitle(std::string& mediaTitle, T1* mediaList[], int mediaCount);
        void searchMovie(string& mediaTitle);
        void searchTvshow(string& mediaTitle);
        void searchMusic(string& mediaTitle);


        void searchID(string &mediaId);

        template<typename T1>
        void searchMediaGenre(std::string& genre, T1* mediaList[], int mediaCount);

    
        void readInMovie(std::string filename);
        void readInTVShow(std::string filename);
        void readInMusic(std::string filename);
    };
}
