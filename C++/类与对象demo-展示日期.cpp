//头文件 
#include <iostream>
#include <string>
#include<cstring>
using namespace std;
//类定义 
class Student;//先定义后使用 向前引用声明 
class Date{
	private:
		int year;
		int day;
		int month;
	public:
//		int setDate(int , int , int );
		Date(int x,int y,int z){ //构造函数声明时可加默认参数值 定义时不加  
				year = x;
				month = y;
				day = z;
		} //构造函数名同类名 如果不在类体内定义 则 Date::Date(){} 
		//一个类可以拥有多个构造函数 重载
		Date(){};//无参的构造函数 声明并定义 
		~Date(); //默认析构函数声明 调用顺序与构造完全相反 
		Date(const Date &date); //拷贝构造函数声明 
		void Display(const Student &stu); //友元成员声明 给形参名 
		//实际上Display是Date的成员函数 Student的友元成员 
		int getYear();
		int getMonth();
		int getDay();
		friend bool isTrue(Date &A,Date &B);//友元函数 声明 
}; 
class Student{
	private:
		char *dz;
	public:
	Student(char *zfc);
	~Student();
	friend void Date::Display(const Student &); //友元成员声明 
};
/*int Date::setDate(int x,int y,int z){ 
	year = x;
	month = y;
	day = z;
}*/
Date::Date(const Date &date){
	year = date.year;
	month = date.month;
	day = date.day;
};//拷贝构造函数的定义 
Date::~Date(){};//析构函数定义 
int Date::getYear(){
	return year;
}
int Date::getMonth(){
	return month;
}
int Date::getDay(){
	return day;
}
void Date::Display(const Student &stu)
{
	cout<<stu.dz<<endl;
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}
bool isTrue(Date &A,Date &B){//友元函数 定义 
	return (A.year == B.year&&A.month == B.month&&A.day == B.day);
}


Student::Student(char *zfc){
	if(zfc){
		dz = new char [strlen(zfc)+1];//因为不知道实际字符串长度 所以要申请动态空间 
		strcpy(dz,zfc);//复制字符串 
	}else dz= 0;
}
Student::~Student(){
	if(dz)
	delete []dz;//释放空间 
}
//主函数 
int main(){
    Student ZY("computerScience");
	Date *t;//定义对象 类似int   
	Date today(2019,04,19);//定义对象 类似int   
	Date day1(); //声明一个函数名为day1的函数 
//	today.setDate(2019,04,19);
	today.Display(ZY);

	t = &today;
//	t -> setDate(2019,04,20);
// (*t).setDate(2019,04,20)
	t -> Display(ZY); //  (*t).Display()
	
	today = Date(1,1,1);//构造无名对象 
	today.Display(ZY);
	Date(2,2,2).Display(ZY);//无名对象
	
	Date day2(today); //拷贝构造函数的调用1 
	day2.Display(ZY); 
	Date day3 = today;  //拷贝构造函数的调用2
	day3.Display(ZY);	
	Date attr[5]={Date(2018,1,1),Date(2019,2,1)}; //对象数组 
	attr[0].Display(ZY);
	
	Date *p;//对象指针 
	p = attr;
	for(;p<attr+2;p++)
	p->Display(ZY); 
	
	Date A (2019,1,1),B(2019,9,1); //友元函数的运用 
	cout<<isTrue(A ,B)<<endl;
	
	today.Display(ZY); // 友元成员的运用 
	return 0;
}
