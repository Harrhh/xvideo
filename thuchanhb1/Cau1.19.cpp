#include <iostream>
using namespace std;

class PS {
private:
    int tu, mau;

public:
    PS() : tu(0), mau(1) {}

    PS(int x, int y) : tu(x), mau(y) {}

    void input() {
        cout << "Nhap vao tu: ";
        cin >> tu;
        cout << "Nhap vao mau: ";
        cin >> mau;
        while (mau == 0) {
            cout << "Mau so phai khac 0. Nhap lai mau: ";
            cin >> mau;
        }
    }

    void display() const {
        cout << tu << "/" << mau << endl;
    }

    bool operator>=(const PS& other) const {
        return (this->tu * other.mau) >= (other.tu * this->mau);
    }
};

int main() {
    PS arr[5];
    PS max_ps;

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ": \n";
        arr[i].input();
    }

    max_ps = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] >= max_ps) {
            max_ps = arr[i];
        }
    }

    cout << "Phan so lon nhat la: ";
    max_ps.display();

    return 0;
}
