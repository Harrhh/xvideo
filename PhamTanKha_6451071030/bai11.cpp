#include <iostream>
#include <cmath>
using namespace std;

class MyColor {
protected:
    int Color; 
public:
    MyColor() : Color(0) {}
    void setColor(int color) {
        Color = color;
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

    void setToaDo(float x_, float y_) {
        x = x_;
        y = y_;
    }

    void hienThiToaDo() {
        cout << "Toa do diem: (" << x << ", " << y << ")" << endl;
    }
};

class Circle : public MyColor {
private:
    Point O; 
    float r;  
public:
    Circle() : r(0) {}

    float tinhDienTich() {
        return M_PI * r * r;
    }

    void setCircle(float x_, float y_, float r_, int color_) {
        O.setToaDo(x_, y_);
        r = r_;
        setColor(color_);
    }

    void hienThi() {
        cout << "Dia chi tam: ";
        O.hienThiToaDo();
        cout << "Ban kinh: " << r << endl;
        cout << "Dien tich: " << tinhDienTich() << endl;
        hienThiColor();
    }

    bool operator>(Circle& other) {
        return tinhDienTich() > other.tinhDienTich();
    }
};

int main() {
    int n;
    cout << "Nhap so luong duong tron: ";
    cin >> n;

    Circle* circles = new Circle[n];

    for (int i = 0; i < n; i++) {
        float x, y, r;
        int color;
        cout << "\nNhap thong tin cho duong tron " << i + 1 << ":" << endl;
        cout << "Nhap toa do tam (x, y): ";
        cin >> x >> y;
        cout << "Nhap ban kinh: ";
        cin >> r;
        cout << "Nhap so hieu mau: ";
        cin >> color;

        circles[i].setCircle(x, y, r, color);
    }

    Circle largestCircle = circles[0];
    for (int i = 1; i < n; i++) {
        if (circles[i] > largestCircle) {
            largestCircle = circles[i];
        }
    }

    cout << "\nDuong tron co dien tich lon nhat la:" << endl;
    largestCircle.hienThi();

    delete[] circles;

    return 0;
}

