#include <iostream>
#include <string>

using namespace std;

class Printer {
protected:
    string name;
    int soluong;
public:
    Printer(string n = "", int sl = 0) : name(n), soluong(sl) {}
    void nhapkho(int q) {
        soluong += q;
        cout << "Da nhap " << q << " vao kho. Tong so luong: " << soluong << endl;
    }
    void xuatkho(int q) {
        if (q > soluong) {
            cout << "Khong du so luong trong kho de xuat!" << endl;
        } else {
            soluong -= q;
            cout << "Da xuat " << q << " khoi kho. Tong so luong con lai: " << soluong << endl;
        }
    }
    void hienThi() const {
        cout << "Ten may in: " << name << endl;
        cout << "So luong trong kho: " << soluong << endl;
    }
};

class Laser : virtual public Printer {
protected:
    int dpi;
public:
    Laser(string n = "", int sl = 0, int d = 0) : Printer(n, sl), dpi(d) {}
    void hienThi() {
        Printer::hienThi();
        cout << "Do phan giai DPI: " << dpi << endl;
    }
};

class ColorPrinter : virtual public Printer {
protected:
    string color;
public:
    ColorPrinter(string n = "", int sl = 0, string c = "") : Printer(n, sl), color(c) {}
    void hienThi() {
        Printer::hienThi();
        cout << "Loai mau: " << color << endl;
    }
};

class ColorLaser : public Laser, public ColorPrinter {
public:
    ColorLaser(string n = "", int sl = 0, int d = 0, string c = "")
        : Printer(n, sl), Laser(n, sl, d), ColorPrinter(n, sl, c) {}
    void hienThi() {
        Printer::hienThi();
        cout << "Do phan giai DPI: " << dpi << endl;
        cout << "Loai mau: " << color << endl;
    }
};

int main() {
    ColorLaser printers[3] = {
        ColorLaser("ColorLaser A", 10, 1200, "CMYK"),
        ColorLaser("ColorLaser B", 5, 600, "RGB"),
        ColorLaser("ColorLaser C", 8, 2400, "CMYK")
    };

    for (int i = 0; i < 3; ++i) {
        cout << "\nThong tin may in thu " << i + 1 << ":\n";
        printers[i].hienThi();

        cout << "Nhap kho 5 may in.\n";
        printers[i].nhapkho(5);

        cout << "Xuat kho 3 may in.\n";
        printers[i].xuatkho(3);

        cout << "Thong tin cap nhat cua may in:\n";
        printers[i].hienThi();
    }

    return 0;
}

