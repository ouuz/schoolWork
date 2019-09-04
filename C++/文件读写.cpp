#include <fstream>
#include <iostream>
using namespace std;
void ReadFile(char *s);
void Change(char *s1,char *s2);

int main ()
{
	ReadFile("ff.txt");
	Change("ff.txt","ff2.txt");
	ReadFile("ff2.txt");
	return 0;
}
void ReadFile(char *s)
{
	ifstream in(s);
	if(!in)
	{	
		cout<<"不能打开文件"<<endl;
		return; 
	}
	char ch;
	in.get(ch);
	while(in.get(ch))
		cout<<ch;
	cout<<"\n\n"; 
	in.close(); 
}

void Change(char *s1,char *s2)
{
	ifstream infile (s1);
	ofstream outfile (s2);
	if(   (!infile)  ||   (!outfile)  )
	{
		cout<<"不能打开文件"<<endl;
		return; 
	}
	char ch;
	while(infile.get(ch))
	{
		if(ch >= 97 && ch <= 122)
			outfile.put(ch-32);
		else
			outfile.put(ch);
	}

	infile.close();
	outfile.close();	
}
