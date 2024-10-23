#include <cassert>
#include "fractions.h"

void tests();

int main(int argc, char* argv[])
{

    if(argc >= 2 && (string)argv[1] == "test")
    {
        tests();
        return 0;
    }
    
    int num1, denom1, num2, denom2;

    // Prompt for first fraction
    cout << "Enter numerator for Fraction 1: ";
    cin >> num1;
    cout << "Enter denominator for Fraction 1: ";
    cin >> denom1;

    if (denom1 == 0) {
        cerr << "Error: Denominator cannot be zero." << endl;
        return 1;  // Exit the program if denominator is zero
    }

    // Create first fraction
    fractions::Fraction frac1(num1, denom1);
    cout << "You entered Fraction 1: " << frac1 << endl;

    // Prompt for second fraction
    cout << "Enter numerator for Fraction 2: ";
    cin >> num2;
    cout << "Enter denominator for Fraction 2: ";
    cin >> denom2;

    if (denom2 == 0) {
        cerr << "Error: Denominator cannot be zero." << endl;
        return 1;  // Exit if denominator is zero
    }

    // Create second fraction
    fractions::Fraction frac2(num2, denom2);
    cout << "You entered Fraction 2: " << frac2 << endl;

    // Perform operations and display results
    cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << endl;
    cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << endl;
    cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << endl;
    cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << endl;


    return 0;
}

void tests()
{
    //test1
    fractions::Fraction testFrac1(2, 3);
    fractions::Fraction testFrac2(3, 5);
    fractions::Fraction ansFrac(0, 1);
    ansFrac = testFrac1 + testFrac2;
    assert(ansFrac == fractions::Fraction(19, 15));
    ansFrac = testFrac1 - testFrac2;
    assert(ansFrac == fractions::Fraction(1, 15));
    ansFrac = testFrac1 * testFrac2;
    assert(ansFrac == fractions::Fraction(2, 5));
    ansFrac = testFrac1 / testFrac2;
    assert(ansFrac == fractions::Fraction(10, 9));

    fractions::Fraction testFrac3(5, 7);
    fractions::Fraction testFrac4(-2, 9);
    ansFrac = testFrac3 + testFrac4;
    assert(ansFrac == fractions::Fraction(31, 63));
    ansFrac = testFrac3 - testFrac4;
    assert(ansFrac == fractions::Fraction(59, 63));
    ansFrac = testFrac3 * testFrac4;
    assert(ansFrac == fractions::Fraction(-10, 63));
    ansFrac = testFrac3 / testFrac4;
    assert(ansFrac == fractions::Fraction(45, -14));
    cout << "All test cases passed" << endl;
}