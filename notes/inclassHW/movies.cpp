#include "movies.h"
//constructor is only called to initate the class
movies::Movie::Movie()
{
    _id = 0;
    _title = "";
};
movies::Movie::Movie(int id, string title)
{
    _id = id;  
    _title = title;
};