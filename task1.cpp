#include <iostream>
using namespace std;

// Клас Pair — зберігає пару чисел
class Pair {
protected:
    double first;
    double second;

public:
    Pair(double a = 0, double b = 0) : first(a), second(b) {}

    void setFirst(double a) { first = a; }     // встановити перше число
    void setSecond(double b) { second = b; }   // встановити друге число

    double getFirst() const { return first; }  // отримати перше число
    double getSecond() const { return second; } // отримати друге число

    double getProduct() const { return first * second; } // добуток чисел
};

class Rectangle : public Pair {
public:
    Rectangle(double width = 0, double height = 0) : Pair(width, height) {}

    double getPerimeter() const { return 2 * (first + second); } // периметр
    double getArea() const { return first * second; }            // площа
};

int main() {
    Rectangle rect(5.0, 3.0); // створити прямокутник зі сторонами 5 і 3

    // Виведення результатів англійською (щоб не було проблем з кодуванням)
    cout << "Rectangle sides: " << rect.getFirst() << " and " << rect.getSecond() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;
    cout << "Area: " << rect.getArea() << endl;

    return 0;
}
