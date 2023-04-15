#include "Fraction.hpp"

using namespace ariel;

void Fraction::simplify()
{
    int gcd = this->gcd(this->getNumerator(), this->getDenominator());
    if (gcd == -1) gcd = 1;
    this->setNumerator(this->getNumerator() / gcd);
    this->setDenominator(this->getDenominator() / gcd);
}

int Fraction::gcd(int num1, int num2) const
{
    if (num1 == 0)
        return num2;
    return gcd(num2 % num1, num1);
}



Fraction Fraction::operator+(const Fraction &other) const
{
    int newDenominator = this->getDenominator() * other.getDenominator();
    int newNumerator = this->getNumerator() * other.getDenominator() + other.getNumerator() * this->getDenominator();
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator+(double num) const
{
    Fraction frac(num);
    return this->operator+(frac);
}

Fraction Fraction::operator-(const Fraction &other) const
{
    int newDenominator = this->getDenominator() * other.getDenominator();
    int newNumerator = this->getNumerator() * other.getDenominator() - other.getNumerator() * this->getDenominator();
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(double num) const
{
    Fraction frac(num);
    return this->operator-(frac);
}

Fraction Fraction::operator*(const Fraction &other) const
{
    return Fraction(this->getNumerator() * other.getNumerator(), this->getDenominator() * other.getDenominator());
}

Fraction ariel::operator*(double num, const Fraction &frac)
{
    return Fraction(frac.getNumerator() * num, frac.getDenominator());
}

Fraction Fraction::operator/(const Fraction& other) const{
    Fraction flipped(other.getDenominator(),other.getNumerator());
    return this->operator*(flipped);
}

Fraction Fraction::operator/(double num) const{
    Fraction frac(num);
    return this->operator/(frac);
}

bool Fraction::operator==(const Fraction& other) const{
    if (this->getNumerator() != other.getNumerator()) return false;
    if (this->getDenominator() != other.getDenominator()) return false;
    return true;
}

bool Fraction::operator==(double num) const{
    Fraction frac(num);
    return this->operator==(frac);
}

bool Fraction::operator>(const Fraction& other) const {
    int thisNum = this->getNumerator();
    int otherNum = other.getNumerator();
    int thisDen = this->getDenominator();
    int otherDen = other.getDenominator();

    if (thisDen < 0) {
        thisNum *= -1;
        thisDen *= -1;
    }

    if (otherDen < 0) {
        otherNum *= -1;
        otherDen *= -1;
    }

    int lhs = thisNum * otherDen;
    int rhs = otherNum * thisDen;

    return lhs > rhs;
}

bool Fraction::operator>(double num) const{
    Fraction frac(num);
    return this->operator>(frac);
}

bool Fraction::operator<(const Fraction& other) const{
    return !(this->operator==(other) or this->operator>(other));
}

bool Fraction::operator<(double num) const{
    Fraction frac(num);
    return this->operator<(frac);
}

bool Fraction::operator>=(const Fraction& other) const{
    return this->operator==(other) or this->operator>(other);
}

bool Fraction::operator>=(double num) const{
    Fraction frac(num);
    return this->operator>=(frac);
}

bool Fraction::operator<=(const Fraction& other) const{
    return this->operator==(other) or this->operator<(other);
}

bool Fraction::operator<=(double num) const{
    Fraction frac(num);
    return this->operator<=(frac);
}

Fraction& Fraction::operator++(){
    this->setNumerator(this->operator+(1).getNumerator());
    this->setDenominator(this->operator+(1).getDenominator());
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction temp = *this;
    this->operator++();
    return temp;
}

Fraction& Fraction::operator--(){
    this->setNumerator(this->operator-(1).getNumerator());
    this->setDenominator(this->operator-(1).getDenominator());
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction temp = *this;
    this->operator--();
    return temp;
}

std::ostream& ariel::operator<<(std::ostream& ost, const Fraction& frac) {
    ost << frac.getNumerator() << "/" << frac.getDenominator();
    return ost;
}

std::istream& ariel::operator>>(std::istream& ist, Fraction& frac) {
    // Read the input as a string
    std::string input;
    ist >> input;

    // Check if the input contains a '/'
    std::size_t pos = input.find('/');
    if (pos == std::string::npos) {
        // Invalid input format, throw an exception
        throw std::invalid_argument("Invalid input format. Expected 'numerator/denominator'");
    }

    // Extract the numerator and denominator as integers
    std::string num_str = input.substr(0, pos);
    std::string den_str = input.substr(pos + 1);
    int num, den;
    try {
        num = std::stoi(num_str);
        den = std::stoi(den_str);
    }
    catch (const std::invalid_argument&) {
        // Invalid input format, throw an exception
        throw std::invalid_argument("Invalid input format. Expected 'numerator/denominator'");
    }

    // Set the fraction object to the extracted values
    frac = Fraction(num, den);

    // Return the input stream
    return ist;
}