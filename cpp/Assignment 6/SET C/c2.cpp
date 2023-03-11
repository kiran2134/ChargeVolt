#include <iostream>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int den)
    {
        numerator = num;
        denominator = den;
        reduce();
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    Rational operator+(const Rational &r) const
    {
        int num = numerator * r.denominator + r.numerator * denominator;
        int den = denominator * r.denominator;
        return Rational(num, den);
    }

    Rational operator-(const Rational &r) const
    {
        int num = numerator * r.denominator - r.numerator * denominator;
        int den = denominator * r.denominator;
        return Rational(num, den);
    }

    Rational operator*(const Rational &r) const
    {
        int num = numerator * r.numerator;
        int den = denominator * r.denominator;
        return Rational(num, den);
    }

    Rational operator/(const Rational &r) const
    {
        int num = numerator * r.denominator;
        int den = denominator * r.numerator;
        return Rational(num, den);
    }

    void reduce()
    {
        if (numerator == 0)
        {
            denominator = 1;
        }
        else
        {
            int gcd = calculateGCD(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0)
            {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    }

    int calculateGCD(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return calculateGCD(b, a % b);
        }
    }

    void display() const
    {
        cout << numerator << "/" << denominator;
    }
};

int main()
{
    Rational r1(2, 3);
    Rational r2(3, 4);

    Rational result = r1 + r2;
    cout << "Sum of ";
    r1.display();
    cout << " and ";
    r2.display();
    cout << " is ";
    result.display();
    cout << endl;

    result = r1 - r2;
    cout << "Difference of ";
    r1.display();
    cout << " and ";
    r2.display();
    cout << " is ";
    result.display();
    cout << endl;

    result = r1 * r2;
    cout << "Product of ";
    r1.display();
    cout << " and ";
    r2.display();
    cout << " is ";
    result.display();
    cout << endl;

    result = r1 / r2;
    cout << "Quotient of ";
    r1.display();
    cout << " and ";
    r2.display();
    cout << " is ";
    result.display();
    cout << endl;

    return 0;
}
