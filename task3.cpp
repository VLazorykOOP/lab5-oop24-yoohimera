#include <iostream>
#include <string>
using namespace std;

// Базовий клас Point — координати точки
class Point {
protected:
    int x, y;

public:
    // Конструктор
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Копіювальний конструктор
    Point(const Point& other) : x(other.x), y(other.y) {}

    // Оператор присвоювання
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    // Вивід у потік
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    // Введення з потоку
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
};

// Похідний клас ColorPoint — координати + колір
class ColorPoint : public Point {
private:
    string color;

public:
    // Конструктор
    ColorPoint(int x = 0, int y = 0, string c = "black") : Point(x, y), color(c) {}

    // Копіювальний конструктор
    ColorPoint(const ColorPoint& other) : Point(other), color(other.color) {}

    // Оператор присвоювання
    ColorPoint& operator=(const ColorPoint& other) {
        if (this != &other) {
            Point::operator=(other); // виклик базового присвоювання
            color = other.color;
        }
        return *this;
    }

    // Вивід у потік
    friend ostream& operator<<(ostream& out, const ColorPoint& cp) ;

    // Введення з потоку
    friend istream& operator>>(istream& in, ColorPoint& cp) ;
};
 ostream& operator<<(ostream& out, const ColorPoint& cp) {
        out << "(" << cp.x << ", " << cp.y << ", " << cp.color << ")";
        return out;
    }

    // Введення з потоку
    istream& operator>>(istream& in, ColorPoint& cp) {
        in >> cp.x >> cp.y >> cp.color;
        return in;
    }
// Головна функція
int main() {
    ColorPoint a(5, 10, "red");    // створення об'єкта
    ColorPoint b;                  // порожній об'єкт

    cout << "Initial point A: " << a << endl;

    // Копіювання через оператор =
    b = a;
    cout << "Copied to point B: " << b << endl;

    // Ввід користувача
    cout << "Enter new color point (x y color): ";
    cin >> b;

    cout << "Updated point B: " << b << endl;

    return 0;
}
