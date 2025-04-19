#include <iostream>
#include <string>

using namespace std;

class MyAddress {
protected:
    string tinh;
    string huyen;
public:
    MyAddress(string t = "", string h = "") : tinh(t), huyen(h) {}
    virtual ~MyAddress() {}
    virtual void nhap() {
        cout << "Nhap tinh: ";
        cin.ignore();
        getline(cin, tinh);
        cout << "Nhap huyen: ";
        getline(cin, huyen);
    }
    virtual void hienThi() const {
        cout << "Tinh: " << tinh << endl;
        cout << "Huyen: " << huyen << endl;
    }
};

class Person : public MyAddress {
protected:
    string name;
    string phone;
public:
    Person(string t = "", string h = "", string n = "", string p = "")
        : MyAddress(t, h), name(n), phone(p) {}
    virtual ~Person() {}
    virtual void nhap() {
        MyAddress::nhap();
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
    }
    virtual void hienThi() {
        MyAddress::hienThi();
        cout << "Ten: " << name << endl;
        cout << "So dien thoai: " << phone << endl;
    }
};

class Officer : public Person {
private:
    float salary;
public:
    Officer(string t = "", string h = "", string n = "", string p = "", float s = 0.0)
        : Person(t, h, n, p), salary(s) {}
    void nhap() {
        Person::nhap();
        cout << "Nhap luong: ";
        cin >> salary;
    }
    void hienThi() {
        Person::hienThi();
        cout << "Luong: " << salary << endl;
    }
    bool operator>(const Officer& other) const {
        return salary > other.salary;
    }
};

int main() {
    Officer* officers[4];

    for (int i = 0; i < 4; ++i) {
        cout << "\nNhap thong tin can bo thu " << i + 1 << ":\n";
        officers[i] = new Officer();
        officers[i]->nhap();
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (*officers[i] > *officers[j]) {
                Officer* temp = officers[i];
                officers[i] = officers[j];
                officers[j] = temp;
            }
        }
    }

    cout << "\nDanh sach can bo sau khi sap xep tang dan theo luong:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "\nCan bo thu " << i + 1 << ":\n";
        officers[i]->hienThi();
        delete officers[i];
    }

    return 0;
}

