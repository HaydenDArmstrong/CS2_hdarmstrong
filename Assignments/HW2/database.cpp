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

// case 1: load media //

void db::Database::readInMovie(string filename)
{
    string line;
    ifstream fin(filename);

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            istringstream iss(line);

            string mediaId, mediaTitle, movDirector, movGenre;
            int mediaYear;
            float movRating;

            if (getline(iss, mediaId, ',') &&
                getline(iss, mediaTitle, ',') &&
                iss >> mediaYear &&
                iss.ignore() &&
                getline(iss, movGenre, ',') &&
                iss >> movRating &&
                iss.ignore() &&
                getline(iss, movDirector, ','))
            {

                movies::Movie *newMovie = new movies::Movie(mediaId, mediaTitle, mediaYear, movGenre, movRating, movDirector);
                addMovie(newMovie);
            }
            else
            {
                cerr << "Error reading line: " << line << endl;
            }
        }
        fin.close();
        cout << "Movies loaded... " << endl;
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void db::Database::readInTVShow(string filename)
{
    string line;
    ifstream fin(filename);

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            istringstream iss(line);

            string mediaId, mediaTitle, tvGenre;
            int mediaYear, numEpisodes;
            double tvRating;

            if (getline(iss, mediaId, ',') &&
                getline(iss, mediaTitle, ',') &&
                iss >> mediaYear &&
                iss.ignore() &&
                getline(iss, tvGenre, ',') &&
                iss >> tvRating &&
                iss.ignore() &&
                iss >> numEpisodes)
            {
                tvshow::Tvshow *newTvShow = new tvshow::Tvshow(mediaId, mediaTitle, mediaYear, tvGenre, tvRating, numEpisodes);
                addTvShow(newTvShow);
            }
            else
            {
                cerr << "Error reading line: " << line << endl; // Error handling
            }
        }
        fin.close();
        cout << "Tv Shows loaded..." << endl;
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void db::Database::readInMusic(string filename)
{
    string line;
    ifstream fin(filename);

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            istringstream iss(line);

            string mediaId, mediaTitle, composer, musGenre;
            int mediaYear, numTracks, totalPlaytime;

            if (getline(iss, mediaId, ',') &&
                getline(iss, mediaTitle, ',') &&
                iss >> mediaYear &&
                iss.ignore() &&
                getline(iss, composer, ',') &&
                getline(iss, musGenre, ',') &&
                iss >> numTracks &&
                iss.ignore() &&
                iss >> totalPlaytime)
            {

                music::Music *newMusic = new music::Music(mediaId, mediaTitle, mediaYear, composer, musGenre, numTracks, totalPlaytime);
                addMusic(newMusic);
            }
            else
            {
                cerr << "Error reading line: " << line << endl;
            }
        }
        fin.close();
        cout << "Music loaded..." << endl;
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void db::Database::writeMediaToFile(string filename, string mediaType)
{
    ofstream fout(filename);

    if (!fout.is_open())
    {
        cout << "File: " << filename << " could not be opened for writing." << endl;
        return;
    }

    if (mediaType == "movie")
    {
        for (int i = 0; i < movieCount; ++i)
        {
            if (_movieList[i])
            {
                fout << _movieList[i]->getId() << ","
                     << _movieList[i]->getTitle() << ","
                     << _movieList[i]->getYear() << ","
                     << _movieList[i]->getGenre() << ","
                     << _movieList[i]->getRating() << ","
                     << _movieList[i]->getDirector() << endl;
            }
        }
    }
    else if (mediaType == "music")
    {
        for (int i = 0; i < musicCount; ++i)
        {
            if (_musicList[i])
            {
                fout << _musicList[i]->getId() << ","
                     << _musicList[i]->getTitle() << ","
                     << _musicList[i]->getYear() << ","
                     << _musicList[i]->getComposer() << ","
                     << _musicList[i]->getMusGenre() << ","
                     << _musicList[i]->getNumTracks() << ","
                     << _musicList[i]->getTotalPlaytime() << endl;
            }
        }
    }
    else if (mediaType == "tvshow")
    {
        for (int i = 0; i < tvCount; ++i)
        {
            if (_tvList[i])
            {
                fout << _tvList[i]->getId() << ","
                     << _tvList[i]->getTitle() << ","
                     << _tvList[i]->getYear() << ","
                     << _tvList[i]->getTvGenre() << ","
                     << _tvList[i]->getTvRating() << ","
                     << _tvList[i]->getNumEpisodes() << endl;
            }
        }
    }

    fout.close();
    cout << "Data written to " << filename << " successfully." << endl;
}

string getMovieInfo(movies::Movie *movie)
{
    ostringstream oss;
    oss << movie->getId() << ","
        << movie->getTitle() << ","
        << movie->getYear() << ","
        << movie->getGenre() << ","
        << movie->getRating() << ","
        << movie->getDirector();
    return oss.str();
}

string getTVShowInfo(tvshow::Tvshow *tvshow)
{
    ostringstream oss;
    oss << tvshow->getId() << ","
        << tvshow->getTitle() << ","
        << tvshow->getYear() << ","
        << tvshow->getTvGenre() << ","
        << tvshow->getTvRating() << ","
        << tvshow->getNumEpisodes();
    return oss.str();
}

string getMusicInfo(music::Music *music)
{
    ostringstream oss;
    oss << music->getId() << ","
        << music->getTitle() << ","
        << music->getYear() << ","
        << music->getComposer() << ","
        << music->getMusGenre() << ","
        << music->getNumTracks() << ","
        << music->getTotalPlaytime();
    return oss.str();
}

// case 2: add media

template <typename T1>
void db::Database::addMedia(T1 *newMedia, T1 *mediaList[], int &mediaCount)
{
    if (mediaCount >= 100)
    {
        cout << "Database is full. Cannot add more media." << endl;
        return;
    }
    mediaList[mediaCount] = newMedia;
    ++mediaCount;
}

void db::Database::addMovie(movies::Movie *newMovie)
{
    addMedia(newMovie, _movieList, movieCount);
}
void db::Database::addTvShow(tvshow::Tvshow *newTvShow)
{
    addMedia(newTvShow, _tvList, tvCount);
}
void db::Database::addMusic(music::Music *newMusic)
{
    addMedia(newMusic, _musicList, musicCount);
}

// case 4: Remove Media

template <typename T1>
void db::Database::removeMedia(string &mediaId, T1 *mediaList[], int &mediaCount)
{
    bool found = false;

    for (int i = 0; i < mediaCount; ++i)
    {
        if (mediaList[i]->getId() == mediaId)
        {                        // Check for matching ID
            delete mediaList[i]; // Delete the media
            found = true;
        }
        if (found && i < mediaCount - 1)
        {
            mediaList[i] = mediaList[i + 1]; // Shift up to replace removed media
        }
    }
    if (found)
    {
        mediaList[mediaCount - 1] = nullptr; // Clear last pointer
        --mediaCount;                        // Decrease the count
        cout << "Media with ID " << mediaId << " deleted successfully." << endl;
    }
    else
    {
        cout << "Media with ID " << mediaId << " not found." << endl;
    }
}

void db::Database::removeMovie(string &mediaId)
{
    db::Database::removeMedia(mediaId, _movieList, movieCount);
}
void db::Database::removeTvshow(string &mediaId)
{
    db::Database::removeMedia(mediaId, _tvList, tvCount);
}
void db::Database::removeMusic(string &mediaId)
{
    db::Database::removeMedia(mediaId, _musicList, musicCount);
}

// case 3 search media
// in progress

template <typename T1>
void db::Database::searchMediaTitle(string &mediaTitle, T1 *mediaList[], int mediaCount)
{
    bool found; // to check if any media was found

    for (int i = 0; i < mediaCount; ++i)
    {
        if (mediaList[i]->getTitle() == mediaTitle)
        {
            found = true;
            cout << "Found media maching title: " << mediaTitle << endl;
            mediaList[i]->printDetails();
        }
    }
    if (!found)
    {

        cout << "No media found with the title: " << mediaTitle << endl;
    }
}
void db::Database::searchMovie(string &mediaTitle)
{
    db::Database::searchMediaTitle(mediaTitle, db::Database::_movieList, movieCount);
}
void db::Database::searchTvshow(string &mediaTitle)
{
    db::Database::searchMediaTitle(mediaTitle, db::Database::_tvList, tvCount);
}
void db::Database::searchMusic(string &mediaTitle)
{
    db::Database::searchMediaTitle(mediaTitle, db::Database::_musicList, musicCount);
}

// case 5 print media
// work in progress

void db::Database::displayAllMedia()
{

    displayMediaList(_movieList, movieCount);

    displayMediaList(_musicList, musicCount);

    displayMediaList(_tvList, tvCount);
}

db::Database::~Database()
{
    for (int i = 0; i < movieCount; ++i)
    {
        // cout << "Deleting: " << _movieList[i]->getId() << endl;
        delete _movieList[i];
    }
    for (int i = 0; i < musicCount; ++i)
    {
        // cout << "Deleting: " << _musicList[i]->getId() << endl;
        delete _musicList[i];
    }
    for (int i = 0; i < tvCount; ++i)
    {
        // cout << "Deleting: " << _tvList[i]->getId() << endl;
        delete _tvList[i];
    }

    movieCount = tvCount = musicCount = 0;
}

template <typename T>
void db::Database::displayMediaList(T **mediaList, int mediaCount)
{
    cout << left << setw(15) << "ID"
         << setw(50) << "Title"
         << setw(10) << "Year"
         << endl;

    cout << string(80, '-') << endl;

    for (int i = 0; i < mediaCount; ++i)
    {
        if (mediaList[i] != nullptr)
        {
            cout << setw(15) << mediaList[i]->getId()
                 << setw(50) << mediaList[i]->getTitle()
                 << setw(10) << mediaList[i]->getYear()
                 << endl;
        }
        else
        {
            cout << "mediaList[" << i << "] is null." << endl;
            cout << setw(10) << "N/A"
                 << setw(25) << "N/A"
                 << setw(10) << "N/A"
                 << endl;
        }
    }
}

void db::Database::writeAllMediaToFile(const string &filename)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cerr << "File: " << filename << " could not be opened for writing." << endl;
        return;
    }

    fout << "Movies:\n";
    fout << "ID,Title,Year,Genre,Rating,Director\n";
    for (int i = 0; i < movieCount; ++i)
    {
        if (_movieList[i] != nullptr)
        {
            fout << _movieList[i]->getId() << ","
                 << _movieList[i]->getTitle() << ","
                 << _movieList[i]->getYear() << ","
                 << _movieList[i]->getGenre() << ","
                 << _movieList[i]->getRating() << ","
                 << _movieList[i]->getDirector() << "\n";
        }
    }

    fout << "\nTV Shows:\n";
    fout << "ID,Title,Year,Genre,Rating,Episodes\n";
    for (int i = 0; i < tvCount; ++i)
    {
        if (_tvList[i] != nullptr)
        {
            fout << _tvList[i]->getId() << ","
                 << _tvList[i]->getTitle() << ","
                 << _tvList[i]->getYear() << ","
                 << _tvList[i]->getTvGenre() << ","
                 << _tvList[i]->getTvRating() << ","
                 << _tvList[i]->getNumEpisodes() << "\n";
        }
    }

    fout << "\nMusic:\n";
    fout << "ID,Title,Year,Composer,Genre,Tracks,Total Playtime\n";
    for (int i = 0; i < musicCount; ++i)
    {
        if (_musicList[i] != nullptr)
        {
            fout << _musicList[i]->getId() << ","
                 << _musicList[i]->getTitle() << ","
                 << _musicList[i]->getYear() << ","
                 << _musicList[i]->getComposer() << ","
                 << _musicList[i]->getMusGenre() << ","
                 << _musicList[i]->getNumTracks() << ","
                 << _musicList[i]->getTotalPlaytime() << "\n";
        }
    }

    fout.close();
    cout << "All media data written to " << filename << " successfully." << endl;
}