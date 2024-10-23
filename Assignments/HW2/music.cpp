#include "music.h"
#include "media.h"

    music::Music::Music(std::string mediaId, std::string mediaTitle, int mediaYear, std::string composer, std::string musGenre, int numTracks, int totalPlaytime)
    : media::Media(mediaId, mediaTitle, mediaYear)
    {
        _composer = composer;
        _musGenre = musGenre;
        _numTracks = numTracks;
        _totalPlaytime = totalPlaytime;
    }

        // Getter and setter s
        std::string music::Music::getComposer()
        {
            return _composer;
        }
        void music::Music::setComposer(std::string composer)
        {
            _composer = composer;
        }

        std::string music::Music::getMusGenre()
        {
            return _musGenre;
        }
        void music::Music::setMusGenre(std::string musGenre)
        {
            _musGenre = musGenre;
        }

        int music::Music::getNumTracks()
        {
            return _numTracks;
        }

        void music::Music::setNumTracks(int numTracks)
        {
            _numTracks = numTracks;
        }

        int music::Music::getTotalPlaytime()
        {
            return _totalPlaytime;
        }

        void music::Music::setTotalPlaytime(int totalPlaytime)
        {
            _totalPlaytime = totalPlaytime;
        }
