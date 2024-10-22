#pragma once
#include "media.h"  

namespace tvshows {
    class Tvshow : public media::Media {
        private:
        std::string genre;
        float rating;
        int episodes;

        public:
        Tvshow(std::string mediaId, std::string mediaTitle, int mediaYear, std::string tvGenre, float tvRating, int numEpisodes)
        {
        Media::setId(mediaId);
        Media::setTitle(mediaTitle);
        Media::setYear(mediaYear);

        genre = tvGenre;
        rating = tvRating;
        episodes = numEpisodes;
        }

        std::string getGenre()
        {
            return genre;
        }
        float getRating()
        {
            return rating;
        }
        int getNumEpisodes()
        {
            return episodes;
        }

        void setGenre(std::string tvGenre)
        {
            genre = tvGenre;
        }

        void setRating(float tvRating)
        {
            rating = tvRating;
        }

        void setNumEpisodes(int numEpisodes)
        {
            episodes = numEpisodes;
        }
        };
    
    string displayInfo() {
        Media::displayInfo(); // Display common media info
        std::cout << "Genre: " << genre << "\nRating: " << rating << "\nNumber of Episodes: " << numEpisodes << std::endl;
    }
    }