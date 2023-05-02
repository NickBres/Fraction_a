#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <cstring>
#include <climits>

using namespace std;

namespace ariel
{
    const int MAX_DIGITS = 1000; // for double numbers

    class Fraction
    {
        int numerator;
        int denominator;

        void simplify();
        Fraction rounded() const;
        int gcd(int num1, int num2) const;
        int mcd(int num1, int num2) const;
        void check_overflow(int num1, int num2, const char *operation) const;

    public:
        Fraction(int numerator = 0, int denominator = 1);

        Fraction(double num);

        Fraction operator+(const Fraction &other) const;
        friend Fraction operator+(double num, const Fraction &frac);
        Fraction operator+(double num) const;

        Fraction operator-(const Fraction &other) const;
        friend Fraction operator-(double num, const Fraction &frac);
        Fraction operator-(double num) const;

        Fraction operator*(const Fraction &other) const;
        friend Fraction operator*(double num, const Fraction &frac);
        Fraction operator*(double num) const;

        Fraction operator/(const Fraction &other) const;
        friend Fraction operator/(double num, const Fraction &frac);
        Fraction operator/(double num) const;

        bool operator==(const Fraction &other) const;
        friend bool operator==(double num, const Fraction &frac);
        bool operator==(double num) const;

        bool operator>(const Fraction &other) const;
        friend bool operator>(double num, const Fraction &frac);
        bool operator>(double num) const;

        bool operator<(const Fraction &other) const;
        friend bool operator<(double num, const Fraction &frac);
        bool operator<(double num) const;

        bool operator>=(const Fraction &other) const;
        friend bool operator>=(double num, const Fraction &frac);
        bool operator>=(double num) const;

        bool operator<=(const Fraction &other) const;
        friend bool operator<=(double num, const Fraction &frac);
        bool operator<=(double num) const;

        Fraction &operator++();
        Fraction operator++(int);

        Fraction &operator--();
        Fraction operator--(int);

        friend std::ostream &operator<<(std::ostream &ost, const Fraction &frac);
        friend std::istream &operator>>(std::istream &ist, Fraction &frac);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int num);
        void setDenominator(int den);
    };

};