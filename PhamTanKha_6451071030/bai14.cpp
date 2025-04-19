#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
protected:
    int hour, minute, second;
public:
    MyTime() : hour(0), minute(0), second(0) {}

    bool isValidTime() {
        return (hour >= 0 && hour < 24) && (minute >= 0 && minute < 60) && (second >= 0 && second < 60);
    }

    void inputTime() {
        do {
            cout << "Nhap gio (0-23): ";
            cin >> hour;
            cout << "Nhap phut (0-59): ";
            cin >> minute;
            cout << "Nhap giay (0-59): ";
            cin >> second;
            if (!isValidTime()) {
                cout << "Thong tin gio, phut, giay khong hop le. Vui long nhap lai.\n";
            }
        } while (!isValidTime());
    }

    void displayTime() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << endl;
    }
};

class MyDate {
protected:
    int day, month, year;
public:
    MyDate() : day(1), month(1), year(1900) {}

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValidDate() {
        if (month < 1 || month > 12) return false;

        int daysInMonth;
        switch (month) {
            case 2: 
                daysInMonth = isLeapYear() ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11: 
                daysInMonth = 30;
                break;
            default: 
                daysInMonth = 31;
        }
        return (day >= 1 && day <= daysInMonth);
    }

    void inputDate() {
        do {
            cout << "Nhap ngay (1-31): ";
            cin >> day;
            cout << "Nhap thang (1-12): ";
            cin >> month;
            cout << "Nhap nam (>= 1): ";
            cin >> year;
            if (!isValidDate()) {
                cout << "Thong tin ngay, thang, nam khong hop le. Vui long nhap lai.\n";
            }
        } while (!isValidDate());
    }

    void displayDate() {
        cout << day << "-" << month << "-" << year << " ";
    }
};

class DateTime : public MyDate, public MyTime {
public:
    DateTime() {}

    void inputDateTime() {
        inputDate();
        inputTime();
    }

    void displayDateTime() {
        displayDate();
        displayTime();
    }
};

int main() {
    DateTime dt[3];

    for (int i = 0; i < 3; i++) {
        cout << "Nhap thong tin cho DateTime " << i + 1 << ":\n";
        dt[i].inputDateTime();
        cout << "Thong tin DateTime " << i + 1 << " la: ";
        dt[i].displayDateTime();
    }

    return 0;
}

