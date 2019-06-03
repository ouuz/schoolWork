#include <iostream>
using namespace std;

class A
{
public:
	int m;
	int *p = &m;
	void show()
	{
		cout << m << endl;
	}
};

int main()
{
	A A1;
	*A1.p = 5;  
	//A1.*p = 5;  
	A1.show();
}
