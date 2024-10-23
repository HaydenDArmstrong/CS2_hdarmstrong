#include "media.h"
using namespace std;

media::Media::Media(string mediaId, string mediaTitle, int mediaYear)
{
    _mediaId= mediaId;
    _mediaTitle = mediaTitle;
    _mediaYear = mediaYear;
}

    
string media::Media::getId()
{
    return _mediaId;
}

void media::Media::setId(string mediaId)
{
    _mediaId = mediaId;
}

string media::Media::getTitle()
{
    return _mediaTitle;
}
void media::Media::setTitle(string mediaTitle)
{
    _mediaTitle = mediaTitle;
}

int media::Media::getYear()
{
    return _mediaYear;
}

void media::Media::setYear(int mediaYear)
{
    _mediaYear = mediaYear;
}

