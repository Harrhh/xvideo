#include <iostream>
#include <string>

using namespace std;

class SV {
protected:
    string lop;
    string hoten;
public:
    SV(string l = "", string ht = "") : lop(l), hoten(ht) {}
    virtual ~SV() {}
    virtual void nhap() {
        cout << "Nhap lop: ";
        cin.ignore();
        getline(cin, lop);
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
    }
    virtual void hienThi() const {
        cout << "Lop: " << lop << endl;
        cout << "Ho ten: " << hoten << endl;
    }
};

class SVTC : public SV {
protected:
    float hocphi;
public:
    SVTC(string l = "", string ht = "", float hp = 0.0) : SV(l, ht), hocphi(hp) {}
    virtual void nhap() {
        SV::nhap();
        cout << "Nhap hoc phi: ";
        cin >> hocphi;
    }
    virtual void hienThi() {
        SV::hienThi();
        cout << "Hoc phi: " << hocphi << endl;
    }
};

class SVCN : public SVTC {
private:
    float dtb;
    float hocbong;
public:
    SVCN(string l = "", string ht = "", float hp = 0.0, float d = 0.0, float hb = 0.0)
        : SVTC(l, ht, hp), dtb(d), hocbong(hb) {}
    void nhap() {
        SVTC::nhap();
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
        cout << "Nhap hoc bong: ";
        cin >> hocbong;
    }
    void hienThi() {
        SVTC::hienThi();
        cout << "Diem trung binh: " << dtb << endl;
        cout << "Hoc bong: " << hocbong << endl;
    }
    bool operator>(const SVCN& other) const {
        return dtb > other.dtb;
    }
	    bool operator<(const SVCN& other) const {
	    return dtb < other.dtb;
	}
};

int main() {
    SVCN* svcns[3];

    for (int i = 0; i < 3; ++i) {
        cout << "\nNhap thong tin sinh vien cu nhan thu " << i + 1 << ":\n";
        svcns[i] = new SVCN();
        svcns[i]->nhap();
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (*svcns[i] < *svcns[j]) {
                SVCN* temp = svcns[i];
                svcns[i] = svcns[j];
                svcns[j] = temp;
            }
        }
    }

    cout << "\nDanh sach sinh vien cu nhan sau khi sap xep theo diem trung binh giam dan:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        svcns[i]->hienThi();
        delete svcns[i];
    }

    return 0;
}

