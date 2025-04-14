#include <iostream>
using namespace std;

class Vector {
private:
    int n;
    float* v;

public:
    Vector() : n(0), v(nullptr) {}

    Vector(int size) : n(size), v(new float[size]) {}

    Vector(const Vector& other) {
        n = other.n;
        v = new float[n];
        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }
    }

    ~Vector() {
        delete[] v;
    }

    void setSize(int size) {
        n = size;
        v = new float[n];
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
        if (this == &other) return *this;

        delete[] v;

        n = other.n;
        v = new float[n];

        for (int i = 0; i < n; ++i) {
            v[i] = other.v[i];
        }
        return *this;
    }

    friend Vector operator*(float k, const Vector& vec) {
        Vector result(vec.n);
        for (int i = 0; i < vec.n; ++i) {
            result.v[i] = k * vec.v[i];
        }
        return result;
    }
};

int main() {
    int n;
    float k;
    cout << "Nhap so phan tu cho vector: ";
    cin >> n;
    Vector a(n);
    a.input();
    cout << "Nhap vao so thuc k: ";
    cin >> k;
    cout << "Vector a: ";
    a.display();

    Vector result = k * a;
    cout << "Vector k * a: ";
    result.display();

    return 0;
}
