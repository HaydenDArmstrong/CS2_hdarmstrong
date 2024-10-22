#include "database.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
movies::Database::Database(string db_name, int db_id)
{
    _db_name = db_name;
    _db_id = db_id;
    movieAmount = 0;
}

void movies::Database::readInFile(string filename)
{
    string line;

    ifstream fin;

    fin.open(filename);

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            istringstream iss(line);

            iss.str(line);

            string imdbID, title, genre, director;
            int year;
            float rating;

            getline(iss, imdbID, ',');
            getline(iss, title, ',');
            iss >> year;
            iss.ignore();
            getline(iss, genre, ',');
            iss >> rating;
            iss.ignore();
            getline(iss, director, ',');
            // cout << title; //sanity check

            Movie *newMovie = new Movie(imdbID, title, year, genre, rating, director);
            addMovie(newMovie);
        }
        fin.close();
    }
}

void movies::Database::writeToFile(string filename)
{
    ofstream fout(filename);

    if (!fout.is_open())
    {
        cout << "File: " << filename << " was not found to write into.";
    }

    for (int i = 0; i < movieAmount; ++i)
    {
        fout << _movieList[i]->getImdbId() << ","
             << _movieList[i]->getTitle() << ","
             << _movieList[i]->getYear() << ","
             << _movieList[i]->getGenre() << ","
             << _movieList[i]->getRating() << ","
             << _movieList[i]->getDirector()
             << endl; // DONT FORGET THIS END LINE
    }
}

void movies::Database::addMovie(Movie *newMovie)
{
    if (movieAmount >= 100)
    {
        cout << "Database is full. Cannot add more movies." << endl;
        return;
    }
    _movieList[movieAmount] = newMovie;
    ++movieAmount;

    // cout << " Movie added successfully, " << movieAmount << "/100" << endl;
}

void movies::Database::deleteMovie(string &imdb_id) // given imdbID, remove movie
{
    bool found = false;
    for (int i = 0; i < movieAmount; ++i)
    {
        if (_movieList[i]->getImdbId() == imdb_id) // if there is a matching id in db:
        {
            delete _movieList[i];
            found = true;
        }
        if (found && i < movieAmount - 1)
        {
            _movieList[i] = _movieList[i + 1]; // shift up by 1 to replace the removed movie, that way we don't leave a "gap"
        }
    }
    if (found)
    {
        _movieList[movieAmount - 1] = nullptr;
        --movieAmount; // decrease total number of movies by 1
        cout << "Movie with ID " << imdb_id << " deleted successfully." << endl;
    }
    else
    {
        cout << "Movie with ID " << imdb_id << " not found." << endl;
    }
}

void movies::Database::printMovieDetails(Movie *movie) // used in search title and genre
{
    cout << endl
         << "Movie Title: " << movie->getTitle() << endl
         << "Released in " << movie->getYear() << endl
         << "Directed by: " << movie->getDirector() << endl
         << "Genre: " << movie->getGenre() << endl
         << "IMDB ID: " << movie->getImdbId() << endl
         << "IMDB rating: " << movie->getRating() << "/10" << endl;
}

void movies::Database::searchTitle(string &title)
{
    bool found = false; // to check if any movie was found
    for (int i = 0; i < movieAmount; ++i)
    {
        if (_movieList[i]->getTitle() == title)
        {
            found = true;

            printMovieDetails(_movieList[i]);
        }
    }
    if (!found)
    {
        cout << "No movie found with the title: " << title << endl;
    }
}

void movies::Database::searchGenre(string &genre)
{
    bool found = false;
    for (int i = 0; i < movieAmount; ++i)
    {
        if (_movieList[i]->getGenre() == genre)
        {
            found = true;
            printMovieDetails(_movieList[i]);
        }
    }
    if (!found)
    {
        cout << "No movie found with genre: " << genre;
    }
}

void movies::Database::displayMovies() // table format
{
    if (movieAmount == 0)
    {
        cout << "No movies in the database." << endl;
        return;
    }
        cout << left << setw(40) << "Title"
         << setw(6) << "Year"
         << setw(20) << "Director"
         << setw(15) << "Genre"
         << setw(10) << "IMDB ID"
         << setw(10) << "Rating" << endl;

    cout << string(98, '-') << endl; // Print a separator line

    // Print each movie's details
    for (int i = 0; i < movieAmount; ++i)
    {
        cout << left << setw(40) << _movieList[i]->getTitle()
             << setw(6) << _movieList[i]->getYear()
             << setw(20) << _movieList[i]->getDirector()
             << setw(15) << _movieList[i]->getGenre()
             << setw(10) << _movieList[i]->getImdbId()
             << setw(10) << _movieList[i]->getRating() << endl;
    }
}

movies::Database::~Database()
{
    for (int i = 0; i < movieAmount; ++i)
    {
        delete _movieList[i];
    }
}
