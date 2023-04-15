#pragma once
#include <iostream>
#include <cmath>

namespace ariel
{
    const int MAX_DIGITS = 1000; // for double numbers

    class Fraction
    {
        int numerator;
        int denominator;

        void simplify();
        int gcd(int num1, int num2) const;

    public:
        Fraction(int numerator = 0, int denominator = 1)
        {
            if (denominator == 0)
            {
                throw std::invalid_argument("Denominator can't be 0");
                exit(1);
            }
            if (denominator < 0) // if denominator is negative, move the sign to the numerator, also avoid two negative signs in the fraction
            {
                numerator *= -1;
                denominator *= -1;
            }
            this->numerator = numerator;
            this->denominator = denominator;
            this->simplify();
        };

        Fraction(double num)
        {
            int numInt = static_cast<int>(std::round(num * MAX_DIGITS));
            double numRound = static_cast<double>(numInt) / MAX_DIGITS;
            if (numRound != num)
            {
                throw std::invalid_argument("Double number has more than 3 digits after decimal point");
                exit(1);
            }
            this->numerator = numInt;
            this->denominator = MAX_DIGITS;
            this->simplify();
        }

        Fraction operator+(const Fraction &other) const;
        Fraction operator+(double num) const;

        Fraction operator-(const Fraction &other) const;
        Fraction operator-(double num) const;

        Fraction operator*(const Fraction &other) const;
        friend Fraction operator*(double num, const Fraction &frac); // different because order is matter

        Fraction operator/(const Fraction &other) const;
        Fraction operator/(double num) const;

        bool operator==(const Fraction &other) const;
        bool operator==(double num) const;

        bool operator>(const Fraction &other) const;
        bool operator>(double num) const;

        bool operator<(const Fraction &other) const;
        bool operator<(double num) const;

        bool operator>=(const Fraction &other) const;
        bool operator>=(double num) const;

        bool operator<=(const Fraction &other) const;
        bool operator<=(double num) const;

        Fraction &operator++();
        Fraction operator++(int);

        Fraction &operator--();
        Fraction operator--(int);

        friend std::ostream &operator<<(std::ostream &ost, const Fraction &frac);
        friend std::istream &operator>>(std::istream &ist, Fraction &frac);

        int getNumerator() const
        {
            return this->numerator;
        };
        int getDenominator() const
        {
            return this->denominator;
        };
        void setNumerator(int num)
        {
            this->numerator = num;
        };
        void setDenominator(int den)
        {
            this->denominator = den;
        };
    };

};