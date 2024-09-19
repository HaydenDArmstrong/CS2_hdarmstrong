#include <iostream>
#include <string>

using namespace std;

// Base class Vehicle
class Vehicle
{
    private:
    int _numTires; // Number of tires
    string _fuel; // Type of fuel

    public:
    // Constructor to initialize number of tires and fuel type
    Vehicle(int, string);

    // Getter for number of tires
    int getNumTires();

    // Getter for fuel type
    string getFuel();
};

// Derived class Car from Vehicle
class Car : public Vehicle
{
    private:
    int _capacity; // Seating capacity
    string _color; // Color of the car

    public:
    // Constructor to initialize all attributes of Car and Vehicle
    Car(int, string, int, string);

    // Getter for seating capacity
    int getCapacity();

    // Getter for color
    string getColor();
};

// Derived class Boat from Vehicle
class Boat : public Vehicle
{
    private:
    bool _sail; // Indicates if the boat has a sail
    string _motorType; // Type of motor

    public:
    // Constructor to initialize all attributes of Boat and Vehicle
    Boat(int, string, bool, string);

    // Getter for sail
    bool hasSail();

    // Getter for motor type
    string getMotorType();
};

// Implementation of Vehicle constructor
Vehicle::Vehicle(int numTires, string fuel)
{
    _numTires = numTires;
    _fuel = fuel;
}

// Implementation of Vehicle getter for number of tires
int Vehicle::getNumTires()
{
    return _numTires;
}

// Implementation of Vehicle getter for fuel type
string Vehicle::getFuel()
{
    return _fuel;
}

// Implementation of Car constructor
Car::Car(int numTires, string fuel, int capacity, string color) : Vehicle(numTires, fuel)
{
    _capacity = capacity;
    _color = color;
}

// Implementation of Car getter for seating capacity
int Car::getCapacity()
{
    return _capacity;
}

// Implementation of Car getter for color
string Car::getColor()
{
    return _color;
}

// Implementation of Boat constructor
Boat::Boat(int numTires, string fuel, bool sail, string motorType) : Vehicle(numTires, fuel)
{
    _sail = sail;
    _motorType = motorType;
}

// Implementation of Boat getter for sail
bool Boat::hasSail()
{
    return _sail;
}

// Implementation of Boat getter for motor type
string Boat::getMotorType()
{
    return _motorType;
}

int main(int argc, char* argv[])
{
    // Creating an instance of Car
    Car myCar(4, "gas", 5, "red");

    // Output the attributes of the car
    cout << "myCar.getCapacity(): " << myCar.getCapacity() << endl;
    cout << "myCar.getFuel(): " << myCar.getFuel() << endl;
    cout << "myCar.getColor(): " << myCar.getColor() << endl;

    // Creating an instance of Boat
    Boat myBoat(0, "diesel", true, "outboard");

    // Output the attributes of the boat
    cout << "myBoat.hasSail(): " << (myBoat.hasSail() ? "Yes" : "No") << endl;
    cout << "myBoat.getMotorType(): " << myBoat.getMotorType() << endl;

    return 0;
}
