#include <iostream>
using namespace std;

class PS
{
private:
    int tu, mau;

public:
    PS() : tu(0), mau(1) {}
    PS(int x, int y) : tu(x), mau(y) {}
    ~PS() {}

    friend istream &operator>>(istream &is, PS &p)
    {
        cout << "Nhap vao tu: ";
        is >> p.tu;
        cout << "Nhap vao mau: ";
        is >> p.mau;
        while (p.mau == 0)
        {
            cout << "\nMau so phai khac 0";
            cout << "Nhap vao mau: ";
            is >> p.mau;
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, const PS &p)
    {
        os << p.tu << "/" << p.mau;
        return os;
    }
    void RutGon();  
    PS operator+(const PS &p);
    PS operator-(const PS &p);
    PS operator*(const PS &p);
    PS operator/(const PS &p);
};

int ucln(int a, int b)
{
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void PS::RutGon() 
{
    int gcd = ucln(tu, mau);
    tu /= gcd;
    mau /= gcd;
    
    if (mau == 1)
    {
        cout << tu; 
    }
    else
    {
        cout << tu << "/" << mau; 
    }
}

PS PS::operator+(const PS &p)
{
    int newTu = this->tu * p.mau + p.tu * this->mau;
    int newMau = this->mau * p.mau;
    PS result(newTu, newMau);
    result.RutGon(); 
    return result;
}

PS PS::operator-(const PS &p)
{
    int newTu = this->tu * p.mau - p.tu * this->mau;
    int newMau = this->mau * p.mau;
    PS result(newTu, newMau);
    result.RutGon();
    return result;
}

PS PS::operator*(const PS &p)
{
    int newTu = this->tu * p.tu;
    int newMau = this->mau * p.mau;
    PS result(newTu, newMau);
    result.RutGon(); 
    return result;
}

PS PS::operator/(const PS &p)
{
    int newTu = this->tu * p.mau;
    int newMau = this->mau * p.tu;
    PS result(newTu, newMau);
    result.RutGon(); 
    return result;
}

int main()
{
    int n;
    cout << "Nhap vao so luong phan so: ";
    cin >> n;
    PS *arr = new PS[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap vao phan so thu " << i+1 << " : \n";
        cin >> arr[i];
    }

    PS sum(0, 1);
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i]; 
    }

    cout << "\nTong cua cac phan so trong mang la: ";
    sum.RutGon(); 
    cout << endl;

    delete[] arr;
    return 0;
}
