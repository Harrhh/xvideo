#include <iostream>
using namespace std;

class Vector {
private:
    int n;  
    int* v;  

public:
    Vector() : n(0), v(nullptr) {}

    Vector(int size) : n(size), v(new int[size]) {}

    Vector(const Vector& other) {
        n = other.n;
        v = new int[n];
        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }
    }

    ~Vector() {
        delete[] v;
    }

    void input() {
        cout << "Nhap " << n << " phan tu cho vector: ";
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
    }

    void display() const {
        cout << "Vector: ";
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        delete[] v;

        n = other.n;
        v = new int[n];
        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }

        return *this;
    }

    friend Vector operator+(const Vector& a, const Vector& b) {
        if (a.n != b.n) {
            cout << "Hai vector phai co so phan tu bang nhau!" << endl;
            exit(1);
        }

        Vector result(a.n);
        for (int i = 0; i < a.n; ++i) {
            result.v[i] = a.v[i] + b.v[i];
        }

        return result;
    }
};

int main() {
    int size;

    cout << "Nhap so phan tu cho vector a: ";
    cin >> size;
    Vector a(size);
    a.input();

    cout << "Nhap so phan tu cho vector b: ";
    cin >> size;
    Vector b(size);
    b.input();

    cout << "Vector a: ";
    a.display();

    cout << "Vector b: ";
    b.display();

    Vector c = a + b;
    cout << "Tong cua 2 vecto a va b la: ";
    c.display();

    return 0;
}
