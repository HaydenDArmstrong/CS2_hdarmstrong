#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    //string tmpStr;
    //string words[100];
    string inputLine;
    int numbers[10][10] = {0}; //two dimensional array
    int colCounter = 0;
    int rowCounter = 0;

    ifstream fin;
    fin.open("input.txt");

    while(fin >> inputLine)
    {
            for(int i=0; i < inputLine.length(); i++)
            {
                numbers[rowCounter][i] = inputLine.at(i) -48 ;
            }
            rowCounter++;
    }

    for(int curRow = 0; curRow < rowCounter; curRow++)
    {
    for(int i = 0; i < 10; i++)
    {
        cout << numbers[curRow][i] << " ";
    }
     cout << endl;
    }
     cout << endl;
    

    /*
      while(fin >> tmpStr)
        {
            words[counter] = tmpStr;
            counter++;
        }

        for(int i = counter-1; i >= 0; i--)
        {
            cout << words[i] << " ";
        }
        */

    fin.close();
    return 0;
}