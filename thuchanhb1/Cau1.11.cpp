#include <iostream>
using namespace std;

class PS {
private:
    int tu, mau;

public:
    PS() : tu(0), mau(1) {}

    PS(int x, int y) : tu(x), mau(y) {}

    void input() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        while (mau == 0) {
            cout << "Mau so phai khac 0. Nhap lai mau so: ";
            cin >> mau;
        }
    }

    void print() const {
        cout << tu << "/" << mau << endl;
    }

    static int UCLN(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void rutGon() {
        int ucln = UCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

    void setFraction(int x, int y) {
        tu = x;
        mau = y;
        if (mau == 0) {
            cout << "Mau so khong the bang 0. Doi mau so thanh 1." << endl;
            mau = 1;
        }
    }
};

int main() {
    PS arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        arr[i].input();
        arr[i].rutGon();
    }

    cout << "\nDanh sach phan so sau khi rut gon:" << endl;
    for (int i = 0; i < 5; i++) {
        arr[i].print();
    }

    return 0;
}
