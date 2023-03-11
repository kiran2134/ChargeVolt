#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    Fraction(int num, int den)
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

    Fraction operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        numerator += denominator;
        reduce();
        return temp;
    }

    friend ostream &operator<<(ostream &out, const Fraction &f)
    {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    friend istream &operator>>(istream &in, Fraction &f)
    {
        in >> f.numerator >> f.denominator;
        f.reduce();
        return in;
    }

    friend bool operator<(const Fraction &f1, const Fraction &f2)
    {
        int num1 = f1.numerator * f2.denominator;
        int num2 = f2.numerator * f1.denominator;
        return num1 < num2;
    }

private:
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
};
int main()
{
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    // pre-increment operator
    ++f1;
    cout << "After pre-increment, f1 = " << f1 << endl;

    // post-increment operator
    Fraction f3 = f2++;
    cout << "After post-increment, f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    // input and output stream operators
    Fraction f4;
    cout << "Enter a fraction: ";
    cin >> f4;
    cout << "You entered: " << f4 << endl;

    // less than operator
    if (f1 < f2)
    {
        cout << f1 << " is less than " << f2 << endl;
    }
    else
    {
        cout << f1 << " is greater than or equal to " << f2 << endl;
    }
    return 0;
}
