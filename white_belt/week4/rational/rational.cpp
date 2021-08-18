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
    if (i == '/', j == 0 || c != '/') {
        //            rational = Rational();
        return stream;
    }
    if (stream) {
        rational = Rational(i, j);
    }
    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}