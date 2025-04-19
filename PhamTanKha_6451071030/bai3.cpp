#include <iostream>
using namespace std;

class SV {
    string lop;
    string Hoten;
public:
    SV() {
        lop = "";
        Hoten = "";
    }
    SV(string lop, string Hoten) {
        this->lop = lop;
        this->Hoten = Hoten;
    }
    virtual ~SV() {}

    string getLop() {
        return lop;
    }
    string getHoten() {
        return Hoten;
    }
    void setLop(string lop) {
        this->lop = lop;
    }
    void setHoten(string Hoten) {
        this->Hoten = Hoten;
    }
    virtual void show() {
        cout << "Ho ten cua sinh vien nay la: " << Hoten << endl;
        cout << "Lop ma sinh vien theo hoc la: " << lop << endl;
    }
};

class SVSP : public SV {
    float Dtb;
    bool Hocbong;
public:
    SVSP() : SV() {
        Dtb = 0;
        Hocbong = false;
    }

    SVSP(string lop, string Hoten, float Dtb, bool Hocbong) : SV(lop, Hoten) {
        this->Dtb = Dtb;
        this->Hocbong = Hocbong;
    }

    float getDtb() {
        return Dtb;
    }
    bool getHocbong() {
        return Hocbong;
    }
    void setDtb(float Dtb) {
        this->Dtb = Dtb;
    }
    void setHocbong(bool Hocbong) {
        this->Hocbong = Hocbong;
    }

    void show() override {
        SV::show();
        cout << "Diem trung binh cua sinh vien la: " << Dtb << endl;
        if (!Hocbong) {
            cout << "Sinh vien nay khong co hoc bong" << endl;
        } else {
            cout << "Sinh vien nay co hoc bong" << endl;
        }
    }
};

class SVCN : public SVSP {
    float Hocphi;
public:
    SVCN() : SVSP() {
        Hocphi = 0;
    }

    SVCN(string lop, string Hoten, float Dtb, bool Hocbong, float Hocphi) 
        : SVSP(lop, Hoten, Dtb, Hocbong) {
        this->Hocphi = Hocphi;
    }

    float getHocphi() {
        return Hocphi;
    }
    void setHocphi(float Hocphi) {
        this->Hocphi = Hocphi;
    }

    void show() override {
        SVSP::show();
        cout << "Hoc phi cua sinh vien nay la: " << Hocphi << endl;
    }
};

int main() {
    SVCN sv[3] = {
        SVCN("12A", "Nguyen Van A", 8.5, true, 15000),
        SVCN("12B", "Tran Thi B", 7.2, false, 20000),
        SVCN("12C", "Le Van C", 9.0, true, 10000)
    };
    for (int i = 0; i < 3; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << ":" << endl;
        sv[i].show();
        cout << endl;
    }

    return 0;
}

