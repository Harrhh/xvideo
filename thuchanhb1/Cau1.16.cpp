#include <iostream>
using namespace std;

class Fraction {
private:
    int tu, mau;

public:
    Fraction() : tu(0), mau(1) {}
    Fraction(int t, int m) : tu(t), mau(m) {
        if (mau == 0) {
            mau = 1;
        }
    }

    void display() const {
        cout << tu << "/" << mau << endl;
    }

    bool operator==(const Fraction& other) const {
        return (tu * other.mau == mau * other.tu);
    }

    void input() {
        cout << "Nhap tu so: ";
        cin >> tu;
        do {
            cout << "Nhap mau so: ";
            cin >> mau;
            if (mau == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai.\n";
            }
        } while (mau == 0);
    }
};

int main() {
    int n;

    cout << "Nhap so luong phan so: ";
    cin >> n;

    Fraction* arr = new Fraction[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so " << i + 1 << ": \n";
        arr[i].input();
    }

    Fraction x;
    cout << "Nhap phan so can tim: \n";
    x.input();

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (x == arr[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Phan so da nhap co trong mang." << endl;
    } else {
        cout << "Phan so da nhap khong co trong mang." << endl;
    }

    delete[] arr;

    return 0;
}
