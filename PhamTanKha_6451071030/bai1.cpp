#include <iostream>
#include <string>

using namespace std;

class MyAttr{
	private:
		int Attr;
	public:
		MyAttr(int a = 0) : Attr(a) {}
		void hienThi() {
			cout << "So hieu thuoc tinh: " << Attr << endl;
		}
		void setAttr(int a) {
        Attr = a;
    }
};

class Mydate{
	private:
		int ngay, thang, nam;
	public:
		Mydate(int d = 1, int m = 1, int y = 2000) : ngay(d), thang(m), nam(y) {}
		bool operator > (Mydate &other) {
			if (nam != other.nam) 
				return nam > other.nam;
			if (thang != other.thang)
				return thang > other.thang;
			return ngay > other.ngay;
		}
		
		bool operator<(const Mydate& other) const {
	        if (nam != other.nam)
	            return nam < other.nam;
	        if (thang != other.thang)
	            return thang < other.thang;
	        return ngay < other.ngay;
	    }
	    
		void hienThiNgay(){
			cout << "Ngay: " << ngay << "-" << thang << "-" << nam << endl;
		}
		void setDate(int d, int m, int y) {
	        ngay = d;
	        thang = m;
	        nam = y;
	    }
};

class Myfile : public MyAttr, public Mydate{
	private:
		string filename;
		int filesize;
   	public:
		Myfile(string name = "", int size = 0, int attr = 0, int d = 1, int m = 1, int y = 2000)
        : MyAttr(attr), Mydate(d, m, y), filename(name), filesize(size) {}
        
        void setFile(string name, int size, int attr, int d, int m, int y) {
	        filename = name;
	        filesize = size;
	        setAttr(attr);
	        setDate(d, m, y);
	    }
	    
	    void hienThiFile() {
	        cout << "Ten tep: " << filename << endl;
	        cout << "Kich thuoc: " << filesize << " bytes" << endl;
	        hienThi();
	        hienThiNgay();
	    }
	    
};

int main() {
    Myfile* files[4];

    for (int i = 0; i < 1; ++i) {
    	cout << "\nNhap thong tin tep thu " << i+1 << ":\n"; 
        string name;
        int size, attr, day, month, year;
        cout << "Nhap ten tep: ";
        cin >> name;
        cout << "Nhap kich thuoc tep (bytes): ";
        cin >> size;
        cout << "Nhap so hieu thuoc tinh: ";
        cin >> attr;
        cout << "Nhap ngay thang nam: ";
        cin >> day >> month >> year;

        files[i] = new Myfile();
        files[i]->setFile(name, size, attr, day, month, year);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (*files[i] > *files[j]) {
                swap(files[i], files[j]);
            }
        }
    }

    cout << "\nDanh sach tep sau khi da sap xep:\n";
    for (int i = 0; i < 1; ++i) {
        files[i]->hienThiFile();
        cout << "--------------------\n";
        delete files[i];
    }

    return 0;
}
