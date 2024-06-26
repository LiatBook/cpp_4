//bookliat@gmail.com
#include <iostream>
#include <cmath> 
// using namespace std;
class Complex {
private:
    double real;   // חלק המספר הממשי
    double imag;   // חלק המספר הדמי

public:
    // בנאי ברירת מחדל - מאתחל את המספר המרוכב ל־0+0i
    Complex() : real(0), imag(0) {}

    // בנאי עם פרמטרים - מאתחל את המספר המרוכב ל־real+imagi
    Complex(double r, double i) : real(r), imag(i) {}

    // בנאי העתקה
    Complex(const Complex& other) {
        real = other.real;
        imag = other.imag;
    }

    // פונקציות לגישה לחלק הממשי והדמי
    double getReal() const;
    double getImaginary() const ;

    // פונקציות לקביעת ערכי החלקים הממשי והדמי
    void setReal(double r) ;
    void setImaginary(double i);

    Complex operator+(const Complex& other) const;

    Complex operator-(const Complex& other) const ;

    Complex operator*(double scalar) const ;

    Complex operator/(double scalar) const ;

    // פונקציות אופרטור לכפל וחילוק של מספר מרוכב במספר מרוכב
    Complex operator*(const Complex& other) const ;

    Complex operator/(const Complex& other) const ;

    bool operator==(const Complex& other) const ;

    bool operator!=(const Complex& other) const ;

    bool operator<(const Complex& other)  ;

       // Friend function for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};

// Operator << implementation (outside the class)
std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real;
    if (complex.imag >= 0) {
        os << "+" << complex.imag << "i";
    } else {
        os << complex.imag << "i";
    }
    return os;
}



