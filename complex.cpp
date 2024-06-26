
//bookliat@gmail.com
#include "complex.hpp"
   

    // פונקציות לגישה לחלק הממשי והדמי
    double Complex::getReal() const { return real; }
    double Complex::getImaginary() const { return imag; }

    // פונקציות לקביעת ערכי החלקים הממשי והדמי
    void Complex::setReal(double r) { real = r; }
    void Complex::setImaginary(double i) { imag = i; }

    // פונקציות אופרטור להוספה ולחיסור של מספרים מרוכבים
    Complex Complex::operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex Complex::operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // פונקציות אופרטור לכפל וחילוק של מספר מרוכב במספר רגיל
    Complex Complex::operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    Complex Complex::operator/(double scalar) const {
        if (scalar == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            return Complex();
        }
        return Complex(real / scalar, imag / scalar);
    }

    // פונקציות אופרטור לכפל וחילוק של מספר מרוכב במספר מרוכב
    Complex Complex::operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex Complex::operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            return Complex();
        }
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    // פונקציות אופרטור להשוואה של מספרים מרוכבים
    bool Complex::operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    bool Complex::operator!=(const Complex& other) const {
        return !(*this == other);
    }

  
    bool Complex::operator<(const Complex& other) {
    double mag1 = std::sqrt(real * real + imag * imag);
    double mag2 = std::sqrt(other.real * other.real + other.imag * other.imag);
    return mag1 < mag2;
}



