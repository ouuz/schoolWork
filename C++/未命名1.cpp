#include <iostream>
#include <cstring>
using namespace std;
class Student{
	private:
		int age;
		char *name;
	public:
		Student(int TrueAge,char* TrueName);
		Student();
		void SetMember(int , char*);
		int Getage();
		char* Getname();
		~Student();		
};

Student::Student(){
	age = 0;
	name= "unnamed";
}

Student::Student(int TrueAge,char* TrueName){
	age = TrueAge;
	if(TrueName)
	{
		name = new char [strlen(TrueName)+1];
		strcpy(name,TrueName);
	}
}

void Student::SetMember(int newAge, char *newName)
{
	age = newAge;
	if(newName)
	{
		name = new char [strlen(newName)+1];
		strcpy(name,newName);
	}
}
int Student::Getage()
{
	return age;
}
char* Student::Getname()
{
	return name;
}
Student::~Student()
{
	if(name)
	delete []name;
}

int main( )
{
Student stu[3]={Student(13,"wang")} ;   /*第一个元素用带参构造函数初始化；第二、三个元素由无参构造函数初始化，默认年龄为 0 ，姓名为 "unnamed"*/
stu[2].SetMember(12,"zhang");           /*修改第三个元素的数据成员值*/
cout<<stu[0].Getage( )<<","<<stu[0].Getname( )<<"\n";
cout<<stu[1].Getage( )<<","<<stu[1].Getname( )<<"\n"; 
cout<<stu[2].Getage( )<<","<<stu[2].Getname( )<<"\n"; /*这三句可改用一个循环*/
    return 0;
}
