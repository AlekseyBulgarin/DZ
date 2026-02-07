#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>
#include <bitset>
#include <stdexcept>
using namespace std;

// ===== ВСТРЕЧА №18 =====
class Pet {
protected:
    string name;
    int age;
public:
    Pet(string n = "", int a = 0) : name(n), age(a) {}
    virtual void show() { cout << "Имя: " << name << ", Возраст: " << age; }
    virtual ~Pet() {}
};

class Dog : public Pet {
    string breed;
public:
    Dog(string n, int a, string b) : Pet(n, a), breed(b) {}
    void show() override {
        Pet::show();
        cout << ", Порода: " << breed << " (Собака)" << endl;
    }
};

class Cat : public Pet {
    string color;
public:
    Cat(string n, int a, string c) : Pet(n, a), color(c) {}
    void show() override {
        Pet::show();
        cout << ", Цвет: " << color << " (Кошка)" << endl;
    }
};

class Parrot : public Pet {
    string vocabulary;
public:
    Parrot(string n, int a, string v) : Pet(n, a), vocabulary(v) {}
    void show() override {
        Pet::show();
        cout << ", Словарный запас: " << vocabulary << " (Попугай)" << endl;
    }
};

class String {
protected:
    char* str;
    size_t length;
public:
    String() : str(nullptr), length(0) {}
    String(const char* s) : length(strlen(s)) {
        str = new char[length + 1];
        strcpy(str, s);
    }
    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    size_t getLength() const { return length; }
    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }
    virtual ~String() { delete[] str; }
    String operator+(const String& other) const {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        String result(temp);
        delete[] temp;
        return result;
    }
    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }
    bool operator!=(const String& other) const {
        return !(*this == other);
    }
    friend ostream& operator<<(ostream& os, const String& s);
};

ostream& operator<<(ostream& os, const String& s) {
    if (s.str) os << s.str;
    return os;
}

class BitString : public String {
public:
    BitString(const char* s) {
        for (size_t i = 0; i < strlen(s); i++) {
            if (s[i] != '0' && s[i] != '1') {
                throw invalid_argument("Только '0' и '1' разрешены");
            }
        }
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    BitString(const BitString& other) : String(other) {}
    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }
};

// ===== ВСТРЕЧА №19 =====
class Animal {
protected:
    string species;
public:
    Animal(string s) : species(s) {}
    virtual void speak() = 0;
};

class Mammal : virtual public Animal {
protected:
    int legs;
public:
    Mammal(string s, int l) : Animal(s), legs(l) {}
};

class PetAnimal : virtual public Animal {
protected:
    string name;
public:
    PetAnimal(string s, string n) : Animal(s), name(n) {}
};

class DomesticDog : public Mammal, public PetAnimal {
public:
    DomesticDog(string n, int l) :
        Animal("Собака"), Mammal("Собака", l), PetAnimal("Собака", n) {
    }
    void speak() override { cout << name << " говорит: Гав!" << endl; }
};

template<typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;
public:
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}
    virtual void show() { cout << "База: " << value1 << ", " << value2 << endl; }
    virtual ~Base() {}
};

template<typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    Child(T1 v1, T2 v2, T3 v3, T4 v4) :
        Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}
    void show() override {
        Base<T1, T2>::show();
        cout << "Потомок: " << value3 << ", " << value4 << endl;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;
public:
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) :
        Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}
    void show() override {
        Child<T1, T2, T3, T4>::show();
        cout << "Потомок2: " << value5 << ", " << value6 << endl;
    }
};

// ===== ВСТРЕЧА №20 =====
class FileHandler {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file) {
            cout << "Не могу открыть файл: " << path << endl;
            return;
        }
        char ch;
        while (file.get(ch)) {
            cout << ch;
        }
        file.close();
        cout << endl;
    }
    virtual ~FileHandler() {}
};

class ASCIIDisplay : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file) {
            cout << "Не могу открыть файл: " << path << endl;
            return;
        }
        char ch;
        while (file.get(ch)) {
            cout << (int)ch << " ";
        }
        file.close();
        cout << endl;
    }
};

class BinaryDisplay : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);
        if (!file) {
            cout << "Не могу открыть файл: " << path << endl;
            return;
        }
        char ch;
        while (file.get(ch)) {
            bitset<8> bits(ch);
            cout << bits << " ";
        }
        file.close();
        cout << endl;
    }
};

// ===== ВСТРЕЧА №21 =====
class Equation {
public:
    virtual void findRoots() = 0;
    virtual ~Equation() {}
};

class LinearEquation : public Equation {
    double a, b;
public:
    LinearEquation(double a1, double b1) : a(a1), b(b1) {}
    void findRoots() override {
        if (a == 0) {
            cout << "Нет корней или бесконечно много корней" << endl;
        }
        else {
            cout << "Корень: x = " << -b / a << endl;
        }
    }
};

class QuadraticEquation : public Equation {
    double a, b, c;
public:
    QuadraticEquation(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {}
    void findRoots() override {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Нет действительных корней" << endl;
        }
        else if (D == 0) {
            cout << "Корень: x = " << -b / (2 * a) << endl;
        }
        else {
            cout << "Корни: x1 = " << (-b + sqrt(D)) / (2 * a)
                << ", x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
        }
    }
};

class Shape {
public:
    virtual void Show() = 0;
    virtual void Save(ofstream& file) = 0;
    virtual void Load(ifstream& file) = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
    double x, y, side;
public:
    Square(double x1 = 0, double y1 = 0, double s = 0) : x(x1), y(y1), side(s) {}
    void Show() override {
        cout << "Квадрат: (" << x << "," << y << "), сторона=" << side << endl;
    }
    void Save(ofstream& file) override {
        file << "Square " << x << " " << y << " " << side << endl;
    }
    void Load(ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
    double x, y, width, height;
public:
    Rectangle(double x1 = 0, double y1 = 0, double w = 0, double h = 0) :
        x(x1), y(y1), width(w), height(h) {
    }
    void Show() override {
        cout << "Прямоугольник: (" << x << "," << y << "), "
            << width << "x" << height << endl;
    }
    void Save(ofstream& file) override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }
    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
    double x, y, radius;
public:
    Circle(double x1 = 0, double y1 = 0, double r = 0) : x(x1), y(y1), radius(r) {}
    void Show() override {
        cout << "Круг: центр(" << x << "," << y << "), радиус=" << radius << endl;
    }
    void Save(ofstream& file) override {
        file << "Circle " << x << " " << y << " " << radius << endl;
    }
    void Load(ifstream& file) override {
        file >> x >> y >> radius;
    }
};

class Ellipse : public Shape {
    double x, y, width, height;
public:
    Ellipse(double x1 = 0, double y1 = 0, double w = 0, double h = 0) :
        x(x1), y(y1), width(w), height(h) {
    }
    void Show() override {
        cout << "Эллипс: (" << x << "," << y << "), "
            << width << "x" << height << endl;
    }
    void Save(ofstream& file) override {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }
    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

// ===== MAIN =====
int main() {
    cout << "=== Встреча 18 ===" << endl;
    Dog dog("Бобик", 3, "Овчарка");
    Cat cat("Мурка", 2, "Рыжий");
    Parrot parrot("Кеша", 1, "Привет");
    dog.show();
    cat.show();
    parrot.show();

    String s1("Hello");
    String s2("World");
    String s3 = s1 + " " + s2;
    cout << "Строка: " << s3 << endl;

    cout << "\n=== Встреча 19 ===" << endl;
    DomesticDog myDog("Шарик", 4);
    myDog.speak();

    Child2<int, double, char, string, bool, float> child2(1, 2.5, 'A', "test", true, 3.14f);
    child2.show();

    cout << "\n=== Встреча 20 ===" << endl;
    FileHandler* f1 = new FileHandler();
    FileHandler* f2 = new ASCIIDisplay();
    FileHandler* f3 = new BinaryDisplay();

    // Создаем тестовый файл
    ofstream test("test.txt");
    test << "ABC";
    test.close();

    cout << "Обычный вывод: ";
    f1->Display("test.txt");
    cout << "ASCII вывод: ";
    f2->Display("test.txt");
    cout << "Бинарный вывод: ";
    f3->Display("test.txt");

    delete f1;
    delete f2;
    delete f3;

    cout << "\n=== Встреча 21 ===" << endl;
    Equation* eq1 = new LinearEquation(2, 4);
    Equation* eq2 = new QuadraticEquation(1, -3, 2);
    eq1->findRoots();
    eq2->findRoots();
    delete eq1;
    delete eq2;

    vector<Shape*> shapes;
    shapes.push_back(new Square(10, 10, 5));
    shapes.push_back(new Rectangle(20, 20, 4, 6));
    shapes.push_back(new Circle(30, 30, 3));
    shapes.push_back(new Ellipse(40, 40, 5, 3));

    ofstream file("shapes.txt");
    for (auto shape : shapes) {
        shape->Save(file);
    }
    file.close();

    cout << "\nСохраненные фигуры:" << endl;
    for (auto shape : shapes) {
        shape->Show();
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}