#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class MyAddress {
protected:
    string Tinh;
    string Huyen;
public:
    MyAddress() : Tinh(""), Huyen("") {}
    MyAddress(string tinh, string huyen) : Tinh(tinh), Huyen(huyen) {}
    virtual ~MyAddress() {}

    void input() {
        cout << "Nhap Tinh: ";
        getline(cin, Tinh);
        cout << "Nhap Huyen: ";
        getline(cin, Huyen);
    }

    void display() const {
        cout << "Tinh: " << Tinh << ", Huyen: " << Huyen << endl;
    }
};

class MyDate {
protected:
    int ngay, thang, nam;
public:
    MyDate() : ngay(0), thang(0), nam(0) {}
    MyDate(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}

    virtual ~MyDate() {}

    void input() {
        cout << "Nhap Ngay: ";
        cin >> ngay;
        cout << "Nhap Thang: ";
        cin >> thang;
        cout << "Nhap Nam: ";
        cin >> nam;
        cin.ignore();
    }

    void display() const {
        cout << "Ngay: " << ngay << "/" << thang << "/" << nam << endl;
    }

    bool operator>(const MyDate& other) const {
        if (nam != other.nam)
            return nam > other.nam;
        if (thang != other.thang)
            return thang > other.thang;
        return ngay > other.ngay;
    }
};

class Person : public MyDate, public MyAddress {
private:
    string Name;
    long Phone;
public:
    Person() : MyDate(), MyAddress(), Name(""), Phone(0) {}
    Person(string name, long phone, int ngay, int thang, int nam, string tinh, string huyen)
        : MyDate(ngay, thang, nam), MyAddress(tinh, huyen), Name(name), Phone(phone) {}

    void input() {
        cout << "Nhap Ten: ";
        getline(cin, Name);
        cout << "Nhap So Dien Thoai: ";
        cin >> Phone;
        cin.ignore();
        MyDate::input();
        MyAddress::input();
    }

    void display() const {
        cout << "Ten: " << Name << endl;
        cout << "So Dien Thoai: " << Phone << endl;
        MyDate::display();
        MyAddress::display();
    }
};

bool comparePerson(Person* a, Person* b) {
    return *a > *b;
}

int main() {
    Person* persons[4];

    for (int i = 0; i < 4; i++) {
        persons[i] = new Person();
        cout << "Nhap thong tin nguoi " << i + 1 << ": " << endl;
        persons[i]->input();
    }

    cout << "\nDanh sach thong tin nguoi truoc khi sap xep:" << endl;
    for (int i = 0; i < 4; i++) {
        persons[i]->display();
        cout << endl;
    }

    sort(persons, persons + 4, comparePerson);

    cout << "\nDanh sach thong tin nguoi sau khi sap xep:" << endl;
    for (int i = 0; i < 4; i++) {
        persons[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete persons[i];
    }

    return 0;
}

