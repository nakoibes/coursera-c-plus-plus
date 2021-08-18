//
// Created by nakoibes on 14.08.2021.
//

//
// Created by nakoibes on 14.08.2021.
//


#include<iostream>
#include <numeric>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;


class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        int gcd_ = gcd(new_numerator, new_denominator);
        numerator = new_numerator / gcd_;
        denominator = new_denominator / gcd_;
        if (numerator * denominator > 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        } else if (numerator * denominator < 0) {
            numerator = -abs(numerator);
            denominator = abs(denominator);
        } else {
            numerator = 0;
            denominator = 1;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    //    void SetNumerator(const int &new_numerator) {
    //        numerator = new_numerator;
    //    }
    //
    //    void SetDenominator(const long &new_denominator) {
    //        denominator = new_denominator;
    //    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational &lhs, const Rational &rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;

}

bool operator<(const Rational &lhs, const Rational &rhs) {
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

ostream &operator<<(ostream &stream, const Rational &rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream &operator>>(istream &stream, Rational &rational) {
    if (!stream) return stream;
    int i = 0;
    int j = 0;
    char c;
    stream >> i;
    if (!stream) return stream;
    stream >> c;
    if (!stream) return stream;
    stream >> j;
    if (c != '/') {
        //            rational = Rational();
        return stream;
    }
    if (stream) {
        rational = Rational(i, j);
    }
    return stream;
}


int main() {
    Rational r1, r2;
    char c;
    try{
        cin >> r1 >> c >> r2;
        if (c == '+') {
            cout << r1 + r2 << endl;
        } else if (c == '-') {
            cout << r1 - r2 << endl;
        } else if (c == '*') {
            cout << r1 * r2 << endl;
        } else {
            cout << r1 / r2 << endl;
        }
    }
    catch (exception &ex){
        cout << ex.what() << endl;
    }
    return 0;
}