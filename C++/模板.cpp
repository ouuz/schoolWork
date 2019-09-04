#include <iostream>
using namespace std;
template <class Type>
class Complex{		
	public:
		Type real,imag;
		Complex(Type r = 0,Type i = 0){
			real = r;
			imag = i;
		}
		friend 	Complex operator + (Complex p1,Complex p2); 
		friend  ostream& operator << (ostream &s, const Complex &c); 
		friend  istream& operator >> (ostream &s,  Complex &c); 
}; 
ostream& operator << (ostream &s, const Complex <float> &c){
	if(c.imag > 0)
			s<<c.real<<"+"<<c.imag<<"i"<<endl;
			else 
			s<<c.real<<c.imag<<"i"<<endl;
	return s;
}

Complex <float> operator + (Complex <float> p1,Complex <float> p2){
	Complex <float> p;
	p.real = p1.real + p2.real;
	p.imag = p1.imag + p2.imag;
	return p;
}
istream& operator >> (istream &s, Complex <float> &c){
   s>>c.real;
   s>>c.imag;
   return s; 
} 
int main ()
{
	Complex <float> A1(2.3,4.6);
	Complex <float> A2; 
	Complex <float> A3;
	cout<<"ÊäÈëA2"<<endl; 
	cin>>A2;
	A3 = A1 + A2;
	cout<<"A1=";
	cout<<A1;
	cout<<endl;"A2=";
	cout<<A2;
	cout<<endl;"A3 = A1 + A2=";
	cout<<A3;
	return 0;
}	
