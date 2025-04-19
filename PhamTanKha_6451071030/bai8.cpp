#include<iostream>
#include<string>
using namespace std;

class MyTime {
protected:
    int hour, minute, second;
public:
    MyTime() : hour(0), minute(0), second(0) {}
    void input() {
        cout << "Nhap gio: ";
        cin >> hour;
        cout << "Nhap phut: ";
        cin >> minute;
        cout << "Nhap giay: ";
        cin >> second;
    }
    void display() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

class MyDate {
protected:
    int day, month, year;
public:
    MyDate() : day(0), month(0), year(0) {}
    void input() {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    }
    void display() const {
        cout << day << "-" << month << "-" << year << endl;
    }
};

class MyFile : public MyTime, public MyDate {
private:
    string filename;
    int filesize;
public:
    MyFile() : filesize(0) {}
    
    void input() {
        cout << "Nhap ten tep: ";
        cin.ignore();
        getline(cin, filename);
        cout << "Nhap kich thuoc tep (bytes): ";
        cin >> filesize;
        MyDate::input();
        MyTime::input();
    }
    
    void display() const {
        cout << "Ten tep: " << filename << endl;
        cout << "Kich thuoc: " << filesize << " bytes" << endl;
        MyDate::display();
        MyTime::display();
    }

    bool operator>(const MyFile &other) const {
        return filesize > other.filesize;
    }

    bool operator<(const MyFile &other) const {
        return filesize < other.filesize;
    }
};

int main() {
    MyFile* files[5];
    for (int i = 0; i < 5; i++) {
        files[i] = new MyFile();
        cout << "Nhap du lieu cho tep " << i + 1 << ":" << endl;
        files[i]->input();
    }

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (*files[i] < *files[j]) { 
                swap(files[i], files[j]);
            }
        }
    }

    cout << "\nDanh sach tep sau khi sap xep theo kich thuoc (giam dan):" << endl;
    for (int i = 0; i < 5; i++) {
        files[i]->display();
    }

    for (int i = 0; i < 5; i++) {
        delete files[i];
    }

    return 0;
}

