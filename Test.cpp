#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
#include <string>

using namespace ariel;

TEST_CASE("Init"){
    Fraction f1(1,2);
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);

    Fraction f2(5);
    CHECK(f2.getNumerator() == 5);
    CHECK(f2.getDenominator() == 1);

    Fraction f3(2.75);
    CHECK(f3.getNumerator() == 11);
    CHECK(f3.getDenominator() == 4);
}

TEST_CASE("+"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 + f2).getNumerator() == 5);
    CHECK((f1 + f2).getDenominator() == 6);

    CHECK((f1 + f3).getNumerator() == 5);
    CHECK((f1 + f3).getDenominator() == 2);

    CHECK((f2 + f3).getNumerator() == 233);
    CHECK((f2 + f3).getDenominator() == 100);

    CHECK((f1 + 0.5).getNumerator() == 1);
    CHECK((f1 + 0.5).getDenominator() == 1);

    CHECK((f2 + 0.5).getNumerator() == 83);
    CHECK((f2 + 0.5).getDenominator() == 100);

    CHECK((f3 + 0.5).getNumerator() == 233);
    CHECK((f3 + 0.5).getDenominator() == 100);
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

    CHECK((f2 - 0.5).getNumerator() == -1);
    CHECK((f2 - 0.5).getDenominator() == 6);

    CHECK((f3 - 0.5).getNumerator() == 3);
    CHECK((f3 - 0.5).getDenominator() == 2);
}

TEST_CASE("*"){
    Fraction f1(1,2);
    Fraction f2(0.333);
    Fraction f3(2);

    CHECK((f1 * f2).getNumerator() == 33);
    CHECK((f1 * f2).getDenominator() == 200);

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

    CHECK((f1 / f2).getNumerator() == 400);
    CHECK((f1 / f2).getDenominator() == 11);

    CHECK((f1 / f3).getNumerator() == 3);
    CHECK((f1 / f3).getDenominator() == 5);

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

    CHECK((++f1).getNumerator() == 2);
    CHECK((f1).getDenominator() == 1);

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

TEST_CASE("<<"){

}

TEST_CASE(">>"){

}

