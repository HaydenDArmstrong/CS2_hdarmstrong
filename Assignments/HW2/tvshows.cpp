#include "tvshows.h"

namespace tvshow {
    // Constructor implementation
    Tvshow::Tvshow(std::string mediaId, std::string mediaTitle, int mediaYear, std::string tvGenre, double tvRating, int numEpisodes)
        : media::Media(mediaId, mediaTitle, mediaYear) // Initialize base class Media
    {
        _tvGenre = tvGenre;
        _tvRating = tvRating;
        _numEpisodes = numEpisodes;
    }

    // Getter and setter implementations
    std::string Tvshow::getTvGenre()
    { 
        return _tvGenre; 
    }
    void Tvshow::setTvGenre(std::string tvGenre) 
    { 
        _tvGenre = tvGenre;
    }

    double Tvshow::getRating() 
    { 
        return _tvRating; 
    }
    void Tvshow::setRating(double rating) 
    { 
        _tvRating = rating; 
    }

    int Tvshow::getNumEpisodes()
    { 
        return _numEpisodes; 
    }
    void Tvshow::setNumEpisodes(int episodes) 
    { 
        _numEpisodes = episodes; 
    }
}