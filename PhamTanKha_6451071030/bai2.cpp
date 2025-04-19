#include <iostream>
#include <string>

using namespace std;

class MyDate {
private:
    int day, month, year;
public:
    MyDate(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void displayDate() {
        cout << "Ngay: " << day << "-" << month << "-" << year << endl;
    }

    bool operator>(const MyDate& other) {
        if (year != other.year) return year > other.year;
        if (month != other.month) return month > other.month;
        return day > other.day;
    }

    bool operator<(const MyDate& other) {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

class Person : public MyDate {
private:
    string name;
    string address;
    string phone;
public:
    Person(string n = "", string addr = "", string ph = "", int d = 1, int m = 1, int y = 2000)
        : MyDate(d, m, y), name(n), address(addr), phone(ph) {}

    void setPerson(string n, string addr, string ph, int d, int m, int y) {
        name = n;
        address = addr;
        phone = ph;
        setDate(d, m, y);
    }

    void displayPerson() {
        cout << "Ten: " << name << endl;
        cout << "Dia chi: " << address << endl;
        cout << "so dien thoai: " << phone << endl;
        displayDate();
    }
};

class Officer : public Person {
private:
    float salary;
public:
    Officer(string n = "", string addr = "", string ph = "", float sal = 0.0, int d = 1, int m = 1, int y = 2000)
        : Person(n, addr, ph, d, m, y), salary(sal) {}

    void setOfficer(string n, string addr, string ph, float sal, int d, int m, int y) {
        setPerson(n, addr, ph, d, m, y);
        salary = sal;
    }

    void displayOfficer() {
        displayPerson();
        cout << "Luong: " << salary << endl;
    }
};

int main() {
    Officer* officers[4];

    for (int i = 0; i < 4; ++i) {
        string name, address, phone;
        float salary;
        int day, month, year;

        cout << "Nhap thong tin can bo thu " << i + 1 << ":\n";
        cout << "Ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Dia chi: ";
        getline(cin, address);
        cout << "So dien thoai: ";
        cin >> phone;
        cout << "Luong: ";
        cin >> salary;
        cout << "Ngay thang nam : ";
        cin >> day >> month >> year;

        officers[i] = new Officer(name, address, phone, salary, day, month, year);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (*officers[i] > *officers[j]) {
                swap(officers[i], officers[j]);
            }
        }
    }

    cout << "\nDanh sach can bo sau khi sap xep:\n";
    for (int i = 0; i < 4; ++i) {
        officers[i]->displayOfficer();
        cout << "--------------------\n";
        delete officers[i];
    }

    return 0;
