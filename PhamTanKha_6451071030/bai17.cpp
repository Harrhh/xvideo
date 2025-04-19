#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string soHieu;      
    int soLuongKho;     
public:
    Printer() : soHieu(""), soLuongKho(0) {}

    Printer(string soHieu, int soLuongKho) {
        this->soHieu = soHieu;
        this->soLuongKho = soLuongKho;
    }

    void nhapkho(int q) {
        soLuongKho += q;
        cout << "Da nhap vao kho " << q << " may in. Tong so luong hien tai: " << soLuongKho << endl;
    }

    void xuatkho(int q) {
        if (q > soLuongKho) {
            cout << "Khong du so luong trong kho de xuat!" << endl;
        } else {
            soLuongKho -= q;
            cout << "Da xuat kho " << q << " may in. Tong so luong con lai: " << soLuongKho << endl;
        }
    }

    virtual void show() {
        cout << "So hieu: " << soHieu << ", So luong trong kho: " << soLuongKho << endl;
    }
};

class Laser : virtual public Printer {
protected:
    int Dpi;
public:
    Laser() : Printer(), Dpi(0) {}

    Laser(string soHieu, int soLuongKho, int Dpi) : Printer(soHieu, soLuongKho) {
        this->Dpi = Dpi;
    }

    void show() override {
        Printer::show();
        cout << "Dpi: " << Dpi << endl;
    }
};

class ColorPrinter : virtual public Printer {
protected:
    string Color;
public:
    ColorPrinter() : Printer(), Color("") {}

    ColorPrinter(string soHieu, int soLuongKho, string Color) : Printer(soHieu, soLuongKho) {
        this->Color = Color;
    }

    void show() override {
        Printer::show();
        cout << "Color: " << Color << endl;
    }
};

class ColorLaser : public Laser, public ColorPrinter {
public:
    ColorLaser() : Printer(), Laser(), ColorPrinter() {}

    ColorLaser(string soHieu, int soLuongKho, int Dpi, string Color)
        : Printer(soHieu, soLuongKho), Laser(soHieu, soLuongKho, Dpi), ColorPrinter(soHieu, soLuongKho, Color) {}

    void show() override {
        Printer::show();
        cout << "Dpi: " << Dpi << endl;
        cout << "Color: " << Color << endl;
    }
};

int main() {
    ColorLaser cl1("CL123", 10, 1200, "RGB");
    ColorLaser cl2("CL456", 5, 600, "CMYK");
    ColorLaser cl3("CL789", 15, 2400, "RGB+");

    cout << "Thong tin ban dau cua cac may in ColorLaser:" << endl;
    cl1.show();
    cout << endl;
    cl2.show();
    cout << endl;
    cl3.show();
    cout << endl;

    cout << "Nhap kho cho cl1 va xuat kho cho cl2:" << endl;
    cl1.nhapkho(5);
    cl2.xuatkho(3);

    cout << "\nThong tin sau khi nhap/xuat kho:" << endl;
    cl1.show();
    cout << endl;
    cl2.show();
    cout << endl;
    cl3.show();
    cout << endl;

    return 0;
}

