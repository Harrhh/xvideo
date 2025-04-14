#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    float midterm, final_exam;

public:
    Student() : name(""), midterm(0), final_exam(0) {}

    void input() {
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap diem ky 1 (diem thi giua ky): ";
        cin >> midterm;
        cout << "Nhap diem ky 2 (diem thi cuoi ky): ";
        cin >> final_exam;
    }

    void display() const {
        cout << "Sinh vien: " << name << "\nDiem ky 1: " << midterm << "\nDiem ky 2: " << final_exam << endl;
    }

    bool isPassed() const {
        float avg = (midterm + 2 * final_exam) / 3;
        return avg >= 5;
    }
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; ++i) {
        cout << "\nNhap thong tin cho sinh vien " << i + 1 << ":\n";
        students[i].input();
    }

    cout << "\nDanh sach sinh vien vua nhap:\n";
    for (int i = 0; i < 5; ++i) {
        students[i].display();
    }

    cout << "\nDanh sach sinh vien co diem trung binh >= 5:\n";
    for (int i = 0; i < 5; ++i) {
        if (students[i].isPassed()) {
            students[i].display();
        }
    }

    return 0;
}
