#include <iostream>
using namespace std;
class A{
	int a;
	public:
	A(int i):a(i)
	{cout<<"A"<<a<<"  "<<endl; 
	 } 
};
class B:virtual public A{
	int b;
	public:
	B(int i,int j):A(i),b(j)
	{
	cout<<"B"<<b<<"  "<<endl; 
	 } 
};
class C:virtual public A{
	int c;
	public:
	C(int i,int j):A(i),c(j)
	{cout<<"C"<<c<<"  "<<endl; 
	 } 
};
class D:public C,public B{
	int d;
	public:
	D(int i,int j,int k):A(k),B(i,j),C(j,i)
	{cout<<"D"<<endl; 
	 } 
};
int main()
{
	D d(1,2,3);
	return 0;
}
