#pragma once
#include "movies.h" // now database.h accesses movies header.
                    //main.cpp does not need to know movies.h
#include "media.h"

using namespace std;

namespace movies
{
    class Database
    {
    private:
        string _db_name;
        int _db_id;
        Movie *_movieList[100];
        int movieAmount = 0;
        void printMovieDetails(Movie *movie);

    public:
        // constructor
        Database(string db_name, int db_id);

        // destructor
        ~Database();

        // methods
        void addMovie(Movie *newMovie);
        void deleteMovie(string &imdb_id);
        void searchTitle(string &title);
        void searchGenre(string &genre);
        void displayMovies();

        // fileio
        void readInFile(string filename);
        void writeToFile(string filename);
    };
}