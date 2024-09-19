#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

void readFile(ifstream&, vector<string>&); //wise to use a vector when the quantitity of values is uncertain
void splitLines(istringstream&);
int main(int argc, char* argv[])
{
    ifstream fin;
    vector<string> fileLines;

    fin.open("input.csv");

    readFile(fin,fileLines);

    for(auto line : fileLines)
    {
        istringstream iss;
        iss.str(line);
        splitLines(iss);
    }

    for (size_t i = 0; i <fileLines.size(); i++) //size of a string is the number of characters
    {
        cout << fileLines.at(i) << endl; //.at does bounds checking. [i] does not
        //cout << fileLines[i] << endl;
    }
    fin.close();
    return 0;
}

//     if(fin.is_open())// if the file exists
//     {
//         string inputLine;
//         while(getline(fin,inputLine))
//         {
//             cout << inputLine << endl;

//             istringstream iss;
//             string token;
//             iss.str(inputLine);

//             while (getline(iss, token, ','))
//             {
//                 cout << token << "-"; //now the values in the csv file are seperated, 'tokenized'
//             }
//             cout << endl;


//         }

//     }
//     fin.close();


//     return 0;
// }

void splitLines(istringstream& iss)
{
    string token;
    while (getline(iss, token, ','))
    {
        cout << token << '-'; //tokenizer
    }

}
void readFile(ifstream& fin, vector<string>& inputLines)
{
    string tmpLine;
    while (getline(fin, tmpLine))
    {
        inputLines.push_back(tmpLine); //pushes it to the 'back' of the vector
    }
}
