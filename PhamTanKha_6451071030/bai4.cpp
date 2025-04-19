#include <iostream>
using namespace std;

class Media {
protected:
    string ten;
    int gia;

public:
    Media() : ten(""), gia(0) {}
    Media(const string ten, int gia) : ten(ten), gia(gia) {}
    virtual ~Media() {}

    void input() {
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap gia: ";
        cin >> gia;
        cin.ignore(); 
    }

    void display() const {
        cout << "Ten: " << ten << endl;
        cout << "Gia: " << gia << endl;
    }
};

class Book : public Media {
private:
    int sotrang;
    string TG;

public:
    Book() : Media(), sotrang(0), TG("") {}
    Book(string ten, int gia, int sotrang, const string TG) : Media(ten, gia), sotrang(sotrang), TG(TG) {}
    ~Book() {}

    void input() {
        Media::input();
        cout << "Nhap so trang: ";
        cin >> sotrang;
        cin.ignore(); 
        cout << "Nhap ten tac gia: ";
        getline(cin, TG);
    }

    void display() {
        Media::display();
        cout << "So trang: " << sotrang << endl;
        cout << "Ten tac gia: " << TG << endl;
    }
};

class Video : public Media {
private:
    double thoigian;

public:
    Video() : Media(), thoigian(0) {}
    Video(string ten, int gia, double thoigian) : Media(ten, gia), thoigian(thoigian) {}
    ~Video() {}

    void input() {
        Media::input();
        cout << "Nhap thoi gian: ";
        cin >> thoigian;
    }

    void display() {
        Media::display();
        cout << "Thoi gian: " << thoigian << " phut" << endl;
    }
};

int main() {
    const int SIZE = 4; 
    Book* book[SIZE];
    Video* video[SIZE];

    for (int i = 0; i < SIZE; i++) {
        book[i] = new Book();
        video[i] = new Video();
    }

    cout << "Nhap du lieu cho sach:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Quyen sach thu " << i + 1 << ":\n";
        book[i]->input();
    }

    cout << "\nNhap du lieu cho video:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Video thu " << i + 1 << ":\n";
        video[i]->input();
    }

    cout << "\nDanh sach cac quyen sach:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Quyen sach thu " << i + 1 << ":\n";
        book[i]->display();
    }

    cout << "\nDanh sach cac video:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Video thu " << i + 1 << ":\n";
        video[i]->display();
    }

    for (int i = 0; i < SIZE; i++) {
        delete book[i];
        delete video[i];
    }

    return 0;
}

