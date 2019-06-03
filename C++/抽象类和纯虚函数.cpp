#include <iostream>
using namespace std;


class Container {
	protected:
		double radius;
		const double PI = 3.1415926;
	public:
		Container(double r) {
			radius = r;
		}
		virtual double area () =0;
		virtual double volume () =0;
		virtual void print () = 0;
};

class Cube:public Container{
	public:
		Cube(double s):Container(s){}
	double area(){
		return radius * radius *6;
	}
	double volume(){
		return radius * radius * radius;
	}
	void print(){
		cout<<"正方体的表面积为：";
		cout<<area()<<endl;
		cout<<"正方体的体积为：";
		cout<<volume()<<endl;
	}
};

class Sphere:public Container{
	public:
		Sphere(double r):Container(r){}
		
		double area(){
			return radius * PI *4;
		}
		
		double volume(){
			return radius * radius * radius * 3 / 4 * PI;
		}
		
		void print(){
				cout<<"球体的表面积为：";
				cout<<area()<<endl;
				cout<<"球体的体积为：";
				cout<<volume()<<endl;
		}
};

class Cylinder:public Container{
	protected:
		double	height;
	public:
	Cylinder(double h,double w):Container(w){
		height = h;
	}
	
	double area(){
		return (radius * height * 2 * PI ) + (radius  * 2 * PI );
	}
	
	double volume(){
		return radius  * 2 * PI *height;
	}
	void print(){
				cout<<"圆柱体的表面积为：";
				cout<<area()<<endl;
				cout<<"圆柱体的体积为：";
				cout<<volume()<<endl;
		}
};
int main()
{
	Container a;
	Container *p;
	Cube cube(2);
	Sphere sphere(2);
	Cylinder cylinder(2,3);
	
	p = &cube;
	cout<<p -> area()<<endl;
	cout<< p -> volume()<<endl;
	p -> print();
	
	p = &sphere;
	cout<<p -> area()<<endl;
	cout<< p -> volume()<<endl;
	p -> print();
	
	p = &cylinder;
	cout<<p -> area()<<endl;
	cout<< p -> volume()<<endl;
	p -> print(); 
	
	return 0; 
}










