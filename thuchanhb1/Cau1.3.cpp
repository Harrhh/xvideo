#include<iostream>
using namespace std;
class Mydate{
    private:
    int ngay;
    int thang;
    int nam;
    public:
    Mydate();
    Mydate(int ngay, int thang, int nam);
    Mydate(const Mydate &md);
    ~Mydate();
    friend istream &operator>>(istream &is, Mydate &md);
    friend ostream &operator<<(ostream &os, const Mydate &md);
    friend int operator>=(const Mydate &a, const Mydate &b);
};
Mydate::Mydate(){
    ngay=0;
    thang=0;
    nam=0;
}
Mydate::Mydate(int x, int y, int z){
    ngay=x;
    thang=y;
    nam=z;
}
Mydate::Mydate(const Mydate &md){
    ngay=md.ngay;
    thang=md.thang;
    nam=md.nam;
}
Mydate::~Mydate(){

}
istream &operator>>(istream &is, Mydate &md){
    cout<<"Nhap ngay: "<<endl;
    is>>md.ngay;
    cout<<"Nhap thang: "<<endl;
    is>>md.thang;
    cout<<"Nhap nam: "<<endl;
    is>>md.nam;
    return is;
}
ostream &operator<<(ostream &os, const Mydate &md){
    os<<md.ngay<<"-"<<md.thang<<"-"<<md.nam<<endl;
    return os;
}
int operator >=(const Mydate &a, const Mydate &b){
    if(a.nam>b.nam) return 1;
    else if(a.nam<b.nam) return 0;
        else return -1;
}
int main(){
    Mydate x,y;
    Mydate a[5];
    Mydate b;
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