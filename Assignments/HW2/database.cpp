#include "database.h"
#include "media.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
db::Database::Database(string db_name, int db_id)
{
    _db_name = db_name;
    _db_id = db_id;
}
// Function to add a new movie to the database
void db::Database::addMovie(movies::Movie* newMovie) {
    if (movieCount >= 100) {
        std::cout << "Database is full. Cannot add more movies." << std::endl;
        return;
    }
    _movieList[movieCount] = newMovie;
    ++movieCount;

    std::cout << "Movie added successfully, " << movieCount << "/100" << std::endl;
}

// Function to add a new TV show to the database
void db::Database::addTVShow(tvshow::Tvshow* newTVShow) {
    if (tvCount >= 100) {
        std::cout << "Database is full. Cannot add more TV shows." << std::endl;
        return;
    }
    _tvList[tvCount] = newTVShow;
    ++tvCount;

    std::cout << "TV Show added successfully, " << tvCount << "/100" << std::endl;
}

// Function to add a new music to the database
void db::Database::addMusic(music::Music* newMusic) {
    if (musicCount >= 100) {
        std::cout << "Database is full. Cannot add more music." << std::endl;
        return;
    }
    _musicList[musicCount] = newMusic;
    ++musicCount;

    std::cout << "Music added successfully, " << musicCount << "/100" << std::endl;
}

void db::Database::readInMovie(std::string filename) {
    std::string line;
    std::ifstream fin(filename);

    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::istringstream iss(line);

            std::string mediaId, mediaTitle, movDirector, movGenre;
            int mediaYear;
            float movRating;

            // Reading each field
            if (getline(iss, mediaId, ',') &&
                getline(iss, mediaTitle, ',') &&
                iss >> mediaYear &&
                iss.ignore() &&  // Ignore the comma
                getline(iss, movGenre, ',') &&
                iss >> movRating &&
                iss.ignore() &&  // Ignore the comma
                getline(iss, movDirector, ',')) {
                
                // Create a new movie and add it to the database
                movies::Movie *newMovie = new movies::Movie(mediaId, mediaTitle, mediaYear, movGenre, movRating, movDirector);
                addMovie(newMovie);
            } else {
                std::cerr << "Error reading line: " << line << std::endl; // Error handling
            }
        }
        fin.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void db::Database::readInTVShow(std::string filename) {
    std::string line;
    std::ifstream fin(filename);

    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::istringstream iss(line);

            std::string mediaId, mediaTitle, tvGenre;
            int mediaYear, numEpisodes;
            double tvRating;

            // Reading each field from the CSV
            if (getline(iss, mediaId, ',') &&
                getline(iss, mediaTitle, ',') &&
                iss >> mediaYear &&
                iss.ignore() &&  // Ignore the comma
                getline(iss, tvGenre, ',') &&
                iss >> tvRating &&
                iss.ignore() &&  // Ignore the comma
                iss >> numEpisodes) {

                // Create a new TV show object and add it to the database
                tvshow::Tvshow *newTVShow = new tvshow::Tvshow(mediaId, mediaTitle, mediaYear, tvGenre, tvRating, numEpisodes);
                addTVShow(newTVShow); // Assuming you have a function addTVShow in your database class
            } else {
                std::cerr << "Error reading line: " << line << std::endl; // Error handling
            }
        }
        fin.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}


void db::Database::readInMusic(std::string filename) {
    std::string line;
    std::ifstream fin(filename);

    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::istringstream iss(line);

            std::string mediaId, mediaTitle, composer, musGenre;
            int mediaYear, numTracks, totalPlaytime;

            // Reading each field from the CSV
            if (getline(iss, mediaId, ',') &&
                getline(iss, mediaTitle, ',') &&
                iss >> mediaYear &&
                iss.ignore() &&  // Ignore the comma
                getline(iss, composer, ',') &&
                getline(iss, musGenre, ',') &&
                iss >> numTracks &&
                iss.ignore() &&  // Ignore the comma
                iss >> totalPlaytime) {

                // Create a new Music object and add it to the database
                music::Music *newMusic = new music::Music(mediaId, mediaTitle, mediaYear, composer, musGenre, numTracks, totalPlaytime);
                addMusic(newMusic); // Assuming you have a function addMusic in your database class
            } else {
                std::cerr << "Error reading line: " << line << std::endl; // Error handling
            }
        }
        fin.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}




// void movies::Database::writeToFile(string filename)
// {
//     ofstream fout(filename);

//     if (!fout.is_open())
//     {
//         cout << "File: " << filename << " was not found to write into.";
//     }

//     for (int i = 0; i < movieAmount; ++i)
//     {
//         fout << _movieList[i]->getImdbId() << ","
//              << _movieList[i]->getTitle() << ","
//              << _movieList[i]->getYear() << ","
//              << _movieList[i]->getGenre() << ","
//              << _movieList[i]->getRating() << ","
//              << _movieList[i]->getDirector()
//              << endl; // DONT FORGET THIS END LINE
//     }
// }

    template <typename MediaType>
    void db::Database::writeMediaToFile(std::string filename, MediaType* mediaList[], int mediaCount,
                                     std::string (*getMediaInfoFunc)(MediaType*)) {
        std::ofstream fout(filename);

        if (!fout.is_open()) {
            std::cout << "Unable to open file: " << filename << " for writing." << std::endl;
            return;
        }

        for (int i = 0; i < mediaCount; ++i) {
            fout << getMediaInfoFunc(mediaList[i]) << std::endl;
        }

        fout.close();
    }

    std::string getMovieInfo(movies::Movie* movie) {
    std::ostringstream oss;
    oss << movie->getId() << "," 
        << movie->getTitle() << ","
        << movie->getYear() << ","
        << movie->getGenre() << ","
        << movie->getRating() << "," 
        << movie->getDirector();
    return oss.str();
}

std::string getTVShowInfo(tvshow::Tvshow* tvshow) {
    std::ostringstream oss;
    oss << tvshow->getId() << ","
        << tvshow->getTitle() << ","
        << tvshow->getYear() << ","
        << tvshow->getTvGenre() << ","
        << tvshow->getTvRating() << ","
        << tvshow->getNumEpisodes();
    return oss.str();
}

std::string getMusicInfo(music::Music* music) {
    std::ostringstream oss;
    oss << music->getId() << ","
        << music->getTitle() << ","
        << music->getYear() << ","
        << music->getComposer() << ","
        << music->getMusGenre() << ","
        << music->getNumTracks() << ","
        << music->getTotalPlaytime();
    return oss.str();
}



template<typename T1>
void db::Database::addMedia(T1* newMedia, T1* mediaList[], int& mediaCount)
{
    if (mediaCount >= 100) {
        cout << "Database is full. Cannot add more media." << endl;
        return;
    }
    mediaList[mediaCount] = newMedia;
    ++mediaCount;
}

void db::Database::addMovie(movies::Movie *newMovie) {
    addMedia(newMovie, _movieList, movieCount);
}
void db::Database::addTvShow(tvshow::Tvshow *newTvShow) {
    addMedia(newTvShow, _tvList, tvCount);
}
void db::Database::addMusic(music::Music *newMusic) {
    addMedia(newMusic, _musicList, musicCount);
}

template<typename T1>
    void db::Database::removeMedia(string& mediaId, T1* mediaList[], int& mediaCount) {
        bool found = false;

        for (int i = 0; i < mediaCount; ++i) {
            if (mediaList[i]->getImdbId() == mediaId) { // Check for matching ID
                delete mediaList[i]; // Delete the media
                found = true;
            }
            if (found && i < mediaCount - 1) {
                mediaList[i] = mediaList[i + 1]; // Shift up to replace removed media
            }
        }
        if (found) {
            mediaList[mediaCount - 1] = nullptr; // Clear last pointer
            --mediaCount; // Decrease the count
            cout << "Media with ID " << mediaId << " deleted successfully." << endl;
        } else {
            cout << "Media with ID " << mediaId << " not found." << endl;
        }
    }


    void db::Database::removeMovie(string& mediaId) {
        db::Database::removeMedia(mediaId, _movieList, movieCount);
    }
    void db::Database::removeTvshow(string& mediaId) {
        db::Database::removeMedia(mediaId, _tvList, tvCount);
    }
    void db::Database::removeMusic(string& mediaId) {
        db::Database::removeMedia(mediaId, _musicList, musicCount);
    }




template<typename T1>
void db::Database::searchMediaTitle(std::string& mediaTitle, T1* mediaList[], int mediaCount) {
    bool found = false; // to check if any media was found
    for (int i = 0; i < mediaCount; ++i) {
        if (mediaList[i]->getTitle() == mediaTitle) {
            found = true;
            // Print details using a hypothetical print method
            mediaList[i]->printDetails(); // Assuming each media type has a printDetails method
        }
    }
    if (!found) {
        std::cout << "No media found with the title: " << mediaTitle << std::endl;
    }
}

    void db::Database::searchMovie(string& mediaTitle) {
        db::Database::searchMediaTitle(mediaTitle, _movieList, movieCount);
    }
    void db::Database::searchTvshow(string& mediaTitle) {
        db::Database::searchMediaTitle(mediaTitle, _tvList, tvCount);
    }
    void db::Database::searchMusic(string& mediaTitle) {
        db::Database::searchMediaTitle(mediaTitle, _musicList, musicCount);
    }

template<typename T1>
void db::Database::searchMediaGenre(std::string& genre, T1* mediaList[], int mediaCount)
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


 db::Database::~Database() {
        // Clean up dynamically allocated Movie objects
        for (int i = 0; i < movieCount; ++i) {
            delete _movieList[i];
        }
        
        // Clean up dynamically allocated Music objects
        for (int i = 0; i < musicCount; ++i) {
            delete _musicList[i];
        }

        // Clean up dynamically allocated TVShow objects
        for (int i = 0; i < tvCount; ++i) {
            delete _tvList[i];
        }
    }
