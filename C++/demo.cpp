#include <fstream>
#include <iostream>
using namespace std;
int main ()
{
	ifstream ifile("ff.txt");
	ofstream ofile("ff3.txt");
	char ch;
	while (ifile.get(ch))
	{
		ofile.put(ch);
		cout<<ch;
	}
		
	ifile.close();
	ofile.close();
 } 
