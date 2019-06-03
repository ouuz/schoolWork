#include <iostream>
using namespace std;
class Complex{		
	public:
	float real,imag;
		Complex(float r =0,float i =0){
			real = r;
			imag = i; 
		};
		
		friend 	Complex operator + (Complex p1,Complex p2); 
		
		friend 	Complex operator - (Complex &p1,Complex &p2); 
		
		Complex operator * (Complex &p2){
			Complex p;
			p.real = real * p2.real;
			p.imag = imag * p2.imag;
			return p;
		};
		
		Complex operator / (Complex &p2){
			Complex p;
			p.real = real / p2.real;
			p.imag = imag / p2.imag;
			return p;
		};
		
		friend Complex operator ++ (Complex &p);
		
		Complex operator ++ (int){
			Complex temp(*this);
			real++;
			imag++;
			return temp; 
		};
		
		void print (){
			if(imag > 0)
			cout<<real<<"+"<<imag<<"i"<<endl;
			else 
			cout<<real<<"-"<<imag<<"i"<<endl;
		}
}; 
Complex operator + (Complex p1,Complex p2){
	Complex p;
	p.real = p1.real + p2.real;
	p.imag = p1.imag + p2.imag;
	return p;
}
Complex operator - (Complex &p1,Complex &p2){
	Complex p;
	p.real = p1.real - p2.real;
	p.imag = p1.imag - p2.imag;
	return p;
}
Complex operator ++ (Complex &p){
		++p.real;
		++p.imag;
		return p;
} 
int main ()
{
	Complex A1(2.3,4.6), A2(3.6,2.8);
	Complex A3,A4,A5,A6;
	A3 = A1 + A2;
	A4 = A1 - A2;
	A5 = A1 * A2;
	A6 = A1 / A2;
	cout<<"A1=";
	A1.print();
	cout<<endl;"A2=";
	A2.print();
	cout<<endl;"A3 = A1 + A2=";
	A3.print();
	cout<<endl;"A4 = A1 - A2=";
	A4.print();	
	cout<<endl;"A5 = A1 * A2=";
	A5.print();
	cout<<endl;"A6 = A1 / A2=";
	A6.print();
	A3 = ++A1;
	cout<<endl<<"after A3 = ++A1"<<endl;
	cout<<"A1 = ";
	A1.print();
	cout<<"A3 = ";
	A3.print();
	A4 = A2 ++;
	cout<<endl<<"after A4 = A2++"<<endl;
	cout<<"A2 = ";
	A2.print();
	cout<<"A4 = ";
	A4.print();
	return 0;
	}	
