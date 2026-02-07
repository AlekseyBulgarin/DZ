#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//   ¹6 
class Fraction {
    int num, den;
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    void reduce() {
        int g = gcd(num, den);
        num /= g; den /= g;
        if (den < 0) { num = -num; den = -den; }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { reduce(); }
    Fraction operator+(const Fraction& f) const {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }
    Fraction operator-(const Fraction& f) const {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }
    Fraction operator*(const Fraction& f) const {
        return Fraction(num * f.num, den * f.den);
    }
    Fraction operator/(const Fraction& f) const {
        return Fraction(num * f.den, den * f.num);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.num << "/" << f.den;
    return os;
}

class Complex {
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    Complex operator+(const Complex& c) const {
        return Complex(re + c.re, im + c.im);
    }
    Complex operator-(const Complex& c) const {
        return Complex(re - c.re, im - c.im);
    }
    Complex operator*(const Complex& c) const {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }
    Complex operator/(const Complex& c) const {
        double d = c.re * c.re + c.im * c.im;
        return Complex((re * c.re + im * c.im) / d, (im * c.re - re * c.im) / d);
    }
    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.re << (c.im >= 0 ? "+" : "") << c.im << "i";
    return os;
}

//   ¹7 
class Overcoat {
    string type;
    double price;
public:
    Overcoat(string t = "", double p = 0) : type(t), price(p) {}
    bool operator==(const Overcoat& o) const { return type == o.type; }
    Overcoat& operator=(const Overcoat& o) {
        if (this != &o) { type = o.type; price = o.price; }
        return *this;
    }
    bool operator>(const Overcoat& o) const {
        return type == o.type && price > o.price;
    }
    void print() const { cout << type << " - $" << price; }
};

class Flat {
    double area;
    double price;
public:
    Flat(double a = 0, double p = 0) : area(a), price(p) {}
    bool operator==(const Flat& f) const { return area == f.area; }
    Flat& operator=(const Flat& f) {
        if (this != &f) { area = f.area; price = f.price; }
        return *this;
    }
    bool operator>(const Flat& f) const { return price > f.price; }
    void print() const { cout << area << " m2 - $" << price; }
};

//   ¹8 
class String {
    char* str;
    size_t len;
public:
    String(const char* s = "") : len(strlen(s)) {
        str = new char[len + 1];
        strcpy(str, s);
    }
    String(const String& other) : len(other.len) {
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    String(String&& other) noexcept : str(other.str), len(other.len) {
        other.str = nullptr;
        other.len = 0;
    }
    ~String() { delete[] str; }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            len = other.len;
            str = new char[len + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    void print() const { if (str) cout << str; }
};

class Array {
    int* arr;
    size_t size;
public:
    Array(size_t s = 0) : size(s) {
        arr = new int[size] {};
    }
    Array(const Array& other) : size(other.size) {
        arr = new int[size];
        for (size_t i = 0; i < size; ++i) arr[i] = other.arr[i];
    }
    Array(Array&& other) noexcept : arr(other.arr), size(other.size) {
        other.arr = nullptr;
        other.size = 0;
    }
    ~Array() { delete[] arr; }
};

//  ¹9
class StringEnhanced {
    char* str;
    size_t len;
public:
    StringEnhanced(const char* s = "") : len(strlen(s)) {
        str = new char[len + 1];
        strcpy(str, s);
    }
    StringEnhanced(const StringEnhanced& other) : len(other.len) {
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    ~StringEnhanced() { delete[] str; }
    char& operator[](size_t idx) { return str[idx]; }
    int operator()(char ch) const {
        for (size_t i = 0; i < len; ++i)
            if (str[i] == ch) return i;
        return -1;
    }
    operator int() const { return len; }
    void print() const { cout << str; }
};

// ¹10 
class Date {
    int day, month, year;
    void normalize() {
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) daysInMonth[1] = 29;
        while (day > daysInMonth[month - 1]) {
            day -= daysInMonth[month - 1];
            month++;
            if (month > 12) { month = 1; year++; }
        }
        while (day < 1) {
            month--;
            if (month < 1) { month = 12; year--; }
            day += daysInMonth[month - 1];
        }
    }
public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) { normalize(); }
    void incDay() { day++; normalize(); }
    Date operator+(int days) const { Date temp = *this; temp.day += days; temp.normalize(); return temp; }
    Date operator-(int days) const { return *this + (-days); }
    int operator%(int mod) const { return day % mod; }
    bool operator<(const Date& d) const {
        if (year != d.year) return year < d.year;
        if (month != d.month) return month < d.month;
        return day < d.day;
    }
    bool operator>(const Date& d) const { return d < *this; }
    bool operator<=(const Date& d) const { return !(*this > d); }
    bool operator>=(const Date& d) const { return !(*this < d); }
    bool operator==(const Date& d) const { return day == d.day && month == d.month && year == d.year; }
    bool operator!=(const Date& d) const { return !(*this == d); }
    bool operator&&(const Date& d) const { return day && d.day; }
    bool operator||(const Date& d) const { return day || d.day; }
    friend ostream& operator<<(ostream& os, const Date& d);
    friend istream& operator>>(istream& is, Date& d);
    friend Date operator*(const Date& date, int factor);
    friend Date operator/(const Date& date, int divisor);
};

ostream& operator<<(ostream& os, const Date& d) {
    os << d.day << "." << d.month << "." << d.year;
    return os;
}

istream& operator>>(istream& is, Date& d) {
    char dot;
    is >> d.day >> dot >> d.month >> dot >> d.year;
    d.normalize();
    return is;
}

Date operator*(const Date& date, int factor) {
    Date temp = date;
    temp.day *= factor;
    temp.normalize();
    return temp;
}

Date operator/(const Date& date, int divisor) {
    Date temp = date;
    temp.day /= divisor;
    temp.normalize();
    return temp;
}

int main() {
    cout << "=== Fraction ===" << endl;
    Fraction f1(1, 2), f2(1, 3);
    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;

    cout << "\n=== Complex ===" << endl;
    Complex c1(1, 2), c2(3, 4);
    cout << c1 << " * " << c2 << " = " << (c1 * c2) << endl;

    cout << "\n=== Overcoat ===" << endl;
    Overcoat o1("coat", 100), o2("coat", 150);
    cout << "Same type: " << (o1 == o2) << ", o2 > o1: " << (o2 > o1) << endl;

    cout << "\n=== Flat ===" << endl;
    Flat fl1(50, 50000), fl2(60, 60000);
    cout << "Same area: " << (fl1 == fl2) << ", fl2 > fl1: " << (fl2 > fl1) << endl;

    cout << "\n=== StringEnhanced ===" << endl;
    StringEnhanced se("Hello");
    cout << "Length: " << (int)se << ", se[1]=" << se[1] << ", find('e')=" << se('e') << endl;

    cout << "\n=== Date ===" << endl;
    Date d1(15, 1, 2024);
    Date d2 = d1 + 10;
    cout << d1 << " + 10 days = " << d2 << endl;
    cout << d1 << " < " << d2 << ": " << (d1 < d2) << endl;

    return 0;
}