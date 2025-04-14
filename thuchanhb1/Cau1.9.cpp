#include <iostream>
using namespace std;

class Mydate
{
private:
    int day, month, year;

public:
    Mydate(int d = 1, int m = 1, int y = 1999) : day(d), month(m), year(y) {}

    void input()
    {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    }

    void print()
    {
        cout << day << "-" << month << "-" << year;
    }
    bool operator>(const Mydate &d2);
    void sort(Mydate arr[], int n);
};

bool Mydate::operator>(const Mydate &d2)
{
    if (year > d2.year)
        return true;
    if (year == d2.year && month > d2.month)
        return true;
    if (year == d2.year && month == d2.month && day > d2.day)
        return true;
    return false;
}
void Mydate::sort(Mydate date[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (date[j] > date[j + 1])
                swap(date[j], date[j + 1]);
        }
    }
}
int main()
{
    int n;
    Mydate date[100], sort;
    cout << "So ngay muon nhap: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ngay thu " << i + 1 << ": \n";
        date[i].input();
    }

    cout << "\nCac ngay vua nhap truoc khi sap xep la:\n";
    for (int i = 0; i < n; i++)
    {
        date[i].print();
        cout << endl;
    }
    sort.sort(date, n);
    cout << "\nCac ngay sau khi sap xep la:\n";
    for (int i = 0; i < n; i++)
    {
        date[i].print();
        cout << endl;
    }

    return 0;
}