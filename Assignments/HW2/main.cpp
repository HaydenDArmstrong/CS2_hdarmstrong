#include "database.h"
#include "media.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void displayMenu()
{
    cout << "Media Database Menu:" << endl;
    cout << "1. Load Media" << endl;
    cout << "2. Add Media" << endl;
    cout << "3. Search Media" << endl;
    cout << "4. Remove Media" << endl;
    cout << "5. Print All Media" << endl;
    cout << "6. Write Database to File" << endl;
    cout << "0. Exit" << endl;
    cout << "Select an option: ";
}

int main()
{
    db::Database mediaDatabase("MyMediaDB", 1);
    int choice;
    string mediaId, mediaTitle;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            // read in of each media
            mediaDatabase.readInMovie("movies.csv");
            mediaDatabase.readInTVShow("tvshows.csv");
            mediaDatabase.readInMusic("music.csv");
            break;
        }
        case 2:
        {
            string givenmedia;
            cout << "What is your media Type? Ex: movie, tvshow, music" << endl;
            cin >> givenmedia;
            cin.ignore();
            if (givenmedia == "movie")
            {
                cout << "Enter Movie ID, Title, Year, Genre, Rating, Director (comma-separated): ";
                getline(cin, mediaId, ',');
                getline(cin, mediaTitle, ',');
                int year;
                cin >> year;
                cin.ignore();
                string genre, director;
                getline(cin, genre, ',');
                float rating;
                cin >> rating;
                cin.ignore();
                getline(cin, director);

                movies::Movie *newMovie = new movies::Movie(mediaId, mediaTitle, year, genre, rating, director);
                mediaDatabase.addMovie(newMovie);
                mediaDatabase.writeMediaToFile("movies.csv", "movie");
            }
            if (givenmedia == "tvshow")
            {
                cout << "Enter TV Show ID, Title, Year, Genre, Rating, Episodes (comma-separated): ";
                getline(cin, mediaId, ',');
                getline(cin, mediaTitle, ',');
                int year, episodes;
                cin >> year;
                cin.ignore();
                string genre;
                getline(cin, genre, ',');
                float rating;
                cin >> rating;
                cin.ignore();
                cin >> episodes;

                tvshow::Tvshow *newTvShow = new tvshow::Tvshow(mediaId, mediaTitle, year, genre, rating, episodes);
                mediaDatabase.addTvShow(newTvShow);
                mediaDatabase.writeMediaToFile("tvshows.csv", "tvshow");
            }
            if (givenmedia == "music")
            {
                cout << "Enter Music ID, Title, Year, Composer, Genre, Tracks, Playtime (comma-separated): ";
                getline(cin, mediaId, ',');
                getline(cin, mediaTitle, ',');
                int year, tracks, playtime;
                cin >> year;
                cin.ignore();
                string composer, genre;
                getline(cin, composer, ',');
                getline(cin, genre, ',');
                cin >> tracks;
                cin.ignore();
                cin >> playtime;

                music::Music *newMusic = new music::Music(mediaId, mediaTitle, year, composer, genre, tracks, playtime);
                mediaDatabase.addMusic(newMusic);
                mediaDatabase.writeMediaToFile("music.csv", "music");
            }
            break;
        }
        case 3:
        {
            string givenmedia;
            cout << "What is your media Type? Ex: movie, tvshow, music" << endl;
            cin >> givenmedia;
            cin.ignore();
            if (givenmedia == "movie")
            {
                cout << "What is the title of media?" << endl;
                getline(cin, mediaTitle);
                mediaDatabase.searchMovie(mediaTitle);
            }
            if (givenmedia == "tvshow")
            {
                cout << "What is the title of media?" << endl;
                getline(cin, mediaTitle);
                mediaDatabase.searchTvshow(mediaTitle);
            }
            if (givenmedia == "music")
            {
                cout << "What is the title of media?" << endl;
                getline(cin, mediaTitle);
                mediaDatabase.searchMusic(mediaTitle);
            }
            break;
        }
        case 4:
        {
            string givenmedia;
            cout << "What is your media Type? Ex: movie, tvshow, music" << endl;
            cin >> givenmedia;
            cin.ignore();
            if (givenmedia == "movie")
            {
                cout << "Enter Movie ID to remove: ";
                getline(cin, mediaId);
                mediaDatabase.removeMovie(mediaId);
                mediaDatabase.writeMediaToFile("movies.csv", "movie");
            }
            if (givenmedia == "tvshow")
            {
                cout << "Enter Tv Show ID to remove: ";
                getline(cin, mediaId);
                mediaDatabase.removeTvshow(mediaId);
                mediaDatabase.writeMediaToFile("tvshows.csv", "tvshow");
            }
            if (givenmedia == "music")
            {
                cout << "Enter Media ID to remove: ";
                getline(cin, mediaId);
                mediaDatabase.removeMusic(mediaId);
                mediaDatabase.writeMediaToFile("music.csv", "music");
            }
            break;
        }
        case 5:
        {
            cout << "Movies:" << endl;
            mediaDatabase.readInMovie("movies.csv");
            cout << "TV Shows:" << endl;
            mediaDatabase.readInTVShow("tvshows.csv");
            cout << "Music:" << endl;
            mediaDatabase.readInMusic("music.csv");
            break;
        }
        case 6:
        {
            // write media to file
            break;
        }
        case 0:
        {
            cout << "Exiting program." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice, please try again." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
