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

    float tinhKhoangCach(Point& other) {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class Triangle : public MyColor {
private:
    Point A, B, C;
public:
    Triangle() {}

    void setTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int color) {
        A.setToaDo(x1, y1);
        B.setToaDo(x2, y2);
        C.setToaDo(x3, y3);
        setColor(color);
    }

    float tinhChuVi() {
        float AB = A.tinhKhoangCach(B);
        float BC = B.tinhKhoangCach(C);
        float CA = C.tinhKhoangCach(A);
        return AB + BC + CA;
    }

    void hienThi() {
        cout << "Dinh A: "; A.hienThiToaDo();
        cout << "Dinh B: "; B.hienThiToaDo();
        cout << "Dinh C: "; C.hienThiToaDo();
        cout << "Mau: "; hienThiColor();
        cout << "Chu vi: " << tinhChuVi() << endl;
    }

    bool operator>(Triangle& other) {
        return tinhChuVi() > other.tinhChuVi();
    }
};

int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    Triangle* triangles = new Triangle[n];

    for (int i = 0; i < n; i++) {
        float x1, y1, x2, y2, x3, y3;
        int color;
        cout << "\nNhap thong tin cho tam giac " << i + 1 << ":" << endl;
        cout << "Nhap toa do dinh A (x1, y1): ";
        cin >> x1 >> y1;
        cout << "Nhap toa do dinh B (x2, y2): ";
        cin >> x2 >> y2;
        cout << "Nhap toa do dinh C (x3, y3): ";
        cin >> x3 >> y3;
        cout << "Nhap so hieu mau: ";
        cin >> color;

        triangles[i].setTriangle(x1, y1, x2, y2, x3, y3, color);
    }

    cout << "\nThong tin tam giac:" << endl;
    for (int i = 0; i < n; i++) {
        triangles[i].hienThi();
    }

    Triangle largestTriangle = triangles[0];
    for (int i = 1; i < n; i++) {
        if (triangles[i] > largestTriangle) {
            largestTriangle = triangles[i];
        }
    }

    cout << "\nTam giac co chu vi lon nhat la:" << endl;
    largestTriangle.hienThi();

    delete[] triangles;

    return 0;
}

