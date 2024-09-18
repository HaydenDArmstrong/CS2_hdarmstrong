#include <iostream>
#include "database.h"

using namespace std;

//std::getline character delimiter usag
//getline(string str, char ',');

//for loop - read in a line as string
//as you read the string, when the character is comma finish the iteration of loop. 
//keep informaiton as a token, then seperate the token

//sstream method
//view 'strings' notes

//rating is float. year is integer.
//id, title, year, genre, rating, director
//string, string, int, string, float, string

int main (int , char* argv)
{

    
    movies::Database db("MyMovieDataBase", 1);
    return 0;
}