#include "database.h"
#include "media.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void displayMenu()
{
    cout << "\nMedia Database Menu:\n"
         << "1. Load Media\n"
         << "2. Add Media\n"
         << "3. Search Media\n"
         << "4. Remove Media\n"
         << "5. Print All Media\n"
         << "6. Write Database to File\n"
         << "0. Exit\n"
         << "Select an option: ";
}

void loadMedia(db::Database &mediaDatabase)
{
    mediaDatabase.readInMovie("movies.csv");
    mediaDatabase.readInTVShow("tvshows.csv");
    mediaDatabase.readInMusic("music.csv");
    cout << "Media loaded successfully.";
}

void addMedia(db::Database &mediaDatabase)
{
    string mediaType;
    string mediaId, mediaTitle;
            cout << "What is your media Type? Ex: movie, tvshow, music" << endl;
            cin >> mediaType;
            cin.ignore();
            if (mediaType == "movie")
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
            if (mediaType == "tvshow")
            {
                string mediaId, mediaTitle;
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
            if (mediaType == "music")
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
}

void searchMedia(db::Database &mediaDatabase)
{
    string mediaType, mediaTitle;
    cout << "Enter media type (movie, tvshow, music): ";
    cin >> mediaType;
    cin.ignore();
    cout << "Enter the title: ";
    getline(cin, mediaTitle);

    if (mediaType == "movie")
    {
        mediaDatabase.searchMovie(mediaTitle);
    }
    else if (mediaType == "tvshow")
    {
        mediaDatabase.searchTvshow(mediaTitle);
    }
    else if (mediaType == "music")
    {
        mediaDatabase.searchMusic(mediaTitle);
    }
}

void removeMedia(db::Database &mediaDatabase)
{
    string mediaType, mediaId;
    cout << "Enter media type (movie, tvshow, music): ";
    cin >> mediaType;
    cin.ignore();
    cout << "Enter Media ID to remove: ";
    getline(cin, mediaId);

    if (mediaType == "movie")
    {
        mediaDatabase.removeMovie(mediaId);
        mediaDatabase.writeMediaToFile("movies.csv", "movie");
    }
    else if (mediaType == "tvshow")
    {
        mediaDatabase.removeTvshow(mediaId);
        mediaDatabase.writeMediaToFile("tvshows.csv", "tvshow");
    }
    else if (mediaType == "music")
    {
        mediaDatabase.removeMusic(mediaId);
        mediaDatabase.writeMediaToFile("music.csv", "music");
    }
    cout << mediaType << " removed successfully.\n";
}

int main()
{
    db::Database mediaDatabase("MyMediaDB", 1);
    int choice;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            loadMedia(mediaDatabase);
            break;
        }
        case 2:
        {
            addMedia(mediaDatabase);
            break;
        }
        case 3:
        {
            searchMedia(mediaDatabase);
            break;
        }
        case 4:
        {
            removeMedia(mediaDatabase);
            break;
        }
        case 5:
        {
            mediaDatabase.displayAllMedia();
            break;
        }
        case 6:
        {
            cout << "Database written to file.\n";
            mediaDatabase.writeAllMediaToFile("output.csv");
            break;
        } // implement
        case 0:
        {
            cout << "Deallocating media..." << endl;
            mediaDatabase.~Database();
            cout << "Exiting program.\n";
            break;
        }
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}