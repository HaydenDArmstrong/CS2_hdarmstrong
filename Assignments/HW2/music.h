#pragma once
#include "media.h"
#include <string>
// composer, genre, numTracks and totalPlaytime.

namespace music
{
    class Music : public media::Media
    {
    private:
        std::string _composer;
        std::string _musGenre;
        int _numTracks;
        int _totalPlaytime;

    public:
        // Constructor declaration
        Music(std::string mediaId, std::string mediaTitle, int mediaYear, std::string composer, std::string musGenre, int numTracks, int totalPlaytime);

        // Getter and setter prototypes
        std::string getComposer();
        void setComposer(std::string composer);

        std::string getMusGenre();
        void setMusGenre(std::string musGenre);

        int getNumTracks();
        void setNumTracks(int numTracks);

        int getTotalPlaytime();
        void setTotalPlaytime(int totalPlaytime);

        void printDetails() const override
        {
            Media::printDetails();
            std::cout << ", Composer: " << _composer << ", Genre: " << _musGenre << ", Number of Tracks: " << _numTracks
                      << ", Playtime: " << _totalPlaytime << std::endl;
        }
    };
}
