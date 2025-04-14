#include<iostream>
using namespace std;
class Mytime{
    private:
    int gio;
    int phut;
    int giay;
    public:
    Mytime();
    Mytime(int gio, int phut, int giay);
    Mytime(const Mytime &mt);
    ~Mytime();
    friend istream &operator>>(istream &is, Mytime &mt);
    friend ostream &operator<<(ostream &os, const Mytime &mt);
    friend int operator>=(const Mytime &a, const Mytime &b);
};
Mytime::Mytime(){
    gio=0;
    phut=0;
    giay=0;
}
Mytime::Mytime(int x, int y, int z){
    gio=x;
    phut=y;
    giay=z;
}
Mytime::Mytime(const Mytime &mt){
    gio=mt.gio;
    phut=mt.phut;
    giay=mt.giay;
}
Mytime::~Mytime(){

}
istream &operator>>(istream &is, Mytime &mt){
    cout<<"Nhap gio: "<<endl;
    is>>mt.gio;
    cout<<"Nhap phut: "<<endl;
    is>>mt.phut;
    cout<<"Nhap giay: "<<endl;
    is>>mt.giay;
    return is;
}
ostream &operator<<(ostream &os, const Mytime &mt){
    os<<mt.gio<<"-"<<mt.phut<<"-"<<mt.giay<<endl;
    return os;
}
int operator >=(const Mytime &a, const Mytime &b){
    if(a.giay>b.giay) return 1;
    else if(a.giay<b.giay) return 0;
        else return -1;
}
int main(){
    Mytime x,y;
    Mytime a[5];
    Mytime b;
    cout<<"Nhap x: "<<endl;
    cin>>x;
    cout<<x;

    cout<<"Nhap y: "<<endl;
    cin>>y;
    cout<<y;

    cout<<"So sanh hai doi tuong x va y: "<<endl;
    if(x>=y == 1){
        cout<<"X lon hon y."<<endl;
    }
    else if(x>=y == 0) {
        cout<<"Y lon hon x."<<endl;
    }
    else cout<<"X bang y."<<endl;

    for(int i=0; i<5;i++){
        cin>>a[i];
    }
    for(int i=0;i<5;i++){
        if((a[i]>=b)==1) b=a[i];
    }

    cout<<"Doi tuong co thoi gian lon nhat: "<<b<<endl;
}