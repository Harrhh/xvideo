#include <iostream>
#include <algorithm>
using namespace std;

class SV {
protected:
    string Lop;
    string Hoten;
public:
    SV() : Lop(""), Hoten("") {}
    SV(string lop, string hoten) : Lop(lop), Hoten(hoten) {}
    virtual ~SV() {}

    virtual void input() {
        cout << "Nhap lop: ";
        getline(cin, Lop);
        cout << "Nhap ho ten: ";
        getline(cin, Hoten);
    }

    virtual void display() const {
        cout << "Lop: " << Lop << endl;
        cout << "Ho ten: " << Hoten << endl;
    }
};

class SVTC : public SV {
protected:
    int Hocphi;
public:
    SVTC() : SV(), Hocphi(0) {}
    SVTC(string lop, string hoten, int hocphi) : SV(lop, hoten), Hocphi(hocphi) {}

    void input() override {
        SV::input();
        cout << "Nhap hoc phi: ";
        cin >> Hocphi;
        cin.ignore();
    }

    void display() const override {
        SV::display();
        cout << "Hoc phi: " << Hocphi << endl;
    }

    bool operator>(const SVTC& other) const {
        return Hocphi > other.Hocphi;
    }
};

class SVCN : public SVTC {
private:
    float Dtb;
    int Hocbong;
public:
    SVCN() : SVTC(), Dtb(0.0), Hocbong(0) {}
    SVCN(string lop, string hoten, int hocphi, float dtb, int hocbong)
        : SVTC(lop, hoten, hocphi), Dtb(dtb), Hocbong(hocbong) {}

    void input() override {
        SVTC::input();
        cout << "Nhap diem trung binh: ";
        cin >> Dtb;
        cout << "Nhap hoc bong: ";
        cin >> Hocbong;
        cin.ignore();
    }

    void display() const override {
        SVTC::display();
        cout << "Diem trung binh: " << Dtb << endl;
        cout << "Hoc bong: " << Hocbong << endl;
    }
};

bool compareHocphi(SVCN* a, SVCN* b) {
    return *a > *b;
}

int main() {
    SVCN* svcn[5];

    for (int i = 0; i < 5; i++) {
        svcn[i] = new SVCN();
        cout << "Nhap sinh vien " << i + 1 << ":" << endl;
        svcn[i]->input();
    }

    cout << "\nDanh sach sinh vien truoc khi sap xep:" << endl;
    for (int i = 0; i < 5; i++) {
        svcn[i]->display();
        cout << endl;
    }

    sort(svcn, svcn + 5, compareHocphi);

    cout << "\nDanh sach sinh vien sau khi sap xep:" << endl;
    for (int i = 0; i < 5; i++) {
        svcn[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        delete svcn[i];
    }

    return 0;
}

