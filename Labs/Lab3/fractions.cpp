#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator is zero, invalid result will be produced");
    }
    else
    {
        _numerator = numerator;
        _denominator = denominator; 
        simplify();
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    // fraction 13/4 and 14/6
    int commonDenom = _denominator * frac._denominator; // 4 x 6 = 24. our common denominator
    int resultNumer1 = _numerator * frac._denominator; // 13 x 6 = 78. our new denominator. 78/24 = 13/4
    int resultNumer2 = frac._numerator * _denominator;   // 14 x 4 = 56. 56/24 = 14/6

    int addNumerators = resultNumer1 + resultNumer2;
    fractions::Fraction result(addNumerators, commonDenom);

    return simplify(result);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    // fraction 2/3 and 3/5
    int commonDenom = _denominator * frac._denominator; // 3 x 5 = 15. our common denominator
    int resultNumer1 = _numerator * frac._denominator; 
    int resultNumer2 = frac._numerator * _denominator; 

    int subtractNumerators = resultNumer1 - resultNumer2;

    fractions::Fraction result(subtractNumerators, commonDenom);

    return simplify(result); 
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    // fraction 2/3 and 3/5
    int resultNumer = _numerator * frac._numerator;         // 2 x 3 = 6
    int resultDenom = _denominator * frac._denominator;     // 3 x 5 = 15

    fractions::Fraction result(resultNumer, resultDenom);    // (6/15)
    return simplify(result);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    if (frac._denominator == 0) {
        throw std::invalid_argument("Division by zero fraction");
    }

    int resultNumer = _numerator * frac._denominator;
    int resultDenom = _denominator * frac._numerator;

    fractions::Fraction result(resultNumer, resultDenom);
    return simplify(result);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    frac.simplify();
    return frac;
}

void fractions::Fraction::simplify()
{
    int gcdNum = gcd(_numerator, _denominator);
    _numerator /= gcdNum;
    _denominator /= gcdNum;
}

int fractions::Fraction::gcd(int a, int b)
{
    if (b == 0)
    {
        return a; // if there is no remainder, return a which should be gcd
                   // in this case a divides b exactly
    }
    else
    {
        return gcd(b, a % b); 
        // find modulus of a and b, set it to b
        // keep reducing the pair of numbers by replacing a with b and b with a % b until b becomes 0
    }
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    Fraction simplified1 = simplify(*this); // Use the current object
    Fraction simplified2 = simplify(frac);   // Copy the other fraction
    return (simplified1._numerator == simplified2._numerator &&
            simplified1._denominator == simplified2._denominator);
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}
