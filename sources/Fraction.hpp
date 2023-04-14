#pragma once
#include <iostream>
#include <string>

namespace ariel{

    class Fraction{
        int numerator;
        int denominator;

        void simplify();
        int mcd(int a, int b) const;
        int gcd(int a, int b) const;

    public:

        Fraction(int numerator, int denominator = 1){
            this->numerator = numerator;
            this->denominator = denominator;
            simplify();
        };

        Fraction operator+(const Fraction& other) const;
        Fraction operator+(double num) const;

        Fraction operator-(const Fraction& other) const;
        Fraction operator-(double num) const;

        Fraction operator*(const Fraction& other) const;
        Fraction operator*(double num) const;

        Fraction operator/(const Fraction& other) const;
        Fraction operator/(double num) const;

        bool operator==(const Fraction& other) const;
        bool operator==(double num) const;

        bool operator>(const Fraction& other) const;
        bool operator>(double num) const;

        bool operator<(const Fraction& other) const;
        bool operator<(double num) const;
        
        bool operator>=(const Fraction& other) const;
        bool operator>=(double num) const;

        bool operator<=(const Fraction& other) const;
        bool operator<=(double num) const;

        Fraction& operator++();
        Fraction operator++(int);

        Fraction& operator--();
        Fraction operator--(int);
        
        int getNumerator() const;
        int getDenominator() const;
    };
    
};