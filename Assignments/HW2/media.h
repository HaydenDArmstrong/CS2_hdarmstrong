#pragma once
#include <string>
#include <iostream>
namespace media {
    class Media{
    protected:
    std::string id;
    std::string title;
    int year;

    public:
     Media(std::string mediaId, std::string mediaTitle, int mediaYear)
     {
        id = mediaId;
        title = mediaTitle;
        year = mediaYear;
     }

     virtual ~Media() = default;

     void displayInfo() {
        //in progress
    }

     //getters
     std::string getId()
     {
        return id;
     }

     std::string getTitle()
     {
        return title;
     }

     int getYear()
     {
        return year;
     }

     void setId(std::string mediaId)
     {
        id = mediaId;
     }

     void setTitle(std::string mediaTitle){
        title = mediaTitle;
     }
    void setYear(int mediaYear) {
        year = mediaYear;
    }


    };
}