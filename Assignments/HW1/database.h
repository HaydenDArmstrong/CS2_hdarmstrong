#pragma once
#include <iostream>
#include <string>
#include "movies.h" // now database.h accesses movies header. 
                    //main.cpp does not need to know movies.h

using namespace std;

namespace databaseset
{
    class Database
    {
        private:
            string _db_name;
            movieset::Movie _movies[100];

        public:
            void printMovies();

    };
}