#pragma once
#include <iostream>

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

        Fraction(double num){
            this->numerator = num * 1000;
            this->denominator = 1000;
            simplify();
        };

        Fraction(){
            this->numerator = 0;
            this->denominator = 1;
        };

        Fraction operator+(const Fraction& other) const;
        Fraction operator+(double num) const;

        Fraction operator-(const Fraction& other) const;
        Fraction operator-(double num) const;

        Fraction operator*(const Fraction& other) const;
        friend Fraction operator*(double num, const Fraction& frac); // different because order is matter

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

        friend std::ostream& operator<<(std::ostream& os,const Fraction& f);
        friend std::istream& operator>>(std::istream& is, Fraction& f);

        int getNumerator() const;
        int getDenominator() const;
    };
    
};