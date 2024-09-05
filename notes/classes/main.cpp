// #include <iostream>
// #include <string>

// //using namespace std;

// namespace Bob
// {

// class Bob
// {
//     private:
//         std::string _name;
//         rectangle::Rectangle rect1;
//     public:
//         Bob(); 
//     std::string getName()
//     {
//         return _name;
//     }
// };
// }

// namespace rectangle
// {

// class Rectangle
// {
//     private:
//         double _side1, _side2;
//         double _area;
//         Bob::Bob bob1;
//     public: 
//         Rectangle() //getters and setters
//         {
//             _side1 = 0;
//             _side2 = 0;
//             _area = 0;
//         }
//         Rectangle(double side1, double side2)
//         {
//             _side1 = side1;
//             _side2 = side2;
//             _area = side1 * side2;
//         }
//         double area()
//         {
//             return _area;
//         }

// };
// }



// int main(int argc, char* argv[])
// {
//     //rectangle::Rectangle* rect1 = new rectangle::Rectangle(42, 15);
//     Bob::Bob bob1;

//     std::cout << "Rectangle 1 has an area of: "
//          << rect1->area() << std::endl;

//     std::cout << "Bob 1 name is "
//          << bob1.getName() << std::endl;

//          delete rect1;
//          return 0;
// }

// //Bob::Bob(); // :: is the scope resolution operator. refers to a namespace





// // /*
// // class pen
// // {
// //     private: //private things can only be accessed  and modified through a specific process
//              // this is usually variables (called attributes) or sometimes functions ( called methods) you dont want to be modified or varied
//     string color;
//     string inkType;
//     float size;
//     float capacity;
//     bool capState;

//     public: //you put things in public so they can be modified, and only things you want modified WITHOUT validation.
//             //this is usually functions (methods)
//     void write();
//     void toggleCap();
//     bool getCapState();
//     void setColor(string); */

// class MyClass
// {
// private:
//     string _fName = " "; // you will need "get"ers and "set"ers to access these
//     string _lName = " ";
//     int _age = 0;

// public:
//     MyClass()
//     {
//         cout << "creating instance of myClass" << endl;
//         _fName = "";
//         _lName = "";
//         _age = 42;
//     }
//     MyClass(string fName, string lName, int age)
//     {
//         _fName = fName;
//         _lName = lName;
//         _age = age;
//     }
//     // get these attributes
//     string getfName()
//     {
//         return _fName; // underscore attribute implies it is an attribute which belongs to a class
//     }
//     string getlName()
//     {
//         return _lName;
//     }
//     int getAge()
//     {
//         return _age;
//     }
//     // set these attributes
//     void setfName(string fName)
//     {
//         _fName = fName;
//     }
//     void setlName(string lName)
//     {
//         _lName = lName;
//     }
//     void setAge(int age)
//     {
//         if (age < 0 || age > 151) // these setters allow for validation; like how there couldnt be someone younger than 0 or older than 151
//         {
//             cout << "age is invalid;" << endl;
//         }
//         else
//         {
//             _age = age;
//         }
//     }
//     void printInfo()
//     {
//         cout << "Hello "
//              << _fName
//              << " "
//              << _lName
//              << ", You are "
//              << _age
//              << " Years old"
//              << endl;
//     }
// };

// void sayHello();
// void sayGoodbye();
// //prototype functions allow for more freedom from declaration order

// void sayHello()
// {
//     cout << "Hello World" << endl;
//     sayGoodbye(); // by this time, sayGoodbye has not yet been declared and compiled if we DONT use a prototype
// }

// void sayGoodbye()
// {
//     cout << "Goodbye World" << endl;
// }
// int main(int argc, char *argv[])
// {
//     MyClass classInstance1; // classes allow for isntances. in this first instance, set to jeremy bergen. in the second, allow for user input
//     MyClass classInstance2;

//     string tmpStr;
//     int givenAge;

//     /* MyClass* classinst1 = new MyClass;
//     MyClass* classinst2 = new MyClass; */

//     classInstance1.setfName("Jeremy");
//     classInstance1.setlName("Bergen");
//     classInstance1.setAge(42);

//     cout << "What is your first name? ";
//     getline(cin, tmpStr);
//     classInstance2.setfName(tmpStr);
//     cout << "What is your last name? ";
//     getline(cin, tmpStr);
//     classInstance2.setlName(tmpStr);
//     cout << "What is your age? ";
//     cin >> givenAge;
//     classInstance2.setAge(givenAge);

//     classInstance1.printInfo();
//     classInstance2.printInfo();

//     return 0;
// }
