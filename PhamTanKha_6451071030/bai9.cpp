#include<iostream>
using namespace std;
class Mycolor{
	protected:
		int Color;
	public:
		Mycolor() : Color(0){}
		Mycolor(int Color) : Color(Color){}
		virtual ~Mycolor(){}
		void setColor(int color) {
        this->Color = color;
    	}
		void display(){
			cout<<"Color: "<<Color<<endl;
		}
};
class Point{
	protected:
		int x;
		int y;
	public:
		Point() : x(0),y(0){}
		Point(int x,int y) : x(x),y(y){}
		virtual ~Point(){}
		virtual void move(float dx, float dy) {
	        x += dx;
	        y += dy;
    	}
		void setPoint(float x, float y) {
	        this->x = x;
	        this->y = y;
    	}

    	virtual void displayPoint() const {
        	cout << "(" << x << ", " << y << ")";
    	}
};
class Triangle : public Mycolor{
	private:
		Point A,B,C;
	public:
		Triangle() : Mycolor(),A(),B(),C(){}
		Triangle(int x1,int y1,int x2,int y2,int x3,int y3,int color) : Mycolor(color), A(x1, y1), B(x2, y2), C(x3, y3) {}
		void setTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int color){
			A.setPoint(x1,y1);
			B.setPoint(x2,y2);
			C.setPoint(x3,y3);
			setColor(color);
		}
		void move(float dx, float dy) {
	        A.move(dx, dy);
	        B.move(dx, dy);
	        C.move(dx, dy);
    }

    	void displayTriangle() {
	        cout << "Toa do cac dinh tam giac: ";
	        A.displayPoint();
	        cout << " - ";
	        B.displayPoint();
	        cout << " - ";
	        C.displayPoint();
	        cout << endl;
	        Mycolor::display();
    	}
};

int main() {
	int x1, y1, x2, y2, x3, y3, dx, dy;
    int k;

    cout << "Nhap toa do 3 dinh tam giac (x1, y1), (x2, y2), (x3, y3):\n";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << "Nhap tinh tien (dx, dy):\n";
    cin >> dx >> dy;

    cout << "Nhap so hieu mau (k):\n";
    cin >> k;

    Triangle t;
    t.setTriangle(x1, y1, x2, y2, x3, y3, k);

    cout << "Tam giac truoc khi tinh tien:\n";
    t.displayTriangle();

    t.move(dx, dy);

    cout << "Tam giac sau khi tinh tien:\n";
    t.displayTriangle();

    return 0;
}
