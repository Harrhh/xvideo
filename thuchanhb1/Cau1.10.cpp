#include <iostream>
#include <math.h>

using namespace std;

class vector
{
private:
    int n;
    int *v;

public:
    vector(int size) : n(size)
    {
        v = new int[n];
        for (int i = 0; i < n; i++)
            v[i] = 0;
    }
    vector(vector &a)
    {
        n = a.n;
        v = new int[n];
        for (int i = 0; i < n; i++)
            v[i] = a.v[i];
    }
    ~vector() {};
    void input()
    {
        // cout << "Nhap phan tu cua vector: ";
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }
    void output()
    {
        // cout << "Cac phan tu cua vector la: ";
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
    vector operator=(const vector &a)
    {
        delete[] v;
        n = a.n;
        v = new int[n];
        for (int i = 0; i < n; i++)
            v[i] = a.v[i];
        return *this;
    }
    friend vector operator+(vector &a, vector &b);
    bool operator==(vector a);
};
vector operator+(vector &a, vector &b)
{
    vector c(a.n);
    for (int i = 0; i < a.n; i++)
        c.v[i] = a.v[i] + b.v[i];
    return c;
}
bool vector::operator==(vector a)
{
    return a.n == n;
}
int main()
{
    int n, m;
    cout << "Nhap kick thuoc cua vector a: ";
    cin >> n;
    vector a(n);
    cout << "Nhap phan tu cua vector a: \n";
    a.input();
    cout << "Phan tu cua vector a: ";
    a.output();
    cout << endl;
    cout << "Nhap kick thuoc cua vector b: ";
    cin >> m;
    vector b(m);
    cout << "Nhap phan tu cua vector b: \n";
    b.input();
    cout << "Phan tu cua vector b: ";
    b.output();
    cout << endl;
    if (a == b)
    {
        vector tong = a + b;
        cout << "Tong hai vector la: ";
        tong.output();
    }
    else
        cout << "Hai vector a va b khong cong duoc voi nhau.";
    return 0;
}