#include <cstring>
#include<iostream>
using namespace std;

class Student
{
private:
	int age;
	char *name;
public:
	static int count;
	Student(int m, char*n)
	{
		age = m;
		name = new char[strlen(n) + 1];
		strcpy(name,n);
		count++;
	};
	Student(){
		age = 0;
		name = new char[10];
		strcpy(name,"unnamed");
		count ++;
	};
	~Student()
	{
	 	count --;
		delete []name;
	}
	void Print() const
	{
		cout << "count=" << count << endl;
		cout << name << "  " << age << endl;
	}
};
int main()
{
	cout << "count=" << Student::count << endl;
	char stuname[20] = "ZhangHong";
	Student s1, *p = new Student(23, stuname);
	s1.Print();
	p->Print();
	delete p;
	s1.Print();
	Student Stu[4];
	cout << "count=" << Student::count << endl;
	return 0;
}

