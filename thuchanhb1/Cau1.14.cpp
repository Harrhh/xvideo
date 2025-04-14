#include <iostream>
using namespace std;

class Mydate {
private:
    int ngay, thang, nam;

public:
    Mydate() : ngay(0), thang(0), nam(0) {}

    void input() {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    void display() const {
        cout << ngay << "-" << thang << "-" << nam << endl;
    }

    bool operator==(const Mydate& other) const {
        return ngay == other.ngay && thang == other.thang && nam == other.nam;
    }
};

int main() {
    Mydate dates[5];
    Mydate x;

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap ngay, thang, nam cho date " << i + 1 << ":\n";
        dates[i].input();
    }

    cout << "\nDanh sach cac ngay trong mang:\n";
    for (int i = 0; i < 5; ++i) {
        dates[i].display();
    }

    cout << "\nNhap ngay, thang, nam cho date x:\n";
    x.input();

    bool found = false;
    for (int i = 0; i < 5; ++i) {
        if (x == dates[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\nNgay x co trong mang.\n";
    } else {
        cout << "\nNgay x khong co trong mang.\n";
    }

    return 0;
}
