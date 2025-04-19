#include <iostream>
#include <cmath>
using namespace std;

class MyColor {
protected:
    int Color;
public:
    MyColor() : Color(0) {}

    void nhapColor() {
        cout << "Nhap so hieu mau: ";
        cin >> Color;
    }

    void hienThiColor() {
        cout << "So hieu mau: " << Color << endl;
    }
};

class Point {
protected:
    float x, y;

public:
    Point() : x(0), y(0) {}

    void nhapToaDo() {
        cout << "Nhap toa do diem (x, y): ";
        cin >> x >> y;
    }

    void hienThiToaDo() {
        cout << "Toa do diem: (" << x << ", " << y << ")" << endl;
    }

    float tinhKhoangCach(Point& p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

class Line : public MyColor {
private:
    Point A, B; 

public:
    void nhapDuLieu() {
        A.nhapToaDo();
        B.nhapToaDo();
        nhapColor();
    }

    float tinhKhoangCach() {
        return A.tinhKhoangCach(B);
    }

    void hienThi() {
        cout << "Toa do diem A: ";
        A.hienThiToaDo();
        cout << "Toa do diem B: ";
        B.hienThiToaDo();
        hienThiColor();
        cout << "Khoang cach giua A va B: " << tinhKhoangCach() << endl;
    }
};

int main() {

    Line line;
    line.nhapDuLieu();

    cout << "\nThong tin ve doan thang:" << endl;
    line.hienThi();

    return 0;
}

