#include <iostream>
#include <string>
#include "database.h"

using namespace std;

int main()
{
    string file = "movies.csv"; //for read and write

    // Create an instance
    movies::Database myDatabase("Movie Database", 001);

    myDatabase.readInFile(file);

    int choice;
    string title, genre, imdb_id, director;
    int year;
    float rating;
    movies::Movie *newMovie = nullptr;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Movie" << endl;
        cout << "2. Remove Movie" << endl;
        cout << "3. Search by Title" << endl;
        cout << "4. Search by Genre" << endl;
        cout << "5. Display All Movies" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: // Add Movie
        {
            cout << "Enter IMDb ID: ";
            getline(cin, imdb_id);
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Genre: ";
            cin.ignore();
            getline(cin, genre);
            cout << "Enter Rating (0.0 - 10.0): ";
            cin >> rating;
            cin.ignore();
            cout << "Enter Director: ";
            getline(cin, director);

            newMovie = new movies::Movie(imdb_id, title, year, genre, rating, director);
            myDatabase.addMovie(newMovie);
            myDatabase.writeToFile(file);
        }
        break;

        case 2: // Remove Movie
            cout << "Enter IMDb ID to remove: ";
            getline(cin, imdb_id);
            myDatabase.deleteMovie(imdb_id);
            myDatabase.writeToFile(file);
            break;

        case 3: // Search by Title
            cout << "Enter Title to search: ";
            getline(cin, title);
            myDatabase.searchTitle(title);
            break;

        case 4: // Search by Genre
            cout << "Enter Genre to search: ";
            getline(cin, genre);
            myDatabase.searchGenre(genre);
            break;

        case 5: // Display All Movies
            myDatabase.displayMovies();
            break;

        case 6: // Exit
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}