#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string hoTen;
    float diemKy1, diemKy2, diemTB;

public:
    Student() : hoTen(""), diemKy1(0), diemKy2(0), diemTB(0) {}

    void input() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap diem ky 1: ";
        cin >> diemKy1;
        cout << "Nhap diem ky 2: ";
        cin >> diemKy2;
        diemTB = (diemKy1 + 2 * diemKy2) / 3;
    }

    void display() const {
        cout << hoTen << " - " << diemKy1 << " - " << diemKy2 << " - " << diemTB << endl;
    }

    bool operator>(const Student& other) const {
        return diemTB > other.diemTB;
    }

    float getDiemTB() const {
        return diemTB;
    }
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        students[i].input();
    }

    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < 5; ++i) {
        students[i].display();
    }

    sort(students, students + 5, [](const Student& a, const Student& b) {
        return a > b;
    });

    cout << "\nDanh sach sinh vien sau khi sap xep theo diem trung binh:\n";
    for (int i = 0; i < 5; ++i) {
        students[i].display();
    }

    return 0;
}
