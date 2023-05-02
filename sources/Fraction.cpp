#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(int numerator,int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be 0");
        exit(1);
    }

    this->numerator = numerator;
    this->denominator = denominator;
    if (this->denominator < 0) // if denominator is negative, move the sign to the numerator, also avoid two negative signs in the fraction
    {
        this->numerator *= -1;
        this->denominator *= -1;
    }
    this->simplify();
};

Fraction::Fraction(double num) : denominator(MAX_DIGITS)
{
    int numInt = static_cast<int>(std::round(num * MAX_DIGITS));
    // double numRound = static_cast<double>(numInt) / MAX_DIGITS;
    //  if (numRound != num)
    //  {
    //      throw std::invalid_argument("Double number has more than 3 digits after decimal point");
    //      exit(1);
    //  }
    this->numerator = numInt;
    this->simplify();
}

int Fraction::getNumerator() const
{
    return this->numerator;
};
int Fraction::getDenominator() const
{
    return this->denominator;
};
void Fraction::setNumerator(int num)
{
    this->numerator = num;
};
void Fraction::setDenominator(int den)
{
    this->denominator = den;
};

void Fraction::check_overflow(int num1, int num2, const char *operation) const
{
    if (strcmp(operation, "add") == 0)
    {
        if (num1 > 0 && num2 > 0 && num1 > INT_MAX - num2)
        {
            throw std::overflow_error("Overflow error");
        }
        else if (num1 < 0 && num2 < 0 && num1 < INT_MIN - num2)
        {
            throw std::overflow_error("Overflow error");
        }
    }

    if (strcmp(operation, "multiply") == 0)
    {
        if (num1 > 0 && num2 > 0 && num1 > INT_MAX / num2)
        {
            throw std::overflow_error("Overflow error");
        }
        else if (num1 > 0 && num2 < 0 && num2 < INT_MIN / num1)
        {
            throw std::overflow_error("Overflow error");
        }
        else if (num1 < 0 && num2 > 0 && num1 < INT_MIN / num2)
        {
            throw std::overflow_error("Overflow error");
        }
        else if (num1 < 0 && num2 < 0 && (num1 < INT_MAX / num2 || num2 < INT_MAX / num1))
        {
            throw std::overflow_error("Overflow error");
        }
    }
}

void Fraction::simplify()
{
    int gcd = this->gcd(this->getNumerator(), this->getDenominator());
    if (gcd < 0)
        gcd *= -1;
    this->setNumerator(this->getNumerator() / gcd);
    this->setDenominator(this->getDenominator() / gcd);
}

Fraction Fraction::rounded() const
{
    int roundedNumerator = round(MAX_DIGITS * static_cast<double>(this->getNumerator()) / this->getDenominator());
    int roundedDenominator = MAX_DIGITS;
    return Fraction(roundedNumerator, roundedDenominator);
}

int Fraction::gcd(int num1, int num2) const
{
    if (num1 == 0)
        return num2;
    return gcd(num2 % num1, num1);
}

int Fraction::mcd(int num1, int num2) const
{
    int i = num1 > num2 ? num1 : num2;
    bool found = false;
    while (!found)
    {
        if (i % num1 == 0 && i % num2 == 0)
        {
            found = true;
        }
        else
        {
            this->check_overflow(i, num1 > num2 ? num1 : num2, "add");
            i += num1 > num2 ? num1 : num2;
        }
    }
    return i;
}

Fraction Fraction::operator+(const Fraction &other) const
{
    int newDenominator = this->mcd(this->getDenominator(), other.getDenominator());

    this->check_overflow(this->getNumerator(), newDenominator / this->getDenominator(), "multiply");
    int newNumerator1 = this->getNumerator() * (newDenominator / this->getDenominator());

    this->check_overflow(other.getNumerator(), newDenominator / other.getDenominator(), "multiply");
    int newNumerator2 = other.getNumerator() * (newDenominator / other.getDenominator());

    this->check_overflow(newNumerator1, newNumerator2, "add");
    int newNumerator = newNumerator1 + newNumerator2;

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator+(double num) const
{
    Fraction frac(num);
    return this->operator+(frac);
}

Fraction ariel::operator+(double num, const Fraction &frac)
{
    return Fraction(num) + frac;
}

Fraction Fraction::operator-(const Fraction &other) const
{
    this->check_overflow(other.getNumerator(), -1, "multiply");
    Fraction flipped(other.getNumerator() * -1, other.getDenominator());
    return this->operator+(flipped);
}

Fraction Fraction::operator-(double num) const
{
    Fraction frac(num);
    return this->operator-(frac);
}

Fraction ariel::operator-(double num, const Fraction &frac)
{
    return Fraction(num) - frac;
}

Fraction Fraction::operator*(const Fraction &other) const
{

    check_overflow(this->getNumerator(), other.getNumerator(), "multiply");
    int newNumerator = this->getNumerator() * other.getNumerator();

    check_overflow(this->getDenominator(), other.getDenominator(), "multiply");
    int newDenominator = this->getDenominator() * other.getDenominator();

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(double num) const
{
    Fraction frac(num);
    return this->operator*(frac);
}

Fraction ariel::operator*(double num, const Fraction &frac)
{
    return Fraction(num) * frac;
}

Fraction Fraction::operator/(const Fraction &other) const
{
    if (other.getNumerator() == 0)
        throw std::runtime_error("Division by zero");
    Fraction flipped(other.getDenominator(), other.getNumerator());
    return this->operator*(flipped);
}

Fraction ariel::operator/(double num, const Fraction &frac)
{
    return Fraction(num) / frac;
}

Fraction Fraction::operator/(double num) const
{
    Fraction frac(num);
    return this->operator/(frac);
}

bool Fraction::operator==(const Fraction &other) const
{
    if (this->getNumerator() == 0 && other.getNumerator() == 0)
        return true;

    Fraction thisFrac = this->rounded();
    Fraction otherFrac = other.rounded();
    return thisFrac.getNumerator() == otherFrac.getNumerator() && thisFrac.getDenominator() == otherFrac.getDenominator();
}

bool Fraction::operator==(double num) const
{
    Fraction frac(num);
    return this->rounded() == (frac);
}

bool ariel::operator==(double num, const Fraction &frac)
{
    return Fraction(num) == frac.rounded();
}

bool Fraction::operator>(const Fraction &other) const
{
    int thisNum = this->getNumerator();
    int otherNum = other.getNumerator();
    int thisDen = this->getDenominator();
    int otherDen = other.getDenominator();

    if (thisDen < 0)
    {
        thisNum *= -1;
        thisDen *= -1;
    }

    if (otherDen < 0)
    {
        otherNum *= -1;
        otherDen *= -1;
    }

    int lhs = thisNum * otherDen;
    int rhs = otherNum * thisDen;

    return lhs > rhs;
}

bool ariel::operator>(double num, const Fraction &frac)
{
    return Fraction(num) > frac;
}

bool Fraction::operator>(double num) const
{
    Fraction frac(num);
    return this->operator>(frac);
}

bool Fraction::operator<(const Fraction &other) const
{
    return !(this->operator==(other) or this->operator>(other));
}

bool ariel::operator<(double num, const Fraction &frac)
{
    return Fraction(num) < frac;
}

bool Fraction::operator<(double num) const
{
    Fraction frac(num);
    return this->operator<(frac);
}

bool Fraction::operator>=(const Fraction &other) const
{
    return this->operator==(other) or this->operator>(other);
}

bool ariel::operator>=(double num, const Fraction &frac)
{
    return Fraction(num) >= frac;
}

bool Fraction::operator>=(double num) const
{
    Fraction frac(num);
    return this->operator>=(frac);
}

bool Fraction::operator<=(const Fraction &other) const
{
    return this->operator==(other) or this->operator<(other);
}

bool ariel::operator<=(double num, const Fraction &frac)
{
    return Fraction(num) <= frac;
}

bool Fraction::operator<=(double num) const
{
    Fraction frac(num);
    return this->operator<=(frac);
}

Fraction &Fraction::operator++()
{
    this->setNumerator(this->operator+(1).getNumerator());
    this->setDenominator(this->operator+(1).getDenominator());
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    this->operator++();
    return temp;
}

Fraction &Fraction::operator--()
{
    this->setNumerator(this->operator-(1).getNumerator());
    this->setDenominator(this->operator-(1).getDenominator());
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    this->operator--();
    return temp;
}

std::ostream &ariel::operator<<(std::ostream &ost, const Fraction &frac)
{
    ost << frac.getNumerator() << "/" << frac.getDenominator();
    return ost;
}

std::istream &ariel::operator>>(std::istream &ist, Fraction &frac)
{
    int num = 0, den = 0;
    ist >> num >> den;
    if (ist.fail() || den == 0)
    {
        throw std::runtime_error("Invalid input");
    }
    if (den < 0) // if denominator is negative, move the sign to the numerator, also avoid two negative signs in the fraction
    {
        num *= -1;
        den *= -1;
    }
    frac.setNumerator(num);
    frac.setDenominator(den);
    return ist;
}