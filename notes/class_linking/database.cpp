#include "database.h"

using namespace std;


void databaseset::Database::printMovies()
{
    for(int i = 0; i < 1; i++)
    {
        cout << _movies[i].getId() << endl;
    }
}