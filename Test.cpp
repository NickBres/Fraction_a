#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>
#include <string>

using namespace ariel;

TEST_CASE("Init"){
    // check that numerator and denominator are initialized correctly
    Fraction f1(1,2);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);

    // check that double is converted to fraction correctly
    Fraction f2(5); 
    CHECK(f2.getNumerator() == 5);
    CHECK(f2.getDenominator() == 1);
    Fraction f3(2.75);
    CHECK(f3.getNumerator() == 11);
    CHECK(f3.getDenominator() == 4);
    CHECK_THROWS(Fraction(0.1234)); // check fraction cant get double with more than 3 digits after decimal point
    CHECK_THROWS(Fraction(0.12345));

    // check that zero denominator throws exception
    CHECK_THROWS(Fraction(1,0)); 

    // check that fraction is always simplified
    Fraction f4(100,200);  
    CHECK(f4.getNumerator() == 1);
    CHECK(f4.getDenominator() == 2);

    //Check negatives
    Fraction f5(-1,5);
    CHECK(f5.getNumerator() == -1);
    CHECK(f5.getDenominator() == 5);
    Fraction f6(1,-5);
    CHECK(f6.getNumerator() == -1);
    CHECK(f6.getDenominator() == 5);
    Fraction f7(-1,-5);
    CHECK(f7.getNumerator() == 1);
    CHECK(f7.getDenominator() == 5);

}

TEST_CASE("+"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 + f2).getNumerator() == 833);
    CHECK((f1 + f2).getDenominator() == 1000);

    CHECK((f1 + f3).getNumerator() == 5);
    CHECK((f1 + f3).getDenominator() == 2);

    CHECK((f2 + f3).getNumerator() == 2333);
    CHECK((f2 + f3).getDenominator() == 1000);

    CHECK((f1 + 0.5).getNumerator() == 1);
    CHECK((f1 + 0.5).getDenominator() == 1);

    CHECK((f2 + 0.5).getNumerator() == 833);
    CHECK((f2 + 0.5).getDenominator() == 1000);

    CHECK((f3 + 0.5).getNumerator() == 5);
    CHECK((f3 + 0.5).getDenominator() == 2);
}

TEST_CASE("-"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 - f2).getNumerator() == 167);
    CHECK((f1 - f2).getDenominator() == 1000);

    CHECK((f1 - f3).getNumerator() == -3);
    CHECK((f1 - f3).getDenominator() == 2);

    CHECK((f2 - f3).getNumerator() == -1667);
    CHECK((f2 - f3).getDenominator() == 1000);

    CHECK((f1 - 0.5).getNumerator() == 0);
    CHECK((f1 - 0.5).getDenominator() == 1);

    CHECK((f2 - 0.5).getNumerator() == -167);
    CHECK((f2 - 0.5).getDenominator() == 1000);

    CHECK((f3 - 0.5).getNumerator() == 3);
    CHECK((f3 - 0.5).getDenominator() == 2);
}

TEST_CASE("*"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 * f2).getNumerator() == 333);
    CHECK((f1 * f2).getDenominator() == 2000);

    CHECK((f1 * f3).getNumerator() == 1);
    CHECK((f1 * f3).getDenominator() == 1);

    CHECK((f2 * f3).getNumerator() == 333);
    CHECK((f2 * f3).getDenominator() == 500);

    CHECK((f1 * 0.5).getNumerator() == 1);
    CHECK((f1 * 0.5).getDenominator() == 4);

    CHECK((f2 * 0.5).getNumerator() == 333);
    CHECK((f2 * 0.5).getDenominator() == 2000);

    CHECK((f3 * 0.5).getNumerator() == 1);
    CHECK((f3 * 0.5).getDenominator() == 1);
}

TEST_CASE("/"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 / f2).getNumerator() == 500);
    CHECK((f1 / f2).getDenominator() == 333);

    CHECK((f1 / f3).getNumerator() == 1);
    CHECK((f1 / f3).getDenominator() == 4);

    CHECK((f2 / f3).getNumerator() == 333);
    CHECK((f2 / f3).getDenominator() == 2000);

    CHECK((f1 / 0.5).getNumerator() == 1);
    CHECK((f1 / 0.5).getDenominator() == 1);

    CHECK((f2 / 0.5).getNumerator() == 333);
    CHECK((f2 / 0.5).getDenominator() == 500);

    CHECK((f3 / 0.5).getNumerator() == 4);
    CHECK((f3 / 0.5).getDenominator() == 1);
}

TEST_CASE("=="){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 == f2) == false);
    CHECK((f1 == f3) == false);
    CHECK((f2 == f3) == false);

    CHECK((f1 == 0.5) == true);
    CHECK((f2 == 0.333) == true);
    CHECK((f3 == 2) == true);
}

TEST_CASE(">"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 > f2) == true);
    CHECK((f1 > f3) == false);
    CHECK((f2 > f3) == false);

    CHECK((f1 > 0.5) == false);
    CHECK((f2 > 0.333) == false);
    CHECK((f3 > 2) == false);
}

TEST_CASE("<"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 < f2) == false);
    CHECK((f1 < f3) == true);
    CHECK((f2 < f3) == true);

    CHECK((f1 < 0.5) == false);
    CHECK((f2 < 0.333) == false);
    CHECK((f3 < 2) == false);
}

TEST_CASE(">="){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 >= f2) == true);
    CHECK((f1 >= f3) == false);
    CHECK((f2 >= f3) == false);

    CHECK((f1 >= 0.5) == true);
    CHECK((f2 >= 0.333) == true);
    CHECK((f3 >= 2) == true);
}

TEST_CASE("<="){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 <= f2) == false);
    CHECK((f1 <= f3) == true);
    CHECK((f2 <= f3) == true);

    CHECK((f1 <= 0.5) == true);
    CHECK((f2 <= 0.333) == true);
    CHECK((f3 <= 2) == true);
}

TEST_CASE("++"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    f1++;
    f2++; 
    f3++;

    CHECK((f1).getNumerator() == 3);
    CHECK((f1).getDenominator() == 2);

    CHECK((++f1).getNumerator() == 5);
    CHECK((f1).getDenominator() == 2);

    CHECK((f2).getNumerator() == 1333);
    CHECK((f2).getDenominator() == 1000);

    CHECK((++f2).getNumerator() == 2333);
    CHECK((f2).getDenominator() == 1000);

    CHECK((f3).getNumerator() == 3);
    CHECK((f3).getDenominator() == 1);

    CHECK((++f3).getNumerator() == 4);
    CHECK((f3).getDenominator() == 1);
}

TEST_CASE("--"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    f1--;
    f2--;
    f3--;

    CHECK((f1).getNumerator() == -1);
    CHECK((f1).getDenominator() == 2);

    CHECK((--f1).getNumerator() == -3);
    CHECK((f1).getDenominator() == 2);

    CHECK((f2).getNumerator() == -667);
    CHECK((f2).getDenominator() == 1000);

    CHECK((--f2).getNumerator() == -1667);
    CHECK((f2).getDenominator() == 1000);

    CHECK((f3).getNumerator() == 1);
    CHECK((f3).getDenominator() == 1);

    CHECK((--f3).getNumerator() == 0);
    CHECK((f3).getDenominator() == 1);
}

TEST_CASE("<<") {
    Fraction f(1, 2);
    std::stringstream ss;
    ss << f;
    CHECK(ss.str() == "1/2");
}

TEST_CASE(">>") {
    std::stringstream ss("1/2");
    Fraction f;
    ss >> f;
    CHECK(f.getNumerator() == 1);
    CHECK(f.getDenominator() == 2);
}


