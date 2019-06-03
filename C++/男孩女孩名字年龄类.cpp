#include <iostream>
#include <string>
using namespace std;
class Girl;
class Boy{
	private:
		int Age;
		string Name;
	public:
		Boy(string,int);
		~Boy();
		void Display();
		friend void VisitBoyGirl(Boy &, Girl &);
};
class Girl{
	private:
		int Age;
		string Name;
	public:
		Girl(string,int);
		~Girl();
		void Display();
		friend void  VisitBoyGirl(Boy &, Girl &);
};
Boy::Boy(string name,int age)
{
	Age = age;
	if(name.length() >0 )
	Name = name;
	cout<<"调用Boy有参构造函数"<<endl;
}
Boy::~Boy()
{
	if(Name.length()>0)
		Name="";
	cout<<"调用Boy析构函数"<<endl;
};

Girl::Girl(string name,int age)
{
	Age = age;
	if(name.length() >0 )
	Name = name;
	cout<<"调用Girl有参构造函数"<<endl;
}
Girl::~Girl()
{
	if(Name.length()>0)
		Name="";
	cout<<"调用Girl析构函数"<<endl;
};
void Girl::Display()
{
	cout<<"女孩名字:"<<Name<<"--年龄:"<<Age<<endl; 
}
void Boy::Display()
{
	cout<<"男孩名字:"<<Name<<"--年龄:"<<Age<<endl; 
}
void VisitBoyGirl(Boy &boy, Girl &girl)
{
	cout<<"调用顶层作为Boy和Girl的友元函数:"<<endl;
	boy.Display();
	girl.Display(); 
}
int main()
{
	Boy boy("John",18);
	Girl girl("Tina",3); 
	boy.Display();
	girl.Display();
	VisitBoyGirl(boy,girl);
	return 0;
}
