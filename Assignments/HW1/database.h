#pragma once
#include "movies.h" // now database.h accesses movies header. 
                    //main.cpp does not need to know movies.h
// should have the variables name, db id, array for movies as pointers.
// shgould be able to add remove, display, and search for movie given title or genre, AND print table of movies
//assume there will never be more thn 100 movies

using namespace std;

namespace movies
{
    class Database
    {
        private:
            string _db_name;
            int _db_id;
            movies::Movie _movieList[100];
            int movieAmount;
        public:
            //constructor
            Database(string _db_name, int _db_id);

            //destructor
            ~database();

            //methods
            void addMovie();
            void printMovies();

            //fileio
            void readInFile(string filename);
            void writeToFIle(string filename)


    };
}