#include <iostream>
using namespace std;

class phanSo
{
private:
    int tu, mau;

public:
    phanSo() {}
    phanSo(int tuSo, int mauSo) : tu(tuSo), mau(mauSo) {}
    void input()
    {
        cout << "Nhap tu so: ";
        cin >> tu;
        do
        {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
            if (mau == 0)
                cout << "Mau so khong hop le! Nhap lai." << endl;
        } while (mau == 0);
    }
    void output()
    {
        if (mau == 1)
            cout << tu;
        else if (tu == 0)
            cout << "0";
        else
            cout << tu << "/" << mau;
    }
    void rutGon();
    int ucln(int a, int b);
    bool operator>=(phanSo a);
    void sort(phanSo arr[], int n);
};
int phanSo::ucln(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a = a - b; 
        else
            b = b - a; 
    }
    return a; 
}
void phanSo::rutGon()
{
    int tmp = ucln(abs(tu), abs(mau));
    if (tu % tmp == 0 || mau % tmp == 0)
    {
        tu = tu / tmp;
        mau = mau / tmp;
    }
    else
        cout << "phan so da toi giai." << endl;
}
bool phanSo::operator>=(phanSo a)
{
    return tu * a.mau >= mau * a.tu;
}
int main()
{
    phanSo arr[5], PS;
    for (int i = 0; i < 5; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        arr[i].input();
    }
    cout << "Cac phan so da nhap la: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Phan so thu " << i + 1 << ": ";
        arr[i].output();
        cout << endl;
    }
    phanSo max = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] >= max)
            max = arr[i];
    }
    cout << "Phan so lon nhat la: ";
    max.output();
    cout << endl;
    phanSo min = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (!(arr[i] >= min))
            min = arr[i];
    }
    cout << "Phan so be nhat la: ";
    min.output();
    return 0;
}
