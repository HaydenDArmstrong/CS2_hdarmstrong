#include "database.h" 
#include "media.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void displayMenu() {
    cout << "Media Database Menu:" << endl;
    cout << "1. Load Movies" << endl;
    cout << "2. Load TV Shows" << endl;
    cout << "3. Load Music" << endl;
    cout << "4. Add Movie" << endl;
    cout << "5. Add TV Show" << endl;
    cout << "6. Add Music" << endl;
    cout << "7. Remove Media" << endl;
    cout << "8. Print All Media" << endl;
    cout << "9. Write Database to File" << endl;
    cout << "0. Exit" << endl;
    cout << "Select an option: ";
}

// void printMedia(const db::Database& db) {
//     cout << "Movies:" << endl;
//     db.printMovies();
//     cout << "TV Shows:" << endl;
//     db.printTVShows();
//     cout << "Music:" << endl;
//     db.printMusic();
// }

int main() {
    db::Database mediaDatabase("MyMediaDB", 1);
    int choice;
    string mediaId, mediaTitle;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character after choice input

        switch (choice) {
            case 1: {
                mediaDatabase.readInMovie("movies.csv");
                break;
            }
            case 2: {
                mediaDatabase.readInTVShow("tvshows.csv");
                break;
            }
            case 3: {
                mediaDatabase.readInMusic("music.csv");
                break;
            }
            case 4: {
                // Example for adding a movie
                cout << "Enter Movie ID, Title, Year, Genre, Rating, Director (comma-separated): ";
                getline(cin, mediaId, ',');
                getline(cin, mediaTitle, ',');
                int year;
                cin >> year;
                cin.ignore(); // Ignore comma
                string genre, director;
                getline(cin, genre, ',');
                float rating;
                cin >> rating;
                cin.ignore(); // Ignore comma
                getline(cin, director);
                
                movies::Movie* newMovie = new movies::Movie(mediaId, mediaTitle, year, genre, rating, director);
                mediaDatabase.addMovie(newMovie);
                break;
            }
            case 5: {
                // Example for adding a TV show
                cout << "Enter TV Show ID, Title, Year, Genre, Rating, Episodes (comma-separated): ";
                getline(cin, mediaId, ',');
                getline(cin, mediaTitle, ',');
                int year, episodes;
                cin >> year;
                cin.ignore(); // Ignore comma
                string genre;
                getline(cin, genre, ',');
                float rating;
                cin >> rating;
                cin.ignore(); // Ignore comma
                cin >> episodes;

                tvshow::Tvshow* newTVShow = new tvshow::Tvshow(mediaId, mediaTitle, year, genre, rating, episodes);
                mediaDatabase.addTVShow(newTVShow);
                break;
            }
            case 6: {
                // Example for adding music
                cout << "Enter Music ID, Title, Year, Composer, Genre, Tracks, Playtime (comma-separated): ";
                getline(cin, mediaId, ',');
                getline(cin, mediaTitle, ',');
                int year, tracks, playtime;
                cin >> year;
                cin.ignore(); // Ignore comma
                string composer, genre;
                getline(cin, composer, ',');
                getline(cin, genre, ',');
                cin >> tracks;
                cin.ignore(); // Ignore comma
                cin >> playtime;

                music::Music* newMusic = new music::Music(mediaId, mediaTitle, year, composer, genre, tracks, playtime);
                mediaDatabase.addMusic(newMusic);
                break;
            }
            case 7: {
                cout << "Enter Media ID to remove: ";
                getline(cin, mediaId);
                mediaDatabase.removeMovie(mediaId);
                mediaDatabase.removeTvshow(mediaId);
                mediaDatabase.removeMusic(mediaId);
                break;
            }
            case 8: {
                //printMedia(mediaDatabase);
                break;
            }
            case 9: {
                //mediaDatabase.writeToFile("output.csv");
                break;
            }
            case 0: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
