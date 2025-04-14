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
    void inPut();
    void outPut();
    friend Complex operator +(const Complex &M, const Complex &H);
    friend Complex operator -(const Complex &N, const Complex &K);
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
void Complex::inPut(){
    cout<<"Nhap so phuc: \n";
    cout<<"phanThuc=";  cin>>phanThuc;
    cout<<"phanAo="; cin>>phanAo;
}
void Complex::outPut(){
    if(phanAo > 0){
        cout<<phanThuc<<"+"<<phanAo<<"i"<<endl;
    }
    else{
        cout<<phanThuc<<phanAo<<"i"<<endl;
    }
    
}
Complex operator +(const Complex &M, const Complex &H){
    Complex M1;
    M1.phanThuc=M.phanThuc+H.phanThuc;
    M1.phanAo=M.phanAo+H.phanAo;
    return M1;
}
Complex operator -(const Complex &N, const Complex &K){
    Complex N1;
    N1.phanThuc=N.phanThuc-K.phanThuc;
    N1.phanAo=N.phanAo-K.phanAo;
    return N1;
}
int main(){
    Complex x,y,z;
    x.inPut();
    cout<<"So phuc x:"<<endl;
    x.outPut();

    y.inPut();
    cout<<"So phuc y:"<<endl;
    y.outPut();

    cout<<"Tong x+y:"<<endl;
    z=x+y;
    z.outPut();

    cout<<"Hieu x-y"<<endl;
    z=x-y;
    z.outPut();
}
