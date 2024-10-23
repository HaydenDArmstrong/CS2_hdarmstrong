#pragma once
#include "media.h"
#include <string>

namespace tvshow {
    class Tvshow : public media::Media {
    private:
        double _tvRating;
        int _numEpisodes;
        std::string _tvGenre;

    public:
        // Constructor declaration
        Tvshow(std::string mediaId, std::string mediaTitle, int mediaYear, std::string tvGenre, double tvRating, int numEpisodes);

        std::string displayInfo() const override {
        return "TV Show Info: Title, Seasons, Episodes";
    }

        // Getter and setter prototypes
        std::string getTvGenre();
        void setTvGenre(std::string tvGenre);

        double getTvRating();
        void setTvRating(double tvRating);

        int getNumEpisodes();
        void setNumEpisodes(int numEpisodes);
    };
}
