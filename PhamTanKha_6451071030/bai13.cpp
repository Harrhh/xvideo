#include <iostream>
using namespace std;

class Printer {
protected:
    string Sohieu;
    int Soluong;
public:
    Printer(string sh = "", int sl = 0) : Sohieu(sh), Soluong(sl) {}

    void Nhapkho(int q) {
        Soluong += q;
    }

    void Xuatkho(int q) {
        if (Soluong >= q) {
            Soluong -= q;
        } else {
            cout << "Khong du so luong de xuat kho!" << endl;
        }
    }

    void display() const {
        cout << "So hieu: " << Sohieu << endl;
        cout << "So luong: " << Soluong << endl;
    }
};

class Laser : public Printer {
protected:
    int dpi;
public:
    Laser(string sh = "", int sl = 0, int d = 0) : Printer(sh, sl), dpi(d) {}

    void display() const {
        Printer::display();
        cout << "DPI: " << dpi << endl;
    }
};

class ColorLaser : public Laser {
private:
    int Somau;
public:
    ColorLaser(string sh = "", int sl = 0, int d = 0, int sm = 0) : Laser(sh, sl, d), Somau(sm) {}

    void display() const {
        Laser::display();
        cout << "So mau: " << Somau << endl;
    }
};

int main() {
    ColorLaser printer1, printer2;

    string sohieu1;
    int soluong1, dpi1, somau1;
    cout << "Nhap thong tin cho may in Laser mau 1:" << endl;
    cout << "Nhap so hieu: ";
    cin >> sohieu1;
    cout << "Nhap so luong: ";
    cin >> soluong1;
    cout << "Nhap DPI: ";
    cin >> dpi1;
    cout << "Nhap so mau: ";
    cin >> somau1;
    printer1 = ColorLaser(sohieu1, soluong1, dpi1, somau1);

    string sohieu2;
    int soluong2, dpi2, somau2;
    cout << "\nNhap thong tin cho may in Laser mau 2:" << endl;
    cout << "Nhap so hieu: ";
    cin >> sohieu2;
    cout << "Nhap so luong: ";
    cin >> soluong2;
    cout << "Nhap DPI: ";
    cin >> dpi2;
    cout << "Nhap so mau: ";
    cin >> somau2;
    printer2 = ColorLaser(sohieu2, soluong2, dpi2, somau2);

    cout << "\nThong tin may in Laser mau 1:" << endl;
    printer1.display();
    cout << "\nThong tin may in Laser mau 2:" << endl;
    printer2.display();

    return 0;
}

