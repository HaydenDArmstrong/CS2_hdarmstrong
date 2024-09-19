#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;


struct Triangle
{
    float side1, side2, side3;
    float area;

};

void promptSides(Triangle*[], int, char);
void printSides(Triangle*[], int);
void calcArea(Triangle*[], int);

/// @brief  THis function takes in an array of pointers to Triangle and size and prints size
/// @param triangles 
/// @param arrSize 
void printSides(Triangle* triangles[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Triangle " << i+1 << "; "
             << triangles[i]->side1 << ","
             << triangles[i]->side2 << ","
             << triangles[i]->side3 << ","
             <<" has an area of: " << triangles[i]->area << endl;
    }

}

///@brief Calcualtes the area for an array of triangle using Heron's Formula
/// @param triangles
/// @param arrSize
    void calcArea(Triangle* triangles[], int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
        {
            int semiPerim = ((triangles[i]->side1 + triangles[i]->side2 + triangles[i]->side3)/2) ;
            triangles[i]-> area = sqrt (semiPerim * (semiPerim- triangles[i]->side1) * (semiPerim - triangles[i]->side2) * (semiPerim - triangles[i]->side3));
        }
    }

// void addThings(Rectangle*, Rectangle*); //prototype function. says need a pointer to rectangle and another pointer to rectangle passed to function

int main(int argc, char* argv[])
{
    int arrSize = 3;
    Triangle* triangles[arrSize];
    char promptOrFile;

    if(argc >=2 && (string)argv[1] == "P") // if there are more arguments (than just the program), AND that argument is P, do P. else do F
    {
        promptOrFile = 'p';
    }
    else
    {
        promptOrFile = 'F';
    }

    promptSides(triangles, arrSize, promptOrFile);

    calcArea(triangles, arrSize);

    printSides(triangles, arrSize);

    

    for (int i=0; i < arrSize; i++)
    {
        delete triangles[i];
    }
    return 0;

}

/// @brief Create instance of Triangle and store address onside of triangles. 
///         Ask users for sides of triangle and store with structure
///         dereferncing the address in triangle
/// @param triangles
/// @param arrSize

void promptSides(Triangle* triangles[], int arrSize, char promptOrFile)
{
 
    if(promptOrFile == 'P')
    {
    for(int i = 0; i < arrSize; i++)
        {
            triangles[i] = new Triangle; // creates a location on the heap 
            cout << "Storing triangle" << i+1 << endl;
            cout << "What is side1? ";
            cin >> triangles[i]->side1; //arrow to derefernce the address
            cout << "What is side2? ";
            cin >> triangles[i]->side2; //arrow to derefernce the address
            cout << "What is side3? ";
            cin >> triangles[i]->side3; //arrow to derefernce the address
        } 
    }
    else
    {
        ifstream fin;
        fin.open("input.txt");

        for (int i=0; i < arrSize; i++)
        {
        triangles[i] = new Triangle;
        float side1, side2, side3;

        fin >> side1 >> side2 >> side3;

        triangles[i]->side1 = side1;
        triangles[i]->side2 = side2;
        triangles[i]->side3 = side3;

        
        }
        fin.close();
    }

}