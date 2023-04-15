#pragma once
#include <iostream>

namespace ariel{

    class Fraction{
        int numerator;
        int denominator;

        void simplify();
        int gcd(int a, int b) const;

    public:

        Fraction(int numerator, int denominator = 1){
            if (denominator == 0){
                throw std::invalid_argument("Denominator can't be 0");
                exit(1);
            }
            if (denominator < 0){
                numerator *= -1;
                denominator *= -1;
            }
            this->numerator = numerator;
            this->denominator = denominator;
            this->simplify();
        };

        Fraction(double num){
            int numInt = static_cast<int>(num * 1000);
            double numRound = static_cast<double>(numInt) / 1000;
            if (numRound != num){
                throw std::invalid_argument("Double number has more than 3 digits after decimal point");
                exit(1); 
            }
            this->numerator = num * 1000;
            this->denominator = 1000;
            this->simplify();
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

        int getNumerator() const{
            return this->numerator;
        };
        int getDenominator() const{
            return this->denominator;
        };
        void setNumerator(int num){
            this->numerator = num;
        };
        void setDenominator(int den){
            this->denominator = den;
        };
    };
    
};