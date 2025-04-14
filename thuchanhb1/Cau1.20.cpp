#include <iostream>
using namespace std;

class Complex {
private:
    float a, b;

public:
    Complex() : a(0), b(0) {}

    Complex(float real, float imag) : a(real), b(imag) {}

    Complex(const Complex& other) : a(other.a), b(other.b) {}

    void input() {
        cout << "Nhap phan thuc: ";
        cin >> a;
        cout << "Nhap phan ao: ";
        cin >> b;
    }

    void display() const {
        if (b < 0) {
            cout << a << " - " << -b << "i" << endl;
        } else {
            cout << a << " + " << b << "i" << endl;
        }
    }

    Complex operator+(const Complex& other) const {
        return Complex(a + other.a, b + other.b);
    }

    Complex operator-(const Complex& other) const {
        return Complex(a - other.a, b - other.b);
    }
};

int main() {
    Complex x, y;

    cout << "Nhap du lieu cho so phuc x:\n";
    x.input();

    cout << "Nhap du lieu cho so phuc y:\n";
    y.input();

    Complex sum = x + y;
    Complex diff = x - y;

    cout << "Tong cua hai so phuc x va y la: ";
    sum.display();

    cout << "Hieu cua hai so phuc x va y la: ";
    diff.display();

    return 0;
}
