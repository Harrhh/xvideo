#include<iostream>
using namespace std;
class Complex{
    private:
    float phanThuc, phanAo;
    public:
    Complex();
    Complex(float a, float b);
    Complex(const Complex &A);
    ~Complex();
    friend istream &operator>>(istream &is, Complex &sp);
    friend ostream &operator<<(ostream &os, const Complex &sp);
    Complex operator +(const Complex &a);
    Complex operator =(const Complex &b);
};
Complex::Complex(){
    phanThuc=0;
    phanAo=0;
}
Complex::Complex(float a, float b){
    phanThuc=a;
    phanAo=b;
}
Complex::Complex(const Complex &A){
    phanThuc=A.phanThuc;
    phanAo=A.phanAo;
}
Complex::~Complex(){

}
istream &operator>>(istream &is, Complex &sp){
    cout<<"Nhap so phuc:"<<endl;
    cout<<"Phan thuc= "; is>>sp.phanThuc;
    cout<<"Phan ao= "; is>>sp.phanAo;
    return is; 
}
ostream &operator<<(ostream &os, const Complex &sp){
    if(sp.phanAo>0){
        os<<sp.phanThuc<<"+"<<sp.phanAo<<"i"<<endl;
    }
    else{
        os<<sp.phanThuc<<sp.phanAo<<"i"<<endl;
    }
    return os;
}
Complex Complex::operator +(const Complex &a){
    Complex a1;
    a1.phanThuc=this->phanThuc+a.phanThuc;
    a1.phanAo=this->phanAo+a.phanAo;
    return a1;
}
Complex Complex::operator =(const Complex &b){
    this->phanThuc=b.phanThuc;
    this->phanAo=b.phanAo;
    return *this;
}

int main(){
    Complex a,b;
    Complex  c[50];
    Complex sp;
    int n;
    cout<<"Nhap so phuc a:"<<endl;
    cin>>a;
    cout<<a;

    cout<<"Nhap so phuc b:"<<endl;
    cin>>b;
    cout<<b;

    cout<<"Gia tri cua a khi gan a=b:"<<endl;
    a=b;
    cout<<a;

    cout<<"Nhap so luong so phuc: "<<endl;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>c[i];
        sp=sp+c[i];
    }
    cout<<"Tong cac so phuc: "<<endl;
    cout<<sp;
}


