#include <iostream>
#include <numeric>
#include <limits>

class Fraction {
private:
    int numerator_;
    int denominator_;

    static void simplify(int &numerator, int &denominator) {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        if (denominator_ == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify(numerator_, denominator_);
    }

    Fraction operator+(const Fraction &other) const {
        int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        if (newNumerator > std::numeric_limits<int>::max() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("Integer overflow");
        }
        return {newNumerator, newDenominator};
    }

    Fraction operator-(const Fraction &other) const {
        int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int newDenominator = denominator_ * other.denominator_;
        if (newNumerator > std::numeric_limits<int>::max() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("Integer overflow");
        }
        return {newNumerator, newDenominator};
    }

    Fraction operator*(const Fraction &other) const {
        int newNumerator = numerator_ * other.numerator_;
        int newDenominator = denominator_ * other.denominator_;
        if (newNumerator > std::numeric_limits<int>::max() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("Integer overflow");
        }
        return {newNumerator, newDenominator};
    }

    Fraction operator/(const Fraction &other) const {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        int newNumerator = numerator_ * other.denominator_;
        int newDenominator = denominator_ * other.numerator_;
        if (newNumerator > std::numeric_limits<int>::max() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("Integer overflow");
        }
        return {newNumerator, newDenominator};
    }

    Fraction operator-() const {
        if (numerator_ == std::numeric_limits<int>::min()) {
            throw std::overflow_error("Integer overflow");
        }
        return {-numerator_, denominator_};
    }

    Fraction &operator++() {
        if (numerator_ > std::numeric_limits<int>::max() - denominator_) {
            throw std::overflow_error("Integer overflow");
        }
        numerator_ += denominator_;
        return *this;
    }

    Fraction operator++(int) {
        Fraction old = *this;
        ++(*this);
        return old;
    }

    Fraction &operator--() {
        if (numerator_ < std::numeric_limits<int>::min() + denominator_) {
            throw std::overflow_error("Integer overflow");
        }
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator--(int) {
        Fraction old = *this;
        --(*this);
        return old;
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
        out << fraction.numerator_ << "/" << fraction.denominator_;
        return out;
    }
};

int main() {
    int numerator_1, denominator_1;
    int numerator_2, denominator_2;
    std::cout << "Enter the numerator of fraction 1: ";
    std::cin >> numerator_1;
    std::cout << "Enter the denominator of fraction 1: ";
    std::cin >> denominator_1;
    std::cout << "Enter the numerator of fraction 2: ";
    std::cin >> numerator_2;
    std::cout << "Enter the denominator of fraction 2: ";
    std::cin >> denominator_2;

    try {
        Fraction f1(numerator_1, denominator_1);
        Fraction f2(numerator_2, denominator_2);

        Fraction addition = f1 + f2;
        Fraction subtraction = f1 - f2;
        Fraction multiplication = f1 * f2;
        Fraction division = f1 / f2;

        std::cout << f1 << " + " << f2 << " = " << addition << std::endl;
        std::cout << f1 << " - " << f2 << " = " << subtraction << std::endl;
        std::cout << f1 << " * " << f2 << " = " << multiplication << std::endl;
        std::cout << f1 << " / " << f2 << " = " << division << std::endl;

        std::cout << "++" << f1 << " = " << ++f1 << std::endl;
        std::cout << "The value of fraction 1 = " << f1 << std::endl;

        std::cout << "--" << f1 << " = " << --f1 << std::endl;
        std::cout << "The value of fraction 1 = " << f1 << std::endl;

        std::cout << f1 << "++ = " << f1++ << std::endl;
        std::cout << "The value of fraction 1 = " << f1 << std::endl;

        std::cout << f1 << "-- = " << f1-- << std::endl;
        std::cout << "The value of fraction 1 = " << f1 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}