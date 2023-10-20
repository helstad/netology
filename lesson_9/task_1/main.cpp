#include <iostream>

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    bool operator==(Fraction f) const {
        if (numerator_ == f.numerator_) {
            if (denominator_ == f.denominator_) { return true; }
            else return false;
        } else return false;
    }

    bool operator!=(Fraction f) const {
        return !(*this == f);
    }

    bool operator>(Fraction f) const {
        return (numerator_ * f.denominator_) > (f.numerator_ * denominator_);
    }

    bool operator<(Fraction f) const {
        return *this != f && !(*this > f);
    }

    bool operator<=(Fraction f) const {
        return *this == f || !(*this > f);
    }

    bool operator>=(Fraction f) const {
        return *this == f || (f < *this);
    }
};

int main() {
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}