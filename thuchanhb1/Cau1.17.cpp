#include <iostream>
using namespace std;

class Complex {
private:
    double a, b;

public:
    Complex() : a(0), b(0) {}

    Complex(double real, double imaginary) : a(real), b(imaginary) {}

    void input() {
        cout << "Nhap phan thuc: ";
        cin >> a;
        cout << "Nhap phan ao: ";
        cin >> b;
    }

    void display() const {
        if (b >= 0)
            cout << a << " + " << b << "i" << endl;
        else
            cout << a << " - " << -b << "i" << endl;
    }

    bool operator==(const Complex& other) const {
        return (a == other.a && b == other.b);
    }
};

int main() {
    int n;
    cout << "Nhap so luong so phuc: ";
    cin >> n;

    Complex* arr = new Complex[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhap so phuc " << i + 1 << ": \n";
        arr[i].input();
    }

    Complex x;
    cout << "Nhap so phuc can tim: \n";
    x.input();

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (x == arr[i]) {
            found = true;
            cout << "So phuc da nhap co trong mang tai vi tri " << i + 1 << endl;
            break;
        }
    }

    if (!found) {
        cout << "So phuc da nhap khong co trong mang." << endl;
    }

    delete[] arr;

    return 0;
}
