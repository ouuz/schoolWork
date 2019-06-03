#include <iostream>
using namespace std;
class Time{
	private:
		int Hour;
		int Minute;
		int Second;
	public:
	Time(int  ,int ,int );
	~Time();
    Time(const Time &time);
	void ModifyTime(int,int,int);
	int GetHour();	
	int GetMinute();	
	int GetSecond();
	void PrintTime();
	void IncreaceOneSecond();
	friend void f(Time t);
};


void f(Time t)
{
	t.PrintTime();
}
//**********构造和析构函数************* 
Time::Time(int h,int m,int s)
{
	Hour = h;
	Minute = m;
	Second = s;
	cout<<"调用有参构造函数"<<endl;
}
Time::Time(const Time &time)
{
	Hour = time.Hour;
	Minute = time.Minute;
	Second = time.Second;
	cout<<"调用拷贝构造函数"<<endl;
}
Time::~Time()
{
	cout<<"调用析构函数"<<endl;
}
///*************更改|输出时间|增加一秒函数**************  
void Time::ModifyTime(int nh,int nm,int ns)
{
	Hour = nh;
	Minute = nm;
	Second = ns;
	cout<<"更改后的时间为："<<endl;
}
void Time::PrintTime()
{
	cout<<Hour<<":"<<Minute<<":"<<Second<<endl; 
} 
void Time::IncreaceOneSecond()
{
	if(Second>=0&&Second<=58)
		Second += 1;	
	else if(Second == 59)
	{
	    if(Minute>=0 && Minute<=58)
	    	Minute +=1;
	    else if(Minute == 59)
	    {
	    	Minute = 0;
	    	if(Hour>=0 && Hour<=23)
	    		Hour += 1;
	    	else if(Hour == 24)
				Hour ;	
		}
		
		if(Hour == 23 && Minute == 59 && Second ==59 )
			Hour = Minute = Second = 0;
			
		Second = 0;	
	}
	cout<<"时间已经增加一秒"<<endl;
	cout<<"增加一秒后的时间是"<<Hour<<":"<<Minute<<":"<<Second<<endl; 
}
//*******************获取时间函数************** 
int Time::GetHour()
{
	return Hour;
}
int Time::GetMinute()
{
	return Minute;
}
int Time::GetSecond()
{
	return Second;
}
//********************主函数********************
int main()
{
	Time today(19,23,54), *p;
	p = &today;
	today.PrintTime();
	today.ModifyTime(23,59,59);
	p -> PrintTime();
	cout<<"当前时间的时为："<<today.GetHour()<<endl; 
	cout<<"当前时间的分为："<<p ->GetMinute()<<endl; 
	cout<<"当前时间的秒为："<<today.GetSecond()<<endl; 
	today.IncreaceOneSecond();
	Time NewDay(today);
	cout<<"调用拷贝构造后创造的新时间为:"<<endl;
	NewDay.PrintTime();
	cout<<"调用f函数："<<endl;
	f(NewDay);
	return 0;
} 
