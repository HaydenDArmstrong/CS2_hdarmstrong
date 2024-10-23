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

    double Tvshow::getTvRating() 
    { 
        return _tvRating; 
    }
    void Tvshow::setTvRating(double rating) 
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

    // std::string printinfo override {
    //     // Additional TV show-specific information can be appended here
    //     std::string info = media::Media::printinfo(mediaId, mediaTitle, mediaYear); // Call to base class function
    //     info += " (TV Show Specific Details)"; // Add your custom details here
    //     return info;
    // }
   
}